
void initHTTP(void) {
  HTTP.on("/ir", handleIr);
  HTTP.on("/set", set);
  HTTP.on("/inline", []() {
    HTTP.send(200, "text/plain", "this works as well");
  });
  HTTP.begin();
}

void set() {
  String root = "{}";
  DynamicJsonBuffer jsonBuffer;
  JsonObject& json = jsonBuffer.createObject();
  JsonArray& main = json.createNestedArray("main");
  for (uint8_t i = 0; i < HTTP.args(); i++) {
    JsonObject& obj = main.createNestedObject();
    obj["code"] = HTTP.arg(i);
    obj["name"] = HTTP.argName(i);
    root = "";
    json.printTo(root);
  }
  writeFile("ir.json", root);
   HTTP.send(200,"text/plain", root);
}

void handleIr() {
  String req;
  for (uint8_t i = 0; i < HTTP.args(); i++) {
    if (HTTP.argName(i) == "code") {
      uint32_t code = strtoul(HTTP.arg(i).c_str(), NULL, 10);
      req+=code;
#if SEND_NEC
      irsend.sendNEC(code, 32);
#endif  // SEND_NEC
    }
  }
 HTTP.send(200,"text/plain",req);
}


