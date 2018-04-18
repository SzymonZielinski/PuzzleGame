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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QFrame>
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
    PuzzleArea *puzzleGameArea;
    QFrame *settingsFrame;
    QSpinBox *puzzleElementsYSpinBox;
    QSpinBox *puzzleElementsXSpinBox;
    QSpinBox *shuffleComplexitySpinBox;
    QPushButton *startGamePushButton;
    QPushButton *loadImagePushButton;
    QCheckBox *randomizeEmptyPieceCheckBox;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *PuzzleGameClass)
    {
        if (PuzzleGameClass->objectName().isEmpty())
            PuzzleGameClass->setObjectName(QStringLiteral("PuzzleGameClass"));
        PuzzleGameClass->resize(1104, 732);
        PuzzleGameClass->setMinimumSize(QSize(600, 300));
        centralWidget = new QWidget(PuzzleGameClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        puzzleGameArea = new PuzzleArea(centralWidget);
        puzzleGameArea->setObjectName(QStringLiteral("puzzleGameArea"));
        puzzleGameArea->setGeometry(QRect(20, 10, 741, 661));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(puzzleGameArea->sizePolicy().hasHeightForWidth());
        puzzleGameArea->setSizePolicy(sizePolicy);
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
        settingsFrame = new QFrame(centralWidget);
        settingsFrame->setObjectName(QStringLiteral("settingsFrame"));
        settingsFrame->setGeometry(QRect(780, 140, 291, 261));
        settingsFrame->setMinimumSize(QSize(280, 260));
        settingsFrame->setFrameShape(QFrame::StyledPanel);
        settingsFrame->setFrameShadow(QFrame::Raised);
        puzzleElementsYSpinBox = new QSpinBox(settingsFrame);
        puzzleElementsYSpinBox->setObjectName(QStringLiteral("puzzleElementsYSpinBox"));
        puzzleElementsYSpinBox->setGeometry(QRect(210, 120, 42, 22));
        puzzleElementsYSpinBox->setMinimum(2);
        puzzleElementsYSpinBox->setMaximum(100);
        puzzleElementsXSpinBox = new QSpinBox(settingsFrame);
        puzzleElementsXSpinBox->setObjectName(QStringLiteral("puzzleElementsXSpinBox"));
        puzzleElementsXSpinBox->setGeometry(QRect(210, 80, 42, 22));
        puzzleElementsXSpinBox->setMinimum(2);
        puzzleElementsXSpinBox->setMaximum(100);
        shuffleComplexitySpinBox = new QSpinBox(settingsFrame);
        shuffleComplexitySpinBox->setObjectName(QStringLiteral("shuffleComplexitySpinBox"));
        shuffleComplexitySpinBox->setGeometry(QRect(210, 40, 41, 22));
        shuffleComplexitySpinBox->setMinimum(1);
        shuffleComplexitySpinBox->setMaximum(10);
        shuffleComplexitySpinBox->setValue(1);
        startGamePushButton = new QPushButton(settingsFrame);
        startGamePushButton->setObjectName(QStringLiteral("startGamePushButton"));
        startGamePushButton->setGeometry(QRect(80, 40, 75, 23));
        loadImagePushButton = new QPushButton(settingsFrame);
        loadImagePushButton->setObjectName(QStringLiteral("loadImagePushButton"));
        loadImagePushButton->setGeometry(QRect(60, 170, 161, 23));
        randomizeEmptyPieceCheckBox = new QCheckBox(settingsFrame);
        randomizeEmptyPieceCheckBox->setObjectName(QStringLiteral("randomizeEmptyPieceCheckBox"));
        randomizeEmptyPieceCheckBox->setGeometry(QRect(70, 210, 161, 17));
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
        startGamePushButton->setText(QApplication::translate("PuzzleGameClass", "Start Game", nullptr));
        loadImagePushButton->setText(QApplication::translate("PuzzleGameClass", "Load an image", nullptr));
        randomizeEmptyPieceCheckBox->setText(QApplication::translate("PuzzleGameClass", "Randomize empty piece", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PuzzleGameClass: public Ui_PuzzleGameClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUZZLEGAME_H
