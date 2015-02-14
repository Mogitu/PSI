
//mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    d= new QColorDialog();

    //Init an Irrlicht instance and give it a target widget into where Irrlicht should show its output - here I named it "irrRenderWidget0" and "irrRenderWidget1".
    this->initIrrInstance0(ui->centralWidget->findChild<QWidget *>("irrRenderWidget0"));
    //this->initIrrInstance1(ui->centralWidget->findChild<QWidget *>("irrRenderWidget1"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initIrrInstance0(QWidget *irrRenderTarget)
{
    this->irr0 = new IrrCoreRenderer(irrRenderTarget, false);

    this->irr0->init();
}

/*
void MainWindow::initIrrInstance1(QWidget *irrRenderTarget)
{
    this->irr1 = new IrrCoreRenderer(irrRenderTarget, true);

    this->irr1->init();
}
*/


void MainWindow::resizeEvent(QResizeEvent *event)
{
   this->irr0->resizeIrrWidget(0, 0, this->size().width()/2, this->size().height());
  // this->irr1->resizeIrrWidget(this->size().width()/2, 0, this->size().width()/2, this->size().height());
}


void MainWindow::on_pushButton_clicked()
{
    //
    irr0->bright->X = d->currentColor().red();
    irr0->bright->Y = d->currentColor().green();
    irr0->bright->Z = d->currentColor().blue();

    this->irr0->minScale = ui->lineEdit->text().toFloat();
    this->irr0->createParticle();


}

void MainWindow::on_pushButton_2_clicked()
{
    this->irr0->deleteParticle();
    d->open();
}



