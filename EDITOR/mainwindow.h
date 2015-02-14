
//mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qcolordialog.h>
#include "IrrRenderWidget.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    IrrRenderWidget* irrRenderWidget;
    QColorDialog* colorPicker;


private:
    Ui::MainWindow *ui;
    void InitIrrRenderWidget(QWidget *irrRenderTarget);


protected:
    virtual void resizeEvent(QResizeEvent *event);


private slots:

    void on_ApplyAll_clicked();
    void on_PickColor_clicked();
};

#endif // MAINWINDOW_H
