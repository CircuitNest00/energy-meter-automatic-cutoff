# Energy Meter with Automatic High-Current Cutoff

An energy meter that measures AC voltage and current. If current exceeds the set limit, a relay disconnects the load.

## Components

- Arduino Uno
- ZMPT101B voltage sensor
- ACS712 current sensor
- 5 V relay
- 16×2 LCD display

## Project files

- Source code
- Project photo: `IMG_0070.jpg`

![Energy meter project](./IMG_0070.jpg)

## How it works

The sensors send voltage and current readings to the Arduino Uno, which displays them on the LCD. If the current goes above the configured limit, the relay disconnects the load.

This is a prototype, not a certified electrical protection device. Use properly rated components and take care when working with AC mains.
