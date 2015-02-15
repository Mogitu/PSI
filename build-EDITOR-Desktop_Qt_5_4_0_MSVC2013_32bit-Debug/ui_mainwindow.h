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
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *ApplyAll;
    QLabel *label;
    QLabel *label_2;
    QComboBox *comboBox;
    QLabel *label_3;
    QPushButton *PickBrightest;
    QPushButton *PickDarkest;
    QGroupBox *groupBox;
    QLineEdit *dirX;
    QLineEdit *dirY;
    QLineEdit *dirZ;
    QLabel *label_4;
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
        lineEdit = new QLineEdit(Options);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(70, 20, 113, 20));
        lineEdit_2 = new QLineEdit(Options);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(70, 50, 113, 20));
        ApplyAll = new QPushButton(Options);
        ApplyAll->setObjectName(QStringLiteral("ApplyAll"));
        ApplyAll->setGeometry(QRect(60, 420, 141, 61));
        label = new QLabel(Options);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 47, 13));
        label_2 = new QLabel(Options);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 50, 47, 13));
        comboBox = new QComboBox(Options);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(70, 80, 69, 22));
        label_3 = new QLabel(Options);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 80, 47, 13));
        PickBrightest = new QPushButton(Options);
        PickBrightest->setObjectName(QStringLiteral("PickBrightest"));
        PickBrightest->setGeometry(QRect(10, 210, 121, 41));
        PickDarkest = new QPushButton(Options);
        PickDarkest->setObjectName(QStringLiteral("PickDarkest"));
        PickDarkest->setGeometry(QRect(10, 260, 121, 41));
        groupBox = new QGroupBox(Options);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 110, 151, 80));
        dirX = new QLineEdit(groupBox);
        dirX->setObjectName(QStringLiteral("dirX"));
        dirX->setGeometry(QRect(10, 50, 31, 20));
        dirY = new QLineEdit(groupBox);
        dirY->setObjectName(QStringLiteral("dirY"));
        dirY->setGeometry(QRect(60, 50, 31, 20));
        dirZ = new QLineEdit(groupBox);
        dirZ->setObjectName(QStringLiteral("dirZ"));
        dirZ->setGeometry(QRect(110, 50, 31, 20));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 20, 111, 16));
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
        lineEdit->setToolTip(QApplication::translate("MainWindow", "Smallest scale of the particles", 0));
#endif // QT_NO_TOOLTIP
        lineEdit->setText(QApplication::translate("MainWindow", "1", 0));
#ifndef QT_NO_TOOLTIP
        lineEdit_2->setToolTip(QApplication::translate("MainWindow", "Biggest scale of particles", 0));
#endif // QT_NO_TOOLTIP
        lineEdit_2->setText(QApplication::translate("MainWindow", "2", 0));
        ApplyAll->setText(QApplication::translate("MainWindow", "Apply", 0));
        label->setText(QApplication::translate("MainWindow", "Min Scale", 0));
        label_2->setText(QApplication::translate("MainWindow", "Max Scale", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Box", 0)
         << QApplication::translate("MainWindow", "Point", 0)
         << QApplication::translate("MainWindow", "Sphere", 0)
        );
        label_3->setText(QApplication::translate("MainWindow", "Shape", 0));
        PickBrightest->setText(QApplication::translate("MainWindow", "Change brightest", 0));
        PickDarkest->setText(QApplication::translate("MainWindow", "Change darkest", 0));
        groupBox->setTitle(QApplication::translate("MainWindow", "Direction", 0));
        dirX->setText(QApplication::translate("MainWindow", "0", 0));
        dirY->setText(QApplication::translate("MainWindow", "0.05", 0));
        dirZ->setText(QApplication::translate("MainWindow", "0", 0));
        label_4->setText(QApplication::translate("MainWindow", "X               Y               Z", 0));
        menuJan->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
