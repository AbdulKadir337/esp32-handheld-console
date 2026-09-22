# ESP32 Handheld Console

![Breadboard Prototype] (docs/breadboard.jpg)

Dette projekt er udviklet som en del af faget **Elektronisk Produktudvikling** på **UCL University College (Seebladsgade, Odense)** af en IT-teknologistuderende.

Formålet med projektet er at prototype og udvikle en kompakt, ESP32-baseret håndholdt spillekonsol. Konsollen kører i øjeblikket spillet **Snake**. Projektet er i øjeblikket i prototypefasen på breadboard, med henblik på fremtidigt design og udlægning af et tilpasset **Printed Circuit Board (PCB)**.

## 🚀 Projektoversigt
Konsollen er bygget op omkring en **ESP32** mikrokontroller, som håndterer spillogikken for Snake, modtager input fra kontrolelementer og opdaterer spillets grafik på et **1,3" OLED-display** via I2C-protokollen.

### 🛠️ Hardwarekomponenter
*   **Mikrokontroller:** ESP32 Development Board (esp32dev) [1]
*   **Display:** 1.3" OLED-display (SH1106 / SSD1306 driver, I2C-interface) [1]
*   **Input:** HW-504 Joystick-modul (Konfigureret til retningsbestemt input)

---

## 🔌 Forbindelsesdiagram (Pin Mapping)

Baseret på projektets nuværende firmwarekonfiguration er komponenterne forbundet til ESP32 på følgende pinde:

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
