#include <WiFi.h>
#include <WebServer.h>
#include <ESP32Servo.h>

Servo servo;

WebServer server(80);

// Servo pin
const int servoPin = 2;

// Access Point credentials
const char* apName = "ESP32-Servo";
const char* apPassword = "12345678";

int angle = 90;


// =========================
// WEB PAGE
// =========================

void handleRoot() {

  String html = R"rawliteral(
<!DOCTYPE html>
<html>

<head>

<meta name="viewport"
      content="width=device-width, initial-scale=1">

<title>ESP32 Servo Control</title>

<style>

body {
  font-family: Arial;
  text-align: center;
  background: #eeeeee;
  margin-top: 50px;
}

.container {
  background: white;
  max-width: 400px;
  margin: auto;
  padding: 30px;
  border-radius: 15px;
  box-shadow: 0px 0px 15px #aaaaaa;
}

h1 {
  color: #333333;
}

#value {
  font-size: 40px;
  font-weight: bold;
}

input[type=range] {
  width: 100%;
}

button {
  font-size: 18px;
  padding: 12px 20px;
  margin: 10px 5px;
  border: none;
  border-radius: 8px;
  cursor: pointer;
}

</style>

</head>


<body>

<div class="container">

<h1>ESP32 Servo Control</h1>

<p>Servo Angle</p>

<div id="value">90°</div>

<br>

<input
  type="range"
  min="0"
  max="180"
  value="90"
  id="slider"
  oninput="moveServo(this.value)"
>

<br><br>

<button onclick="moveServo(0)">
0°
</button>

<button onclick="moveServo(90)">
90°
</button>

<button onclick="moveServo(180)">
180°
</button>

</div>


<script>

function moveServo(angle) {

  document.getElementById("value").innerHTML =
    angle + "°";

  document.getElementById("slider").value =
    angle;

  fetch("/servo?angle=" + angle);
}

</script>

</body>

</html>

)rawliteral";

  server.send(200, "text/html", html);
}


// =========================
// SERVO CONTROL
// =========================

void handleServo() {

  if (server.hasArg("angle")) {

    angle = server.arg("angle").toInt();

    // Limit angle from 0 to 180
    angle = constrain(angle, 0, 180);

    servo.write(angle);

    Serial.print("Servo Angle: ");
    Serial.println(angle);

    server.send(200, "text/plain", "OK");

  } else {

    server.send(400, "text/plain", "Missing angle");
  }
}


// =========================
// SETUP
// =========================

void setup() {

  Serial.begin(115200);

  // Attach servo
  servo.setPeriodHertz(50);
  servo.attach(servoPin, 500, 2400);

  // Set initial position
  servo.write(90);


  // =========================
  // CREATE ESP32 ACCESS POINT
  // =========================

  WiFi.mode(WIFI_AP);

  WiFi.softAP(apName, apPassword);


  Serial.println();
  Serial.println("==============================");
  Serial.println("ESP32 SERVO ACCESS POINT");
  Serial.println("==============================");

  Serial.print("WiFi Name: ");
  Serial.println(apName);

  Serial.print("WiFi Password: ");
  Serial.println(apPassword);

  Serial.print("IP Address: ");
  Serial.println(WiFi.softAPIP());


  // =========================
  // WEB SERVER
  // =========================

  server.on("/", handleRoot);

  server.on("/servo", handleServo);

  server.begin();

  Serial.println("Web Server Started!");
}


// =========================
// LOOP
// =========================

void loop() {

  server.handleClient();
}
