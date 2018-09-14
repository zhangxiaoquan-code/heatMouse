#ifndef MYSCENE_H
#define MYSCENE_H

#include <QObject>
#include <QGraphicsScene>
#include <QTimer>
#include "mypicitem.h"


class myScene : public QGraphicsScene
{
    Q_OBJECT
public:
    explicit myScene(QObject *parent = 0);
    void score();
    int miceNumber;
private slots:
    void miceC();
    void getScore();
signals:
    void scoreElimt(int);
private:

    //myPicItem * item[4][4];
    myPicItem * item[16];
    QTimer *ptimer;
    int preScore;


};

#endif // MYSCENE_H
