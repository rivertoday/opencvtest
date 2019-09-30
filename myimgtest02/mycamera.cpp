#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#include "myfunctions.h"
#include <time.h>

int mycamera()
{
    //打开摄像头
    VideoCapture videoCapture(0);
    if (!videoCapture.isOpened()) {
        cout << "Video not open!" << endl;
        system("pause");
        return 1;
    }

    //获取FPS
    double rate = videoCapture.get(CAP_PROP_FPS);
    cout << "FPS from CAP_PROP_FPS:" << rate << endl;

    //Calculate the FPS by myself
    cout << "###Calculate the FPS by myself!!" << endl;
    Mat frame;
    // Start and end times
    time_t start, end;
    // Number of frames to capture
    int num_frames = 120;
    // define the fps
    double fps=16.00;

    // Start time
    time(&start);
    // Grab a few frames
    for(int i = 0; i < num_frames; i++) {
        videoCapture >> frame;
    }
    // End Time
    time(&end);

    // Time elapsed
    double seconds = difftime (end, start);
    cout << "Time taken : " << seconds << " seconds" << endl;

    // Calculate frames per second
    fps  = num_frames / seconds;
    cout << "Estimated frames per second : " << fps << endl;
    // assgin the correct fps to rate
    rate = fps;
    cout << "###Finished calculating the FPS by myself, it is "<< rate << endl;

    //获取编码器
    //int myFourCC = VideoWriter::fourcc('X', 'V', 'I', 'D');//avi
    int myFourCC = VideoWriter::fourcc('m', 'p', '4', 'v');//mp4
    //'m', 'p', '4', 'v'//'F','L','V','1'//'m', 'p', '4','2' //'m','p','4','v'//'d','i','v','x'
    //获取尺寸
    Size size = Size(videoCapture.get(CAP_PROP_FRAME_WIDTH), videoCapture.get(CAP_PROP_FRAME_HEIGHT));
    if (size.width <= 0 || size.height <= 0) {
        cout << "ERROR while get the width or the height" << endl;
    }
    else {
        cout << "width: " << size.width << "\nheight: " << size.height << endl;
    }

    //创建写入文件
    VideoWriter writer("camera_record.mp4", myFourCC, rate, size, true);
    //检查是否成功创建
    if(!writer.isOpened()) {
        cerr << "Can not create video file." << endl;
        return -1;
    }else {
        cout << "Destination file has been created" << endl;
    }

    //将摄像头内容写入文件
    namedWindow("Live", WINDOW_AUTOSIZE);

    while (videoCapture.isOpened()) {
        bool ret = videoCapture.read(frame);
        if (ret) {
            imshow("Live", frame);
            //writer.write(frame);
            writer << frame;
            if (waitKey(20) > 0) break;
        } else {
            break;
        }
    }

    cout << "FINISH ALL WORK----------" << endl;
    videoCapture.release(); //when everything done, release the capture
    writer.release();
    destroyAllWindows();
    system("pause");

    return 0;

}
