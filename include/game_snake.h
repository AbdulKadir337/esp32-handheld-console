#pragma once
#include <Arduino.h>

struct Cell {
  uint8_t x;
  uint8_t y;
};

enum Direction : uint8_t { UP, DOWN, LEFT, RIGHT };

constexpr uint8_t SCREEN_WIDTH = 128;
constexpr uint8_t SCREEN_HEIGHT = 64;
constexpr uint8_t CELL_SIZE = 4;
constexpr uint8_t GRID_WIDTH = SCREEN_WIDTH / CELL_SIZE;
constexpr uint8_t GRID_HEIGHT = SCREEN_HEIGHT / CELL_SIZE;
constexpr uint8_t MAX_SNAKE = 120;
constexpr unsigned long START_STEP_MS = 180;
constexpr unsigned long MIN_STEP_MS = 70;

extern Cell snake[MAX_SNAKE];
extern Cell food;
extern uint8_t snakeLength;
extern uint16_t score;
extern Direction direction;
extern Direction queuedDirection;
extern bool gameOver;
extern unsigned long lastStep;

bool sameCell(const Cell &a, const Cell &b);
bool isOpposite(Direction a, Direction b);
bool snakeContains(const Cell &cell, uint8_t count);
void placeFood();
void startGame();
bool moveSnake();