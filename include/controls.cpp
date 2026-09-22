#include "controls.h"
#include <Arduino.h>

const int JOY_X_GPIO = 25;
const int JOY_Y_GPIO = 26;
const int JOY_BTN_GPIO = 27;

int joyXCenter = 1910;
int joyYCenter = 1922;

const int JOY_DEADZONE = 700;

void setupControls() {
  pinMode(JOY_BTN_GPIO, INPUT_PULLUP);
}

bool readRequestedDirection(Direction &requested) {
  int x = analogRead(JOY_X_GPIO);
  int y = analogRead(JOY_Y_GPIO);

  Serial.print("X=");
  Serial.print(x);
  Serial.print(" Y=");
  Serial.println(y);

  if (y > joyXCenter + JOY_DEADZONE) { requested = LEFT; return true; }
  if (y < joyXCenter - JOY_DEADZONE) { requested = RIGHT;  return true; }
  if (x > joyYCenter + JOY_DEADZONE) { requested = DOWN;  return true; }
  if (x < joyYCenter - JOY_DEADZONE) { requested = UP;    return true; }

  return false;
}
