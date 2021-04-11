#include "menubar.h"

MenuBar::MenuBar(QWidget *parent, QWidget* menuBar) : QWidget(parent), menuBar(menuBar)
{
    this->startButton = nullptr;
    this->quitButton = nullptr;
    this->activePlace = nullptr;
}

void MenuBar::setButtonStart(QPushButton *buttonStart)
{
    delete this->startButton;
    this->startButton = buttonStart;
    connect(startButton, &QPushButton::clicked, this, &MenuBar::on_StartButton_clicked);
    connect(this, &MenuBar::startClick, this, &MenuBar::startGame);
}

void MenuBar::setButtonQuit(QPushButton *buttonQuit)
{
    delete this->quitButton;
    this->quitButton = buttonQuit;
    connect(quitButton, &QPushButton::clicked, qApp, &QApplication::quit);
}

void MenuBar::setActivePlace(QWidget *activePlace)
{
    delete this->activePlace;
    this->activePlace = activePlace;
    activePlace->setEnabled(false);
}


void MenuBar::showMenu()
{
    if(!menuBar->isEnabled())
    {
        activePlace->setEnabled(false);
        menuBar->setEnabled(true);
    }
}

void MenuBar::startGame()
{
    if(!activePlace->isEnabled())
    {
        activePlace->setEnabled(true);
        menuBar->setEnabled(false);
    }
}


void MenuBar::on_StartButton_clicked()
{
    emit startClick();
}
