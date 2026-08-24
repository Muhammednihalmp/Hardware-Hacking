#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>

ESP8266WebServer server(80);

#define LED_PIN 4   // D2 = GPIO4

int brightness = 0;


// ==========================
// WEB PAGE
// ==========================
const char page[] PROGMEM = R"=====(
<!DOCTYPE html>
<html>

<head>
<meta name="viewport" content="width=device-width,initial-scale=1">
<title>ESP8266 LED</title>

<style>

body {
  margin: 0;
  padding: 0;
  font-family: Arial;
  background: #f2f2f2;
  text-align: center;
}

.box {
  width: 85%;
  max-width: 400px;
  margin: 70px auto;
  padding: 30px;
  background: white;
  border-radius: 15px;
  box-shadow: 0 5px 20px rgba(0,0,0,.15);
}

h2 {
  margin-bottom: 25px;
}

#value {
  font-size: 40px;
  font-weight: bold;
  margin: 20px;
}

#status {
  font-size: 18px;
  margin-bottom: 25px;
}

input[type=range] {
  width: 100%;
  height: 10px;
  cursor: pointer;
}

.buttons {
  margin-top: 25px;
}

button {
  width: 110px;
  padding: 12px;
  margin: 5px;
  border: none;
  border-radius: 8px;
  font-size: 16px;
  color: white;
  cursor: pointer;
}

.on {
  background: #28a745;
}

.off {
  background: #dc3545;
}

</style>

</head>

<body>

<div class="box">

<h2>LED Brightness</h2>

<div id="value">0%</div>

<div id="status">LED OFF</div>

<input
  id="slider"
  type="range"
  min="0"
  max="1023"
  value="0"
  oninput="changeBrightness(this.value)"
>

<div class="buttons">

<button class="on" onclick="setBrightness(1023)">
ON
</button>

<button class="off" onclick="setBrightness(0)">
OFF
</button>

</div>

</div>


<script>

function updateDisplay(pwm) {

  let percent = Math.round((pwm / 1023) * 100);

  document.getElementById("value").innerHTML =
    percent + "%";

  document.getElementById("slider").value =
    pwm;

  if (percent == 0) {
    document.getElementById("status").innerHTML =
      "LED OFF";
  }
  else {
    document.getElementById("status").innerHTML =
      "LED ON";
  }
}


function changeBrightness(pwm) {

  updateDisplay(pwm);

  fetch("/brightness?v=" + pwm)
    .catch(() => {
      document.getElementById("status").innerHTML =
        "Connection Error";
    });
}


function setBrightness(pwm) {

  updateDisplay(pwm);

  fetch("/brightness?v=" + pwm)
    .catch(() => {
      document.getElementById("status").innerHTML =
        "Connection Error";
    });
}

</script>

</body>
</html>
)=====";


// ==========================
// HOME PAGE
// ==========================
void handleRoot() {

  server.send(
    200,
    "text/html",
    page
  );

}


// ==========================
// BRIGHTNESS
// ==========================
void handleBrightness() {

  if (server.hasArg("v")) {

    brightness = server.arg("v").toInt();

    brightness = constrain(
      brightness,
      0,
      1023
    );

    analogWrite(
      LED_PIN,
      brightness
    );

    Serial.print("PWM: ");
    Serial.print(brightness);

    Serial.print("  Brightness: ");
    Serial.print(
      (brightness * 100) / 1023
    );

    Serial.println("%");
  }

  server.send(
    200,
    "text/plain",
    "OK"
  );

}


// ==========================
// SETUP
// ==========================
void setup() {

  Serial.begin(115200);

  pinMode(
    LED_PIN,
    OUTPUT
  );

  // LED OFF
  analogWrite(
    LED_PIN,
    0
  );


  // WiFi Access Point
  WiFi.softAP(
    "ESP8266",
    "12345678"
  );


  // Web page
  server.on(
    "/",
    handleRoot
  );


  // Brightness control
  server.on(
    "/brightness",
    handleBrightness
  );


  server.begin();


  Serial.println();
  Serial.println("==============================");
  Serial.println("ESP8266 LED Brightness");
  Serial.println("==============================");

  Serial.println("LED : D2 / GPIO4");
  Serial.println("WiFi: ESP8266");
  Serial.println("Pass : 12345678");
  Serial.println("URL  : http://192.168.4.1");

}


// ==========================
// LOOP
// ==========================
void loop() {

  server.handleClient();

}