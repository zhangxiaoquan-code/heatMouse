#include "mypicitem.h"
#include <QPixmap>
#include <QDebug>
#include<QApplication>
#include<QCursor>

int myPicItem::score = 0;

myPicItem::myPicItem(QString path)
{
    this->setPixmap(QPixmap(path));
    isMiceAppear = false;
}

//void myPicItem::setPos(QString path)
//{
//    this->setPixmap(QPixmap(path));
//}
void myPicItem::setPic(QString path)
{
    this->setPixmap(QPixmap(path));
}

void myPicItem::mouseReleaseEvent(QGraphicsSceneMouseEvent * event)
{
    this->setPixmap(QPixmap(":/img/bg.jpg"));

    QCursor myCursor=QCursor(QPixmap(":/img/chui_up.png"));
    QApplication::setOverrideCursor(myCursor);
}

int myPicItem::getScore()
{
    return score;
}

void myPicItem::mousePressEvent(QGraphicsSceneMouseEvent * event)
{
    QCursor myCursor=QCursor(QPixmap(":/img/chui.png"));
    QApplication::setOverrideCursor(myCursor);
    if(this->isMiceAppear)
    {
        this->setPixmap(QPixmap(":/img/beat.jpg"));
        this->setMiceAppear(false);
        score++;

    }


}

void myPicItem::setMiceAppear(bool MiceAppear)
{
    this->isMiceAppear = MiceAppear;
}
