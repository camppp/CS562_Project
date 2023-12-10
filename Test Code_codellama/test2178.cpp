#include <ArduinoOTA.h>

bool web = true; // Assume web request is true for demonstration purposes

void do_web(){
  if(web){
    // Handle web requests and perform OTA updates using ArduinoOTA library
    ArduinoOTA.handle();
  }
}
