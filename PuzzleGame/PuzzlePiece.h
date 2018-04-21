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
	PuzzleAreaBase* myPuzzleArea = Q_NULLPTR;
	/// właściwa pozycja X elementu
	int correctX = -1;
	/// właściwa pozycja Y elementu
	int correctY = -1;
	/// bieżąca pozycja X elementu
	int currentX = -1;
	/// bieżąca pozycja Y elementu
	int currentY = -1;
protected:
	/// Kliknięcie myszą na elemencie układanki powoduje przesunięcie go w wolne miejsce obok (o ile to możliwe).
	void mousePressEvent(QMouseEvent *qevent);
public:
	PuzzlePiece();
	PuzzlePiece(PuzzleAreaBase* puzzleArea);
	PuzzlePiece(int correctPositionX, int correctPositionY, int currentPositionX, int currentPositionY, PuzzleAreaBase* puzzleArea);
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
	Zwraca informację o poprawnej pozycji X elementu
	*/
	int getCorrectPositionX();
	/**
	Zwraca informację o poprawnej pozycji Y elementu
	*/
	int getCorrectPositionY();
	/**
	Zamienia dwa elementy miejscami.
	*/
	void swapPuzzlePiece(PuzzlePiece& puzzlePiece);
	/**
	Zwraca informację, czy element znajduje się na właściwej pozycji.
	\param x Współrzędna x elementu
	\param y Współrzędna y elementu
	\return true jeśli prawda, false w przeciwnym wypadku
	*/
	bool isInCorrectPosition(const int x, const int y);
	/**
	\brief Przeładowanie operatora przypisania (do poprawnego działania std::swap)
	*/
	PuzzlePiece& operator=(PuzzlePiece piece);
};