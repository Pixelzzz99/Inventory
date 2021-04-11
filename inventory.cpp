#include "inventory.h"
#include <QHeaderView>
#include <QDragMoveEvent>
#include <QDragEnterEvent>
#include <QMimeData>
#include <QLabel>

Inventory::Inventory(QTableWidget* parent) : QTableWidget(parent)
{
    configureRowsAndColumnsToResizeTable();
    setAcceptDrops(true);
}

void Inventory::configureRowsAndColumnsToResizeTable()
{
    setColumnCount(3);
    setRowCount(3);
    configureHeaders();
    setDragDropMode(QAbstractItemView::DragDrop);
    setEditTriggers(QAbstractItemView::NoEditTriggers);
    this->resize(302, 302);
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

        QLabel *newIcon = new QLabel(this);
        newIcon->setPixmap(pixmap.scaled(100, 100));

        newIcon->move(event->position().toPoint() - offset);
        newIcon->show();
        newIcon->setAttribute(Qt::WA_DeleteOnClose);

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
