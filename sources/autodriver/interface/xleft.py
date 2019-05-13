#!/usr/bin/env python

import RPi.GPIO as GPIO
import time
from multiprocessing import Process

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

def xright():
    while True:
        GPIO.output(E1,True)
        GPIO.output(M1,True)
        GPIO.output(E2,True)
        GPIO.output(M2,True)
    i=0
    while True:
        i += 1
        time.sleep(1)

if __name__ == '__main__':
    # We create a Process
    action_process = Process(target=xright)

    # We start the process and we block for 5 seconds.
    action_process.start()
    action_process.join(timeout=0.03)

    # We terminate the process.
    action_process.terminate()


GPIO.output(E1,False)
GPIO.output(E2,False)

