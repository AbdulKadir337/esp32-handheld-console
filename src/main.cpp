#include <Arduino.h>
#include "controls.h"
#include "display.h"
#include "game_snake.h"

void setup() {  
  Serial.begin(9600);
  setupControls();
  setupDisplay();
  randomSeed(micros());
  startGame();
  drawGame();
}

void loop() {
  Direction requested;
  if (readRequestedDirection(requested)) {
    if (gameOver) {
      startGame();
      Serial.println(" I am starting the game 1");
      drawGame();
      Serial.println(" I am drawing the game 1");
      delay(120);
      return;
    }
    if (!isOpposite(requested, direction)) queuedDirection = requested;
  }

  const unsigned long stepMs = max(MIN_STEP_MS, START_STEP_MS - score * 4UL);
  if (!gameOver && millis() - lastStep >= stepMs) {
    lastStep = millis();
    moveSnake();
    Serial.println(" I am moving the game 2");
    drawGame();
    Serial.println(" I am drawing the game 2");
  }

  delay(10);
}
