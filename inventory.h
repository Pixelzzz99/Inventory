#ifndef INVENTORY_H
#define INVENTORY_H

#include <QObject>
#include <QWidget>
#include <QDragEnterEvent>
#include <QTableWidget>
#include <QLabel>
/*
    Класс Инвентаря
*/
class Inventory : public QTableWidget
{
private:
    Q_OBJECT

    int mRow = 3;
    int mColumn = 3;

    //метод создающий Предмет и перемещающий на точку куда был кинут предмет
    QLabel* createNewItemAndMoveOnPoint(QPixmap pixmap, QPoint dropPoint, QPoint oldPoint);
public:

    Inventory(QTableWidget* parent = nullptr);

    //Метод настраивающий таблицу в целом
    void configureRowsAndColumnsToResizeTable();

    //Метод задающий количество столбцов и строк в таблице
    void putColumnAndRowsCount(int columnCount, int rowsCount);

    //Метод соединяющий методы configureHorizontalHeader() и configureVerticalHeader()
    void configureHeaders();

    //методы настраивающий ячейчки и убирающие заглавия столбцов и строк
    void configureHorizontalHeader();
    void configureVerticalHeader();

protected:
    //Оброботчик события когда Предмет заходит в облоасть видимости Инвентаря
    void dragEnterEvent(QDragEnterEvent *event) override;

    //Оброботчик события когда Предмет находится в области Инвентаря
    void dragMoveEvent(QDragMoveEvent *event) override;

    //Обротчик события когда Предмет кинут в Инвентарь
    void dropEvent(QDropEvent *event) override;

};

#endif // INVENTORY_H
