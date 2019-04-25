#!/usr/bin/env python

import RPi.GPIO as GPIO
import time

E1 = 19
M1 = 26
E2 = 20
M2 = 21

GPIO.setwarnings(False)
GPIO.setmode(GPIO.BCM)
GPIO.setup(E1,GPIO.OUT)
GPIO.setup(M1, GPIO.OUT)
GPIO.setup(E2,GPIO.OUT)
GPIO.setup(M2, GPIO.OUT)

while True:
    GPIO.output(E1,False)
    GPIO.output(M1,False)
    GPIO.output(E2,False)
    GPIO.output(M2,False)
