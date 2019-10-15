/**
 * @file filter2D_demo.cpp
 * @brief Sample code that shows how to implement your own linear filters by using filter2D function
 * @author OpenCV team
 */

#include "opencv2/imgproc.hpp"
#include "opencv2/imgcodecs.hpp"
#include "opencv2/highgui.hpp"

using namespace cv;

/**
 * @function main
 */
int filter2D_demo ( int argc, char** argv )
{
    // Declare variables
    Mat src, dst;

    Mat kernel;
    Point anchor;
    double delta;
    int ddepth;
    int kernel_size;
    const char* origin_window_name = "Original image";
    const char* window_name = "filter2D Demo";

    //![load]
    const char* imageName = argc >=2 ? argv[1] : "../data/lena.jpg";

    // Loads an image
    src = imread( imageName, IMREAD_COLOR ); // Load an image

    if( src.empty() )
    {
        printf(" Error opening image\n");
        printf(" Program Arguments: [image_name -- default ../data/lena.jpg] \n");
        return -1;
    }
    //![load]
    imshow( origin_window_name, src );

    //![init_arguments]
    // Initialize arguments for the filter
    anchor = Point( -1, -1 );
    delta = 0;
    ddepth = CV_8U;//-1 means dst has the same depth as the src
    //![init_arguments]

    // Loop - Will filter the image with different kernel sizes each 0.5 seconds
    int ind = 0;
    for(;;)
    {
        //![update_kernel]
        // Update kernel size for a normalized box filter
        kernel_size = 3 + 2*( ind%5 );
        kernel = Mat::ones( kernel_size, kernel_size, CV_32F )/ (float)(kernel_size*kernel_size);
        //![update_kernel]

        //![apply_filter]
        // Apply filter
        filter2D(src, dst, ddepth , kernel, anchor, delta, BORDER_DEFAULT );
        //![apply_filter]
        imshow( window_name, dst );

        char c = (char)waitKey(500);
        // Press 'ESC' to exit the program
        if( c == 27 )
        { break; }

        ind++;
    }

    printf(" Processing with Gaussian kernel\n");
    Mat gk = (Mat_<double>(3,3) << 0.0947416, 0.118318, 0.0947416, 0.118318, 0.147761, 0.118318, 0.0947416, 0.118318, 0.0947416);
    kernel = gk;

    filter2D(src, dst, ddepth , kernel, anchor, delta, BORDER_DEFAULT );
    //![apply_filter]
    imshow( window_name, dst );

    waitKey(0);

    return 0;
}
