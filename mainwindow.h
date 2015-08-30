#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QThread>
#include "dispwidget.h"
#include <QGraphicsView>

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void updatePath();

private:
    QPushButton* button;
    QPushButton* update;
    DispWidget* dispWidget;
    QGraphicsView* view;
    QThread workThread;
};

#endif // MAINWINDOW_H
