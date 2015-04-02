
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

    openShapeBox(ui->comboShape->currentText());
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
    irrRenderWidget->particleSettings->setColorBright(colorPickerBright->currentColor());
    irrRenderWidget->particleSettings->setColorDark(colorPickerDark->currentColor());
    irrRenderWidget->particleSettings->setDirection(ui->dirX->text().toFloat(),ui->dirY->text().toFloat(),ui->dirZ->text().toFloat());

    irrRenderWidget->particleSettings->minStartSize = ui->lineMinScale->text().toFloat();
    irrRenderWidget->particleSettings->maxStartSize = ui->lineMaxScale->text().toFloat();

    irrRenderWidget->particleSettings->minRate = ui->lineMinRate->text().toFloat();
    irrRenderWidget->particleSettings->maxRate = ui->lineMaxRate->text().toFloat();

    irrRenderWidget->particleSettings->minTime = ui->lineMinTime->text().toFloat();
    irrRenderWidget->particleSettings->maxTime = ui->lineMaxTime->text().toFloat();

    irrRenderWidget->particleSettings->duration = ui->lineDuration->text().toFloat();
    irrRenderWidget->particleSettings->type = ui->comboShape->currentText();

    irrRenderWidget->particleSettings->boxSize.MinEdge = vector3df(ui->lineMinBoxX->text().toFloat(),ui->lineMinBoxY->text().toFloat(),ui->lineMinBoxZ->text().toFloat());
    irrRenderWidget->particleSettings->boxSize.MaxEdge = vector3df(ui->lineMaxBoxX->text().toFloat(),ui->lineMaxBoxY->text().toFloat(),ui->lineMaxBoxZ->text().toFloat());

    irrRenderWidget->particleSettings->sphereCenter = vector3df(ui->centerBoxX->text().toFloat(), ui->centerBoxY->text().toFloat(), ui->centerBoxZ->text().toFloat());
    irrRenderWidget->particleSettings->sphereRadius = ui->lineSpereRadius->text().toFloat();
    //create the emitter
    irrRenderWidget->particleSettings->createEmitter();
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
    QString filename = QFileDialog::getSaveFileName();
    QFile f( filename );
    f.open( QIODevice::WriteOnly );
    irrRenderWidget->particleSettings->exportToFile(filename.toStdWString().c_str(),  ui);
    f.close();
}

void MainWindow::on_comboShape_currentIndexChanged(const QString &text)
{
   openShapeBox(text);
}

void MainWindow::openShapeBox(const QString text)
{
    if(text.toStdString() == "box")
    {
        ui->groupBoxSettings->setVisible(true);
        ui->groupSphereSettings->setVisible(false);
    }
    else if(text.toStdString() == "sphere")
    {
        ui->groupSphereSettings->setVisible(true);
        ui->groupBoxSettings->setVisible(false);
    }
}

void MainWindow::on_loadTexture_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, tr("Open File"));
    if(!file.isNull() && !file.isEmpty())
    {
        irrRenderWidget->particleSettings->loadTexture(file);
        ui->lineTexture->setText(file);
    }
    else
        ui->lineTexture->setText("No file found!");
}
