# 🚗 RoboCar

An intelligent Arduino-powered robot car that navigates autonomously and avoids obstacles in real-time using ultrasonic sensing.  
Perfect for learning embedded systems, motor control, and autonomous robotics.

---

## 🎯 Project Goal

Learn how to:
- Build a smart robot car using Arduino
- Integrate ultrasonic sensing for obstacle detection
- Control DC motors via L298N motor driver
- Apply real-world autonomous decision making
- Simulate circuit design using TinkerCAD
- Document a full robotics project for submission

---

## 🧱 What We Did

We built a robot car capable of avoiding obstacles with zero user control:

1. **Sensor Integration** – HC-SR04 detects objects in front of the car.
2. **Motor Control** – L298N motor driver handles 4 DC motors.
3. **Autonomous Movement** – Logic in Arduino decides to go forward or turn.
4. **Safety Add-on** – Optional flame sensor support.

---

## 🛠️ Tools & Technologies

- 🔌 Arduino UNO  
- ⚙️ 4× DC Motors  
- 🔋 9V Battery  
- 🧠 L298N Motor Driver Modules  
- 📏 HC-SR04 Ultrasonic Sensor  
- 🔥 Flame Sensor (optional)  
- 🎨 TinkerCAD  
- 👨‍💻 Arduino IDE  
- 🧪 Real hardware + simulation tested

---

## ⚡ Circuit Design

> 📷 See `TinkerCAD-Sketch.png`  
> 🛠️ Includes:
- 2x L298N Motor Drivers
- HC-SR04 Ultrasonic Sensor
- Arduino UNO
- Breadboard + Jumper Wires
- Battery Pack

---

## 💻 Arduino Code

You’ll find the full code in `Source_Code.ino`.

📦 **Required Library:**  
[HCSR04 Ultrasonic Sensor Library](https://github.com/gamegine/HCSR04-ultrasonic-sensor-lib)

**How to install:**
1. Download the ZIP from the link above  
2. In Arduino IDE: Sketch → Include Library → Add .ZIP Library  
3. Select the ZIP file  

---

## 🧪 How It Works

```cpp
if (distance > 30) {
  goForward();
} else {
  stopMotors();
  turnRight();
}
```
The sensor reads distance
If safe: move forward
If blocked: stop and turn

---

## 🎞️ Demo & Simulation

###🧪 TinkerCAD Simulation

https://github.com/user-attachments/assets/0ff8258a-567c-41a4-b77e-9dcb00278561

###🤖 Real Robot Demo

https://github.com/user-attachments/assets/edc750fd-f77a-41f0-92bf-6ac0b60549a1

---

## 👤 Author
> Designed by: [Abdulrahman Qutah]  
> Date: [1 Aug 2025]
