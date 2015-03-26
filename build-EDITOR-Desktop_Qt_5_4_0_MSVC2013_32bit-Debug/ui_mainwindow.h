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
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionExport;
    QWidget *centralWidget;
    QGroupBox *Options;
    QLineEdit *lineMinScale;
    QLineEdit *lineMaxScale;
    QPushButton *ApplyAll;
    QLabel *labelMinScale;
    QLabel *labelMaxScale;
    QComboBox *comboShape;
    QLabel *labelShape;
    QPushButton *PickBrightest;
    QPushButton *PickDarkest;
    QGroupBox *groupDirection;
    QLineEdit *dirX;
    QLineEdit *dirY;
    QLineEdit *dirZ;
    QLabel *labelDirection;
    QLabel *labelDuration;
    QLineEdit *lineDuration;
    QLineEdit *lineMinRate;
    QLabel *labelMinRate;
    QLineEdit *lineMaxRate;
    QLabel *labelMaxRate;
    QLineEdit *lineMinTime;
    QLabel *labelMinTime;
    QLabel *labelMaxTime;
    QLineEdit *lineMaxTime;
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
    QWidget *ParticlePreviewWidget;
    QMenuBar *menuBar;
    QMenu *menuJan;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(699, 566);
        actionExport = new QAction(MainWindow);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        Options = new QGroupBox(centralWidget);
        Options->setObjectName(QStringLiteral("Options"));
        Options->setGeometry(QRect(0, 10, 271, 491));
        QFont font;
        font.setBold(false);
        font.setWeight(50);
        Options->setFont(font);
        lineMinScale = new QLineEdit(Options);
        lineMinScale->setObjectName(QStringLiteral("lineMinScale"));
        lineMinScale->setGeometry(QRect(70, 20, 113, 20));
        lineMaxScale = new QLineEdit(Options);
        lineMaxScale->setObjectName(QStringLiteral("lineMaxScale"));
        lineMaxScale->setGeometry(QRect(70, 50, 113, 20));
        ApplyAll = new QPushButton(Options);
        ApplyAll->setObjectName(QStringLiteral("ApplyAll"));
        ApplyAll->setGeometry(QRect(70, 460, 101, 31));
        labelMinScale = new QLabel(Options);
        labelMinScale->setObjectName(QStringLiteral("labelMinScale"));
        labelMinScale->setGeometry(QRect(10, 20, 47, 13));
        labelMaxScale = new QLabel(Options);
        labelMaxScale->setObjectName(QStringLiteral("labelMaxScale"));
        labelMaxScale->setGeometry(QRect(10, 50, 47, 13));
        comboShape = new QComboBox(Options);
        comboShape->setObjectName(QStringLiteral("comboShape"));
        comboShape->setGeometry(QRect(70, 300, 69, 22));
        labelShape = new QLabel(Options);
        labelShape->setObjectName(QStringLiteral("labelShape"));
        labelShape->setGeometry(QRect(10, 300, 47, 13));
        PickBrightest = new QPushButton(Options);
        PickBrightest->setObjectName(QStringLiteral("PickBrightest"));
        PickBrightest->setGeometry(QRect(160, 260, 91, 31));
        PickDarkest = new QPushButton(Options);
        PickDarkest->setObjectName(QStringLiteral("PickDarkest"));
        PickDarkest->setGeometry(QRect(160, 230, 91, 31));
        groupDirection = new QGroupBox(Options);
        groupDirection->setObjectName(QStringLiteral("groupDirection"));
        groupDirection->setGeometry(QRect(0, 220, 151, 71));
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
        labelDuration = new QLabel(Options);
        labelDuration->setObjectName(QStringLiteral("labelDuration"));
        labelDuration->setGeometry(QRect(10, 80, 47, 13));
        lineDuration = new QLineEdit(Options);
        lineDuration->setObjectName(QStringLiteral("lineDuration"));
        lineDuration->setGeometry(QRect(70, 80, 111, 20));
        lineMinRate = new QLineEdit(Options);
        lineMinRate->setObjectName(QStringLiteral("lineMinRate"));
        lineMinRate->setGeometry(QRect(70, 110, 111, 20));
        labelMinRate = new QLabel(Options);
        labelMinRate->setObjectName(QStringLiteral("labelMinRate"));
        labelMinRate->setGeometry(QRect(10, 110, 47, 13));
        lineMaxRate = new QLineEdit(Options);
        lineMaxRate->setObjectName(QStringLiteral("lineMaxRate"));
        lineMaxRate->setGeometry(QRect(70, 140, 111, 20));
        labelMaxRate = new QLabel(Options);
        labelMaxRate->setObjectName(QStringLiteral("labelMaxRate"));
        labelMaxRate->setGeometry(QRect(10, 140, 47, 13));
        lineMinTime = new QLineEdit(Options);
        lineMinTime->setObjectName(QStringLiteral("lineMinTime"));
        lineMinTime->setGeometry(QRect(70, 170, 111, 20));
        labelMinTime = new QLabel(Options);
        labelMinTime->setObjectName(QStringLiteral("labelMinTime"));
        labelMinTime->setGeometry(QRect(10, 170, 47, 13));
        labelMaxTime = new QLabel(Options);
        labelMaxTime->setObjectName(QStringLiteral("labelMaxTime"));
        labelMaxTime->setGeometry(QRect(10, 200, 47, 13));
        lineMaxTime = new QLineEdit(Options);
        lineMaxTime->setObjectName(QStringLiteral("lineMaxTime"));
        lineMaxTime->setGeometry(QRect(70, 200, 111, 20));
        groupBoxSettings = new QGroupBox(Options);
        groupBoxSettings->setObjectName(QStringLiteral("groupBoxSettings"));
        groupBoxSettings->setGeometry(QRect(10, 330, 141, 121));
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
        groupSphereSettings = new QGroupBox(Options);
        groupSphereSettings->setObjectName(QStringLiteral("groupSphereSettings"));
        groupSphereSettings->setGeometry(QRect(160, 330, 101, 121));
        lineSpereRadius = new QLineEdit(groupSphereSettings);
        lineSpereRadius->setObjectName(QStringLiteral("lineSpereRadius"));
        lineSpereRadius->setGeometry(QRect(60, 50, 31, 20));
        labelSphereRadius = new QLabel(groupSphereSettings);
        labelSphereRadius->setObjectName(QStringLiteral("labelSphereRadius"));
        labelSphereRadius->setGeometry(QRect(10, 50, 41, 16));
        ParticlePreviewWidget = new QWidget(centralWidget);
        ParticlePreviewWidget->setObjectName(QStringLiteral("ParticlePreviewWidget"));
        ParticlePreviewWidget->setGeometry(QRect(280, 10, 401, 491));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 699, 21));
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

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Particle Editor Alpha", 0));
        actionExport->setText(QApplication::translate("MainWindow", "Export", 0));
        Options->setTitle(QApplication::translate("MainWindow", "Settings", 0));
#ifndef QT_NO_TOOLTIP
        lineMinScale->setToolTip(QApplication::translate("MainWindow", "Smallest scale of the particles", 0));
#endif // QT_NO_TOOLTIP
        lineMinScale->setText(QApplication::translate("MainWindow", "1", 0));
#ifndef QT_NO_TOOLTIP
        lineMaxScale->setToolTip(QApplication::translate("MainWindow", "Biggest scale of particles", 0));
#endif // QT_NO_TOOLTIP
        lineMaxScale->setText(QApplication::translate("MainWindow", "2", 0));
        ApplyAll->setText(QApplication::translate("MainWindow", "Apply", 0));
        labelMinScale->setText(QApplication::translate("MainWindow", "Min Scale", 0));
        labelMaxScale->setText(QApplication::translate("MainWindow", "Max Scale", 0));
        comboShape->clear();
        comboShape->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "box", 0)
         << QApplication::translate("MainWindow", "sphere", 0)
        );
        labelShape->setText(QApplication::translate("MainWindow", "Shape", 0));
        PickBrightest->setText(QApplication::translate("MainWindow", "Change brightest", 0));
        PickDarkest->setText(QApplication::translate("MainWindow", "Change darkest", 0));
        groupDirection->setTitle(QApplication::translate("MainWindow", "Direction", 0));
        dirX->setText(QApplication::translate("MainWindow", "0", 0));
        dirY->setText(QApplication::translate("MainWindow", "0.05", 0));
        dirZ->setText(QApplication::translate("MainWindow", "0", 0));
        labelDirection->setText(QApplication::translate("MainWindow", "X              Y                Z", 0));
        labelDuration->setText(QApplication::translate("MainWindow", "Duration", 0));
#ifndef QT_NO_TOOLTIP
        lineDuration->setToolTip(QApplication::translate("MainWindow", "Biggest scale of particles", 0));
#endif // QT_NO_TOOLTIP
        lineDuration->setText(QApplication::translate("MainWindow", "2000", 0));
#ifndef QT_NO_TOOLTIP
        lineMinRate->setToolTip(QApplication::translate("MainWindow", "Biggest scale of particles", 0));
#endif // QT_NO_TOOLTIP
        lineMinRate->setText(QApplication::translate("MainWindow", "100", 0));
        labelMinRate->setText(QApplication::translate("MainWindow", "Min Rate", 0));
#ifndef QT_NO_TOOLTIP
        lineMaxRate->setToolTip(QApplication::translate("MainWindow", "Biggest scale of particles", 0));
#endif // QT_NO_TOOLTIP
        lineMaxRate->setText(QApplication::translate("MainWindow", "200", 0));
        labelMaxRate->setText(QApplication::translate("MainWindow", "Max Rate", 0));
#ifndef QT_NO_TOOLTIP
        lineMinTime->setToolTip(QApplication::translate("MainWindow", "Biggest scale of particles", 0));
#endif // QT_NO_TOOLTIP
        lineMinTime->setText(QApplication::translate("MainWindow", "500", 0));
        labelMinTime->setText(QApplication::translate("MainWindow", "Min Time", 0));
        labelMaxTime->setText(QApplication::translate("MainWindow", "Max Time", 0));
#ifndef QT_NO_TOOLTIP
        lineMaxTime->setToolTip(QApplication::translate("MainWindow", "Biggest scale of particles", 0));
#endif // QT_NO_TOOLTIP
        lineMaxTime->setText(QApplication::translate("MainWindow", "1000", 0));
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
        menuJan->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
