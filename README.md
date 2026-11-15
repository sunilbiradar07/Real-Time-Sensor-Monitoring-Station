# Real-Time-Sensor-Monitoring-Station
## Project Overview
The Real-Time Sensor Monitoring Station is an embedded systems project designed to monitor environmental conditions and detect abnormal situations using multiple sensors interfaced with an LPC2129 (ARM7) microcontroller.

The system collects sensor data, processes it in real time, and displays the monitored values and sensor status on a Serial Terminal through UART communication.

## Communication Protocol
- UART (Universal Asynchronous Receiver Transmitter)
UART is used for serial communication between the LPC2129 microcontroller and the computer to display sensor readings on the Serial Terminal.

## Project Block Diagram
The system consists of multiple sensors connected to the LPC2129 microcontroller. The MCU processes the sensor inputs and sends the monitored data to the computer through the UART interface.
<img width="1535" height="1024" alt="ChatGPT Image Nov 14, 2026, 06_10_01 PM" src="https://github.com/user-attachments/assets/1664a7a1-127f-449b-a8b6-faba956b0c08" />


## Serial Terminal Output
The following parameters are displayed on the Serial Terminal:

TEMP : 28 °C
LIGHT : 50 %
VTG : 3.3 % (MAX)
VIBRATIONS : NO
FLAME : NO
