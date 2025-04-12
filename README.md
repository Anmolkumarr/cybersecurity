# Fingerprint-Based Smart Door Lock System

## Overview

The **Fingerprint-Based Smart Door Lock System** is a secure and efficient access control solution developed as part of a hackathon project. Leveraging biometric authentication, this system ensures that only authorized individuals can unlock the door. The solution is designed with a strong focus on **cybersecurity**, **usability**, and **real-time** operation.

##  Key Features

- **Biometric Authentication** using fingerprint scanner
- **Secure Lock Control** with relay-based mechanism
- **Web Dashboard (optional)** for logs and access control
- Tamper Detection & Alert System**
- Microcontroller-based**, low power consumption
- 🛡Data encryption** and secure fingerprint storage

---

## Tech Stack

| Component             | Technology                    |
|----------------------|-------------------------------|
| Microcontroller       | Arduino Uno / ESP32           |
| Biometric Sensor      | R305 / GT-511C3 Fingerprint   |
| Actuator              | 5V Relay Module + Electric Lock |
| Programming Language  | C++ (Arduino IDE)             |
| Communication         | UART / Serial / Wi-Fi         |
| Optional Dashboard    | Flask (Python) + SQLite       |

---

## Hardware Requirements

-  Microcontroller (e.g., Arduino Uno or ESP32)
-  Fingerprint Sensor Module (R305 or GT-511C3)
-  5V Relay Module
-  Solenoid Lock / Door Strike Lock
-  Power Supply (5V/12V)
-  Jumper wires, Breadboard (for prototyping)

---

##  Software Requirements

- Arduino IDE or PlatformIO
- Fingerprint sensor library (e.g., [Adafruit Fingerprint Sensor](https://github.com/adafruit/Adafruit-Fingerprint-Sensor-Library))
- (Optional) Python 3 + Flask + SQLite for dashboard
- (Optional) ngrok for remote access

---

##  Setup Instructions

### 1.  Connect Hardware

- Connect fingerprint sensor to TX/RX pins of the microcontroller.
- Connect relay module to a digital pin to control the door lock.
- Power components accordingly.

### 2.  Upload Code to Microcontroller

- Install the necessary fingerprint sensor library in Arduino IDE.
- Open `door_lock.ino` (included in the repo).
- Upload the code using Arduino IDE or PlatformIO.

### 3.  Enroll Fingerprints

- Run the `enroll.ino` sketch to register authorized fingerprints.
- Store enrolled fingerprints in the sensor’s flash memory.

### 4. Lock Operation

- Upon successful fingerprint match, the relay is activated to unlock the door.
- Unauthorized access attempts are logged.
- Optional tamper detection system alerts through buzzer or dashboard notification.

### 5. Usage Guidelines

- Place finger on the sensor for authentication.
- If matched: door unlocks temporarily.
- If unmatched: system denies access and logs the attempt.
- Use dashboard to monitor access logs and add/remove authorized prints (optional).

### 6. Cybersecurity Highlights

- Biometric templates are stored securely in hardware memory.
- Optional dashboard is protected with login/auth.
- Tamper alerts for suspicious activities.

### 7. Contributors
Anmol Kumar
Gaurav Kumar Yadav
