
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

//writes all information entered in the editors labels into respective variables and creates a new emitter from them.
void MainWindow::on_ApplyAll_clicked()
{
    //set all variables
    irrRenderWidget->particleManager->setColorBright(colorPickerBright->currentColor());
    irrRenderWidget->particleManager->setColorDark(colorPickerDark->currentColor());
    irrRenderWidget->particleManager->setDirection(ui->dirX->text().toFloat(),ui->dirY->text().toFloat(),ui->dirZ->text().toFloat());

    irrRenderWidget->particleManager->minStartSize = ui->lineMinScale->text().toFloat();
    irrRenderWidget->particleManager->maxStartSize = ui->lineMaxScale->text().toFloat();

    irrRenderWidget->particleManager->minRate = ui->lineMinRate->text().toFloat();
    irrRenderWidget->particleManager->maxRate = ui->lineMaxRate->text().toFloat();

    irrRenderWidget->particleManager->minTime = ui->lineMinTime->text().toFloat();
    irrRenderWidget->particleManager->maxTime = ui->lineMaxTime->text().toFloat();

    irrRenderWidget->particleManager->duration = ui->lineDuration->text().toFloat();
    irrRenderWidget->particleManager->type = ui->comboShape->currentText();

    irrRenderWidget->particleManager->boxSize.MinEdge = vector3df(ui->lineMinBoxX->text().toFloat(),ui->lineMinBoxY->text().toFloat(),ui->lineMinBoxZ->text().toFloat());
    irrRenderWidget->particleManager->boxSize.MaxEdge = vector3df(ui->lineMaxBoxX->text().toFloat(),ui->lineMaxBoxY->text().toFloat(),ui->lineMaxBoxZ->text().toFloat());

    irrRenderWidget->particleManager->sphereRadius = ui->lineSpereRadius->text().toFloat();
    //create the emitter
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
