#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PuzzleGame.h"

class PuzzleGame : public QMainWindow
{
	Q_OBJECT

public:
	PuzzleGame(QWidget *parent = Q_NULLPTR);
public slots:
	void clickButton();
private:
	Ui::PuzzleGameClass ui;
};
