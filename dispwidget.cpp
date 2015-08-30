#include "dispwidget.h"
#include <QDebug>

DispWidget::DispWidget(QObject *parent):QGraphicsScene(parent)
{

}

void DispWidget::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    path = new Path;
    path->startDraw(event);
    QPen pen(Qt::red);
    currPath = path->path();
    addPath(currPath,pen);
    QGraphicsScene::mousePressEvent(event);
}

void DispWidget::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    path->drawing(event);
    currPath = path->path();
    QPen pen(Qt::red);
    addPath(currPath,pen);
    QGraphicsScene::mouseMoveEvent(event);
}

void DispWidget::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    path->endDraw();
    currPath = path->path();
    QPen pen(Qt::red);
    addPath(currPath,pen);
    QGraphicsScene::mouseReleaseEvent(event);
    qDebug() << "number of all the items: " << items().size();
}

void DispWidget::arrangeSpots()
{
    qreal width = sceneRect().width();
    qreal height = sceneRect().height();
    QPointF topLeft = sceneRect().topLeft();
    int horizontalCount = int(width / 5);
    int verticalCount = int(height / 10);

    QPen pen(Qt::red);
//    QBrush brush(Qt::red,Qt::SolidPattern);
    QSizeF size(5,10);
    QPointF tmpTopLeft = sceneRect().topLeft();
//    qreal x,y,startX,startY;
//    startX = topLeft.x();
//    startY = topLeft.y();

    for (int i=0;i<horizontalCount;i++)
    {
        tmpTopLeft.setX(topLeft.x() + i*5);
//        x = startX + i*5;
        qDebug() << "i: " << i;
        for (int j=0;j<verticalCount;j++)
        {
            tmpTopLeft.setY(topLeft.y() + j*10);
//            y = startY + j*5;
            qDebug() << "j: " << j;
            QRectF tmpRect(tmpTopLeft,size);
//            QRectF tmpRect(x,y,5,10);
            if (currPath.contains(tmpRect.center()))
            {
                addRect(tmpRect,pen);
                m_spots << tmpRect;
            }
        }
    }
}

QList<QPointF> DispWidget::getSpots()
{
    QList<QPointF> centers;
    for (int i=0;i<m_spots.size();i++)
    {
        centers << m_spots.at(i).center();
        qDebug() << "x: " << m_spots.at(i).center().x();
        qDebug() << "y: " << m_spots.at(i).center().y();
    }
    return centers;
}
