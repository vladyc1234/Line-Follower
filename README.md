# Line-Follower

This code is designed for a line-follower robot. 

The setup() function initializes the serial communication, sets up the QTR Sensors, and calibrates the sensors with a loop that moves the robot left and right until it is calibrated. It then sets up an LED to indicate that calibration has been completed. 

The loop() function calls pidControl(), which reads in the sensor values, calculates an error value, and applies PID control to set motor speeds based on the error value. The setMotorSpeed() function takes in motor speeds in both directions and sets them accordingly by setting pins to high or low to allow current flow and writing analog values to enable pins.

## Components 

  * 1 x 3D printed frame
  * 1 x Arduino UNO
  * 1 x Breadboard
  * 1 x QTR sensor
  * 1 x LiPo battery
  * 2 x wheels
  * 2 x motors
  * 1 x motor driver
  * Wires per logic

## Line-Follower video link: [https://youtu.be/Ldly6dWF0-I](https://youtu.be/Ldly6dWF0-I)

## Line-Follower Setup
![3997f6d2-b5af-46df-91fd-682c62c53016](https://user-images.githubusercontent.com/73032808/213567279-e33116b7-b741-4331-ba58-dfcd8ea7bcbd.jpg)
![image](https://user-images.githubusercontent.com/73032808/213567286-87fea946-32b2-4e86-b6ca-47e864c130ea.jpg)
