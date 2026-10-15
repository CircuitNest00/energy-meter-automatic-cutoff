# LoRa-Based Health Monitoring Prototype

An Arduino Uno project that uses a pulse oximeter, DHT11 temperature sensor, GPS module, and emergency input button. A custom-designed PCB connects the components, and a LoRa module sends the collected data wirelessly.

## Components

- Arduino Uno
- LoRa module on a custom-designed PCB
- Pulse oximeter
- DHT11 temperature and humidity sensor
- GPS module: NEO-6M 
- RS-232 cable
- Emergency input button

## Project files

- Source code
- Project photo

## How it works

The Arduino Uno reads data from the pulse oximeter and DHT11 sensor, obtains location data from the GPS module, and sends the information over LoRa. The emergency button provides an input for emergency use.

This is a prototype project, not a certified medical or emergency-response device.
