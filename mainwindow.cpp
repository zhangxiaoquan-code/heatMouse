#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QDebug>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    this->scene = new myScene;

    connect(this->scene,SIGNAL(scoreElimt(int)),this,SLOT(showScore(int)));
    this->ui->graphicsView->setScene(scene);

    //this->ui->label->setPixmap(QPixmap(":/img/chui_up.png"));

}

void MainWindow::showScore(int values)
{
    QString temp ;
    this->ui->label->setText("您的分数:"+temp.number(values));
    qDebug()<<this->scene->miceNumber;
    if(this->scene->miceNumber > 100)
    {
        int select = QMessageBox::warning(this,"您的成绩","您太菜了","返回重玩","不玩了");
        this->scene->miceNumber = 0;
        if(1 == select)
        {
            this->close();
        }
    }
}


MainWindow::~MainWindow()
{
    delete ui;
}
