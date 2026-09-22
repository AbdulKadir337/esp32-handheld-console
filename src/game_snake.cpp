#include "game_snake.h"

Cell snake[MAX_SNAKE];
Cell food;
uint8_t snakeLength;
uint16_t score;
Direction direction;
Direction queuedDirection;
bool gameOver;
unsigned long lastStep;

bool sameCell(const Cell &a, const Cell &b) { return a.x == b.x && a.y == b.y; }

bool isOpposite(Direction a, Direction b) {
  return (a == UP && b == DOWN) || (a == DOWN && b == UP) ||
         (a == LEFT && b == RIGHT) || (a == RIGHT && b == LEFT);
}

bool snakeContains(const Cell &cell, uint8_t count) {
  for (uint8_t i = 0; i < count; ++i) {
    if (sameCell(snake[i], cell)) return true;
  }
  return false;
}

void placeFood() {
  do {
    food.x = random(GRID_WIDTH);
    food.y = random(GRID_HEIGHT);
  } while (snakeContains(food, snakeLength));
}

void startGame() {
  snakeLength = 4;
  score = 0;
  direction = RIGHT;
  queuedDirection = RIGHT;
  gameOver = false;

  const uint8_t startX = GRID_WIDTH / 2;
  const uint8_t startY = GRID_HEIGHT / 2;
  for (uint8_t i = 0; i < snakeLength; ++i) {
    snake[i] = {static_cast<uint8_t>(startX - i), startY};
  }

  placeFood();
  lastStep = millis();
}

bool moveSnake() {
  direction = queuedDirection;
  Cell next = snake[0];

  if (direction == UP) {
    if (next.y == 0) { gameOver = true; return true; }
    --next.y;
  } else if (direction == DOWN) {
    if (next.y == GRID_HEIGHT - 1) { gameOver = true; return true; }
    ++next.y;
  } else if (direction == LEFT) {
    if (next.x == 0) { gameOver = true; return true; }
    --next.x;
  } else {
    if (next.x == GRID_WIDTH - 1) { gameOver = true; return true; }
    ++next.x;
  }

  const bool eating = sameCell(next, food);
  const uint8_t collisionCount = eating ? snakeLength : snakeLength - 1;

  if (snakeContains(next, collisionCount)) {
    gameOver = true;
    return true;
  }

  if (eating && snakeLength < MAX_SNAKE) ++snakeLength;

  for (uint8_t i = snakeLength - 1; i > 0; --i) {
    snake[i] = snake[i - 1];
  }
  snake[0] = next;

  if (eating) {
    ++score;
    placeFood();
  }

  return true;
}