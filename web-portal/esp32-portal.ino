#include <WiFi.h>
#include <WebServer.h>

WebServer server(80);

void setup() {
  Serial.begin(115200);

  WiFi.softAP("ESP32", "12345678");

  server.on("/", []() {
    server.send(200, "text/html",
                "<h1>Hello from ESP32!</h1>"
                "<p>Welcome to my web portal.</p>");
  });

  server.begin();

  Serial.println("WiFi: ESP32");
  Serial.println("Password: 12345678");
  Serial.println("Open: 192.168.4.1");
}

void loop() {
  server.handleClient();
}
