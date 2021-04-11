#ifndef ITEM_H
#define ITEM_H

#include <QWidget>
#include <QDrag>
#include <QLabel>

/*
    Класс Предмета с возможностью Drag And Drop
*/
class Item : public QWidget
{
    Q_OBJECT
    QLabel* _item;
    QPixmap _pathToImage;

    QPoint dragStartPosition;
public:
    explicit Item(QWidget* parent = nullptr, QString path = nullptr);
    void setPixmapItem(QPixmap newPixmap);
protected:
    //void dragEnterEvent(QDragEnterEvent *event) override;
    //void dragMoveEvent(QDragMoveEvent *event) override;
    //void dropEvent(QDropEvent *event) override;
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // ITEM_H
