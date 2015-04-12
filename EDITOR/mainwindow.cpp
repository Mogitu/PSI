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
    connectInputElements();
}

MainWindow::~MainWindow()
{
    delete ui;
}

//Connect all input elements to the appropriate signals and slots.
//Example: buttons to click signals and textfields to textchanged, etc.
void MainWindow::connectInputElements(){
    connect(ui->lineMinScale,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->lineMaxScale,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->lineDuration,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));

    connect(ui->lineMinBoxX,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->lineMinBoxY,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->lineMinBoxZ,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));

    connect(ui->lineMaxBoxX,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->lineMaxBoxY,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->lineMaxBoxZ,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));

    connect(ui->centerBoxX,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->centerBoxY,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->centerBoxZ,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));

    connect(ui->lineMinRate,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->lineMaxRate,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));

    connect(ui->lineMinTime,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->lineMaxTime,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));

    connect(ui->lineSpereRadius,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));

    connect(ui->dirX,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->dirY,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->dirZ,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));

    connect(colorPickerBright,SIGNAL(colorSelected(QColor)),this,SLOT(applySettings()));
    connect(colorPickerDark,SIGNAL(colorSelected(QColor)),this,SLOT(applySettings()));

    connect(ui->lineTexture, SIGNAL(textChanged(QString)), this, SLOT(applySettings()));
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
void MainWindow::applySettings()
{
    //set all variables

    irrRenderWidget->particleSettings->imagepath= ui->lineTexture->text().toStdString().c_str();
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

//Open dialog for darkest color
void MainWindow::on_PickDarkest_clicked()
{
    colorPickerDark->open();
}

//Opens dialog for brightest color
void MainWindow::on_PickBrightest_clicked()
{
    colorPickerBright->open();
}

//Exports all particle settings to xml
void MainWindow::on_actionExport_triggered()
{
    //set the the entered text from the dialog as filename to use when saving
    QString filename = QFileDialog::getSaveFileName();
    //create the file
    QFile f( filename );
    //open for writing
    f.open( QIODevice::WriteOnly );
    //export to xml
    irrRenderWidget->particleSettings->exportToFile(filename.toStdWString().c_str(),  ui);
    //done, close.
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
    applySettings();
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
