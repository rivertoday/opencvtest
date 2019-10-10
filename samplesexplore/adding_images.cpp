/**
 * @file AddingImages.cpp
 * @brief Simple linear blender ( dst = alpha*src1 + beta*src2 )
 * @author OpenCV team
 */
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>
#include <Windows.h>

using namespace cv;

// we're NOT "using namespace std;" here, to avoid collisions between the beta variable and std::beta in c++17
using std::cin;
using std::cout;
using std::endl;

/**
 * @function main
 * @brief Main function
 */
int AddingImages( void )
{
   double alpha = 0.5; double beta; double input = 0.5;

   Mat src1, src2, dst;

   /// Ask the user enter alpha
   cout << " Simple Linear Blender " << endl;
   cout << "-----------------------" << endl;
   cout << "* Enter alpha [0.0-1.0]: ";
   //cin >> input;
   cout << "-----------------------" << endl;

   // We use the alpha provided by the user if it is between 0 and 1
   if( input >= 0 && input <= 1 )
     { alpha = input; }

   //![load]
   /// Read images ( both have to be of the same size and type )
   src1 = imread( "singer.jpg", IMREAD_COLOR);
   src2 = imread( "background2.jpg", IMREAD_COLOR);
   //![load]

   if( src1.empty() ) {
       cout << "Error loading src1" << endl; return -1;
   }else {
       cout << "Loading src1 successfully" <<endl;
   }
   if( src2.empty() ) {
       cout << "Error loading src2" << endl; return -1;
   }else {
       cout << "Loading src2 successfully" <<endl;
   }

   for (int i=0; i<100; i++) {
       double da = static_cast<double>(i);
       alpha = static_cast<double>(da/100);
       cout << "progress: " << alpha << endl;
       //![blend_images]
       beta = ( 1.0 - alpha );
       addWeighted( src1, alpha, src2, beta, 1.0, dst);
       //![blend_images]

       //![display]
       imshow( "Linear Blend", dst );

       //Sleep(5000);
       //if (waitKey(20) > 0) break;

       waitKey(25);
       //![display]
   }


   return 0;
}
