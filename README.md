# 🔌 IoT-Based Smart Energy Meter using ESP32 & Blynk IoT

This project demonstrates a real-time electricity energy monitoring system using an **ESP32**, voltage and current sensors (**ZMPT101B** and **ACS712**), and the **Blynk IoT platform**. It tracks **voltage (V)**, **current (A)**, **apparent power (W)**, and **energy consumption (kWh)**, displaying the data both on a local **LCD** and remotely via a **mobile/web dashboard**.

---

## 📟 Features

- 📡 Real-time monitoring of voltage, current, power, and energy.
- 🖥️ Dual display: 16x2 LCD + Blynk IoT dashboard.
- 📲 WiFi-enabled remote tracking via smartphone/web.
- 🔋 Tracks energy usage over time (kWh calculation).
- ⚠️ Expandable for relay control, alarms, or smart billing.

---

## 🧰 Hardware Requirements

| Component         | Description                          |
|------------------|--------------------------------------|
| ESP32 Dev Board   | Main IoT microcontroller             |
| ZMPT101B          | AC Voltage Sensor                    |
| ACS712 (20A/30A)  | AC Current Sensor                    |
| 16x2 LCD Display  | For real-time local display          |
| Jumper Wires      | Connections                          |
| Breadboard/PCB    | Mounting platform                    |

---

## ⚙️ Wiring (GPIO Pin Map)

| Peripheral      | ESP32 GPIO Pin |
|----------------|----------------|
| Voltage Sensor | GPIO 35 (ADC)  |
| Current Sensor | GPIO 34 (ADC)  |
| LCD RS         | GPIO 13        |
| LCD EN         | GPIO 12        |
| LCD D4-D7      | GPIO 14, 27, 26, 25 |

---

## 🖥️ Software Requirements

- [Arduino IDE](https://www.arduino.cc/en/software)
- [EmonLib](https://github.com/openenergymonitor/EmonLib)
- [Blynk Library (New Platform)](https://docs.blynk.io)
- ESP32 Board Support (via Board Manager)

---

## 📲 Blynk Configuration

1. Create a new **Device Template** in Blynk IoT.
2. Add 4 **virtual datastreams**:
   - `V0`: Voltage
   - `V1`: Current
   - `V2`: Apparent Power
   - `V3`: Energy (kWh)
3. Get your **Template ID**, **Device Name**, and **Auth Token** and replace them in the code.
