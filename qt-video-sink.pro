QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = VideoSink
TEMPLATE = app
QMAKE_CXXFLAGS += -Werror=return-type

CONFIG += c++17

# linking qt5-gstreamer libs to project
CONFIG += link_pkgconfig
#PKGCONFIG += gstreamer-1.0 glib-2.0 gobject-2.0 gstreamer-app-1.0 gstreamer-pbutils-1.0 gstreamer-rtsp-1.0
PKGCONFIG += Qt5GStreamer-1.0 Qt5GStreamerUi-1.0

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


FORMS += \
    Src/Widgets/videoviewerwidget.ui

HEADERS += \
    Src/Widgets/videoviewerwidget.h \
    Src/Widgets/videowidget.h

SOURCES += \
    Src/Widgets/videoviewerwidget.cpp \
    Src/Widgets/videowidget.cpp \
    Src/main.cpp


# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
