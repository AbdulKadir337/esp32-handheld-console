## 🕹️ ESP32 Handheld Console

---

## Breadboard prototype

![Breadboard Prototype](docs/images/breadboard.jpg)

This project is developed as part of the **Electronic Product Development** (*Elektronisk Produktudvikling*) course at **UCL University College (Seebladsgade, Odense)** by an IT Technology student.

The goal of this project is to prototype and develop a compact, ESP32-based handheld gaming console. The system currently runs a fully functional version of the classic game **Snake**. The project is in the breadboard prototyping phase, with the ultimate objective of engineering and routing a custom **Printed Circuit Board (PCB)**.

## 🚀 Project Overview
The console utilizes an ESP32 microcontroller to execute the Snake game logic, process control inputs, and update the game graphics on a **1.3" OLED display** using the I2C communication protocol.

### 🛠️ Hardware Components
*   **Microcontroller:** ESP32 Development Board (esp32dev)
*   **Display:** 1.3" OLED Display (SH1106 / SSD1306 driver, I2C interface)
*   **Input:** HW-504 Joystick Module (Configured for analog direction control)

---

## 🔌 Hardware Wiring Diagram (Pin Mapping)

![Wiring Diagram](docs/hardware/schematics/wiring_diagram.png)

Based on the current firmware configuration, the components are interfaced with the ESP32 using the following pin mapping:

### 1. I2C OLED Display

| OLED Pin | ESP32 GPIO | Beskrivelse |
| :--- | :--- | :--- |
| **GND** | GND | Stel (Ground) |
| **VCC** | 3V3 / 5V | Strømforsyning |
| **SCL** | GPIO 22 | I2C Hardware Clock [1] |
| **SDA** | GPIO 21 | I2C Hardware Data [1] |

### 2. HW-504 Joystick / Kontrolknapper
*Bemærk: Pindene er defineret digitalt i firmwaren til retningsstyring.*

| Funktion / Retning | ESP32 GPIO | Beskrivelse |
| :--- | :--- | :--- |
| **UP** | GPIO 25 | Input for bevægelse opad [1] |
| **DOWN** | GPIO 26 | Input for bevægelse nedad [1] |
| **LEFT** | GPIO 27 | Input for bevægelse mod venstre [1] |
| **RIGHT** | GPIO 32 | Input for bevægelse mod højre [1] |

---
