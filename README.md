# Line-Follower made by Vlaganii (Neacsu Vlad and Dinu Marinel Gabriel)

## Project summary

This project was made for the UniBuc Robotics class of 2022 - 2023.

The class provided us with the physical components required to build this robot. We received a kit containing the 3D printed frame, the QTR-8A Sensor, the two wheels, a small ball breaing acting as the third wheel and screws. In addition to the kit we received LiPo batteries for powering the line-follower robot.

The purpose of this project was to write a code that could help the line-follower robot finish an unkown track in under 20 seconds.

## Code description

This code is designed for a line-follower robot. 

The setup() function initializes the serial communication, sets up the QTR-8A Sensor, and calibrates the sensors with a loop that moves the robot left and right until it is calibrated. It then sets up an LED to indicate that calibration has been completed. 

The loop() function calls pidControl(), which reads in the sensor values, calculates an error value, and applies PID control to set motor speeds based on the error value. The setMotorSpeed() function takes in motor speeds in both directions and sets them accordingly by setting pins to high or low to allow current flow and writing analog values to enable pins.

Regarding the PID function, the most important elements were P and D. P dealt with track curves in general and D dealt with the oscillations caused by P or other factors. I had a negligible effect.

The PID function was desgined to work on different cases, meaning it assignes different values for P and D based on how tight a turn is.

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
