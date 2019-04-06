#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->paletteListView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    uiDialog = new UIDialog();
    upperRect = new QGraphicsScene;
    upperRectColor = new QGraphicsRectItem;
    lowerRect = new QGraphicsScene;
    lowerRectColor = new QGraphicsRectItem;
    colourSliderRectangles(QColor(0,0,0),QColor(0,0,0));

    ui->valueMinSlider->setMaximum(255);
    ui->valueMaxSlider->setMaximum(255);
    ui->saturationMinSlider->setMaximum(255);
    ui->saturationMaxSlider->setMaximum(255);
    ui->hueMinSlider->setMaximum(359);
    ui->hueMaxSlider->setMaximum(359);

    setColorPaletteList(uiDialog->getPaletteList());

}

MainWindow::~MainWindow()
{
    delete uiDialog;
    delete ui;
}

void MainWindow::on_loadFileButton_clicked()
{
    uiDialog->display();
    scene = new QGraphicsScene;
    clearScene();
    std::vector<Field> board = uiDialog->getBoard().getBoard();
    int sizeX = ui->mapGraphicView->size().width()/uiDialog->getBoard().getSizeX();
    int sizeY = ui->mapGraphicView->size().height()/uiDialog->getBoard().getSizeY();
    for(Field field:board)
    {
        QGraphicsRectItem *item = new QGraphicsRectItem;
        item->setPen(Qt::NoPen);
        item->setRect(field.getX()*sizeX,field.getY()*sizeY,sizeX,sizeY);
        item->setBrush(QBrush(field.getColor()));
        scene->addItem(item);
        boardObjects.push_back(item);
    }
    ui->mapGraphicView->setScene(scene);
    ui->mapGraphicView->fitInView(scene->sceneRect(), Qt::KeepAspectRatio);
    Field max = *std::max_element(board.begin(),board.end());
    Field min = *std::min_element(board.begin(),board.end());
    ui->maxValueLabel->setText(QString::number(max.getValue()));
    ui->minValueLabel->setText(QString::number(min.getValue()));

}

void MainWindow::clearScene()
{
    for(auto &i:boardObjects)
    {
        delete i;
    }
    boardObjects.clear();
    scene->clear();
}

void MainWindow::setColorPaletteList(std::vector<std::string> paletteList)
{
    int rows = paletteList.size();
    QStandardItemModel *model = new QStandardItemModel( rows, 1, this );
    for(int i = 0; i < paletteList.size(); i++)
    {
        QString rowName = QString::fromStdString(paletteList.at(i));
        QStandardItem *item = new QStandardItem(rowName);
        model->setItem(i, 0, item);
    }
    ui->paletteListView->setModel(model);
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
    ui->hueMaxSlider->setValue(up.hue());
    ui->saturationMaxSlider->setValue(up.saturation());
    ui->valueMaxSlider->setValue(up.value());

    ui->hueMinSlider->setValue(down.hue());
    ui->saturationMinSlider->setValue(down.saturation());
    ui->valueMinSlider->setValue(down.value());
}



void MainWindow::on_hueMaxSlider_sliderMoved(int position)
{
    int hue = position;
    int saturation = ui->saturationMaxSlider->value();
    int value = ui->valueMaxSlider->value();
    QColor newColor;
    newColor.setHsv(hue,saturation,value);
    colourUpperSliderRectangle(newColor);
}

void MainWindow::on_saturationMaxSlider_sliderMoved(int position)
{
    int hue = ui->hueMaxSlider->value();
    int saturation = position;
    int value = ui->valueMaxSlider->value();
    QColor newColor;
    newColor.setHsv(hue,saturation,value);
    colourUpperSliderRectangle(newColor);
}

void MainWindow::on_valueMaxSlider_sliderMoved(int position)
{
    int hue = ui->hueMaxSlider->value();
    int saturation = ui->saturationMaxSlider->value();
    int value = position;
    QColor newColor;
    newColor.setHsv(hue,saturation,value);
    colourUpperSliderRectangle(newColor);
}

void MainWindow::on_hueMinSlider_sliderMoved(int position)
{
    int hue = position;
    int saturation = ui->saturationMinSlider->value();
    int value = ui->valueMinSlider->value();
    QColor newColor;
    newColor.setHsv(hue,saturation,value);
    colourLowerSliderRectangle(newColor);
}

void MainWindow::on_saturationMinSlider_sliderMoved(int position)
{
    int hue = ui->hueMinSlider->value();
    int saturation = position;
    int value = ui->valueMinSlider->value();
    QColor newColor;
    newColor.setHsv(hue,saturation,value);
    colourLowerSliderRectangle(newColor);
}

void MainWindow::on_valueMinSlider_sliderMoved(int position)
{
    int hue = ui->hueMinSlider->value();
    int saturation = ui->saturationMinSlider->value();
    int value = position;
    QColor newColor;
    newColor.setHsv(hue,saturation,value);
    colourLowerSliderRectangle(newColor);
}

void MainWindow::on_savePaletteButton_clicked()
{
    QModelIndex index = ui->paletteListView->currentIndex();
    std::string identifier = "palette" + std::to_string(index.row());
    std::string name = ui->paletteNameTextEdit->text().toStdString();
    int hueDown = ui->hueMinSlider->value();
    int saturationDown = ui->saturationMinSlider->value();
    int valueDown = ui->valueMinSlider->value();
    int hueUp = ui->hueMaxSlider->value();
    int saturationUp = ui->saturationMaxSlider->value();
    int valueUp = ui->valueMaxSlider->value();
    QColor down;
    down.setHsv(hueDown,saturationDown,valueDown);
    QColor up;
    up.setHsv(hueUp,saturationUp,valueUp);
    uiDialog->setPaletteColors(identifier,name,up,down);
    setColorPaletteList(uiDialog->getPaletteList());
}

void MainWindow::on_paletteListView_clicked(const QModelIndex &index)
{
    QColor maximum,minimum;
    std::string name,identifier;
    identifier = "palette" + std::to_string(index.row());
    uiDialog->getPaletteColors(identifier,name,maximum,minimum);
    colourLowerSliderRectangle(minimum);
    colourUpperSliderRectangle(maximum);
    setColoursSliders(maximum,minimum);
    uiDialog->setColorPalette(ColorPalette(name,maximum,minimum));
    ui->paletteNameTextEdit->setText(QString::fromStdString(name));
    uiDialog->display();
}

void MainWindow::on_saveChartButton_clicked()
{

}
