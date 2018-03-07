/********************************************************************************
** Form generated from reading UI file 'PuzzleGame.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PUZZLEGAME_H
#define UI_PUZZLEGAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PuzzleGameClass
{
public:
    QWidget *centralWidget;
    QLabel *label;
    QPushButton *testPushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PuzzleGameClass)
    {
        if (PuzzleGameClass->objectName().isEmpty())
            PuzzleGameClass->setObjectName(QStringLiteral("PuzzleGameClass"));
        PuzzleGameClass->resize(1082, 732);
        centralWidget = new QWidget(PuzzleGameClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 60, 131, 81));
        testPushButton = new QPushButton(centralWidget);
        testPushButton->setObjectName(QStringLiteral("testPushButton"));
        testPushButton->setGeometry(QRect(960, 20, 91, 31));
        PuzzleGameClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PuzzleGameClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1082, 21));
        PuzzleGameClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(PuzzleGameClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        PuzzleGameClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(PuzzleGameClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        PuzzleGameClass->setStatusBar(statusBar);

        retranslateUi(PuzzleGameClass);

        QMetaObject::connectSlotsByName(PuzzleGameClass);
    } // setupUi

    void retranslateUi(QMainWindow *PuzzleGameClass)
    {
        PuzzleGameClass->setWindowTitle(QApplication::translate("PuzzleGameClass", "PuzzleGame", nullptr));
        label->setText(QApplication::translate("PuzzleGameClass", "TextLabel", nullptr));
        testPushButton->setText(QApplication::translate("PuzzleGameClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PuzzleGameClass: public Ui_PuzzleGameClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUZZLEGAME_H
