#ifndef DISPWIDGET_H
#define DISPWIDGET_H

#include <QGraphicsScene>
#include "path.h"

class DispWidget : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit DispWidget(QObject *parent = 0);

public slots:
    void arrangeSpots();
    QList<QPointF> getSpots();

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

private:
    Path* path;
    QPainterPath currPath;
    QList<QRectF> m_spots;
};

#endif // DISPWIDGET_H
