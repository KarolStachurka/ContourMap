#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    uiDialog = new UIDialog();
    upperRect = new QGraphicsScene;
    upperRectColor = new QGraphicsRectItem;
    lowerRect = new QGraphicsScene;
    lowerRectColor = new QGraphicsRectItem;
    colourSliderRectangles(QColor(0,0,0),QColor(0,0,0));

    ui->blueMinSlider->setMaximum(255);
    ui->blueMaxSlider->setMaximum(255);
    ui->greenMinSlider->setMaximum(255);
    ui->greenMaxSlider->setMaximum(255);
    ui->redMinSlider->setMaximum(255);
    ui->redMaxSlider->setMaximum(255);
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

void MainWindow::setColorPaletteList(vector<std::string> paletteList)
{
    for(auto name:paletteList)
    {
    }
}

void MainWindow::colourSliderRectangles(QColor up, QColor down)
{
    upperRectColor->setRect(0,0,100,100);
    upperRectColor->setBrush(QBrush(up));
    upperRect->addItem(upperRectColor);
    ui->upperColorDisplay->setScene(upperRect);

    lowerRectColor->setRect(0,0,100,100);
    lowerRectColor->setBrush(QBrush(down));
    lowerRect->addItem(lowerRectColor);
    ui->lowerColorDisplay->setScene(lowerRect);

    setColoursSliders(up,down);
}
void MainWindow::colourUpperSliderRectangle(QColor up)
{
    upperRectColor->setBrush(QBrush(up));
}

void MainWindow::colourLowerSliderRectangle(QColor down)
{
    lowerRectColor->setBrush(QBrush(down));
}

void MainWindow::setColoursSliders(QColor up, QColor down)
{
    ui->redMaxSlider->setValue(up.red());
    ui->greenMaxSlider->setValue(up.green());
    ui->blueMaxSlider->setValue(up.blue());

    ui->redMinSlider->setValue(down.red());
    ui->greenMinSlider->setValue(down.green());
    ui->blueMinSlider->setValue(down.blue());
}



void MainWindow::on_redMaxSlider_sliderMoved(int position)
{
    int red = position;
    int green = ui->greenMaxSlider->value();
    int blue = ui->blueMaxSlider->value();
    QColor newColor = QColor(red,green,blue);
    colourUpperSliderRectangle(newColor);
}

void MainWindow::on_greenMaxSlider_sliderMoved(int position)
{
    int red = ui->redMaxSlider->value();
    int green = position;
    int blue = ui->blueMaxSlider->value();
    QColor newColor = QColor(red,green,blue);
    colourUpperSliderRectangle(newColor);
}

void MainWindow::on_blueMaxSlider_sliderMoved(int position)
{
    int red = ui->redMaxSlider->value();
    int green = ui->greenMaxSlider->value();
    int blue = position;
    QColor newColor = QColor(red,green,blue);
    colourUpperSliderRectangle(newColor);
}

void MainWindow::on_redMinSlider_sliderMoved(int position)
{
    int red = position;
    int green = ui->greenMinSlider->value();
    int blue = ui->blueMinSlider->value();
    QColor newColor = QColor(red,green,blue);
    colourLowerSliderRectangle(newColor);
}

void MainWindow::on_greenMinSlider_sliderMoved(int position)
{
    int red = ui->redMinSlider->value();
    int green = position;
    int blue = ui->blueMinSlider->value();
    QColor newColor = QColor(red,green,blue);
    colourLowerSliderRectangle(newColor);
}

void MainWindow::on_blueMinSlider_sliderMoved(int position)
{
    int red = ui->redMinSlider->value();
    int green = ui->greenMinSlider->value();
    int blue = position;
    QColor newColor = QColor(red,green,blue);
    colourLowerSliderRectangle(newColor);
}

void MainWindow::on_savePaletteButton_clicked()
{

}
