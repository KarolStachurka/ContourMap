#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    uiDialog = new UIDialog();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_loadFileButton_clicked()
{
    uiDialog->display();
    scene = new QGraphicsScene;
    std::vector<Field> board = uiDialog->getBoard().getBoard();
    for(Field field:board)
    {
        QGraphicsRectItem *item = new QGraphicsRectItem;
        item->setRect(field.getX()*20,field.getY()*20,20,20);
        item->setBrush(QBrush(field.getColor()));
        scene->addItem(item);
        boardObjects.push_back(item);

    }
    ui->mapGraphicView->setScene(scene);

}
