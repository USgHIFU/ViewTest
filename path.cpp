#include "path.h"
#include <QDebug>

Path::Path()
{
}

void Path::startDraw(QGraphicsSceneMouseEvent *event)
{
    QPainterPath currPath = path();
    currPath.moveTo(event->scenePos());
    m_startPoint = event->scenePos();
//    setPath(currPath);
//    qDebug() << "x: " << currPath.currentPosition().x()
//             << " y: " << currPath.currentPosition().y();
}

void Path::drawing(QGraphicsSceneMouseEvent *event)
{
    QPainterPath currPath = path();
    currPath.lineTo(event->scenePos());
    setPath(currPath);
//    qDebug() << "x: " << currPath.currentPosition().x()
//             << " y: " << currPath.currentPosition().y();
//    qDebug() << currPath.length();
}

void Path::endDraw()
{
    QPainterPath currPath = path();
    currPath.lineTo(m_startPoint);
    setPath(currPath);
}
