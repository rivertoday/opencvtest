#include <QCoreApplication>
#include "samplefunctions.h"

int main(int argc, char *argv[])
{
    //QCoreApplication a(argc, argv);

    //图像平滑处理
    //Smoothing(argc, argv);

    //腐蚀与膨胀
    //Morphology_1(argc, argv);

    //更多形态学变化
    //Morphology_2(argc, argv);

    //图像金字塔
    //Pyramids(argc, argv);

    //基本的阈值操作
    //MyThreshold(argc, argv);

    //实现自己的线性滤波器
    //filter2D_demo(argc, argv);

    //给图像添加边界
    //copyMakeBorder_demo(argc, argv);

    //Sobel导数
    //Sobel_Demo(argc, argv);

    //Laplace 算子
    //Laplace_Demo(argc, argv);

    //Canny 边缘检测
    //CannyDetector_Demo(argc, argv );

    //霍夫变换
    //houghlines(argc, argv);

    //霍夫圆变换
    //HoughCircle_Demo(argc, argv);

    //Remapping 重映射
    //Remap_Demo(argc, argv);

    //仿射变换
    //Geometric_Transforms_Demo(argc, argv);

    //直方图均衡化
    //EqualizeHist_Demo(argc, argv);

    //直方图计算
    calcHist_Demo(argc, argv);



    return 0;
    //return a.exec();
}
