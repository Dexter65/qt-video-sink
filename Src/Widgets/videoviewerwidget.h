#ifndef VIDEOVIEWERWIDGET_H
#define VIDEOVIEWERWIDGET_H

#include <QWidget>

namespace Ui {
class VideoViewerWidget;
}

class VideoViewerWidget : public QWidget
{
    Q_OBJECT

public:
    explicit VideoViewerWidget(QWidget *parent = nullptr);
    ~VideoViewerWidget();

private:
    Ui::VideoViewerWidget *ui;
};

#endif // VIDEOVIEWERWIDGET_H
