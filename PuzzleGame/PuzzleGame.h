#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PuzzleGame.h"

/** PuzzleGame
Klasa reprezentuje główne okno programu. Dziedziczy po QMainWindow.
Dostarcza interfejs użytkownika oraz inicjalizuje instancję PuzzleArea.
*/
class PuzzleGame : public QMainWindow
{
	Q_OBJECT
public:
	/**
	\brief Domyślny konstruktor.
	\param parent "Rodzic" elementu.
	*/
	PuzzleGame(QWidget *parent = Q_NULLPTR);
	/**
	\brief Domyślny destruktor.
	*/
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
	/**
	\brief Zmiana stanu checkboxa "Pokazuj animacje".
	*/
	void showAnimationsCheckBoxStateChanged(bool checkState);
	/**
	\brief Zmiana wartości spinboxa prędkości animacji.
	*/
	void animationSpeedSpinBoxValueChanged(int animationSpeed);
	
private:
	Ui::PuzzleGameClass ui;
	QHBoxLayout *puzzleGameLayout;
};
