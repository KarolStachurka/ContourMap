#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QStandardItemModel>
#include <QFileDialog>
#include <vector>
#include <uidialog.h>
#include <field.h>
#include <utils.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void showBoard(std::vector<Field> board);
    void loadColorPalette(int index);
    void clearScene();
    void colourSliderRectangles(QColor up, QColor down);
    void setColoursSliders(QColor up, QColor down);
    void colourUpperSliderRectangle(QColor up);
    void colourLowerSliderRectangle(QColor down);
    void getCurrentColours(QColor &up, QColor &down);
    void temporaryColourBoard();
    void setColorPaletteList(std::vector<std::string> paletteList);

private slots:
    void on_loadFileButton_clicked();
    
    void on_hueMaxSlider_sliderMoved(int position);

    void on_saturationMaxSlider_sliderMoved(int position);

    void on_valueMaxSlider_sliderMoved(int position);

    void on_hueMinSlider_sliderMoved(int position);

    void on_saturationMinSlider_sliderMoved(int position);

    void on_valueMinSlider_sliderMoved(int position);

    void on_savePaletteButton_clicked();

    void on_paletteListView_clicked(const QModelIndex &index);

    void on_saveChartButton_clicked();

private:
    Ui::MainWindow *ui;
    UIDialog *uiDialog;
    std::vector <QGraphicsRectItem *> boardObjects;
    QGraphicsScene *scene;
    QGraphicsScene *upperRect;
    QGraphicsRectItem *upperRectColor;
    QGraphicsScene *lowerRect;
    QGraphicsRectItem *lowerRectColor;
    bool isInitialized;

};

#endif // MAINWINDOW_H
