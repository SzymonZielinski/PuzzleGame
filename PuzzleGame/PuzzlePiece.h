#pragma once

#include <QtWidgets>
#include "PuzzleAreaBase.h"
/**
Pojedynczy element układanki. Dziedziczy po QLabel.
*/
class PuzzlePiece : public QLabel
{
private:
	/// wskaźnik do obszaru całej układanki
	PuzzleAreaBase* myPuzzleArea;
	/// właściwa pozycja X elementu
	int correctX;
	/// właściwa pozycja Y elementu
	int correctY;
	/// bieżąca pozycja X elementu
	int currentX;
	/// bieżąca pozycja Y elementu
	int currentY;
protected:
	//void resizeEvent(QResizeEvent *event);
	/// Kliknięcie myszą na elemencie układanki powoduje przesunięcie go w wolne miejsce obok (o ile to możliwe).
	void mousePressEvent(QMouseEvent *qevent);
public:
	PuzzlePiece();
	PuzzlePiece(PuzzleAreaBase* puzzleArea);
	PuzzlePiece(const int correctPositionX, const int correctPositionY, const int width, const int height);
	PuzzlePiece(const PuzzlePiece& puzzlePiece);
	~PuzzlePiece();

	/**
	Ustawia obszar układanki dla danego elementu.
	*/
	void setPuzzleArea(PuzzleAreaBase* puzzleArea);
	/**
	Ustawia właściwą pozycję danego elementu.
	*/
	void setCorrectPosition(const int positionX, const int positionY);
	/**
	Ustawia bieżącą pozycję danego elementu.
	*/
	void setCurrentPosition(const int positionX, const int positionY);
	/**
	Zamienia dane o widocznej części elementu miejscami.
	*/
	void swapVisibleImageData(PuzzlePiece& puzzlePiece);
	/**
	Zwraca informację, czy element znajduje się na właściwej pozycji.
	\param x Współrzędna x elementu
	\param y Współrzędna y elementu
	\return true jeśli prawda, false w przeciwnym wypadku
	*/
	bool isInCorrectPosition(const int x, const int y);
	/**
	Przeładowanie operatora przypisania (do poprawnego działania std::swap)
	*/
	PuzzlePiece& operator=(PuzzlePiece piece);
};