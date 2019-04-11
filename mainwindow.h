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
//!  Definition of class MainWindow.
/*!
  Class is responsible for creating graphical user interface.
*/
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //! Displays board with contour map from vector of fields
        /*!
          \param board - vector of fields
        */
    void showBoard(std::vector<Field> board);
    //! Loads colors from choosen color palette
        /*!
          \param index - index of color palette
        */
    void loadColorPalette(int index);
    //! Clears all objects drawn on contour board display
        /*!
        */
    void clearScene();
    //! Displays colours of highest and lowest values
        /*!
          \param up - color of highest value
          \param down - color of lowest value
        */
    void colourSliderRectangles(QColor up, QColor down);
    //! Sets values on sliders representing HSV colour of lowest and highest value on map
        /*!
          \param up - color of highest value
          \param down - color of lowest value
        */
    void setColoursSliders(QColor up, QColor down);
    //! Sets colour o highest value
        /*!
          \param up - color of highest value
        */
    void colourUpperSliderRectangle(QColor up);
    //! Sets colour o lowest value
        /*!
          \param down - color of lowest value
        */
    void colourLowerSliderRectangle(QColor down);
    //! Returns by reference current colors of highest and lowest value
        /*!
          \param up - color of highest value
          \param down - color of lowest value
        */
    void getCurrentColours(QColor &up, QColor &down);
    //! Displays contour map in currently set colors
        /*!
        */
    void temporaryColourBoard();
    //! Displays list of loaded color palettes from config
        /*!
          \param paletteList - list of loaded palettes names
        */
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

    void on_zoomInButton_clicked();

    void on_zooOutButton_clicked();

private:
    /// Pointer to ui
    Ui::MainWindow *ui;
    /// Pointer to object handling all interactions with user
    UIDialog *uiDialog;
    /// Vector of pointers for every element of contour map
    std::vector <QGraphicsRectItem *> boardObjects;
    /// Contains pointer to scene for all contour map
    QGraphicsScene *scene;
    /// Contains pointer to scene for color of lowest value of map
    QGraphicsScene *upperRect;
    /// Contains pointer to item with color of highest value of map
    QGraphicsRectItem *upperRectColor;
    /// Contains pointer to scene for color of lowest value of map
    QGraphicsScene *lowerRect;
    /// Contains pointer to item with color of lowest value of map
    QGraphicsRectItem *lowerRectColor;
    /// Boolean defining if any contour map was initialized
    bool isInitialized;
    /// Represents scale of zoom of map
    int zoom;

};

#endif // MAINWINDOW_H
