#include <opencv2/core.hpp>
#include <opencv2/highgui.hpp>
#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

//定义图像的宽度和高度
static int w=320, h=320;
static Size wd(w, h);

void MyLine( Mat img, Point start, Point end )
{
    int thickness = 2;
    int lineType = 8;
    line( img,
         start,
         end,
         Scalar( 0, 0, 0 ),
         thickness,
         lineType );
}

void MyEllipse( Mat img, double angle )
{
    int thickness = 2;
    int lineType = 8;

    ellipse( img,
            Point( static_cast<int>(w/2.0),  static_cast<int>(w/2.0) ),
            Size( static_cast<int>(w/4.0), static_cast<int>(w/16.0) ),
            angle,
            0,
            360,
            Scalar( 255, 0, 0 ),
            thickness,
            lineType );
}

void MyFilledCircle( Mat img, Point center )
{
    int thickness = -1;
    int lineType = 8;

    circle( img,
           center,
           static_cast<int>(w/32.0),
           Scalar( 0, 0, 255 ),
           thickness,
           lineType );
}

void MyPolygon( Mat img )
{
    int lineType = 8;

    /** 创建一些点 */
    Point rook_points[1][20];
    rook_points[0][0] = Point( static_cast<int>(w/4.0), static_cast<int>(7*h/8.0) );
    rook_points[0][1] = Point( static_cast<int>(3*w/4.0), static_cast<int>(7*h/8.0) );
    rook_points[0][2] = Point( static_cast<int>(3*w/4.0), static_cast<int>(13*h/16.0) );
    rook_points[0][3] = Point( static_cast<int>(11*w/16.0), static_cast<int>(13*h/16.0) );
    rook_points[0][4] = Point( static_cast<int>(19*w/32.0), static_cast<int>(3*h/8.0) );
    rook_points[0][5] = Point( static_cast<int>(3*w/4.0), static_cast<int>(3*h/8.0) );
    rook_points[0][6] = Point( static_cast<int>(3*w/4.0), static_cast<int>(h/8.0) );
    rook_points[0][7] = Point( static_cast<int>(26*w/40.0), static_cast<int>(h/8.0) );
    rook_points[0][8] = Point( static_cast<int>(26*w/40.0), static_cast<int>(h/4.0) );
    rook_points[0][9] = Point( static_cast<int>(22*w/40.0), static_cast<int>(h/4.0) );
    rook_points[0][10] = Point( static_cast<int>(22*w/40.0), static_cast<int>(h/8.0) );
    rook_points[0][11] = Point( static_cast<int>(18*w/40.0), static_cast<int>(h/8.0) );
    rook_points[0][12] = Point( static_cast<int>(18*w/40.0), static_cast<int>(h/4.0) );
    rook_points[0][13] = Point( static_cast<int>(14*w/40.0), static_cast<int>(h/4.0) );
    rook_points[0][14] = Point( static_cast<int>(14*w/40.0), static_cast<int>(h/8.0) );
    rook_points[0][15] = Point( static_cast<int>(w/4.0), static_cast<int>(h/8.0) );
    rook_points[0][16] = Point( static_cast<int>(w/4.0), static_cast<int>(3*h/8.0) );
    rook_points[0][17] = Point( static_cast<int>(13*w/32.0), static_cast<int>(3*h/8.0) );
    rook_points[0][18] = Point( static_cast<int>(5*w/16.0), static_cast<int>(13*h/16.0) );
    rook_points[0][19] = Point( static_cast<int>(w/4.0), static_cast<int>(13*h/16.0)) ;

    const Point* ppt[1] = { rook_points[0] };
    int npt[] = { 20 };

    fillPoly( img,
             ppt,
             npt,
             1,
             Scalar( 255, 255, 255 ),
             lineType );
}

int drawing_1()
{
    /// 窗口名字
    char atom_window[] = "Drawing 1: Atom";
    char rook_window[] = "Drawing 2: Rook";


    /// 创建空全黑像素的空图像
    Mat atom_image = Mat::zeros( wd, CV_8UC3 );
    Mat rook_image = Mat::zeros( wd, CV_8UC3 );


    /// 1. 画一个简单的原子。

    /// 1.a. 创建椭圆
    MyEllipse( atom_image, 90 );
    MyEllipse( atom_image, 0 );
    MyEllipse( atom_image, 45 );
    MyEllipse( atom_image, -45 );

    /// 1.b. 创建圆
    MyFilledCircle( atom_image, Point( static_cast<int>(w/2.0), static_cast<int>(h/2.0)) );

    /// 2. 画一个赌棍

    /// 2.a. 创建一个凸多边形
    MyPolygon( rook_image );

    /// 2.b. 创建矩形
    rectangle( rook_image,
              Point( 0, static_cast<int>(7*h/8.0) ),
              Point( w, h),
              Scalar( 0, 255, 255 ),
              -1,
              8 );

    /// 2.c. 画几条直线
    MyLine( rook_image, Point( 0, static_cast<int>(15*h/16) ), Point( w, static_cast<int>(15*h/16) ) );
    MyLine( rook_image, Point( static_cast<int>(w/4), static_cast<int>(7*h/8) ), Point( static_cast<int>(w/4), h ) );
    MyLine( rook_image, Point( static_cast<int>(w/2), static_cast<int>(7*h/8) ), Point( static_cast<int>(w/2), h ) );
    MyLine( rook_image, Point( static_cast<int>(3*w/4), static_cast<int>(7*h/8) ), Point( static_cast<int>(3*w/4), h ) );

    /// 创建窗口
    namedWindow(atom_window, 1);
    namedWindow(rook_window, 1);

    /// 显示图像
    imshow(atom_window, atom_image);
    imshow(rook_window, rook_image);

    /// 等待用户按键
    waitKey();

    return 0;
}
