/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
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
    QLabel *labelDuration;
    QLineEdit *lineMinTime;
    QLineEdit *lineMinScale;
    QLabel *labelMinScale;
    QLineEdit *lineMaxScale;
    QLabel *labelMaxScale;
    QLabel *labelMinTime;
    QLineEdit *lineDuration;
    QLineEdit *lineMaxTime;
    QLabel *labelMaxTime;
    QLineEdit *lineMaxRate;
    QLabel *labelMaxRate;
    QLineEdit *lineMinRate;
    QLabel *labelMinRate;
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
    QPushButton *ApplyAll;
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

        labelMaxScale = new QLabel(gridLayoutWidget);
        labelMaxScale->setObjectName(QStringLiteral("labelMaxScale"));

        gridLayout->addWidget(labelMaxScale, 1, 2, 1, 1);

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
        horizontalLayoutWidget_3->setGeometry(QRect(10, 40, 431, 111));
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
        lineSpereRadius->raise();
        labelSphereRadius->raise();
        centerBoxY->raise();
        centerBoxZ->raise();
        centerBoxX->raise();
        labelCenter->raise();
        groupBoxSettings->raise();

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
        tabWidget->addTab(tab_2, QString());
        ApplyAll = new QPushButton(centralWidget);
        ApplyAll->setObjectName(QStringLiteral("ApplyAll"));
        ApplyAll->setGeometry(QRect(400, 540, 101, 31));
        MainWindow->setCentralWidget(centralWidget);
        ParticlePreviewWidget->raise();
        tabWidget->raise();
        ApplyAll->raise();
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
        labelMaxScale->setText(QApplication::translate("MainWindow", "Max Scale", 0));
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
        groupBox->setTitle(QApplication::translate("MainWindow", "Shape", 0));
        labelShapeType->setText(QApplication::translate("MainWindow", "Shape Type:", 0));
        comboShape->clear();
        comboShape->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "box", 0)
         << QApplication::translate("MainWindow", "sphere", 0)
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
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Affector", 0));
        ApplyAll->setText(QApplication::translate("MainWindow", "Apply", 0));
        menuJan->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
