# Smart-Vehicle-Tracking-Alert-System-using-ESP32-
# 🚗 Smart Vehicle Accident Detection & Alert System

An IoT-based vehicle safety system using **ESP32, GPS, GSM, ThingSpeak, ThingESP Pro & Twilio** to detect accidents, track real-time location, and send emergency alerts to predefined contacts.

## ✨ Features

* 🚨 Automatic accident detection
* 📍 Real-time GPS location tracking
* 📱 Emergency SMS alerts
* ☁️ IoT data monitoring using ThingSpeak
* 💬 Twilio-based notifications
* 🔗 ThingESP Pro integration
* ⚡ ESP32-based real-time processing
* 🆘 Automatic location sharing during emergencies

## 🔄 Workflow

```text
Vehicle Movement
       ↓
Accident Detection
       ↓
ESP32 Processes Data
       ↓
GPS Gets Location
       ↓
Data Sent to IoT Platform
       ↓
Emergency Alert Triggered
       ↓
SMS / Notification Sent
       ↓
Emergency Contact Receives Location
```

## 🔌 Hardware Connections

| Component                 | ESP32 Connection | Purpose                           |
| ------------------------- | ---------------- | --------------------------------- |
| GPS Module                | UART TX/RX       | Obtains real-time location        |
| GSM Module                | UART TX/RX       | Sends emergency communication     |
| Accident Detection Sensor | GPIO / ADC       | Detects accident/impact condition |
| Power Supply              | VIN / 5V / GND   | Provides required power           |
| Common Ground             | GND              | Common electrical reference       |

> **Note:** Use the GPIO/UART pins defined in the project source code. Do not connect modules directly to ESP32 pins until their voltage and power requirements are verified.

## ⚙️ Hardware Setup

1. Connect the **ESP32** as the main controller.
2. Connect the accident detection sensor to the configured ESP32 input.
3. Connect the **GPS module** through the configured UART interface.
4. Connect the **GSM module** through the configured communication interface.
5. Connect all required **GND connections**.
6. Provide a stable power supply suitable for each module.
7. Verify GPS signal and GSM network availability before testing.

## 💻 Software Setup

1. Install **Arduino IDE**.
2. Install the required **ESP32 board package**.
3. Open the project source code.
4. Configure Wi-Fi and communication credentials.
5. Configure **ThingSpeak** API details.
6. Configure **ThingESP Pro** credentials/settings.
7. Configure **Twilio** account credentials and destination number.
8. Select the correct ESP32 board and COM port.
9. Upload the code to the ESP32.
10. Open Serial Monitor and verify sensor, GPS, GSM, and IoT communication.

## ☁️ IoT Configuration

### ThingSpeak

* Create a ThingSpeak channel.
* Configure the required fields.
* Copy the Channel ID and API key.
* Add them to the project configuration.

### ThingESP Pro

* Configure the required IoT communication settings.
* Add the required credentials/configuration to the code.

### Twilio

* Create/configure the Twilio service.
* Add the required authentication details.
* Configure the destination emergency contact.

## 🎯 Objective

To develop an IoT-enabled vehicle safety system that automatically detects accidents, identifies the accident location, and sends emergency alerts to predefined contacts for faster assistance.
