#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <inventory.h>
#include <item.h>
#include <menubar.h>

/*
    Главное окно
*/

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
private:
    Q_OBJECT

    Ui::MainWindow *ui_Main;

    MenuBar* menuBar;
    QPushButton* menuButton;

    Item* itemSlot;
    Inventory* inventoryTable;

    //метод который соединяет Виджет Меню с Главным окном
    void configureMenuBar();

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    //Метод Соединяющийся с Базой Данных
    bool connectDB();


};
#endif // MAINWINDOW_H
