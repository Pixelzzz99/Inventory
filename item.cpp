#include "item.h"
#include <QMimeData>
#include <QDrag>
#include <QDragEnterEvent>
#include <QPainter>

Item::Item(QWidget *parent, QString path) : QWidget(parent)
{
    _item = new QLabel(this);
    _item->resize(100, 100);
    _pathToImage = QPixmap(path).scaled(100, 100);
    _item->setPixmap(_pathToImage);
}

void Item::setPixmapItem(QPixmap newPixmap)
{
    _item->setPixmap(newPixmap);
}

void Item::mousePressEvent(QMouseEvent *event)
{
    QLabel* child = static_cast<QLabel*>(childAt(event->position().toPoint()));
    if(!child) return;

    QPixmap pixmap = child->pixmap(Qt::ReturnByValue);

    QPoint mousePosition = event->position().toPoint();
    QPoint oldPosition = child->pos();

    QDrag* drag = collectInformationFromItemAndGetDragItem(pixmap, mousePosition, oldPosition);

    QPixmap tempPixmap = createShadowPixmapItem(pixmap);
    child->setPixmap(tempPixmap);

    if(drag->exec(Qt::CopyAction | Qt::MoveAction, Qt::CopyAction) == Qt::MoveAction)
        child->close();
    else {
        child->show();
        child->setPixmap(pixmap);
    }

}

QDrag* Item::collectInformationFromItemAndGetDragItem(QPixmap pixmap, QPoint mousePosition, QPoint oldPosition)
{
    QByteArray itemData;
    QDataStream dataStream(&itemData, QIODevice::WriteOnly);
    dataStream <<pixmap<<QPoint(mousePosition - oldPosition);

    QMimeData* mimeData = new QMimeData;
    mimeData->setData("app/x-dnditemdata", itemData);

    QDrag *drag = new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(mousePosition - oldPosition);
    return drag;
}

QPixmap Item::createShadowPixmapItem(QPixmap pixmap)
{
    QPixmap tempPixmap = pixmap;
    QPainter painter;
    painter.begin(&tempPixmap);
    painter.fillRect(pixmap.rect(), QColor(127, 127, 127, 127));
    painter.end();
    return tempPixmap;

}
