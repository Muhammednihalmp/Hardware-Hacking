#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

#define LED_PIN 2   // GPIO2 = D4 on NodeMCU

bool ledState = false;

// Web page
const char MAIN_page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>
<head>
  <meta name="viewport" content="width=device-width, initial-scale=1">

  <title>ESP8266 LED Control</title>

  <style>
    body {
      margin: 0;
      padding: 0;
      font-family: Arial, sans-serif;
      background: #f2f2f2;
      text-align: center;
    }

    .container {
      width: 90%;
      max-width: 400px;
      margin: 80px auto;
      padding: 30px;
      background: white;
      border-radius: 15px;
      box-shadow: 0 5px 20px rgba(0,0,0,0.15);
    }

    h1 {
      color: #333;
    }

    #status {
      font-size: 20px;
      margin: 20px 0;
      font-weight: bold;
    }

    button {
      width: 140px;
      padding: 15px;
      margin: 10px;
      border: none;
      border-radius: 10px;
      font-size: 18px;
      cursor: pointer;
    }

    .on {
      background: #28a745;
      color: white;
    }

    .off {
      background: #dc3545;
      color: white;
    }

    button:hover {
      opacity: 0.8;
    }
  </style>
</head>

<body>

  <div class="container">
    <h1>ESP8266 LED Control</h1>

    <div id="status">LED is OFF</div>

    <button class="on" onclick="controlLED('on')">
      ON
    </button>

    <button class="off" onclick="controlLED('off')">
      OFF
    </button>
  </div>

  <script>
    function controlLED(state) {

      fetch("/led/" + state)
        .then(response => response.text())
        .then(data => {

          document.getElementById("status").innerHTML = data;

        })
        .catch(error => {
          document.getElementById("status").innerHTML =
            "Connection error";
        });
    }
  </script>

</body>
</html>
)=====";


// Home page
void handleRoot() {
  server.send(200, "text/html", MAIN_page);
}


// LED ON
void handleLEDOn() {
  // Built-in ESP8266 LED is usually active LOW
  digitalWrite(LED_PIN, LOW);

  ledState = true;

  server.send(200, "text/plain", "LED is ON");
}


// LED OFF
void handleLEDOff() {
  digitalWrite(LED_PIN, HIGH);

  ledState = false;

  server.send(200, "text/plain", "LED is OFF");
}


void setup() {

  Serial.begin(115200);

  // Set LED pin as output
  pinMode(LED_PIN, OUTPUT);

  // LED initially OFF
  digitalWrite(LED_PIN, HIGH);


  // Create WiFi Access Point
  WiFi.softAP("ESP8266", "12345678");


  // Web page
  server.on("/", handleRoot);


  // LED control URLs
  server.on("/led/on", handleLEDOn);
  server.on("/led/off", handleLEDOff);


  // Start server
  server.begin();


  Serial.println();
  Serial.println("================================");
  Serial.println("ESP8266 Web Server Started");
  Serial.println("================================");

  Serial.println("WiFi: ESP8266");
  Serial.println("Password: 12345678");
  Serial.println("Open: http://192.168.4.1");
}


void loop() {
  server.handleClient();
}