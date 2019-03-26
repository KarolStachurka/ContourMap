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

    ui->blueMinSlider->setMaximum(255);
    ui->blueMaxSlider->setMaximum(255);
    ui->greenMinSlider->setMaximum(255);
    ui->greenMaxSlider->setMaximum(255);
    ui->redMinSlider->setMaximum(255);
    ui->redMaxSlider->setMaximum(255);

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
    std::vector<Field> board = uiDialog->getBoard().getBoard();
    for(Field field:board)
    {
        QGraphicsRectItem *item = new QGraphicsRectItem;
        item->setPen(Qt::NoPen);
        item->setRect(field.getX()*20,field.getY()*20,20,20);
        item->setBrush(QBrush(field.getColor()));
        scene->addItem(item);
        boardObjects.push_back(item);

    }
    ui->mapGraphicView->fitInView(0,0,scene->width(),scene->height(), Qt::KeepAspectRatio);
    ui->mapGraphicView->setScene(scene);
    Field max = *std::max_element(board.begin(),board.end());
    Field min = *std::min_element(board.begin(),board.end());
    ui->maxValueLabel->setText(QString::number(max.getValue()));
    ui->minValueLabel->setText(QString::number(min.getValue()));

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
    QModelIndex index = ui->paletteListView->currentIndex();
    std::string identifier = "palette" + std::to_string(index.row());
    std::string name = ui->paletteNameTextEdit->text().toStdString();
    int redDown = ui->redMinSlider->value();
    int greenDown = ui->greenMinSlider->value();
    int blueDown = ui->blueMinSlider->value();
    int redUp = ui->redMaxSlider->value();
    int greenUp = ui->greenMaxSlider->value();
    int blueUp = ui->blueMaxSlider->value();
    QColor down = QColor(redDown,greenDown,blueDown);
    QColor up = QColor(redUp,greenUp,blueUp);
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
    ui->paletteNameTextEdit->setText(QString::fromStdString(name));
}
