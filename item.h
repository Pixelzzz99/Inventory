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

    QDrag* collectInformationFromItemAndGetDragItem(QPixmap pixmap, QPoint mousePosition, QPoint oldPosition);
    QPixmap createShadowPixmapItem(QPixmap pixmap);

public:
    explicit Item(QWidget* parent = nullptr, QString path = nullptr);
    void setPixmapItem(QPixmap newPixmap);
protected:
    void mousePressEvent(QMouseEvent *event) override;
};

#endif // ITEM_H
