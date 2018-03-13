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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHeaderView>
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
    QPushButton *testPushButton;
    QFrame *frame;
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
        testPushButton->setGeometry(QRect(760, 20, 75, 23));
        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setGeometry(QRect(9, 9, 741, 661));
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
        frame->setPalette(palette);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
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
        testPushButton->setText(QApplication::translate("PuzzleGameClass", "PushButton", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PuzzleGameClass: public Ui_PuzzleGameClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PUZZLEGAME_H
