#include <QCoreApplication>
#include "samplefunctions.h"

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    //图像平滑处理
    //Smoothing(argc, argv );

    //腐蚀与膨胀
    //Morphology_1(argc, argv );

    //更多形态学变化
    //Morphology_2(argc, argv );

    //图像金字塔
    Pyramids(argc, argv );

    return 0;
    //return a.exec();
}
