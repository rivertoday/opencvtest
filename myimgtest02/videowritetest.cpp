#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#include "myfunctions.h"

int videowritetest() {
    //定义视频的帧率
    double rate = 25.0;
    //定义视频的宽度和高度
    Size videoSize(320, 240);
    //定义编码器
    int codec = VideoWriter::fourcc('M', 'J', 'P', 'G');
    //创建 writer ，并指定 FOURCC 及 FPS 等参数
    VideoWriter writer = VideoWriter("myvideo.avi", codec, rate, videoSize);

    //检查是否成功创建
    if(!writer.isOpened())
    {
        cerr << "Can not create video file." << endl;
        return -1;
    }

    //视频帧
    Mat frame(videoSize, CV_8UC3);

    for(int i = 0; i < 100; i++)
    {
        //将图像置为黑色
        frame = Scalar::all(0);
        //将整数 i 转为 i 字符串类型
        char text[128];
        snprintf(text, sizeof(text), "%d", i);
        //将数字绘到画面上
        putText(frame, text, Point(videoSize.width/3, videoSize.height/3),
        FONT_HERSHEY_SCRIPT_SIMPLEX, 3,
        Scalar(0,0,255), 3, 8);
        //将图像写入视频
        writer << frame;
    }

    //退出程序时会自动关闭视频文件
    return 0;
}
