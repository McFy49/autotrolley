#!/usr/bin/env bash

# Save the latest frame log values
sudo ./sources/hello_pixy > nodes/output.txt | while [ true ]; do
   # write the value of x y width & height on their specific nodes
   tail nodes/output.txt | grep "x: " | cut -d ":" -f 3 | cut -d "y" -f 1 | tr -d " " > nodes/x |\
   tail nodes/output.txt | grep "y: " | cut -d ":" -f 4 | cut -d "w" -f 1 | tr -d " " > nodes/y |\
   tail nodes/output.txt | grep "h: " | cut -d ":" -f 5 | cut -d "h" -f 1 | tr -d " " > nodes/width |\
   tail nodes/output.txt | grep "t: " | cut -d ":" -f 6 | tr -d " " > nodes/height;
   # launch the autodriver
   ./sources/autodriver/autodriver
done
