#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);
#define BTN 2

void setup() {
  pinMode(BTN, INPUT_PULLUP);

  WiFi.softAP("ESP8266-Portal", "12345678");

  server.on("/", []() {
    String s = "<style>body{text-align:center;font:30px Arial}</style>";
    s += "<h1>ESP8266 Portal</h1><h2>";
    s += digitalRead(BTN) == LOW ? "Button PRESSED" : "Button OFF";
    s += "</h2>";
    server.send(200, "text/html", s);
  });

  server.begin();
}

void loop() {
  server.handleClient();
}