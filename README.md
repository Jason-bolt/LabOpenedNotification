# LabOpenedNotification

This is a simple system, that uses an ultrasonic sensor to determine if the lab is opened.
The ultrasonic sensor is connected to an ESP32 microcontroller which is connected to the lab WiFi. The ESP32 sends the sensor readings to Thingspeak cloud service.
A mobile app then fetches the data from there and displays the status of the lab, if its opened or not.

The lab closes with a gate, hence the lab status is determined by checking the distance between the gate doors and post.
