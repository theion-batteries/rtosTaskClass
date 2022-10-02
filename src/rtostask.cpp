#include "rtostask.h"

void webServer::init()
{
    Serial.begin(115200);
    server = WiFiServer(port);
}
void webServer::scanNetwork()
{
    // if the ssid and pass are passed to constructor, ignore scan
    if (!ssid.isEmpty() && !password.isEmpty()) return;
    int n = wlan.scanNetworks();
    Serial.println("scanning network available: ");
    bool found = false;
    // iterate wifis
    for (int i = 0;i < n; i++)
    {
        Serial.println(wlan.SSID(i));
        for (auto saved : saved_wifis)
        {
            if (wlan.SSID(i) == saved.first)
            {
                Serial.println("found saved wifi: ");
                Serial.println("-------------------");
                Serial.println(saved.first);
                Serial.println("-------------------");

                ssid = saved.first;
                password = saved.second;
                found = true;
                break;
            }
        }
        if (found) break;
    }
}
void webServer::connect()
{
    // Connect to Wi-Fi network with SSID and password
    Serial.print("Connecting to ");
    Serial.println(ssid);
    wlan.begin(ssid.c_str(), password.c_str());
    while (wlan.status() != WL_CONNECTED) {
        delay(500);
        Serial.print(".");
    }
    // Print local IP address and start web wlan
    Serial.println("");
    Serial.println("wlan connected.");
    Serial.println("IP address: ");
    Serial.println(wlan.localIP());
    Serial.println("port: ");
    Serial.println(port);
    server.begin();
}
void webServer::disconnect()
{
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
    client_connected = false;
}
void webServer::listen()
{
    if (client = server.available()) // once server availble
    {
        Serial.println("New Client connected ..");          // print a message out in the serial port
        Serial.println(client.remoteIP());
        Serial.println(client.remotePort());
        client_connected = true;

    }

}


void webServer::parseRequest()
{
    while (client.connected())
    {
        if (client.available()) //if there's bytes to read from the client,
        {
            Serial.println("incoming data");
            auto cmd = client.readString();
            Serial.println(cmd);
            lastCmd = cmd;
            // create thread and process the cmd inside it 
            handleRequestTask();
            // debug
            client.println("done!");
        }
    }

}


void webServer::handleclientTask()
{
    Serial.println("new handle client task");

    xTaskCreate(
        clientTaskWrapper,   /* Task function. */
        "parseClient",        /* String with name of task. */
        10000,            /* Stack size in bytes. */
        NULL,             /* Parameter passed as input of the task */
        0,                /* Priority of the task. */
        NULL);            /* Task handle. */

}
void webServer::processCmd()
{
    Serial.println("process cmd ");
    for(int i =0; i<1000; i++)
    {
    Serial.println("processing request");
    Serial.println(i);   
    delay(100); 
    }
    //parser.processCmd(lastCmd);
    Serial.println("request finish");
    // feedback client and delete
    vTaskDelete(NULL);
}
void webServer::handleRequestTask()
{
    Serial.println("new handle request task");
    
    xTaskCreate(
        reqTaskWrapper, //taskwrapper<webServer>(this, std::bind(&webServer::processCmd,this)),
        "processClientReq",        /* String with name of task. */
        10000,            /* Stack size in bytes. */
        NULL,             /* Parameter passed as input of the task */
        0,                /* Priority of the task. */
        NULL);            /* Task handle. */

}

void reqTaskWrapper(void* parm) {
    static_cast<webServer *>(parm)->processCmd();
}

void clientTaskWrapper(void* parm) {
    static_cast<webServer *>(parm)->parseRequest();
}

