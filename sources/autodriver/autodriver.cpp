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
   int r;
   std::this_thread::sleep_for(std::chrono::milliseconds(20));
   return r;
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
 if (XValue<165 && XValue!=0)
   {
       cout << "\n- moving to the right";
       system("python ./sources/autodriver/interface/xright.py");
   }

   if (XValue>165)
   {
      cout << "\n- moving to the left";
      system("python ./sources/autodriver/interface/xleft.py");
   }

// Y axis
   if (YValue<5 && YValue!=0)
       cout << "\n- The object is not detected anymore, that mean that the object moved to the top but the autotrolley can't do anything";

   if (YValue>250 && YValue!=0)
       cout << "\n- The object is not detected anymore, that mean that the object moved to the bottom but the autotrolley can't do anything";

// Size of the object
   if (WidthValue<75 && HeightValue<75 && HeightValue!=0 && WidthValue!=0)
   {
       cout << "\n- moving further from the object";
       system("python ./sources/autodriver/interface/getfurther.py");
   }

   if (WidthValue>75 && HeightValue>75)
   {
       cout << "\n- moving closer to the object";
       system("python ./sources/autodriver/interface/getcloser.py");
   }


/* Close the node reading */

   for (int i=0; i<4; i++)
       node[i].close();

return 0;

}
