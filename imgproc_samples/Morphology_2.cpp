/**
 * @file Morphology_2.cpp
 * @brief Advanced morphology Transformations sample code
 * @author OpenCV team
 */

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"
#include <iostream>

using namespace cv;

/// Global variables
static Mat src, dst;

static int morph_elem = 0;
static int morph_size = 0;
static int morph_operator = 0;
static int const max_operator = 4;
static int const max_elem = 2;
static int const max_kernel_size = 21;

static const char* window_name = "Morphology Transformations Demo";


/** Function Headers */
void Morphology_Operations( int, void* );

/**
 * @function main
 */
int Morphology_2( int argc, char** argv )
{
  //![load]
  CommandLineParser parser( argc, argv, "{@input | ../data/baboon.jpg | input image}" );
  src = imread( parser.get<String>( "@input" ), IMREAD_COLOR );
  if (src.empty())
  {
    std::cout << "Could not open or find the image!\n" << std::endl;
    std::cout << "Usage: " << argv[0] << " <Input image>" << std::endl;
    return -1;
  }
  //![load]

  //![window]
  namedWindow( window_name, WINDOW_NORMAL); // Create window
  //namedWindow( window_name, WINDOW_AUTOSIZE ); // Create window
  //![window]

  //![create_trackbar1]
  /// Create Trackbar to select Morphology operation
  char trackbarname[100] = "Operator: \r\n 0: Opening - 1: Closing \r\n  2: Gradient - 3: Top Hat \r\n 4: Black Hat";
  //char trackbarname[50] = "Operator: 0: O;1: C;2: G;3: TH;4: BH";
  createTrackbar(trackbarname, window_name, &morph_operator, max_operator, Morphology_Operations );
  //![create_trackbar1]

  //![create_trackbar2]
  /// Create Trackbar to select kernel type
  createTrackbar( "Element:\n 0: Rect - 1: Cross - 2: Ellipse", window_name,
                  &morph_elem, max_elem,
                  Morphology_Operations );
  //![create_trackbar2]

  //![create_trackbar3]
  /// Create Trackbar to choose kernel size
  createTrackbar( "Kernel size:\n 2n +1", window_name,
                  &morph_size, max_kernel_size,
                  Morphology_Operations );
  //![create_trackbar3]

  /// Default start
  Morphology_Operations( 0, 0 );

  waitKey(0);
  return 0;
}

//![morphology_operations]
/**
 * @function Morphology_Operations
 */
void Morphology_Operations( int, void* )
{
  // Since MORPH_X : 2,3,4,5 and 6
  //![operation]
  int operation = morph_operator + 2;
  //![operation]

  Mat element = getStructuringElement( morph_elem, Size( 2*morph_size + 1, 2*morph_size+1 ), Point( morph_size, morph_size ) );

  /// Apply the specified morphology operation
  morphologyEx( src, dst, operation, element );
  imshow( window_name, dst );
}
//![morphology_operations]
