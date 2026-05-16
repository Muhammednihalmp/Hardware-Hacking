# Simple LED ON Example

This Arduino sketch turns ON an LED connected to GPIO2 and keeps it ON continuously.

## Code

```cpp
void setup() {
  pinMode(2, OUTPUT);    // Set GPIO2 as output
  digitalWrite(2, HIGH); // Turn the LED ON
}

void loop() {
  // Nothing needed here
}
```

## How It Works

* `pinMode(2, OUTPUT)` configures GPIO2 as an output pin.
* `digitalWrite(2, HIGH)` sets GPIO2 to HIGH, turning the LED ON.
* The `loop()` function is empty because no repeated action is required.

## Upload Instructions

1. Connect your board to the computer.
2. Open the Arduino IDE.
3. Paste the code into a new sketch.
4. Select the correct board and port.
5. Click **Upload**.

## Result

The LED connected to GPIO2 will stay ON after the program is uploaded.
