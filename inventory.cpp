#include "inventory.h"
#include <QHeaderView>
#include <QDragMoveEvent>
#include <QDragEnterEvent>
#include <QMimeData>


Inventory::Inventory(QTableWidget* parent) : QTableWidget(parent)
{
    configureRowsAndColumnsToResizeTable();
    setAcceptDrops(true);
}

void Inventory::configureRowsAndColumnsToResizeTable()
{
    putColumnAndRowsCount(mColumn, mRow);
    configureHeaders();
    setDragDropMode(QAbstractItemView::DragDrop);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->resize(302, 302);
}

void Inventory::putColumnAndRowsCount(int columnCount, int rowsCount)
{
    setColumnCount(columnCount);
    setRowCount(rowsCount);
}

void Inventory::configureHeaders()
{
    configureHorizontalHeader();
    configureVerticalHeader();
}

void Inventory::configureHorizontalHeader()
{
    QHeaderView* horizontalView = horizontalHeader();
    horizontalView->setDefaultSectionSize(100);
    horizontalView->setVisible(false);
    horizontalView->setDisabled(true);
}

void Inventory::configureVerticalHeader()
{
    QHeaderView* verticalView = verticalHeader();
    verticalView->setDefaultSectionSize(100);
    verticalView->setVisible(false);
    verticalView->setDisabled(true);
}


void Inventory::dragEnterEvent(QDragEnterEvent *event)
{
    if (event->mimeData()->hasFormat("app/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void Inventory::dragMoveEvent(QDragMoveEvent *event)
{
    if (event->mimeData()->hasFormat("app/x-dnditemdata")) {
        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

void Inventory::dropEvent(QDropEvent *event)
{

    if (event->mimeData()->hasFormat("app/x-dnditemdata"))
    {
        QByteArray itemData = event->mimeData()->data("app/x-dnditemdata");
        QDataStream dataStream(&itemData, QIODevice::ReadOnly);

        QPixmap pixmap;
        QPoint offset;
        dataStream >> pixmap >> offset;
        QPoint dropPoint = event->position().toPoint();

        QLabel *newIcon = createNewItemAndMoveOnPoint(pixmap, dropPoint, offset);
        newIcon->show();

        if (event->source() == this) {
            event->setDropAction(Qt::MoveAction);
            event->accept();
        } else {
            event->acceptProposedAction();
        }
    } else {
        event->ignore();
    }
}

QLabel* Inventory::createNewItemAndMoveOnPoint(QPixmap pixmap, QPoint dropPoint, QPoint oldPoint)
{
    QLabel *newIcon = new QLabel(this);
    newIcon->setPixmap(pixmap.scaled(100, 100));
    newIcon->move(dropPoint - oldPoint);
    newIcon->setAttribute(Qt::WA_DeleteOnClose);
    return newIcon;
}
