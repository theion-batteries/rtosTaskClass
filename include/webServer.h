#include <Arduino.h>
#include <WiFi.h>
#include <FS.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>


const char* ssid = "Halal-wifi";
const char* password = "Halal-Wlan";
 
AsyncWebServer server(80);
const char HTML[] PROGMEM = "<script src=\"https://www.w3schools.com/js/myScript.js\"></script> <form onSubmit=\"event.preventDefault(); formToJson(this);\"> <label class=\"label\">Network Name</label> <input type=\"text\" name=\"ssid\"/> <label>Password</label> <input type=\"text\" name=\"pass\"/> <input type=\"submit\" value=\"Submit\"></form>";
