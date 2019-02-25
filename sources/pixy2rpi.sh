#!/usr/bin/env bash

# Save the latest frame log values
sudo ./sources/hello_pixy | while read -r frame; do
   echo "$frame" > nodes/output.txt |\
   # write the value of x y width & height on their specific nodes
   grep "x: " nodes/output.txt | cut -d ":" -f 3 | cut -d "y" -f 1 | tr -d " " > nodes/x |\
   grep "y: " nodes/output.txt | cut -d ":" -f 4 | cut -d "w" -f 1 | tr -d " " > nodes/y |\
   grep "h: " nodes/output.txt | cut -d ":" -f 5 | cut -d "h" -f 1 | tr -d " " > nodes/width |\
   grep "t: " nodes/output.txt | cut -d ":" -f 6 | tr -d " " > nodes/height;

   # launch the autodriver
   ./sources/autodriver/autodriver
done
