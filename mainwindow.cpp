#include "mainwindow.h"
#include <QVBoxLayout>
#include <QRectF>
#include <QLineF>
#include <QPen>
#include <QBrush>
#include <QPainterPath>
#include <QColor>
#include <QImage>
#include <QDebug>
#include "worker.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    dispWidget = new DispWidget(this);
    dispWidget->setSceneRect(0,0,1024,768);

    QImage img(":/background/368-0456.jpg");

    dispWidget->addPixmap(QPixmap::fromImage(img));
    // add text
//    scene->addText("Hello world!");

    // add lines
//    QLineF line(0,0,30,30);
//    QPen pen(Qt::red);
//    scene->addLine(line,pen);

    view = new QGraphicsView(dispWidget,this);

    button = new QPushButton("display",this);
    update = new QPushButton("update",this);

    QVBoxLayout* layout = new QVBoxLayout;
    layout->addWidget(view);
    layout->addWidget(button);
    layout->addWidget(update);
    QWidget* widget = new QWidget(this);
    widget->setLayout(layout);

    setCentralWidget(widget);
    connect(button,SIGNAL(clicked(bool)),dispWidget,SLOT(arrangeSpots()));
    connect(update,SIGNAL(clicked(bool)),dispWidget,SLOT(getSpots()));
}

MainWindow::~MainWindow()
{

}

void MainWindow::updatePath()
{
//    // add path
//    QPainterPath path;

//    path.moveTo(0,0);
//    path.lineTo(10,10);

//    path.moveTo(0, 0);
//    path.cubicTo(99, 0,  50, 50,  99, 99);
//    path.cubicTo(0, 99,  50, 50,  0, 0);

//    QPen pen(Qt::red);
//    QBrush brush(Qt::blue,Qt::SolidPattern);
//    dispWidget->addPath(path,pen,brush);

//    qDebug() << path.length() << endl;

//    path.lineTo(100,200);
//    dispWidget->addPath(path,pen);

//    qDebug() << path.length() << endl;

//    QColor color(Qt::red);
//    color.setAlpha(126);
//    QRectF rect(10,10,50,50);
//    QBrush brush4rect(color,Qt::SolidPattern);
//    dispWidget->addRect(rect,pen,brush4rect);

    qDebug() << "another thread is working.";
    dispWidget->update(dispWidget->sceneRect());
    dispWidget->getSpots();
}
