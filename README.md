#Energy Meter with Automatic Cutoff

An Arduino Uno project that measures AC voltage and current using a ZMPT101B voltage sensor and ACS712 current sensor. A 16×2 LCD displays the readings, and a 5 V relay disconnects the load if the current exceeds a set limit.

#Components

- Arduino Uno
- ZMPT101B AC voltage sensor
- ACS712 current sensor
- 5 V relay
- 16×2 LCD display
  
#Project files

- Source code
- Project photo
  
#How it works

The Arduino Uno reads the voltage and current sensor signals and displays the measurements on the LCD. When the measured current exceeds the configured limit, the Arduino activates the relay to disconnect the load.
This is a prototype project, not a certified electrical protection device. Use properly rated components and take appropriate precautions when working with AC mains.
