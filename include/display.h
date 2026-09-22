#pragma once
#include <Arduino.h>
#include <U8g2lib.h>
#include "game_snake.h"

extern U8G2_SH1106_128X64_NONAME_F_HW_I2C display;

const uint8_t OLED_SDA = 21;
const uint8_t OLED_SCL = 22;

void setupDisplay();
void drawGame();

/*
#pragma once
#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <U8g2lib.h>
#include <Adafruit_SSD1306.h>

#include "game_snake.h"

constexpr int OLED_SDA = 21;
constexpr int OLED_SCL = 22;

extern Adafruit_SSD1306 display;

void setupDisplay();
void drawGame();
*/