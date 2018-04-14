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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>
#include "PuzzleArea.h"

QT_BEGIN_NAMESPACE

class Ui_PuzzleGameClass
{
public:
    QWidget *centralWidget;
    QPushButton *testPushButton;
    PuzzleArea *puzzleGameArea;
    QSpinBox *shuffleComplexitySpinBox;
    QSpinBox *puzzleElementsXSpinBox;
    QSpinBox *puzzleElementsYSpinBox;
    QPushButton *loadImagePushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PuzzleGameClass)
    {
        if (PuzzleGameClass->objectName().isEmpty())
            PuzzleGameClass->setObjectName(QStringLiteral("PuzzleGameClass"));
        PuzzleGameClass->resize(1104, 732);
        centralWidget = new QWidget(PuzzleGameClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        testPushButton = new QPushButton(centralWidget);
        testPushButton->setObjectName(QStringLiteral("testPushButton"));
        testPushButton->setGeometry(QRect(790, 70, 75, 23));
        puzzleGameArea = new PuzzleArea(centralWidget);
        puzzleGameArea->setObjectName(QStringLiteral("puzzleGameArea"));
        puzzleGameArea->setGeometry(QRect(20, 10, 741, 661));
        QPalette palette;
        QBrush brush(QColor(170, 255, 255, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Base, brush);
        QBrush brush1(QColor(170, 170, 255, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        puzzleGameArea->setPalette(palette);
        puzzleGameArea->setFrameShape(QFrame::StyledPanel);
        puzzleGameArea->setFrameShadow(QFrame::Raised);
        shuffleComplexitySpinBox = new QSpinBox(centralWidget);
        shuffleComplexitySpinBox->setObjectName(QStringLiteral("shuffleComplexitySpinBox"));
        shuffleComplexitySpinBox->setGeometry(QRect(900, 70, 41, 22));
        shuffleComplexitySpinBox->setMinimum(1);
        shuffleComplexitySpinBox->setMaximum(10);
        shuffleComplexitySpinBox->setValue(1);
        puzzleElementsXSpinBox = new QSpinBox(centralWidget);
        puzzleElementsXSpinBox->setObjectName(QStringLiteral("puzzleElementsXSpinBox"));
        puzzleElementsXSpinBox->setGeometry(QRect(910, 120, 42, 22));
        puzzleElementsXSpinBox->setMinimum(2);
        puzzleElementsXSpinBox->setMaximum(100);
        puzzleElementsYSpinBox = new QSpinBox(centralWidget);
        puzzleElementsYSpinBox->setObjectName(QStringLiteral("puzzleElementsYSpinBox"));
        puzzleElementsYSpinBox->setGeometry(QRect(910, 170, 42, 22));
        puzzleElementsYSpinBox->setMinimum(2);
        puzzleElementsYSpinBox->setMaximum(100);
        loadImagePushButton = new QPushButton(centralWidget);
        loadImagePushButton->setObjectName(QStringLiteral("loadImagePushButton"));
        loadImagePushButton->setGeometry(QRect(790, 20, 161, 23));
        PuzzleGameClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(PuzzleGameClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1104, 21));
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
        testPushButton->setText(QApplication::translate("PuzzleGameClass", "Shuffle", nullptr));
        loadImagePushButton->setText(QApplication::translate("PuzzleGameClass", "Load an image", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PuzzleGameClass: public Ui_PuzzleGameClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUZZLEGAME_H
