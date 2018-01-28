#include <IRremoteESP8266.h>
#include <IRsend.h>
#include <ESP8266WiFi.h>        
#include <ESP8266WebServer.h>   
#include <ESP8266SSDP.h>       
#include <FS.h>                 
#include <ArduinoJson.h>       
#include <ESP8266HTTPUpdateServer.h>
#include <DNSServer.h> 


ESP8266HTTPUpdateServer httpUpdater;
ESP8266WebServer HTTP;
File fsUploadFile;
IRsend irsend(4); 

String ir = "{}";
const char* ssid = "ZyXEL_KEENETIC_LITE";
const char* password = "";

void setup(void) {
  HTTP = ESP8266WebServer (80);
  irsend.begin();
 FS_init();
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  Serial.println("");

  // Wait for connection
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());

  initHTTP();


  ir = readFile("ir.json", 1024);
  Serial.println("Server started ", millis());
}

void loop(void) {
  HTTP.handleClient();
}
