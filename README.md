# Robotivia Hackathon Competition

**SOUL** is a multifunctional smart robot designed and built for the RoboTivia Hackathon. The project won **1st place** with a **cash prize of 25,000 EGP**. It combines line following, obstacle avoidance, and object handling using a robotic arm. Additionally, the robot can be remotely controlled through a custom mobile application developed by us using **MIT App Inventor**.

---

## Features

### 1. Line Following  
Utilizes a 5-channel IR sensor array to accurately detect and follow line paths.

### 2. Obstacle Avoidance  
Employs an ultrasonic sensor to detect and avoid obstacles in real time.

### 3. Robotic Arm  
Equipped with 6 servo motors to grab, lift, and move objects from one place to another.

### 4. Remote Control  
Includes a Bluetooth module HC-05 and a mobile app for full remote control of the robot and arm.

### 5. Fully Autonomous Navigation  
The robot can operate independently using pre-programmed Arduino logic.

---

## Components Used

- **Microcontroller:** Arduino Uno  
- **Sensors:**  
  - 5-Channel IR Sensor (for line following)  
  - Ultrasonic Sensor (for obstacle detection)  
- **Actuators:**  
  - 4 DC Motors (for movement)  
  - 6 Servo Motors (for robotic arm control)  
- **Motor Driver:** L298N  
- **Wireless Module:** HC-05 Bluetooth Module  
- **Power Supply:** Li-Ion Battery Pack  
- **Chassis:** Custom design (acrylic)

---

## Mobile Application

A mobile application was developed using **MIT App Inventor** to provide full remote control over the robot. The app allows the user to:

- Control movement (forward, backward, left, right)  
- Control the robotic arm (open, close, lift, lower)  
- Switch between manual and autonomous modes  
- Start or stop the robot remotely

---

## Achievements

- 1st Place Winner at RoboTivia Hackathon  
- Cash prize of 25,000 EGP  
- Successfully completed all competition challenges:  
  - Line following track  
  - Obstacle avoidance maze  
  - Object pickup and placement  
- Developed a fully functional mobile control app

---

## Project Structure

```bash
├── ArduinoCode/
│   ├── line_following.ino
│   ├── obstacle_avoidance.ino
│   ├── arm_control.ino
│   └── bluetooth_control.ino
├── App/
│   └── Robotivia_App.aia
├── schematics/
│   ├── wiring_diagram.png
│   └── robot_design.pdf
├── media/
│   ├── photos/
│   └── videos/
├── README.md
└── LICENSE
