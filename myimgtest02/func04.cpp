#include <opencv2/opencv.hpp>
#include <iostream>

using namespace std;
using namespace cv;

#include "myfunctions.h"

int func04() {
    Mat A = Mat::eye(3,3,CV_32FC1);
    Mat B = A * 3 + 1;
    Mat C = B.diag(0) + B.col(1);
    cout << "A = " << A << endl << endl;
    cout << "B = " << B << endl << endl;
    cout << "C = " << C << endl << endl;
    cout << "C .* diag(B) = " << C.dot(B.diag(0)) << endl;
    cout << "C .* cross(B) = " << C.cross(B.diag(0)) << endl;
    return 0;
}
