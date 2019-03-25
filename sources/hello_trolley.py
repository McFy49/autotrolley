#!/usr/bin/env python
# -*- coding: utf-8 -*-

from termcolor import colored
import RPi.GPIO as GPIO  # bibliothèque pour utiliser les GPIO
import os

# Initialize the GPIO
GPIO.setmode(GPIO.BCM)   # mode de numérotation des pins
GPIO.setup(18,GPIO.OUT)  # la pin 18 réglée en sortie (output)

# Output on the hardware through a LED
GPIO.output(18,GPIO.HIGH)   # sortie au niveau logique haut (3.3 V)

# Clear the terminal
os.system('clear')

# Output on the terminal
print(colored('    #                        #######                                            ','white'))
print(colored('   # #   #    # #####  ####     #    #####   ####  #      #      ###### #     # ','white'))
print(colored('  #   #  #    #   #   #    #    #    #    # #    # #      #      #       #   #  ','white'))
print(colored(' #     # #    #   #   #    #    #    #    # #    # #      #      #####    ###   ','white'))
print(colored(' ####### #    #   #   #    #    #    #####  #    # #      #      #         #    ','white'))
print(colored(' #     # #    #   #   #    #    #    #   #  #    # #      #      #         #    ','white'))
print(colored(' #     #  ####    #    ####     #    #    #  ####  ###### ###### ######    #    ','white'))
print('')
print(colored(' is runing ..','yellow'))
