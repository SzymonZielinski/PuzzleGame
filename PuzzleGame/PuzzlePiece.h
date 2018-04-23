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
	/// Zdarzenie - kliknięcie myszą na elemencie układanki powoduje przesunięcie go w wolne miejsce obok (o ile to możliwe).
	void mousePressEvent(QMouseEvent *qevent);
public:
	/// Tworzy nowy obiekt typu PuzzlePiece z domyślnie zainicjowanymi wartościami.
	PuzzlePiece();
	/**
	/// Tworzy nowy obiekt typu PuzzlePiece z ustawieniem "rodzica" (obszaru danej układanki).
	\param puzzleArea Wskaźnik do obszaru danej układanki ("rodzica")
	*/
	PuzzlePiece(PuzzleAreaBase* puzzleArea);
	/**
	Tworzy nowy obiekt typu PuzzlePiece z podanymi parametrami
	\param correctPositionX właściwa pozycja X elementu
	\param correctPositionY właściwa pozycja Y elementu
	\param currentPositionX bieżąca pozycja X elementu
	\param currentPositionY bieżąca pozycja Y elementu
	\param puzzleArea Wskaźnik do obszaru danej układanki ("rodzica")
	*/
	PuzzlePiece(int correctPositionX, int correctPositionY, int currentPositionX, int currentPositionY, PuzzleAreaBase* puzzleArea);
	/**
	Tworzy nowy obiekt typu PuzzlePiece na bazie istniejącego elementu
	\param puzzlePiece Obiekt, na podstawie którego tworzymy nową instancję.
	*/
	PuzzlePiece(const PuzzlePiece& puzzlePiece);
	/**
	Domyślny destruktor.
	*/
	~PuzzlePiece();

	/**
	Ustawia obszar układanki dla danego elementu.
	*/
	void setPuzzleArea(PuzzleAreaBase* puzzleArea);
	/**
	Ustawia właściwą pozycję danego elementu.
	\param positionX właściwa pozycja X elementu
	\param positionY właściwa pozycja Y elementu
	*/
	void setCorrectPosition(const int positionX, const int positionY);
	/**
	Ustawia bieżącą pozycję danego elementu.
	\param positionX bieżąca pozycja X elementu
	\param positionY bieżąca pozycja Y elementu
	*/
	void setCurrentPosition(const int positionX, const int positionY);
	/**
	Zwraca informację o poprawnej pozycji X elementu
	\return Właściwa pozycja X elementu
	*/
	int getCorrectPositionX();
	/**
	Zwraca informację o poprawnej pozycji Y elementu
	\return Właściwa pozycja Y elementu
	*/
	int getCorrectPositionY();
	/**
	Zamienia dwa elementy miejscami.
	\param puzzlePiece Element do zamiany miejscami
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
	\param piece Element, który przypisujemy
	*/
	PuzzlePiece& operator=(PuzzlePiece piece);
};