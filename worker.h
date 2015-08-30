#ifndef WORKER_H
#define WORKER_H

#include <QObject>
#include "dispwidget.h"

class worker : public QObject
{
    Q_OBJECT
public:
    explicit worker(QObject *parent = 0);
    void setScene(DispWidget* myScene);

signals:
    resultReady();

public slots:
    void doWork();

private:
    DispWidget* m_scene;
};

#endif // WORKER_H
