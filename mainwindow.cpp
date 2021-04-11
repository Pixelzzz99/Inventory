#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMimeData>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui_Main(new Ui::MainWindow)
{
    ui_Main->setupUi(this);
    configureMenuBar();
    inventoryTable = new Inventory(ui_Main->Inventory);
    itemSlot = new Item(ui_Main->Item, ":/new/Items/Apple");
    setAcceptDrops(true);
}

MainWindow::~MainWindow()
{
    delete ui_Main;
}

void MainWindow::configureMenuBar()
{
    menuBar = new MenuBar(this, ui_Main->MainMenu);
    menuButton = ui_Main->MainMenuButton;
    menuBar->setButtonStart(ui_Main->StartButton);
    menuBar->setButtonQuit(ui_Main->QuitButton);
    menuBar->setActivePlace(ui_Main->ActivePlace);
    connect(menuButton, &QPushButton::clicked, menuBar, &MenuBar::showMenu);
}


