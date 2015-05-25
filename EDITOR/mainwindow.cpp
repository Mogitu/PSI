//mainwindow.cpp

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include "IrrRenderWidget.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    colorPickerBright= new QColorDialog();
    colorPickerDark = new QColorDialog();
    colorPickerFade = new QColorDialog();
    InitIrrRenderWidget(ui->centralWidget->findChild<QWidget *>("ParticlePreviewWidget"));
    openShapeBox(ui->comboShape->currentText());
    connectInputElements();
    ui->centralWidget->findChild<QWidget *>("ParticlePreviewWidget")->installEventFilter(this);

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

    connect(ui->checkAttract,SIGNAL(stateChanged(int)),this,SLOT(applySettings()));
    connect(ui->attrX,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->attrY,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->attrZ,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->attrAttr,SIGNAL(stateChanged(int)),this,SLOT(applySettings()));
    connect(ui->attrAttrX,SIGNAL(stateChanged(int)),this,SLOT(applySettings()));
    connect(ui->attrAttrY,SIGNAL(stateChanged(int)),this,SLOT(applySettings()));
    connect(ui->attrAttrZ,SIGNAL(stateChanged(int)),this,SLOT(applySettings()));

    connect(ui->checkFade,SIGNAL(stateChanged(int)),this,SLOT(applySettings()));
    connect(ui->fadeTime,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(colorPickerFade,SIGNAL(colorSelected(QColor)),this,SLOT(applySettings()));

    connect(ui->checkGravity,SIGNAL(stateChanged(int)),this,SLOT(applySettings()));
    connect(ui->gravX,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->gravY,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->gravZ,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->gravForcelost,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));

    connect(ui->checkRotation,SIGNAL(stateChanged(int)),this,SLOT(applySettings()));
    connect(ui->rotSpeedX,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->rotSpeedY,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->rotSpeedZ,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->rotPivotX,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->rotPivotY,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->rotPivotZ,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));

    connect(ui->checkScale,SIGNAL(stateChanged(int)),this,SLOT(applySettings()));
    connect(ui->S_Width,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->S_Height,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));

    connect(ui->lineRingRadius,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->lineRingThickness,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));

    connect(ui->lineCylinderRadius,SIGNAL(textChanged(QString)),this,SLOT(applySettings()));
    connect(ui->checkCylinderOutlineOnly,SIGNAL(stateChanged(int)),this,SLOT(applySettings()));


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

    irrRenderWidget->particleSettings->attraction = ui->checkAttract->isChecked();
    irrRenderWidget->particleSettings->setAttractionPoint(ui->attrX->text().toFloat(),ui->attrY->text().toFloat(),ui->attrZ->text().toFloat());
    irrRenderWidget->particleSettings->attraction_attract = ui->attrAttr->isChecked();
    irrRenderWidget->particleSettings->attraction_affectX = ui->attrAttrX->isChecked();
    irrRenderWidget->particleSettings->attraction_affectY = ui->attrAttrY->isChecked();
    irrRenderWidget->particleSettings->attraction_affectZ = ui->attrAttrZ->isChecked();

    irrRenderWidget->particleSettings->fade = ui->checkFade->isChecked();
    irrRenderWidget->particleSettings->fade_timeNeededToFadeOut = ui->fadeTime->text().toFloat();
    irrRenderWidget->particleSettings->setColorFade(colorPickerFade->currentColor());

    irrRenderWidget->particleSettings->gravity = ui->checkGravity->isChecked();
    irrRenderWidget->particleSettings->setGravity(ui->gravX->text().toFloat(), ui->gravY->text().toFloat(), ui->gravZ->text().toFloat());
    irrRenderWidget->particleSettings->gravity_timeForceLost = ui->gravForcelost->text().toFloat();

    irrRenderWidget->particleSettings->rotation = ui->checkRotation->isChecked();
    irrRenderWidget->particleSettings->setRotation(ui->rotPivotX->text().toFloat(), ui->rotPivotY->text().toFloat(), ui->rotPivotZ->text().toFloat());
    irrRenderWidget->particleSettings->setRotationspeed(ui->rotSpeedX->text().toFloat(), ui->rotSpeedY->text().toFloat(), ui->rotSpeedZ->text().toFloat());

    irrRenderWidget->particleSettings->scaleAF = ui->checkScale->isChecked();
    irrRenderWidget->particleSettings->scale_scaleTo.Width = ui->S_Width->text().toFloat();
    irrRenderWidget->particleSettings->scale_scaleTo.Height = ui->S_Height->text().toFloat();

    //ring settings
    irrRenderWidget->particleSettings->ringRadius=ui->lineRingRadius->text().toFloat();
    irrRenderWidget->particleSettings->ringThickness=ui->lineRingThickness->text().toFloat();

    //cylinder settings
    irrRenderWidget->particleSettings->cylinderRadius =ui->lineCylinderRadius->text().toFloat();
    irrRenderWidget->particleSettings->cylinderOutLineOnly = ui->checkCylinderOutlineOnly->isChecked();


    //create the emitter
    irrRenderWidget->particleSettings->createEmitter();

    //apply affectors
    irrRenderWidget->particleSettings->createAffector();
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

void MainWindow::on_FadeColor_clicked()
{
    colorPickerFade->open();
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
        ui->groupPointSettings->setVisible(false);
        ui->groupRingSettings->setVisible(false);
        ui->groupCylinderSettings->setVisible(false);
    }
    else if(text.toStdString() == "sphere")
    {
        ui->groupSphereSettings->setVisible(true);
        ui->groupBoxSettings->setVisible(false);
        ui->groupPointSettings->setVisible(false);
        ui->groupRingSettings->setVisible(false);
        ui->groupCylinderSettings->setVisible(false);
    }
    else if(text.toStdString() == "cylinder")
    {
        ui->groupCylinderSettings->setVisible(true);
        ui->groupSphereSettings->setVisible(false);
        ui->groupBoxSettings->setVisible(false);
        ui->groupPointSettings->setVisible(false);
        ui->groupRingSettings->setVisible(false);
    }
    else if(text.toStdString() == "ring")
    {
        ui->groupCylinderSettings->setVisible(false);
        ui->groupSphereSettings->setVisible(false);
        ui->groupBoxSettings->setVisible(false);
        ui->groupPointSettings->setVisible(false);
        ui->groupRingSettings->setVisible(true);
    }
    else if(text.toStdString() == "point")
    {
        ui->groupCylinderSettings->setVisible(false);
        ui->groupSphereSettings->setVisible(false);
        ui->groupBoxSettings->setVisible(false);
        ui->groupPointSettings->setVisible(true);
        ui->groupRingSettings->setVisible(false);
    }
    applySettings();
}

bool MainWindow::eventFilter(QObject *obj, QEvent *event)
{
    switch(event->type())
    {
        case QEvent::MouseButtonPress:
            irrRenderWidget->mouseDown=true;
            irrRenderWidget->pos = ((QMouseEvent*)event)->globalPos();
            qDebug()<<"mouse down";
            return true;
            break;
        case QEvent::MouseButtonRelease:
            irrRenderWidget->mouseDown=false;
            qDebug()<<"mouse release";
            return true;
            break;
        case QEvent::MouseMove:
            if(irrRenderWidget->mouseDown){
                //position of mouse during the drag/move
                QPoint newPos = ((QMouseEvent*)event)->globalPos();
                //find difference in positions
                f32 diffX= newPos.x()- irrRenderWidget->pos.x();
                f32 diffY= newPos.y()- irrRenderWidget->pos.y();
                //find the direction of the drag by normalising the x and y components
                vector3df dir(diffX,diffY,0);
                dir.normalize();
                //translate to new position
                irrRenderWidget->camera->translate(-0.3,vector3df(dir.X,-dir.Y,0));
            }
            return true;
            break;
        case QEvent::Wheel:
            {
                f32 change = ((QWheelEvent*)event)->angleDelta().y();
                if(change>0){
                    irrRenderWidget->camera->translate(-5,vector3df(0,0,1));
                }
                else if(change<0)
                {
                    irrRenderWidget->camera->translate(5,vector3df(0,0,1));
                }
                return true;
            }
            break;
        default:
         return false;
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
