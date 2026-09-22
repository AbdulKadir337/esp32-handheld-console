#pragma once
#include <Arduino.h>
#include "game_snake.h"

// Hardware peripheral constants for the HW-504 joystick
constexpr int JOY_X_GPIO = 25;    // Analog VRx pin 
constexpr int JOY_Y_GPIO = 26;    // Analog VRy pin 
constexpr int JOY_BTN_GPIO = 27;  // Digital SW pin 

void setupControls();
bool readRequestedDirection(Direction &requested);
