#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <Servo.h>

Servo servo;

ESP8266WebServer server(80);

const int servoPin = 2; // D4

// Access Point credentials
const char* apName = "ESP8266-Servo";
const char* apPassword = "12345678";

int angle = 90;

void handleRoot() {

  String html = R"rawliteral(
<!DOCTYPE html>
<html>
<head>
<meta name="viewport" content="width=device-width, initial-scale=1">

<title>ESP8266 Servo</title>

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
}

h1 {
  color: #333;
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
}
</style>
</head>

<body>

<div class="container">

<h1>ESP8266 Servo Control</h1>

<p>Servo Angle</p>

<div id="value">90°</div>

<br>

<input type="range"
       min="0"
       max="180"
       value="90"
       id="slider"
       oninput="moveServo(this.value)">

<br><br>

<button onclick="moveServo(0)">0°</button>
<button onclick="moveServo(90)">90°</button>
<button onclick="moveServo(180)">180°</button>

</div>

<script>

function moveServo(angle) {

  document.getElementById("value").innerHTML = angle + "°";

  document.getElementById("slider").value = angle;

  fetch("/servo?angle=" + angle);
}

</script>

</body>
</html>
)rawliteral";

  server.send(200, "text/html", html);
}

void handleServo() {

  if (server.hasArg("angle")) {

    angle = server.arg("angle").toInt();

    angle = constrain(angle, 0, 180);

    servo.write(angle);

    Serial.print("Servo angle: ");
    Serial.println(angle);

    server.send(200, "text/plain", "OK");

  } else {

    server.send(400, "text/plain", "Missing angle");
  }
}

void setup() {

  Serial.begin(115200);

  // Servo
  servo.attach(servoPin);
  servo.write(90);

  // Start ESP8266 Access Point
  WiFi.mode(WIFI_AP);

  WiFi.softAP(apName, apPassword);

  Serial.println();
  Serial.println("================================");
  Serial.println("ESP8266 SERVO ACCESS POINT");
  Serial.println("================================");

  Serial.print("AP Name: ");
  Serial.println(apName);

  Serial.print("AP IP Address: ");
  Serial.println(WiFi.softAPIP());

  // Web server
  server.on("/", handleRoot);
  server.on("/servo", handleServo);

  server.begin();

  Serial.println("Web server started!");
}

void loop() {

  server.handleClient();
}
