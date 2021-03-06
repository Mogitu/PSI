
//mainwindow.h

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <qcolordialog.h>
#include <qfiledialog.h>
#include "IrrRenderWidget.h"
#include <QMessageBox>
#include <QT>

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
    QColorDialog* colorPickerBright;
    QColorDialog* colorPickerDark;
    QColorDialog* colorPickerFade;

    void openShapeBox(const QString text);
private:
    Ui::MainWindow *ui;
    void InitIrrRenderWidget(QWidget *irrRenderTarget);
    void connectInputElements();

protected:
    virtual void resizeEvent(QResizeEvent *event);
    virtual bool eventFilter(QObject *obj, QEvent *event);

private slots:
    void applySettings();
    void on_PickDarkest_clicked();
    void on_PickBrightest_clicked();
    void on_FadeColor_clicked();
    void on_actionExport_triggered();
    void on_comboShape_currentIndexChanged(const QString &arg1);
    void on_loadTexture_clicked();   
};

#endif // MAINWINDOW_H
