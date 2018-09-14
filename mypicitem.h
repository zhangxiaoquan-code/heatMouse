#ifndef MYPICITEM_H
#define MYPICITEM_H

#include <QGraphicsPixmapItem>
#include <QGraphicsSceneMouseEvent>

class myPicItem : public QGraphicsPixmapItem
{
public:
    myPicItem(){}
    myPicItem(QString path);
    void setPic(QString path);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent * event);
    void mousePressEvent(QGraphicsSceneMouseEvent * event);

    void setMiceAppear(bool MiceAppear);
    int getScore();
    bool isMiceAppear;
private:

    static int score;

};

#endif // MYPICITEM_H
