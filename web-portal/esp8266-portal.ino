#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

void setup() {
  Serial.begin(115200);

  WiFi.softAP("ESP8266", "12345678");

  server.on("/", []() {
    server.send(200, "text/html",
                "<h1>Hello from ESP8266!</h1>"
                "<p>Welcome to my web portal.</p>");
  });

  server.begin();

  Serial.println("WiFi: ESP8266");
  Serial.println("Password: 12345678");
  Serial.println("Open: 192.168.4.1");
}

void loop() {
  server.handleClient();
}
