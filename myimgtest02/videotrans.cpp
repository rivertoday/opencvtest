#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#include "myfunctions.h"
#include <time.h>

int videotrans() {
    //////////////////////////////////////////////////////
    //1.定义源文件
    //打开第一个摄像头
    //VideoCapture cap(0);

    //打开视频文件
    VideoCapture vc;
    vc.open("F:/LuLei/output/rawtest.avi");

    //检查是否成功打开
    if(!vc.isOpened()) {
        cerr << "Can not open source file." << endl;
        return 1;
    }else {
        cout << "Source video file has been opened." << endl;
    }

    /////////////////////////////////////////////////////
    // 2. 定义要保存的文件
    /** 打开输出视频文件 */
    unsigned int f = (unsigned)vc.get(CAP_PROP_FOURCC);
    char fourcc[] = {
            (char)f, // First character is lowest bits
            (char)(f >> 8), // Next character is bits 8-15
            (char)(f >> 16), // Next character is bits 16-23
            (char)(f >> 24), // Last character is bits 24-31
            '\0' // and don't forget to terminate
    };
    cout << "Detected FourCC: " << fourcc << endl;
    cout << "Detected FPS: " << (int)vc.get(CAP_PROP_FPS) <<endl;

    // Based on above detected FourCC, we decide to choose MEPG-1 as encoder
    int myFourCC = VideoWriter::fourcc('P','I','M','1');//MPEG-1
    Size size = Size(vc.get(CAP_PROP_FRAME_WIDTH), vc.get(CAP_PROP_FRAME_HEIGHT));
    VideoWriter vw("lulei_trans.avi", // 输出视频文件名
        myFourCC,//(int)vc.get(CAP_PROP_FOURCC), // 也可设为FOURCC_PROMPT，在运行时选取
        (double)vc.get(CAP_PROP_FPS), // 视频帧率
        size, // 视频大小
        false); // isColor， 单通道，因为后面要转换成灰度图以及边缘检测


    //检查是否成功创建
    if(!vw.isOpened()) {
        cerr << "Can not create video file." << endl;
        return -1;
    }else {
        cout << "Destination file has been created" << endl;
    }

    /////////////////////////////////////////////////
    //3.对源文件进行灰度设置，然后保存到目标文件

    Mat frame, edges;
    //创建窗口
    namedWindow("edges",1);

    for(;;)
    {
        //Mat frame;
        //从 cap 中读一帧，存到 frame
        vc >> frame;
        //如果未读到图像
        if(frame.empty())
            break;

        //将读到的图像转为灰度图
        cvtColor(frame, edges, COLOR_BGR2GRAY);
        //进行边缘提取操作
        Canny(edges, edges, 0, 30, 3);
        //显示结果
        imshow("edges", edges);

        //将图像写入视频
        vw << edges;

        //等待 30 秒，如果按键则推出循环
        if(waitKey(30) >= 0)
            break;
    }

    //退出时会自动释放 cap 中占用资源
    vc.release(); //when everything done, release the capture
    vw.release();
    destroyAllWindows();
    system("pause");
    return 0;

}
