#include <QDebug>
#include "worker.h"

worker::worker(QObject *parent) : QObject(parent)
{
}

void worker::setScene(DispWidget* myScene)
{
    m_scene = myScene;
}

void worker::doWork()
{
    qreal width = m_scene->sceneRect().width();
    qreal height = m_scene->sceneRect().height();
    QPointF topLeft = m_scene->sceneRect().topLeft();
    int horizontalCount = int(width / 5);
    int verticalCount = int(height / 10);

    QPen pen(Qt::red);
    QSizeF size(5,10);

    for (int i=0;i<horizontalCount;i++)
    {
        topLeft.setX(topLeft.x() + i*5);
        qDebug() << "i: " << i;
        for (int j=0;j<verticalCount;j++)
        {
            topLeft.setY(topLeft.y() + j*10);
            qDebug() << "j: " << j;
            QRectF tmpRect(topLeft,size);
            m_scene->addRect(tmpRect,pen);
        }
    }
}
