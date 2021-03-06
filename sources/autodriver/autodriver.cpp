#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <thread>
#include <chrono>
#include <cstdlib>

using namespace std;


/*                                               */
/*             Auto Driver algorithm             */
/*                           __________________  */
/*           Width                               */
/*       |    ⇆              -(AT): AutoTrolley  */
/*     - |    0 ⇅ Height     -0: Object that     */
/*   y ⇩ |   /               have been detected  */
/*     + |  / z              by the Pixy Cam     */
/*       | /                 __________________  */
/*       |/                                      */
/*   ----|----------------      auteur:  Auto    */
/*  (AT) |     - ⇨ +            Driver - 2019    */
/*       |       x                               */
/*                                               */



/*
sub functions :
*/

int refresh() /* refresh the screen every 20 miliseconds (as pixy is 50fps) */
{
   int r0;
   std::this_thread::sleep_for(std::chrono::milliseconds(20));
   return r0;
}

int killgpio() /* kill every screen: screen where the python script are launched */
{
   int r1;
   system("pkill screen");
   return r1;
}

int main()
{

/* variable */

   ifstream node[4]; // array listing the 4 values from the nodes
   int position [5]; // array listing the 4 nodes for the position of the object
   int XValue=0; // value of the horizontal position of the object
   int YValue=0; // value of the vertical position of the object
   int WidthValue=0; // value of the width of the object
   int HeightValue=0; // value of the width of the object


/* Launch Hello Trolley */

   system("python ./sources/hello_trolley.py");

/* Check that every node is well existing & save that value on variables */

   node[0].open("./nodes/x");
   node[1].open("./nodes/y");
   node[2].open("./nodes/width");
   node[3].open("./nodes/height");

   for (int i=0; i<4; i++)
   {
       if (!node[i])
       {
           cout << "\nSome nodes doesn't exist, run again the program.\n";
           return 13;
       }
   }


/* Save the nodes values into variables */

   for (int i=0; i<4; i++)
   {
       while (node[i] >> position[i])
       {
          XValue=position[0];
          YValue=position[1];
          WidthValue=position[2];
          HeightValue=position[3];
       }

   }


/* Print the output of the actual position of the object followed */

   cout << "\nThe position of the object followed is:"
        << "\n x: " << XValue
        << "\n y: " << YValue
        << "\n width: " << WidthValue
        << "\n height: " << HeightValue;


/* Behave in function of that the autotrolley have to take */

   cout << "\n\nThe Autotrolley is :";
   refresh();

// X axis
   if (XValue>210)
   {
      killgpio();
      cout << "\n- moving to the right";
      system("screen -d -m python ./sources/autodriver/interface/xright.py");
   }
   
   else if (XValue<110 && XValue!=0)
   {
       killgpio();
       cout << "\n- moving to the left";
       system("screen -d -m python ./sources/autodriver/interface/xleft.py");
   }
   
// Size of the object  
   else if (WidthValue>36 && HeightValue>36)
   {
       killgpio();
       cout << "\n- moving closer to the object";
       system("screen -d -m python ./sources/autodriver/interface/getcloser.py");
   }
   
   else if (WidthValue<25 && HeightValue<15 && HeightValue!=0 && WidthValue!=0)
   {
       killgpio();
       cout << "\n- moving further from the object";
       system("screen -d -m python ./sources/autodriver/interface/getfurther.py");
   }

// Y axis
   if (YValue<5 && YValue!=0)
       cout << "\n- The object is not detected anymore, that mean that the object moved to the top but the autotrolley can't do anything";

   if (YValue>250 && YValue!=0)
       cout << "\n- The object is not detected anymore, that mean that the object moved to the bottom but the autotrolley can't do anything";

// shutdown the motors if nothing is detected
   if (XValue==0 && YValue==0 && WidthValue==0 && HeightValue==0)
   {
       killgpio();
       cout << "\n- nothing detected, motors off";
       system("screen -d -m python ./sources/autodriver/interface/get0.py");
   }
   
/* Close the node reading */

   for (int i=0; i<4; i++)
       node[i].close();

return 0;

}
