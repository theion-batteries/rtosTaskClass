#pragma once
#include <WiFi.h>
#include <map>
#include <memory>
#include <functional>


class webServer
{
private:
    std::map<const char*, const char*> saved_wifis{ {"TheionEngineeringLab", "!2021BatLab1"}, {"Halal-wifi", "Halal-Wlan"}, };
    // Replace with your network credentials
    String ssid;
    String password;
    // Set web server port number 
    uint port = 80;
    WiFiClass wlan;
    WiFiServer server;
    WiFiClient client;
    //std::shared_ptr< cmdParser> parser;
    String lastCmd;
    bool client_connected = false;
public:
    // default 
    webServer() {

        Serial.begin(115200);
        Serial.println("creating web server");
       // parser = std::make_shared<cmdParser>();
        //parser = new cmdParser();
        server = WiFiServer(port);
    }
    ~webServer() {
        //delete parser;
    }
    // constructor accepting ssid and password
    webServer(const char* ssid, const char* password, uint port) :ssid(ssid), password(password), port(port) {
        server = WiFiServer(port);
    }


    void init();
    // scan
    void scanNetwork();
    // connect
    void connect();
    // disconnect
    void disconnect();
    // listen for clients
    void listen();
    // parse req
    void parseRequest();
    // process cmd wrapper
    void processCmd();
    // handle client
    void handleclientTask();
        // handle request Task
    void handleRequestTask();

};

extern "C"
{
void reqTaskWrapper(void* parm);
void clientTaskWrapper(void* parm);
}
