#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PuzzleGame.h"

/** PuzzleGame
Klasa reprezentuje główne okno programu. Dziedziczy po QMainWindow.
*/
class PuzzleGame : public QMainWindow
{
	Q_OBJECT
public:
	PuzzleGame(QWidget *parent = Q_NULLPTR);
	~PuzzleGame();
public slots:
	/**
	\brief Rozpoczęcie gry (przycisk) z bieżącymi ustawieniami.
	*/
	void startGamePushButtonClick();
	/**
	\brief Ładowanie obrazku puzzli z pliku (przycisk).
	*/
	void loadImagePushButtonClick();
	void showAnimationsCheckBoxStateChanged(bool checkState);
	void animationSpeedSpinBoxValueChanged(int animationSpeed);
	
private:
	Ui::PuzzleGameClass ui;
	QHBoxLayout *puzzleGameLayout;
};
