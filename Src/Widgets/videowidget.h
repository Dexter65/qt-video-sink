#ifndef VIDEOWIDGET_H
#define VIDEOWIDGET_H

#include <QWidget>

#include <QGst/Pipeline>
#include <QGst/ElementFactory>
#include <QGst/Bus>
#include <QGst/Ui/VideoWidget>
#include <QGst/Message>

#include <QGlib/Global>
#include <QGlib/Connect>


class VideoWidget : public QGst::Ui::VideoWidget
{
    Q_OBJECT


    QGst::PipelinePtr m_pipeline;

public:
    explicit VideoWidget(QWidget *parent = nullptr);
    ~VideoWidget();

public slots:
    void setUri(const QString & uri);
    void play();

protected slots:
    void onBusMessage(const QGst::MessagePtr & message);

signals:

};

#endif // VIDEOWIDGET_H
