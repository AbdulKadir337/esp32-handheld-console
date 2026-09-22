#include "display.h"
#include "game_snake.h"
#include <Wire.h>

U8G2_SH1106_128X64_NONAME_F_HW_I2C display(U8G2_R0, U8X8_PIN_NONE);

void setupDisplay() {
  Wire.begin(OLED_SDA, OLED_SCL);
  display.begin();
}

void drawGame() {
  display.clearBuffer();

  for (uint8_t i = 0; i < snakeLength; ++i) {
    display.drawBox(snake[i].x * CELL_SIZE, snake[i].y * CELL_SIZE, CELL_SIZE, CELL_SIZE);
  }

  display.drawBox(food.x * CELL_SIZE, food.y * CELL_SIZE, CELL_SIZE, CELL_SIZE);

  if (gameOver) {
    display.setFont(u8g2_font_6x10_tf);
    display.drawStr(18, 28, "GAME OVER");
  }

  display.sendBuffer();
}

/*
#include "display.h"
#include <Wire.h>

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

void setupDisplay() {
  Wire.begin(OLED_SDA, OLED_SCL);
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    while (true) delay(1000);
  }
}

void drawGame() {
  display.clearDisplay();

  for (uint8_t i = 0; i < snakeLength; ++i) {
    display.fillRect(snake[i].x * CELL_SIZE, snake[i].y * CELL_SIZE, CELL_SIZE, CELL_SIZE, SSD1306_WHITE);
  }

  display.drawRect(food.x * CELL_SIZE, food.y * CELL_SIZE, CELL_SIZE, CELL_SIZE, SSD1306_WHITE);

  if (gameOver) {
    display.fillRect(12, 20, 104, 25, SSD1306_BLACK);
    display.drawRect(12, 20, 104, 25, SSD1306_WHITE);
    display.setTextColor(SSD1306_WHITE);
    display.setTextSize(1);
    display.setCursor(22, 25);
    display.print("GAME OVER  ");
    display.print(score);
    display.setCursor(19, 35);
    display.print("Press a direction");
  }

  display.display();
}*/