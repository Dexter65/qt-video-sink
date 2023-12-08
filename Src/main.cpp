#include "Widgets/videoviewerwidget.h"

#include <QApplication>
#include <QGst/Init>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QGst::init();

    VideoViewerWidget* videoViewer = new VideoViewerWidget();
    videoViewer->show();

    return a.exec();
}
