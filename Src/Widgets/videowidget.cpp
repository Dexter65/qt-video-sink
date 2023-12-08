#include "videowidget.h"

VideoWidget::VideoWidget(QWidget *parent)
    : QGst::Ui::VideoWidget{parent}
{

}

VideoWidget::~VideoWidget()
{
    if (m_pipeline) {
        m_pipeline->setState(QGst::StateNull);
        stopPipelineWatch();
    }
}

void VideoWidget::setUri(const QString &uri)
{
    if (!m_pipeline) {
        m_pipeline = QGst::ElementFactory::make("playbin").dynamicCast<QGst::Pipeline>();
        if (m_pipeline) {
            // let the video widget watch the pipeline for new video sinks
            watchPipeline(m_pipeline);

            // watch the bus for messages
            QGst::BusPtr bus = m_pipeline->bus();
            bus->addSignalWatch();
            QGlib::connect(bus, "message", this, &VideoWidget::onBusMessage);
        } else {
            qCritical() << "Failed to create the pipeline";
        }
    }

    if (m_pipeline) {
        m_pipeline->setProperty("uri", uri);
    }
}

void VideoWidget::play()
{
    if (m_pipeline) {
        m_pipeline->setState(QGst::StatePlaying);
    }
}

void VideoWidget::onBusMessage(const QGst::MessagePtr &message)
{
    auto deb = qDebug();
    deb << "video message: ";

    switch (message->type()) {
    case QGst::MessageEos: //End of stream. We reached the end of the file.
        deb << "eos";
        break;
    case QGst::MessageError: // Some error occurred.
        deb << "error";
        qCritical() << message.staticCast<QGst::ErrorMessage>()->error();
        break;
    case QGst::MessageStateChanged: //The element in message->source() has changed state
        deb << "state changed";
        if (message->source() == m_pipeline) {
            qDebug() << m_pipeline->currentState();
        }
        break;
    case QGst::MessageWarning:
        deb << "warning: " << message.staticCast<QGst::WarningMessage>()->error();
        break;
    case QGst::MessageInfo:
        deb << "info: " << message.staticCast<QGst::InfoMessage>()->error();
        break;
    default:
        deb << "other";
        break;
    }
}
