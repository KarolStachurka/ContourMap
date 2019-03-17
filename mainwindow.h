#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
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

private slots:
    void on_loadFileButton_clicked();
    
private:
    Ui::MainWindow *ui;
    UIDialog *uiDialog;
    std::vector <QGraphicsRectItem *> boardObjects;
    QGraphicsScene *scene;
};

#endif // MAINWINDOW_H
