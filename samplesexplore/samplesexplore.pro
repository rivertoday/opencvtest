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
        adding_images.cpp \
        basic_linear_transform.cpp \
        how_to_scan_images.cpp \
        main.cpp \
        mat_mask_operations.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target


win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../opencv/build/x64/vc14/lib/ -lopencv_world411
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../opencv/build/x64/vc14/lib/ -lopencv_world411d

INCLUDEPATH += $$PWD/../../opencv/build/include
DEPENDPATH += $$PWD/../../opencv/build/include

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../opencv/build/x64/vc14/lib/libopencv_world411.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../opencv/build/x64/vc14/lib/libopencv_world411d.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += $$PWD/../../opencv/build/x64/vc14/lib/opencv_world411.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += $$PWD/../../opencv/build/x64/vc14/lib/opencv_world411d.lib

HEADERS += \
    samplefunctions.h
