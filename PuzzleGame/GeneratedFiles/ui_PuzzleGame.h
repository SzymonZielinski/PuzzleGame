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
#include <QtWidgets/QLabel>
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
    QSpinBox *difficultySpinBox;
    QPushButton *startGamePushButton;
    QPushButton *loadImagePushButton;
    QCheckBox *randomizeEmptyPieceCheckBox;
    QLabel *difficultyLabel;
    QLabel *rowsLabel;
    QLabel *columnsLabel;
    QSpinBox *puzzleSpacingXSpinBox;
    QSpinBox *puzzleSpacingYSpinBox;
    QLabel *puzzleSpacingYLabel;
    QLabel *puzzleSpacingXLabel;
    QCheckBox *showAnimationsCheckBox;
    QSpinBox *animationSpeedSpinBox;
    QLabel *animationSpeedLabel;
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
        settingsFrame->setGeometry(QRect(780, 30, 291, 361));
        settingsFrame->setMinimumSize(QSize(280, 260));
        settingsFrame->setFrameShape(QFrame::StyledPanel);
        settingsFrame->setFrameShadow(QFrame::Raised);
        puzzleElementsYSpinBox = new QSpinBox(settingsFrame);
        puzzleElementsYSpinBox->setObjectName(QStringLiteral("puzzleElementsYSpinBox"));
        puzzleElementsYSpinBox->setGeometry(QRect(220, 100, 42, 22));
        puzzleElementsYSpinBox->setMinimum(2);
        puzzleElementsYSpinBox->setMaximum(100);
        puzzleElementsXSpinBox = new QSpinBox(settingsFrame);
        puzzleElementsXSpinBox->setObjectName(QStringLiteral("puzzleElementsXSpinBox"));
        puzzleElementsXSpinBox->setGeometry(QRect(220, 70, 42, 22));
        puzzleElementsXSpinBox->setMinimum(2);
        puzzleElementsXSpinBox->setMaximum(100);
        difficultySpinBox = new QSpinBox(settingsFrame);
        difficultySpinBox->setObjectName(QStringLiteral("difficultySpinBox"));
        difficultySpinBox->setGeometry(QRect(220, 40, 41, 22));
        difficultySpinBox->setMinimum(1);
        difficultySpinBox->setMaximum(10);
        difficultySpinBox->setValue(1);
        startGamePushButton = new QPushButton(settingsFrame);
        startGamePushButton->setObjectName(QStringLiteral("startGamePushButton"));
        startGamePushButton->setGeometry(QRect(10, 10, 251, 23));
        loadImagePushButton = new QPushButton(settingsFrame);
        loadImagePushButton->setObjectName(QStringLiteral("loadImagePushButton"));
        loadImagePushButton->setGeometry(QRect(10, 160, 251, 23));
        randomizeEmptyPieceCheckBox = new QCheckBox(settingsFrame);
        randomizeEmptyPieceCheckBox->setObjectName(QStringLiteral("randomizeEmptyPieceCheckBox"));
        randomizeEmptyPieceCheckBox->setGeometry(QRect(10, 130, 161, 17));
        difficultyLabel = new QLabel(settingsFrame);
        difficultyLabel->setObjectName(QStringLiteral("difficultyLabel"));
        difficultyLabel->setGeometry(QRect(10, 40, 171, 16));
        rowsLabel = new QLabel(settingsFrame);
        rowsLabel->setObjectName(QStringLiteral("rowsLabel"));
        rowsLabel->setGeometry(QRect(10, 70, 171, 16));
        columnsLabel = new QLabel(settingsFrame);
        columnsLabel->setObjectName(QStringLiteral("columnsLabel"));
        columnsLabel->setGeometry(QRect(10, 100, 171, 16));
        puzzleSpacingXSpinBox = new QSpinBox(settingsFrame);
        puzzleSpacingXSpinBox->setObjectName(QStringLiteral("puzzleSpacingXSpinBox"));
        puzzleSpacingXSpinBox->setGeometry(QRect(220, 200, 42, 22));
        puzzleSpacingXSpinBox->setMinimum(0);
        puzzleSpacingXSpinBox->setMaximum(20);
        puzzleSpacingXSpinBox->setValue(1);
        puzzleSpacingYSpinBox = new QSpinBox(settingsFrame);
        puzzleSpacingYSpinBox->setObjectName(QStringLiteral("puzzleSpacingYSpinBox"));
        puzzleSpacingYSpinBox->setGeometry(QRect(220, 230, 42, 22));
        puzzleSpacingYSpinBox->setMinimum(0);
        puzzleSpacingYSpinBox->setMaximum(20);
        puzzleSpacingYSpinBox->setValue(1);
        puzzleSpacingYLabel = new QLabel(settingsFrame);
        puzzleSpacingYLabel->setObjectName(QStringLiteral("puzzleSpacingYLabel"));
        puzzleSpacingYLabel->setGeometry(QRect(10, 230, 171, 16));
        puzzleSpacingXLabel = new QLabel(settingsFrame);
        puzzleSpacingXLabel->setObjectName(QStringLiteral("puzzleSpacingXLabel"));
        puzzleSpacingXLabel->setGeometry(QRect(10, 200, 171, 16));
        showAnimationsCheckBox = new QCheckBox(settingsFrame);
        showAnimationsCheckBox->setObjectName(QStringLiteral("showAnimationsCheckBox"));
        showAnimationsCheckBox->setGeometry(QRect(10, 270, 161, 17));
        showAnimationsCheckBox->setChecked(true);
        animationSpeedSpinBox = new QSpinBox(settingsFrame);
        animationSpeedSpinBox->setObjectName(QStringLiteral("animationSpeedSpinBox"));
        animationSpeedSpinBox->setGeometry(QRect(211, 300, 51, 22));
        animationSpeedSpinBox->setMinimum(50);
        animationSpeedSpinBox->setMaximum(1000);
        animationSpeedSpinBox->setSingleStep(50);
        animationSpeedSpinBox->setValue(100);
        animationSpeedLabel = new QLabel(settingsFrame);
        animationSpeedLabel->setObjectName(QStringLiteral("animationSpeedLabel"));
        animationSpeedLabel->setGeometry(QRect(10, 300, 171, 16));
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
        loadImagePushButton->setText(QApplication::translate("PuzzleGameClass", "Load an image from a file", nullptr));
        randomizeEmptyPieceCheckBox->setText(QApplication::translate("PuzzleGameClass", "Randomize empty piece", nullptr));
        difficultyLabel->setText(QApplication::translate("PuzzleGameClass", "Difficulty (1 - very easy, 10 - hard):", nullptr));
        rowsLabel->setText(QApplication::translate("PuzzleGameClass", "Number of rows:", nullptr));
        columnsLabel->setText(QApplication::translate("PuzzleGameClass", "Number of columns:", nullptr));
        puzzleSpacingYLabel->setText(QApplication::translate("PuzzleGameClass", "Spacing between columns:", nullptr));
        puzzleSpacingXLabel->setText(QApplication::translate("PuzzleGameClass", "Spacing between rows:", nullptr));
        showAnimationsCheckBox->setText(QApplication::translate("PuzzleGameClass", "Show animations", nullptr));
        animationSpeedLabel->setText(QApplication::translate("PuzzleGameClass", "Animation speed (ms):", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PuzzleGameClass: public Ui_PuzzleGameClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUZZLEGAME_H
