/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExport;
    QWidget *centralWidget;
    QWidget *ParticlePreviewWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QGroupBox *Options;
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *lblTexture;
    QLineEdit *lineTexture;
    QPushButton *loadTexture;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout;
    QLabel *labelSolid;
    QLabel *labelMinTime;
    QLineEdit *lineDuration;
    QLineEdit *lineMaxTime;
    QLabel *labelMaxTime;
    QLineEdit *lineMaxRate;
    QLabel *labelMaxRate;
    QLineEdit *lineMinRate;
    QLabel *labelMinRate;
    QLabel *labelMaxScale;
    QLabel *labelDuration;
    QLineEdit *lineMinTime;
    QLineEdit *lineMinScale;
    QLabel *labelMinScale;
    QLineEdit *lineMaxScale;
    QCheckBox *checkSolid;
    QGroupBox *groupBox;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelShapeType;
    QComboBox *comboShape;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBoxSettings;
    QLabel *labelMinBoxDimension;
    QLabel *labelMaxBoxDimension;
    QLineEdit *lineMinBoxX;
    QLineEdit *lineMinBoxY;
    QLineEdit *lineMinBoxZ;
    QLineEdit *lineMaxBoxZ;
    QLineEdit *lineMaxBoxY;
    QLineEdit *lineMaxBoxX;
    QGroupBox *groupPointSettings;
    QLabel *label_2;
    QGroupBox *groupCylinderSettings;
    QLabel *label;
    QLineEdit *lineCylinderRadius;
    QCheckBox *checkCylinderOutlineOnly;
    QGroupBox *groupRingSettings;
    QLineEdit *lineRingRadius;
    QLabel *labelRingRadius;
    QLabel *labelRingThickness;
    QLineEdit *lineRingThickness;
    QGroupBox *groupSphereSettings;
    QLineEdit *lineSpereRadius;
    QLabel *labelSphereRadius;
    QLineEdit *centerBoxY;
    QLineEdit *centerBoxZ;
    QLineEdit *centerBoxX;
    QLabel *labelCenter;
    QWidget *gridLayoutWidget_2;
    QGridLayout *gridLayout_2;
    QPushButton *PickDarkest;
    QPushButton *PickBrightest;
    QGroupBox *groupDirection;
    QLineEdit *dirX;
    QLineEdit *dirY;
    QLineEdit *dirZ;
    QLabel *labelDirection;
    QWidget *tab_2;
    QGroupBox *Affect_Options;
    QCheckBox *checkAttract;
    QGroupBox *Attract_Set;
    QWidget *horizontalLayoutWidget_4;
    QHBoxLayout *horizontalLayout_5;
    QLabel *attrXlabel;
    QLineEdit *attrX;
    QLabel *attrYlabel;
    QLineEdit *attrY;
    QLabel *attrZlabel;
    QLineEdit *attrZ;
    QLabel *attrSpdlabel;
    QLineEdit *attrSpeed;
    QLabel *attrAttrlabel;
    QCheckBox *attrAttr;
    QWidget *horizontalLayoutWidget_5;
    QHBoxLayout *horizontalLayout_6;
    QLabel *attrAttrXlabel;
    QCheckBox *attrAttrX;
    QLabel *attrAttrYlabel;
    QCheckBox *attrAttrY;
    QLabel *attrAttrZlabel;
    QCheckBox *attrAttrZ;
    QCheckBox *checkScale;
    QGroupBox *Scale_Options;
    QWidget *horizontalLayoutWidget_6;
    QHBoxLayout *horizontalLayout_7;
    QLabel *S_Widthlabel;
    QLineEdit *S_Width;
    QLabel *S_Heightlabel;
    QLineEdit *S_Height;
    QCheckBox *checkFade;
    QGroupBox *Fade_Options;
    QWidget *horizontalLayoutWidget_7;
    QHBoxLayout *horizontalLayout_8;
    QLabel *fadeTimelabel;
    QLineEdit *fadeTime;
    QPushButton *FadeColor;
    QGroupBox *Gravity_Options;
    QWidget *horizontalLayoutWidget_8;
    QHBoxLayout *horizontalLayout_9;
    QLabel *gravXlabel;
    QLineEdit *gravX;
    QLabel *gravYlabel;
    QLineEdit *gravY;
    QLabel *gravZlabel;
    QLineEdit *gravZ;
    QWidget *horizontalLayoutWidget_9;
    QHBoxLayout *horizontalLayout_10;
    QLabel *gravForcelostlabel;
    QLineEdit *gravForcelost;
    QCheckBox *checkGravity;
    QCheckBox *checkRotation;
    QGroupBox *Rotation_Options;
    QWidget *horizontalLayoutWidget_10;
    QHBoxLayout *horizontalLayout_11;
    QLabel *rotSpeedXlabel;
    QLineEdit *rotSpeedX;
    QLabel *rotSpeedYlabel;
    QLineEdit *rotSpeedY;
    QLabel *rotSpeedZlabel;
    QLineEdit *rotSpeedZ;
    QWidget *horizontalLayoutWidget_11;
    QHBoxLayout *horizontalLayout_12;
    QLabel *rotPivotXlabel;
    QLineEdit *rotPivotX;
    QLabel *rotPivotYlabel;
    QLineEdit *rotPivotY;
    QLabel *rotPivotZlabel;
    QLineEdit *rotPivotZ;
    QMenuBar *menuBar;
    QMenu *menuJan;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1024, 768);
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        ParticlePreviewWidget = new QWidget(centralWidget);
        ParticlePreviewWidget->setObjectName(QStringLiteral("ParticlePreviewWidget"));
        ParticlePreviewWidget->setGeometry(QRect(520, 30, 491, 491));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(10, 10, 501, 511));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        Options = new QGroupBox(tab);
        Options->setObjectName(QStringLiteral("Options"));
        Options->setGeometry(QRect(10, 10, 471, 471));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        Options->setFont(font);
        horizontalLayoutWidget = new QWidget(Options);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(10, 20, 451, 31));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        lblTexture = new QLabel(horizontalLayoutWidget);
        lblTexture->setObjectName(QStringLiteral("lblTexture"));

        horizontalLayout->addWidget(lblTexture);

        lineTexture = new QLineEdit(horizontalLayoutWidget);
        lineTexture->setObjectName(QStringLiteral("lineTexture"));
        lineTexture->setReadOnly(true);

        horizontalLayout->addWidget(lineTexture);

        loadTexture = new QPushButton(horizontalLayoutWidget);
        loadTexture->setObjectName(QStringLiteral("loadTexture"));

        horizontalLayout->addWidget(loadTexture);

        gridLayoutWidget = new QWidget(Options);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayoutWidget->setGeometry(QRect(10, 60, 451, 141));
        gridLayout = new QGridLayout(gridLayoutWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        labelSolid = new QLabel(gridLayoutWidget);
        labelSolid->setObjectName(QStringLiteral("labelSolid"));

        gridLayout->addWidget(labelSolid, 5, 2, 1, 1);

        labelMinTime = new QLabel(gridLayoutWidget);
        labelMinTime->setObjectName(QStringLiteral("labelMinTime"));

        gridLayout->addWidget(labelMinTime, 4, 0, 1, 1);

        lineDuration = new QLineEdit(gridLayoutWidget);
        lineDuration->setObjectName(QStringLiteral("lineDuration"));

        gridLayout->addWidget(lineDuration, 5, 1, 1, 1);

        lineMaxTime = new QLineEdit(gridLayoutWidget);
        lineMaxTime->setObjectName(QStringLiteral("lineMaxTime"));

        gridLayout->addWidget(lineMaxTime, 4, 3, 1, 1);

        labelMaxTime = new QLabel(gridLayoutWidget);
        labelMaxTime->setObjectName(QStringLiteral("labelMaxTime"));

        gridLayout->addWidget(labelMaxTime, 4, 2, 1, 1);

        lineMaxRate = new QLineEdit(gridLayoutWidget);
        lineMaxRate->setObjectName(QStringLiteral("lineMaxRate"));

        gridLayout->addWidget(lineMaxRate, 2, 3, 1, 1);

        labelMaxRate = new QLabel(gridLayoutWidget);
        labelMaxRate->setObjectName(QStringLiteral("labelMaxRate"));

        gridLayout->addWidget(labelMaxRate, 2, 2, 1, 1);

        lineMinRate = new QLineEdit(gridLayoutWidget);
        lineMinRate->setObjectName(QStringLiteral("lineMinRate"));

        gridLayout->addWidget(lineMinRate, 2, 1, 1, 1);

        labelMinRate = new QLabel(gridLayoutWidget);
        labelMinRate->setObjectName(QStringLiteral("labelMinRate"));

        gridLayout->addWidget(labelMinRate, 2, 0, 1, 1);

        labelMaxScale = new QLabel(gridLayoutWidget);
        labelMaxScale->setObjectName(QStringLiteral("labelMaxScale"));

        gridLayout->addWidget(labelMaxScale, 1, 2, 1, 1);

        labelDuration = new QLabel(gridLayoutWidget);
        labelDuration->setObjectName(QStringLiteral("labelDuration"));

        gridLayout->addWidget(labelDuration, 5, 0, 1, 1);

        lineMinTime = new QLineEdit(gridLayoutWidget);
        lineMinTime->setObjectName(QStringLiteral("lineMinTime"));

        gridLayout->addWidget(lineMinTime, 4, 1, 1, 1);

        lineMinScale = new QLineEdit(gridLayoutWidget);
        lineMinScale->setObjectName(QStringLiteral("lineMinScale"));

        gridLayout->addWidget(lineMinScale, 1, 1, 1, 1);

        labelMinScale = new QLabel(gridLayoutWidget);
        labelMinScale->setObjectName(QStringLiteral("labelMinScale"));

        gridLayout->addWidget(labelMinScale, 1, 0, 1, 1);

        lineMaxScale = new QLineEdit(gridLayoutWidget);
        lineMaxScale->setObjectName(QStringLiteral("lineMaxScale"));

        gridLayout->addWidget(lineMaxScale, 1, 3, 1, 1);

        checkSolid = new QCheckBox(gridLayoutWidget);
        checkSolid->setObjectName(QStringLiteral("checkSolid"));
        checkSolid->setChecked(false);

        gridLayout->addWidget(checkSolid, 5, 3, 1, 1);

        groupBox = new QGroupBox(Options);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 300, 451, 161));
        horizontalLayoutWidget_2 = new QWidget(groupBox);
        horizontalLayoutWidget_2->setObjectName(QStringLiteral("horizontalLayoutWidget_2"));
        horizontalLayoutWidget_2->setGeometry(QRect(10, 10, 431, 31));
        horizontalLayout_2 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        labelShapeType = new QLabel(horizontalLayoutWidget_2);
        labelShapeType->setObjectName(QStringLiteral("labelShapeType"));

        horizontalLayout_2->addWidget(labelShapeType);

        comboShape = new QComboBox(horizontalLayoutWidget_2);
        comboShape->setObjectName(QStringLiteral("comboShape"));

        horizontalLayout_2->addWidget(comboShape);

        horizontalLayoutWidget_3 = new QWidget(groupBox);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayoutWidget_3->setGeometry(QRect(10, 40, 462, 111));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        groupBoxSettings = new QGroupBox(horizontalLayoutWidget_3);
        groupBoxSettings->setObjectName(QStringLiteral("groupBoxSettings"));
        labelMinBoxDimension = new QLabel(groupBoxSettings);
        labelMinBoxDimension->setObjectName(QStringLiteral("labelMinBoxDimension"));
        labelMinBoxDimension->setGeometry(QRect(10, 20, 91, 16));
        labelMaxBoxDimension = new QLabel(groupBoxSettings);
        labelMaxBoxDimension->setObjectName(QStringLiteral("labelMaxBoxDimension"));
        labelMaxBoxDimension->setGeometry(QRect(10, 60, 91, 16));
        lineMinBoxX = new QLineEdit(groupBoxSettings);
        lineMinBoxX->setObjectName(QStringLiteral("lineMinBoxX"));
        lineMinBoxX->setGeometry(QRect(10, 40, 31, 20));
        lineMinBoxY = new QLineEdit(groupBoxSettings);
        lineMinBoxY->setObjectName(QStringLiteral("lineMinBoxY"));
        lineMinBoxY->setGeometry(QRect(50, 40, 31, 20));
        lineMinBoxZ = new QLineEdit(groupBoxSettings);
        lineMinBoxZ->setObjectName(QStringLiteral("lineMinBoxZ"));
        lineMinBoxZ->setGeometry(QRect(100, 40, 31, 20));
        lineMaxBoxZ = new QLineEdit(groupBoxSettings);
        lineMaxBoxZ->setObjectName(QStringLiteral("lineMaxBoxZ"));
        lineMaxBoxZ->setGeometry(QRect(100, 80, 31, 20));
        lineMaxBoxY = new QLineEdit(groupBoxSettings);
        lineMaxBoxY->setObjectName(QStringLiteral("lineMaxBoxY"));
        lineMaxBoxY->setGeometry(QRect(50, 80, 31, 20));
        lineMaxBoxX = new QLineEdit(groupBoxSettings);
        lineMaxBoxX->setObjectName(QStringLiteral("lineMaxBoxX"));
        lineMaxBoxX->setGeometry(QRect(10, 80, 31, 20));

        horizontalLayout_3->addWidget(groupBoxSettings);

        groupPointSettings = new QGroupBox(horizontalLayoutWidget_3);
        groupPointSettings->setObjectName(QStringLiteral("groupPointSettings"));
        label_2 = new QLabel(groupPointSettings);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 151, 16));
        QFont font1;
        font1.setBold(true);
        font1.setItalic(true);
        font1.setWeight(75);
        label_2->setFont(font1);

        horizontalLayout_3->addWidget(groupPointSettings);

        groupCylinderSettings = new QGroupBox(horizontalLayoutWidget_3);
        groupCylinderSettings->setObjectName(QStringLiteral("groupCylinderSettings"));
        label = new QLabel(groupCylinderSettings);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 47, 13));
        lineCylinderRadius = new QLineEdit(groupCylinderSettings);
        lineCylinderRadius->setObjectName(QStringLiteral("lineCylinderRadius"));
        lineCylinderRadius->setGeometry(QRect(10, 40, 61, 20));
        checkCylinderOutlineOnly = new QCheckBox(groupCylinderSettings);
        checkCylinderOutlineOnly->setObjectName(QStringLiteral("checkCylinderOutlineOnly"));
        checkCylinderOutlineOnly->setGeometry(QRect(10, 70, 101, 17));

        horizontalLayout_3->addWidget(groupCylinderSettings);

        groupRingSettings = new QGroupBox(horizontalLayoutWidget_3);
        groupRingSettings->setObjectName(QStringLiteral("groupRingSettings"));
        lineRingRadius = new QLineEdit(groupRingSettings);
        lineRingRadius->setObjectName(QStringLiteral("lineRingRadius"));
        lineRingRadius->setGeometry(QRect(10, 40, 51, 20));
        labelRingRadius = new QLabel(groupRingSettings);
        labelRingRadius->setObjectName(QStringLiteral("labelRingRadius"));
        labelRingRadius->setGeometry(QRect(10, 20, 47, 13));
        labelRingThickness = new QLabel(groupRingSettings);
        labelRingThickness->setObjectName(QStringLiteral("labelRingThickness"));
        labelRingThickness->setGeometry(QRect(10, 60, 47, 13));
        lineRingThickness = new QLineEdit(groupRingSettings);
        lineRingThickness->setObjectName(QStringLiteral("lineRingThickness"));
        lineRingThickness->setGeometry(QRect(10, 80, 51, 20));

        horizontalLayout_3->addWidget(groupRingSettings);

        groupSphereSettings = new QGroupBox(horizontalLayoutWidget_3);
        groupSphereSettings->setObjectName(QStringLiteral("groupSphereSettings"));
        groupSphereSettings->setEnabled(true);
        lineSpereRadius = new QLineEdit(groupSphereSettings);
        lineSpereRadius->setObjectName(QStringLiteral("lineSpereRadius"));
        lineSpereRadius->setGeometry(QRect(10, 40, 31, 20));
        labelSphereRadius = new QLabel(groupSphereSettings);
        labelSphereRadius->setObjectName(QStringLiteral("labelSphereRadius"));
        labelSphereRadius->setGeometry(QRect(10, 20, 41, 16));
        centerBoxY = new QLineEdit(groupSphereSettings);
        centerBoxY->setObjectName(QStringLiteral("centerBoxY"));
        centerBoxY->setGeometry(QRect(50, 80, 31, 20));
        centerBoxZ = new QLineEdit(groupSphereSettings);
        centerBoxZ->setObjectName(QStringLiteral("centerBoxZ"));
        centerBoxZ->setGeometry(QRect(100, 80, 31, 20));
        centerBoxX = new QLineEdit(groupSphereSettings);
        centerBoxX->setObjectName(QStringLiteral("centerBoxX"));
        centerBoxX->setGeometry(QRect(10, 80, 31, 20));
        labelCenter = new QLabel(groupSphereSettings);
        labelCenter->setObjectName(QStringLiteral("labelCenter"));
        labelCenter->setGeometry(QRect(10, 60, 47, 13));

        horizontalLayout_3->addWidget(groupSphereSettings);

        gridLayoutWidget_2 = new QWidget(Options);
        gridLayoutWidget_2->setObjectName(QStringLiteral("gridLayoutWidget_2"));
        gridLayoutWidget_2->setGeometry(QRect(9, 210, 451, 91));
        gridLayout_2 = new QGridLayout(gridLayoutWidget_2);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_2->setContentsMargins(0, 0, 0, 0);
        PickDarkest = new QPushButton(gridLayoutWidget_2);
        PickDarkest->setObjectName(QStringLiteral("PickDarkest"));

        gridLayout_2->addWidget(PickDarkest, 0, 1, 1, 1);

        PickBrightest = new QPushButton(gridLayoutWidget_2);
        PickBrightest->setObjectName(QStringLiteral("PickBrightest"));

        gridLayout_2->addWidget(PickBrightest, 1, 1, 1, 1);

        groupDirection = new QGroupBox(gridLayoutWidget_2);
        groupDirection->setObjectName(QStringLiteral("groupDirection"));
        dirX = new QLineEdit(groupDirection);
        dirX->setObjectName(QStringLiteral("dirX"));
        dirX->setGeometry(QRect(10, 40, 31, 20));
        dirY = new QLineEdit(groupDirection);
        dirY->setObjectName(QStringLiteral("dirY"));
        dirY->setGeometry(QRect(60, 40, 31, 20));
        dirZ = new QLineEdit(groupDirection);
        dirZ->setObjectName(QStringLiteral("dirZ"));
        dirZ->setGeometry(QRect(110, 40, 31, 20));
        labelDirection = new QLabel(groupDirection);
        labelDirection->setObjectName(QStringLiteral("labelDirection"));
        labelDirection->setGeometry(QRect(20, 20, 111, 16));

        gridLayout_2->addWidget(groupDirection, 0, 0, 2, 1);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        Affect_Options = new QGroupBox(tab_2);
        Affect_Options->setObjectName(QStringLiteral("Affect_Options"));
        Affect_Options->setGeometry(QRect(10, 10, 471, 461));
        checkAttract = new QCheckBox(Affect_Options);
        checkAttract->setObjectName(QStringLiteral("checkAttract"));
        checkAttract->setEnabled(true);
        checkAttract->setGeometry(QRect(20, 30, 70, 17));
        checkAttract->setTristate(false);
        Attract_Set = new QGroupBox(Affect_Options);
        Attract_Set->setObjectName(QStringLiteral("Attract_Set"));
        Attract_Set->setGeometry(QRect(100, 10, 361, 91));
        horizontalLayoutWidget_4 = new QWidget(Attract_Set);
        horizontalLayoutWidget_4->setObjectName(QStringLiteral("horizontalLayoutWidget_4"));
        horizontalLayoutWidget_4->setGeometry(QRect(10, 20, 351, 31));
        horizontalLayout_5 = new QHBoxLayout(horizontalLayoutWidget_4);
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        attrXlabel = new QLabel(horizontalLayoutWidget_4);
        attrXlabel->setObjectName(QStringLiteral("attrXlabel"));

        horizontalLayout_5->addWidget(attrXlabel);

        attrX = new QLineEdit(horizontalLayoutWidget_4);
        attrX->setObjectName(QStringLiteral("attrX"));
        attrX->setClearButtonEnabled(false);

        horizontalLayout_5->addWidget(attrX);

        attrYlabel = new QLabel(horizontalLayoutWidget_4);
        attrYlabel->setObjectName(QStringLiteral("attrYlabel"));

        horizontalLayout_5->addWidget(attrYlabel);

        attrY = new QLineEdit(horizontalLayoutWidget_4);
        attrY->setObjectName(QStringLiteral("attrY"));

        horizontalLayout_5->addWidget(attrY);

        attrZlabel = new QLabel(horizontalLayoutWidget_4);
        attrZlabel->setObjectName(QStringLiteral("attrZlabel"));

        horizontalLayout_5->addWidget(attrZlabel);

        attrZ = new QLineEdit(horizontalLayoutWidget_4);
        attrZ->setObjectName(QStringLiteral("attrZ"));

        horizontalLayout_5->addWidget(attrZ);

        attrSpdlabel = new QLabel(horizontalLayoutWidget_4);
        attrSpdlabel->setObjectName(QStringLiteral("attrSpdlabel"));

        horizontalLayout_5->addWidget(attrSpdlabel);

        attrSpeed = new QLineEdit(horizontalLayoutWidget_4);
        attrSpeed->setObjectName(QStringLiteral("attrSpeed"));

        horizontalLayout_5->addWidget(attrSpeed);

        attrAttrlabel = new QLabel(horizontalLayoutWidget_4);
        attrAttrlabel->setObjectName(QStringLiteral("attrAttrlabel"));

        horizontalLayout_5->addWidget(attrAttrlabel);

        attrAttr = new QCheckBox(horizontalLayoutWidget_4);
        attrAttr->setObjectName(QStringLiteral("attrAttr"));

        horizontalLayout_5->addWidget(attrAttr);

        horizontalLayoutWidget_5 = new QWidget(Attract_Set);
        horizontalLayoutWidget_5->setObjectName(QStringLiteral("horizontalLayoutWidget_5"));
        horizontalLayoutWidget_5->setGeometry(QRect(10, 50, 301, 31));
        horizontalLayout_6 = new QHBoxLayout(horizontalLayoutWidget_5);
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        horizontalLayout_6->setContentsMargins(0, 0, 0, 0);
        attrAttrXlabel = new QLabel(horizontalLayoutWidget_5);
        attrAttrXlabel->setObjectName(QStringLiteral("attrAttrXlabel"));

        horizontalLayout_6->addWidget(attrAttrXlabel);

        attrAttrX = new QCheckBox(horizontalLayoutWidget_5);
        attrAttrX->setObjectName(QStringLiteral("attrAttrX"));

        horizontalLayout_6->addWidget(attrAttrX);

        attrAttrYlabel = new QLabel(horizontalLayoutWidget_5);
        attrAttrYlabel->setObjectName(QStringLiteral("attrAttrYlabel"));

        horizontalLayout_6->addWidget(attrAttrYlabel);

        attrAttrY = new QCheckBox(horizontalLayoutWidget_5);
        attrAttrY->setObjectName(QStringLiteral("attrAttrY"));

        horizontalLayout_6->addWidget(attrAttrY);

        attrAttrZlabel = new QLabel(horizontalLayoutWidget_5);
        attrAttrZlabel->setObjectName(QStringLiteral("attrAttrZlabel"));

        horizontalLayout_6->addWidget(attrAttrZlabel);

        attrAttrZ = new QCheckBox(horizontalLayoutWidget_5);
        attrAttrZ->setObjectName(QStringLiteral("attrAttrZ"));

        horizontalLayout_6->addWidget(attrAttrZ);

        checkScale = new QCheckBox(Affect_Options);
        checkScale->setObjectName(QStringLiteral("checkScale"));
        checkScale->setGeometry(QRect(20, 420, 51, 17));
        Scale_Options = new QGroupBox(Affect_Options);
        Scale_Options->setObjectName(QStringLiteral("Scale_Options"));
        Scale_Options->setGeometry(QRect(100, 400, 361, 51));
        horizontalLayoutWidget_6 = new QWidget(Scale_Options);
        horizontalLayoutWidget_6->setObjectName(QStringLiteral("horizontalLayoutWidget_6"));
        horizontalLayoutWidget_6->setGeometry(QRect(10, 20, 187, 22));
        horizontalLayout_7 = new QHBoxLayout(horizontalLayoutWidget_6);
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_7->setObjectName(QStringLiteral("horizontalLayout_7"));
        horizontalLayout_7->setContentsMargins(0, 0, 0, 0);
        S_Widthlabel = new QLabel(horizontalLayoutWidget_6);
        S_Widthlabel->setObjectName(QStringLiteral("S_Widthlabel"));

        horizontalLayout_7->addWidget(S_Widthlabel);

        S_Width = new QLineEdit(horizontalLayoutWidget_6);
        S_Width->setObjectName(QStringLiteral("S_Width"));

        horizontalLayout_7->addWidget(S_Width);

        S_Heightlabel = new QLabel(horizontalLayoutWidget_6);
        S_Heightlabel->setObjectName(QStringLiteral("S_Heightlabel"));

        horizontalLayout_7->addWidget(S_Heightlabel);

        S_Height = new QLineEdit(horizontalLayoutWidget_6);
        S_Height->setObjectName(QStringLiteral("S_Height"));

        horizontalLayout_7->addWidget(S_Height);

        checkFade = new QCheckBox(Affect_Options);
        checkFade->setObjectName(QStringLiteral("checkFade"));
        checkFade->setGeometry(QRect(20, 110, 51, 17));
        Fade_Options = new QGroupBox(Affect_Options);
        Fade_Options->setObjectName(QStringLiteral("Fade_Options"));
        Fade_Options->setGeometry(QRect(100, 110, 361, 71));
        horizontalLayoutWidget_7 = new QWidget(Fade_Options);
        horizontalLayoutWidget_7->setObjectName(QStringLiteral("horizontalLayoutWidget_7"));
        horizontalLayoutWidget_7->setGeometry(QRect(10, 20, 219, 31));
        horizontalLayout_8 = new QHBoxLayout(horizontalLayoutWidget_7);
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_8->setObjectName(QStringLiteral("horizontalLayout_8"));
        horizontalLayout_8->setContentsMargins(0, 0, 0, 0);
        fadeTimelabel = new QLabel(horizontalLayoutWidget_7);
        fadeTimelabel->setObjectName(QStringLiteral("fadeTimelabel"));

        horizontalLayout_8->addWidget(fadeTimelabel);

        fadeTime = new QLineEdit(horizontalLayoutWidget_7);
        fadeTime->setObjectName(QStringLiteral("fadeTime"));

        horizontalLayout_8->addWidget(fadeTime);

        FadeColor = new QPushButton(horizontalLayoutWidget_7);
        FadeColor->setObjectName(QStringLiteral("FadeColor"));

        horizontalLayout_8->addWidget(FadeColor);

        Gravity_Options = new QGroupBox(Affect_Options);
        Gravity_Options->setObjectName(QStringLiteral("Gravity_Options"));
        Gravity_Options->setGeometry(QRect(100, 190, 361, 101));
        horizontalLayoutWidget_8 = new QWidget(Gravity_Options);
        horizontalLayoutWidget_8->setObjectName(QStringLiteral("horizontalLayoutWidget_8"));
        horizontalLayoutWidget_8->setGeometry(QRect(10, 30, 212, 31));
        horizontalLayout_9 = new QHBoxLayout(horizontalLayoutWidget_8);
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_9->setObjectName(QStringLiteral("horizontalLayout_9"));
        horizontalLayout_9->setContentsMargins(0, 0, 0, 0);
        gravXlabel = new QLabel(horizontalLayoutWidget_8);
        gravXlabel->setObjectName(QStringLiteral("gravXlabel"));

        horizontalLayout_9->addWidget(gravXlabel);

        gravX = new QLineEdit(horizontalLayoutWidget_8);
        gravX->setObjectName(QStringLiteral("gravX"));

        horizontalLayout_9->addWidget(gravX);

        gravYlabel = new QLabel(horizontalLayoutWidget_8);
        gravYlabel->setObjectName(QStringLiteral("gravYlabel"));

        horizontalLayout_9->addWidget(gravYlabel);

        gravY = new QLineEdit(horizontalLayoutWidget_8);
        gravY->setObjectName(QStringLiteral("gravY"));

        horizontalLayout_9->addWidget(gravY);

        gravZlabel = new QLabel(horizontalLayoutWidget_8);
        gravZlabel->setObjectName(QStringLiteral("gravZlabel"));

        horizontalLayout_9->addWidget(gravZlabel);

        gravZ = new QLineEdit(horizontalLayoutWidget_8);
        gravZ->setObjectName(QStringLiteral("gravZ"));

        horizontalLayout_9->addWidget(gravZ);

        horizontalLayoutWidget_9 = new QWidget(Gravity_Options);
        horizontalLayoutWidget_9->setObjectName(QStringLiteral("horizontalLayoutWidget_9"));
        horizontalLayoutWidget_9->setGeometry(QRect(10, 60, 211, 31));
        horizontalLayout_10 = new QHBoxLayout(horizontalLayoutWidget_9);
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QStringLiteral("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        gravForcelostlabel = new QLabel(horizontalLayoutWidget_9);
        gravForcelostlabel->setObjectName(QStringLiteral("gravForcelostlabel"));

        horizontalLayout_10->addWidget(gravForcelostlabel);

        gravForcelost = new QLineEdit(horizontalLayoutWidget_9);
        gravForcelost->setObjectName(QStringLiteral("gravForcelost"));

        horizontalLayout_10->addWidget(gravForcelost);

        checkGravity = new QCheckBox(Affect_Options);
        checkGravity->setObjectName(QStringLiteral("checkGravity"));
        checkGravity->setGeometry(QRect(20, 190, 70, 17));
        checkRotation = new QCheckBox(Affect_Options);
        checkRotation->setObjectName(QStringLiteral("checkRotation"));
        checkRotation->setGeometry(QRect(20, 300, 70, 17));
        Rotation_Options = new QGroupBox(Affect_Options);
        Rotation_Options->setObjectName(QStringLiteral("Rotation_Options"));
        Rotation_Options->setGeometry(QRect(100, 300, 361, 101));
        horizontalLayoutWidget_10 = new QWidget(Rotation_Options);
        horizontalLayoutWidget_10->setObjectName(QStringLiteral("horizontalLayoutWidget_10"));
        horizontalLayoutWidget_10->setGeometry(QRect(20, 20, 321, 31));
        horizontalLayout_11 = new QHBoxLayout(horizontalLayoutWidget_10);
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_11->setObjectName(QStringLiteral("horizontalLayout_11"));
        horizontalLayout_11->setContentsMargins(0, 0, 0, 0);
        rotSpeedXlabel = new QLabel(horizontalLayoutWidget_10);
        rotSpeedXlabel->setObjectName(QStringLiteral("rotSpeedXlabel"));

        horizontalLayout_11->addWidget(rotSpeedXlabel);

        rotSpeedX = new QLineEdit(horizontalLayoutWidget_10);
        rotSpeedX->setObjectName(QStringLiteral("rotSpeedX"));

        horizontalLayout_11->addWidget(rotSpeedX);

        rotSpeedYlabel = new QLabel(horizontalLayoutWidget_10);
        rotSpeedYlabel->setObjectName(QStringLiteral("rotSpeedYlabel"));

        horizontalLayout_11->addWidget(rotSpeedYlabel);

        rotSpeedY = new QLineEdit(horizontalLayoutWidget_10);
        rotSpeedY->setObjectName(QStringLiteral("rotSpeedY"));

        horizontalLayout_11->addWidget(rotSpeedY);

        rotSpeedZlabel = new QLabel(horizontalLayoutWidget_10);
        rotSpeedZlabel->setObjectName(QStringLiteral("rotSpeedZlabel"));

        horizontalLayout_11->addWidget(rotSpeedZlabel);

        rotSpeedZ = new QLineEdit(horizontalLayoutWidget_10);
        rotSpeedZ->setObjectName(QStringLiteral("rotSpeedZ"));

        horizontalLayout_11->addWidget(rotSpeedZ);

        horizontalLayoutWidget_11 = new QWidget(Rotation_Options);
        horizontalLayoutWidget_11->setObjectName(QStringLiteral("horizontalLayoutWidget_11"));
        horizontalLayoutWidget_11->setGeometry(QRect(20, 50, 321, 31));
        horizontalLayout_12 = new QHBoxLayout(horizontalLayoutWidget_11);
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_12->setObjectName(QStringLiteral("horizontalLayout_12"));
        horizontalLayout_12->setContentsMargins(0, 0, 0, 0);
        rotPivotXlabel = new QLabel(horizontalLayoutWidget_11);
        rotPivotXlabel->setObjectName(QStringLiteral("rotPivotXlabel"));

        horizontalLayout_12->addWidget(rotPivotXlabel);

        rotPivotX = new QLineEdit(horizontalLayoutWidget_11);
        rotPivotX->setObjectName(QStringLiteral("rotPivotX"));

        horizontalLayout_12->addWidget(rotPivotX);

        rotPivotYlabel = new QLabel(horizontalLayoutWidget_11);
        rotPivotYlabel->setObjectName(QStringLiteral("rotPivotYlabel"));

        horizontalLayout_12->addWidget(rotPivotYlabel);

        rotPivotY = new QLineEdit(horizontalLayoutWidget_11);
        rotPivotY->setObjectName(QStringLiteral("rotPivotY"));

        horizontalLayout_12->addWidget(rotPivotY);

        rotPivotZlabel = new QLabel(horizontalLayoutWidget_11);
        rotPivotZlabel->setObjectName(QStringLiteral("rotPivotZlabel"));

        horizontalLayout_12->addWidget(rotPivotZlabel);

        rotPivotZ = new QLineEdit(horizontalLayoutWidget_11);
        rotPivotZ->setObjectName(QStringLiteral("rotPivotZ"));

        horizontalLayout_12->addWidget(rotPivotZ);

        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1024, 21));
        menuJan = new QMenu(menuBar);
        menuJan->setObjectName(QStringLiteral("menuJan"));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuJan->menuAction());
        menuJan->addAction(actionExport);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Particle Editor Alpha", 0));
        actionExport->setText(QApplication::translate("MainWindow", "Export", 0));
        Options->setTitle(QApplication::translate("MainWindow", "Settings", 0));
        lblTexture->setText(QApplication::translate("MainWindow", "Texture", 0));
        loadTexture->setText(QApplication::translate("MainWindow", "Load", 0));
        labelSolid->setText(QApplication::translate("MainWindow", "Solid", 0));
        labelMinTime->setText(QApplication::translate("MainWindow", "Min Time", 0));
#ifndef QT_NO_TOOLTIP
        lineDuration->setToolTip(QApplication::translate("MainWindow", "Biggest scale of particles", 0));
#endif // QT_NO_TOOLTIP
        lineDuration->setText(QApplication::translate("MainWindow", "2000", 0));
#ifndef QT_NO_TOOLTIP
        lineMaxTime->setToolTip(QApplication::translate("MainWindow", "Biggest scale of particles", 0));
#endif // QT_NO_TOOLTIP
        lineMaxTime->setText(QApplication::translate("MainWindow", "1000", 0));
        labelMaxTime->setText(QApplication::translate("MainWindow", "Max Time", 0));
#ifndef QT_NO_TOOLTIP
        lineMaxRate->setToolTip(QApplication::translate("MainWindow", "Biggest scale of particles", 0));
#endif // QT_NO_TOOLTIP
        lineMaxRate->setText(QApplication::translate("MainWindow", "200", 0));
        labelMaxRate->setText(QApplication::translate("MainWindow", "Max Rate", 0));
#ifndef QT_NO_TOOLTIP
        lineMinRate->setToolTip(QApplication::translate("MainWindow", "Biggest scale of particles", 0));
#endif // QT_NO_TOOLTIP
        lineMinRate->setText(QApplication::translate("MainWindow", "100", 0));
        labelMinRate->setText(QApplication::translate("MainWindow", "Min Rate", 0));
        labelMaxScale->setText(QApplication::translate("MainWindow", "Max Scale", 0));
        labelDuration->setText(QApplication::translate("MainWindow", "Duration", 0));
#ifndef QT_NO_TOOLTIP
        lineMinTime->setToolTip(QApplication::translate("MainWindow", "Biggest scale of particles", 0));
#endif // QT_NO_TOOLTIP
        lineMinTime->setText(QApplication::translate("MainWindow", "500", 0));
#ifndef QT_NO_TOOLTIP
        lineMinScale->setToolTip(QApplication::translate("MainWindow", "Smallest scale of the particles", 0));
#endif // QT_NO_TOOLTIP
        lineMinScale->setText(QApplication::translate("MainWindow", "1", 0));
        labelMinScale->setText(QApplication::translate("MainWindow", "Min Scale", 0));
#ifndef QT_NO_TOOLTIP
        lineMaxScale->setToolTip(QApplication::translate("MainWindow", "Biggest scale of particles", 0));
#endif // QT_NO_TOOLTIP
        lineMaxScale->setText(QApplication::translate("MainWindow", "2", 0));
        checkSolid->setText(QString());
        groupBox->setTitle(QApplication::translate("MainWindow", "Shape", 0));
        labelShapeType->setText(QApplication::translate("MainWindow", "Shape Type:", 0));
        comboShape->clear();
        comboShape->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "box", 0)
         << QApplication::translate("MainWindow", "sphere", 0)
         << QApplication::translate("MainWindow", "ring", 0)
         << QApplication::translate("MainWindow", "cylinder", 0)
         << QApplication::translate("MainWindow", "point", 0)
        );
        groupBoxSettings->setTitle(QApplication::translate("MainWindow", "Box settings", 0));
        labelMinBoxDimension->setText(QApplication::translate("MainWindow", "Min dimensions", 0));
        labelMaxBoxDimension->setText(QApplication::translate("MainWindow", "Max dimensions", 0));
        lineMinBoxX->setText(QApplication::translate("MainWindow", "-7", 0));
        lineMinBoxY->setText(QApplication::translate("MainWindow", "0", 0));
        lineMinBoxZ->setText(QApplication::translate("MainWindow", "-7", 0));
        lineMaxBoxZ->setText(QApplication::translate("MainWindow", "7", 0));
        lineMaxBoxY->setText(QApplication::translate("MainWindow", "0", 0));
        lineMaxBoxX->setText(QApplication::translate("MainWindow", "7", 0));
        groupPointSettings->setTitle(QApplication::translate("MainWindow", "Point settings", 0));
        label_2->setText(QApplication::translate("MainWindow", "NO OPTIONS AVAILABLE", 0));
        groupCylinderSettings->setTitle(QApplication::translate("MainWindow", "Cylinder settings", 0));
        label->setText(QApplication::translate("MainWindow", "Radius", 0));
        lineCylinderRadius->setText(QApplication::translate("MainWindow", "20", 0));
        checkCylinderOutlineOnly->setText(QApplication::translate("MainWindow", "Outline only", 0));
        groupRingSettings->setTitle(QApplication::translate("MainWindow", "Ring settings", 0));
        lineRingRadius->setText(QApplication::translate("MainWindow", "20", 0));
        labelRingRadius->setText(QApplication::translate("MainWindow", "Radius:", 0));
        labelRingThickness->setText(QApplication::translate("MainWindow", "Thickness", 0));
        lineRingThickness->setText(QApplication::translate("MainWindow", "20", 0));
        groupSphereSettings->setTitle(QApplication::translate("MainWindow", "Sphere settings", 0));
        lineSpereRadius->setText(QApplication::translate("MainWindow", "20", 0));
        labelSphereRadius->setText(QApplication::translate("MainWindow", "Radius", 0));
        centerBoxY->setText(QApplication::translate("MainWindow", "0", 0));
        centerBoxZ->setText(QApplication::translate("MainWindow", "0", 0));
        centerBoxX->setText(QApplication::translate("MainWindow", "0", 0));
        labelCenter->setText(QApplication::translate("MainWindow", "Center", 0));
        PickDarkest->setText(QApplication::translate("MainWindow", "Change darkest", 0));
        PickBrightest->setText(QApplication::translate("MainWindow", "Change brightest", 0));
        groupDirection->setTitle(QApplication::translate("MainWindow", "Direction", 0));
        dirX->setText(QApplication::translate("MainWindow", "0", 0));
        dirY->setText(QApplication::translate("MainWindow", "0.05", 0));
        dirZ->setText(QApplication::translate("MainWindow", "0", 0));
        labelDirection->setText(QApplication::translate("MainWindow", "X              Y                Z", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Particle", 0));
        Affect_Options->setTitle(QApplication::translate("MainWindow", "Settings", 0));
        checkAttract->setText(QApplication::translate("MainWindow", "Attraction", 0));
        Attract_Set->setTitle(QApplication::translate("MainWindow", "Attraction Settings", 0));
        attrXlabel->setText(QApplication::translate("MainWindow", "X", 0));
        attrX->setText(QApplication::translate("MainWindow", "0", 0));
        attrX->setPlaceholderText(QString());
        attrYlabel->setText(QApplication::translate("MainWindow", "Y", 0));
        attrY->setText(QApplication::translate("MainWindow", "0", 0));
        attrZlabel->setText(QApplication::translate("MainWindow", "Z", 0));
        attrZ->setText(QApplication::translate("MainWindow", "0", 0));
        attrSpdlabel->setText(QApplication::translate("MainWindow", "Speed", 0));
        attrSpeed->setText(QApplication::translate("MainWindow", "0", 0));
        attrAttrlabel->setText(QApplication::translate("MainWindow", "Attract", 0));
        attrAttr->setText(QString());
        attrAttrXlabel->setText(QApplication::translate("MainWindow", "Attract X", 0));
        attrAttrX->setText(QString());
        attrAttrYlabel->setText(QApplication::translate("MainWindow", "Attract Y", 0));
        attrAttrY->setText(QString());
        attrAttrZlabel->setText(QApplication::translate("MainWindow", "Attract Z", 0));
        attrAttrZ->setText(QString());
        checkScale->setText(QApplication::translate("MainWindow", "Scale", 0));
        Scale_Options->setTitle(QApplication::translate("MainWindow", "Scale Settings", 0));
        S_Widthlabel->setText(QApplication::translate("MainWindow", "Width", 0));
        S_Width->setText(QApplication::translate("MainWindow", "0", 0));
        S_Heightlabel->setText(QApplication::translate("MainWindow", "Height", 0));
        S_Height->setText(QApplication::translate("MainWindow", "0", 0));
        checkFade->setText(QApplication::translate("MainWindow", "Fade", 0));
        Fade_Options->setTitle(QApplication::translate("MainWindow", "Fade Settings", 0));
        fadeTimelabel->setText(QApplication::translate("MainWindow", "Fade Out Time", 0));
        fadeTime->setText(QApplication::translate("MainWindow", "0", 0));
        FadeColor->setText(QApplication::translate("MainWindow", "Pick Fade Color", 0));
        Gravity_Options->setTitle(QApplication::translate("MainWindow", "Gravity Settings", 0));
        gravXlabel->setText(QApplication::translate("MainWindow", "X", 0));
        gravX->setText(QApplication::translate("MainWindow", "0", 0));
        gravYlabel->setText(QApplication::translate("MainWindow", "Y", 0));
        gravY->setText(QApplication::translate("MainWindow", "0", 0));
        gravZlabel->setText(QApplication::translate("MainWindow", "Z", 0));
        gravZ->setText(QApplication::translate("MainWindow", "0", 0));
        gravForcelostlabel->setText(QApplication::translate("MainWindow", "Time Force Lost", 0));
        gravForcelost->setText(QApplication::translate("MainWindow", "0", 0));
        checkGravity->setText(QApplication::translate("MainWindow", "Gravity", 0));
        checkRotation->setText(QApplication::translate("MainWindow", "Rotation", 0));
        Rotation_Options->setTitle(QApplication::translate("MainWindow", "Rotation Settings", 0));
        rotSpeedXlabel->setText(QApplication::translate("MainWindow", "Speed X", 0));
        rotSpeedX->setText(QApplication::translate("MainWindow", "0", 0));
        rotSpeedYlabel->setText(QApplication::translate("MainWindow", "Speed Y", 0));
        rotSpeedY->setText(QApplication::translate("MainWindow", "0", 0));
        rotSpeedZlabel->setText(QApplication::translate("MainWindow", "Speed Z", 0));
        rotSpeedZ->setText(QApplication::translate("MainWindow", "0", 0));
        rotPivotXlabel->setText(QApplication::translate("MainWindow", "Pivot X", 0));
        rotPivotX->setText(QApplication::translate("MainWindow", "0", 0));
        rotPivotYlabel->setText(QApplication::translate("MainWindow", "Pivot Y", 0));
        rotPivotY->setText(QApplication::translate("MainWindow", "0", 0));
        rotPivotZlabel->setText(QApplication::translate("MainWindow", "Pivot Z", 0));
        rotPivotZ->setText(QApplication::translate("MainWindow", "0", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Affector", 0));
        menuJan->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
