
//mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    colorPickerBright= new QColorDialog();
    colorPickerDark = new QColorDialog();
    InitIrrRenderWidget(ui->centralWidget->findChild<QWidget *>("ParticlePreviewWidget"));
}

MainWindow::~MainWindow()
{

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
    irrRenderWidget->particleManager->setColorBright(colorPickerBright->currentColor());
    irrRenderWidget->particleManager->setColorDark(colorPickerDark->currentColor());
    irrRenderWidget->particleManager->setDirection(ui->dirX->text().toFloat(),ui->dirY->text().toFloat(),ui->dirZ->text().toFloat());
    irrRenderWidget->particleManager->minScale = ui->lineEdit->text().toFloat();
    irrRenderWidget->particleManager->maxScale = ui->lineEdit_2->text().toFloat();
    irrRenderWidget->particleManager->createEmitter();
}

void MainWindow::on_PickDarkest_clicked()
{
    colorPickerDark->open();
}

void MainWindow::on_PickBrightest_clicked()
{
    colorPickerBright->open();
}



void MainWindow::on_actionExport_triggered()
{
   irrRenderWidget->exportToFile();
}
