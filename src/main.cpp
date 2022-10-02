//#define crtp
#define runtime_polymorphism
#ifdef crtp
#include "crtp.h"
#endif
#ifdef runtime_polymorphism
#include "runtime_poly.h"
#endif
#include "HowToFunctional.hpp"
#include "HowToSmartPtr.hpp"
#include "HowToThreads.hpp"
#include "webServer.h"

void setup() {
    Serial.begin(115200);/*
    repeat_n(3, []() {
      std::cout<<"Lambda-Funktion\n";
    });
    repeat_n(3, &f_ptr);
    repeat_n(3, FObj());
    test_shared_ptr();
    test_unique_ptr();
    test_threads();*/
    Wrapper* w = new Wrapper();
    std::thread tw1 = w->member1Thread();
    std::thread tw2 = w->member2Thread("hello", 100);
    tw1.join();
    tw2.join();
    std::unique_ptr<Base> pBase = std::make_unique<Derived>();      
    
    pBase->SayHello();
    test();



 WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println(WiFi.localIP());
 
  server.on("/html", HTTP_GET, [](AsyncWebServerRequest *request){
    request->send(200, "text/html", HTML);
  });
 
  server.begin();


}

void loop() {
    //test_threads();
}
