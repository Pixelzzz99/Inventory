#ifndef MENUBAR_H
#define MENUBAR_H

#include <QObject>
#include <QWidget>
#include <QMainWindow>
#include <QPushButton>
#include <QApplication>
#include <QMenu>

/*
    Класс Меню сверху с кнопками Старт и выход
*/

class MenuBar : public QWidget
{
private:
    Q_OBJECT
    QPushButton *startButton;
    QPushButton *quitButton;
    QWidget* menuBar;
    QWidget* activePlace;
public:

    explicit MenuBar(QWidget *parent = nullptr, QWidget* menuBar = nullptr);
    //Сеттер принимающий Кнопку с UI кнопку выхода
    void setButtonStart(QPushButton *buttonStart);
    //Сеттер принимающий Кнопку с UI кнопку старта
    void setButtonQuit(QPushButton *buttonQuit);
    //Сеттер принимающий Виджет который активирует игровое поле
    void setActivePlace(QWidget* activePlace);

signals:
    //Сигнал срабатывающий при нажатии кнопки Старта
    void startClick();

public slots:
    //Слот вызывается и главного окна при нажатии кнопки Меню
    void showMenu();

private slots:
    //Слот срабатывающий при нажатии кнопки Старт
    void startGame();
    //Слот срабатывающий при нажатии кнопки старт и вызывающий сигнал startClick
    void on_StartButton_clicked();
};

#endif // MENUBAR_H
