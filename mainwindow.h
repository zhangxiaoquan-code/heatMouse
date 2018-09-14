#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myscene.h"
#include <QGraphicsSceneMouseEvent>
#include<QMessageBox>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:
    void showScore(int values);
private:
    Ui::MainWindow *ui;
    myScene * scene;
};

#endif // MAINWINDOW_H
