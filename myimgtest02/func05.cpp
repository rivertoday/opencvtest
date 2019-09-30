#include <opencv2/opencv.hpp>
#include <stdio.h>

using namespace std;
using namespace cv;

#include "myfunctions.h"

int func05() {
    Mat M(600, 800, CV_8UC1);

    /*
    for( int i = 0; i < M.rows; ++i)
    {
        //获取指针时需要指定类型
        uchar * p = M.ptr<uchar>(i);
        for( int j = 0; j < M.cols; ++j )
        {
            double d1 = (double) ((i+j)%255);
            //用 at() 读写像素时，需要指定类型
            M.at<uchar>(i,j) = d1;
            //下面代码错误，应该使用 at<uchar>()
            //但编译时不会提醒错误
            //运行结果不正确， d2 不等于 d1
            double d2 = M.at<double>(i,j);
        }
    }
    */

    //在变量声明时指定矩阵元素类型
    Mat_<uchar> M1 = (Mat_< uchar >&)M;
    for( int i = 0; i < M1.rows; ++i)
    {
        //不需指定元素类型，语句简洁
        uchar * p = M1.ptr(i);
        for( int j = 0; j < M1.cols; ++j )
        {
            double d1 = (double) ((i+j)%255);
            //直接使用 Matlab 风格的矩阵元素读写，简洁
            M1(i,j) = d1;
            double d2 = M1(i ,j);
        }

    }

    //显示结果显示结果
    imshow("grayim", M1);
    waitKey(0);

    return 0;

}
