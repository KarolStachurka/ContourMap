#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QStandardItemModel>
#include <vector>
#include <uidialog.h>
#include <field.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void diplayBoard();
    void colourSliderRectangles(QColor up, QColor down);
    void setColoursSliders(QColor up, QColor down);
    void colourUpperSliderRectangle(QColor up);
    void colourLowerSliderRectangle(QColor down);
    void setColorPaletteList(std::vector<std::string> paletteList);

private slots:
    void on_loadFileButton_clicked();
    
    void on_redMaxSlider_sliderMoved(int position);

    void on_greenMaxSlider_sliderMoved(int position);

    void on_blueMaxSlider_sliderMoved(int position);

    void on_redMinSlider_sliderMoved(int position);

    void on_greenMinSlider_sliderMoved(int position);

    void on_blueMinSlider_sliderMoved(int position);

    void on_savePaletteButton_clicked();

    void on_paletteListView_clicked(const QModelIndex &index);

private:
    Ui::MainWindow *ui;
    UIDialog *uiDialog;
    std::vector <QGraphicsRectItem *> boardObjects;
    QGraphicsScene *scene;
    QGraphicsScene *upperRect;
    QGraphicsRectItem *upperRectColor;
    QGraphicsScene *lowerRect;
    QGraphicsRectItem *lowerRectColor;

};

#endif // MAINWINDOW_H
