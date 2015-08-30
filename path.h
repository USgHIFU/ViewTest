#ifndef PATH_H
#define PATH_H

#include <QPainterPath>
#include <QGraphicsPathItem>
#include <QGraphicsSceneMouseEvent>
#include <QPointF>

class Path: public QGraphicsPathItem
{
public:
    Path();

    void startDraw(QGraphicsSceneMouseEvent* event);
    void drawing(QGraphicsSceneMouseEvent* event);
    void endDraw();

private:
    QPointF m_startPoint;

};

#endif // PATH_H
