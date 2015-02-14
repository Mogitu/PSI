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
    QPushButton *PickColor;
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
        PickColor = new QPushButton(Options);
        PickColor->setObjectName(QStringLiteral("PickColor"));
        PickColor->setGeometry(QRect(10, 80, 75, 23));
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
        lineEdit->setText(QApplication::translate("MainWindow", "1", 0));
        lineEdit_2->setText(QApplication::translate("MainWindow", "1", 0));
        ApplyAll->setText(QApplication::translate("MainWindow", "Apply", 0));
        label->setText(QApplication::translate("MainWindow", "Min Scale", 0));
        label_2->setText(QApplication::translate("MainWindow", "Max Scale", 0));
        PickColor->setText(QApplication::translate("MainWindow", "Change Color", 0));
        menuJan->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
