QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        CannyDetector_Demo.cpp \
        EqualizeHist_Demo.cpp \
        Geometric_Transforms_Demo.cpp \
        HoughCircle_Demo.cpp \
        Laplace_Demo.cpp \
        MatchTemplate_Demo.cpp \
        Morphology_1.cpp \
        Morphology_2.cpp \
        MyThreshold.cpp \
        Pyramids.cpp \
        Remap_Demo.cpp \
        Smoothing.cpp \
        Sobel_Demo.cpp \
        calcBackProject_Demo1.cpp \
        calcBackProject_Demo2.cpp \
        calcHist_Demo.cpp \
        copyMakeBorder_demo.cpp \
        filter2D_demo.cpp \
        findContours_demo.cpp \
        houghlines.cpp \
        hull_demo.cpp \
        main.cpp \
        pointPolygonTest_demo.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    samplefunctions.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../opencv/build/x64/vc14/lib/ -lopencv_world411
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../opencv/build/x64/vc14/lib/ -lopencv_world411d

INCLUDEPATH += $$PWD/../../opencv/build/include
DEPENDPATH += $$PWD/../../opencv/build/include
