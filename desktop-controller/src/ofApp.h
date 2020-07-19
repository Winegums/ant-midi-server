#pragma once

#include "ofMain.h"
#include "ofxSerial.h"
#include "ofxOsc.h"

// send host (aka ip address)
#define HOST "localhost"

/// send port
#define PORT 12345

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
        // SERIAL SETUP
        std::vector<ofx::IO::SerialDevice> devices;
        int numberOfConnectedDevices = 0;
        std::vector<std::string> receivedData;
        std::vector<int> foundDevicesArray;

        // DEVICE STRUCT
        struct AntDevice {
            int numberOfSensors;
            std::vector<int> deviceValues;
            std::vector<int> lastDeviceValues;
            std::vector<int> deviceValuesMin;
            std::vector<int> deviceValuesMax;
            std::vector<int> deltaValues;
        };
    
        std::vector<AntDevice> deviceData;

        std::vector<int> updateDeltaValue(std::vector<int> value, std::vector<int> lastValue);
        void outputDeviceValueOSC(int deviceID, std::vector<int> deltaValues, std::vector<int> deviceValuesMin, std::vector<int> deviceValuesMax);
        std::vector<int> convertStrtoVec(string str);
        
        // OSC SETUP
        ofxOscSender sender;
};
