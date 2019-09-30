#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#include "myfunctions.h"

int imgrwtest() {
    //读入图像，并将之转为单通道图像
    Mat im = imread("river.jpg", 0);
    //请一定检查是否成功读图
    if( im.empty() )
    {
        cout << "Can not load image." << endl;
        return 1;
    }

    //进行 Canny 操作，并将结果存于 result
    Mat result;
    Canny(im, result, 50, 150);
    //保存结果
    imwrite("river canny.png", result);
    return 0;
}
