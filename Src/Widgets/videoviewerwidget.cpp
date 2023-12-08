#include "videoviewerwidget.h"
#include "ui_videoviewerwidget.h"

VideoViewerWidget::VideoViewerWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VideoViewerWidget)
{
//    ui->setupUi(this);
}

VideoViewerWidget::~VideoViewerWidget()
{
    delete ui;
}
