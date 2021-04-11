#ifndef INVENTORY_H
#define INVENTORY_H

#include <QObject>
#include <QWidget>
#include <QDragEnterEvent>
#include <QTableWidget>
/*
    Класс Инвентаря
*/
class Inventory : public QTableWidget
{
private:
    Q_OBJECT

    QTableWidget* _inventory;
    int mRow;
    int mColumn;

public:

    Inventory(QTableWidget* parent = nullptr);

    void configureRowsAndColumnsToResizeTable();
    void configureHeaders();
    void configureHorizontalHeader();
    void configureVerticalHeader();

protected:
    void dragEnterEvent(QDragEnterEvent *event) override;
    void dragMoveEvent(QDragMoveEvent *event) override;
    void dropEvent(QDropEvent *event) override;

};

#endif // INVENTORY_H
