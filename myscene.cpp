#include "myscene.h"
#include<QDebug>
#include<stdio.h>
#include<time.h>
#include <QCursor>
#include <QWidget>
#include<QApplication>


myScene::myScene(QObject *parent) : QGraphicsScene(parent)
{
    QCursor myCursor= QCursor(QPixmap(":/img/chui_up.png"));
    QApplication::setOverrideCursor(myCursor);

    this->miceNumber = 0;
//    this->item = new myPicItem(":/img/beat.jpg");
//    this->item->setPos(100,100);
//    this->addItem(this->item);

//    item2 = new myPicItem(":/img/chui.png");
//    //item2->setPic(":/img/pause.png");
//    item2->setPos(200,200);
//    this->addItem(this->item2);

//    for(int i = 0 ; i < 4 ; ++i)
//    {
//        for(int j = 0 ; j < 4 ; ++j)
//        {
//            this->item[i][j] = new myPicItem(":/img/bg.jpg");
//            this->item[i][j]->setPos(this->item[i][j]->boundingRect().width()*i,this->item[i][j]->boundingRect().height()*j);
//            this->addItem(this->item[i][j]);

//        }
//    }
    for(int i = 0 ; i < 16 ; ++i)
    {
        this->item[i] = new myPicItem(":/img/bg.jpg");
        this->item[i]->setPos(this->item[i]->boundingRect().width()*(i/4),this->item[i]->boundingRect().height()*(i%4));
        this->addItem(this->item[i]);
    }

    this->ptimer = new QTimer;
    connect(this->ptimer,SIGNAL(timeout()),this,SLOT(miceC()));
    connect(this->ptimer,SIGNAL(timeout()),this,SLOT(getScore()));
    this->ptimer->start(1000);

}

void myScene::getScore()
{
    myPicItem temp;
    int score =  temp.getScore();
    if(preScore != score)
    {
        preScore= score;
        emit scoreElimt(score);
    }

}

void myScene::miceC()
{
    for(int i = 0;i < 16; ++i)
    {
        if(this->item[i]->isMiceAppear)
        {
            this->item[i]->setPic(":/img/bg.jpg");
            this->item[i]->setMiceAppear(false);
        }
    }

    srand((unsigned)time(NULL));
    for(int i = 0 ; i < rand()%2 +1 ;)
    {
        int index = rand()%15;

        if(!this->item[index]->isMiceAppear)
        {
            miceNumber ++;
            this->item[index]->setPic(":/img/bg1.jpg");
            this->item[index]->setMiceAppear(true);
            ++i;
        }

    }
}
