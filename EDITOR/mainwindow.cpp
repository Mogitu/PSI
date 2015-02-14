
//mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    colorPicker= new QColorDialog();
    InitIrrRenderWidget(ui->centralWidget->findChild<QWidget *>("ParticlePreviewWidget"));
}

MainWindow::~MainWindow()
{
    delete irrRenderWidget;
    delete colorPicker;
    delete ui;
}

void MainWindow::InitIrrRenderWidget(QWidget *irrRenderTarget)
{
    irrRenderWidget = new IrrRenderWidget(irrRenderTarget, false);
    irrRenderWidget->init();
}


void MainWindow::resizeEvent(QResizeEvent *event)
{
   irrRenderWidget->resizeIrrWidget(0, 0, this->size().width()/2, this->size().height());
}


void MainWindow::on_ApplyAll_clicked()
{
    irrRenderWidget->bright->X = colorPicker->currentColor().red();
    irrRenderWidget->bright->Y = colorPicker->currentColor().green();
    irrRenderWidget->bright->Z = colorPicker->currentColor().blue();
    irrRenderWidget->minScale = ui->lineEdit->text().toFloat();
    irrRenderWidget->maxScale = ui->lineEdit_2->text().toFloat();

    irrRenderWidget->createEmitter();
}


void MainWindow::on_PickColor_clicked()
{   
    colorPicker->open();
}
