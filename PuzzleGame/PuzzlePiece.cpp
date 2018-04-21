#include<iostream>
#include "PuzzlePiece.h"

PuzzlePiece::PuzzlePiece()
{
}

PuzzlePiece::PuzzlePiece(PuzzleAreaBase* puzzleArea)
{
	myPuzzleArea = puzzleArea;
}

PuzzlePiece::PuzzlePiece(int correctPositionX, int correctPositionY, int currentPositionX, int currentPositionY, PuzzleAreaBase* puzzleArea)
{
	if (correctPositionX >= 0)
		correctX = correctPositionX;
	if (correctPositionY >= 0)
		correctX = correctPositionY;
	if (currentPositionX >= 0)
		correctX = currentPositionX;
	if (currentPositionY >= 0)
		correctX = currentPositionY;
	myPuzzleArea = puzzleArea;
}

PuzzlePiece::PuzzlePiece(const PuzzlePiece& puzzlePiece)
{
	myPuzzleArea = puzzlePiece.myPuzzleArea;
	correctX = puzzlePiece.correctX;
	correctY = puzzlePiece.correctY;
	currentX = puzzlePiece.currentX;
	currentY = puzzlePiece.currentY;
	setGeometry(puzzlePiece.geometry());

	if (puzzlePiece.pixmap())
	{
		QImage tmpImage = puzzlePiece.pixmap()->toImage();
		setPixmap(QPixmap::fromImage(tmpImage));
	}
	setVisible(puzzlePiece.isVisible());
}

PuzzlePiece::~PuzzlePiece()
{
}

void PuzzlePiece::setPuzzleArea(PuzzleAreaBase* puzzleArea)
{
	myPuzzleArea = puzzleArea;
}

void PuzzlePiece::setCorrectPosition(const int positionX, const int positionY)
{
	if (positionX >= 0)
		correctX = positionX;
	if (positionY >= 0)
		correctY = positionY;
}

int PuzzlePiece::getCorrectPositionX()
{
	return correctX;
}

int PuzzlePiece::getCorrectPositionY()
{
	return correctY;
}

void PuzzlePiece::setCurrentPosition(const int positionX, const int positionY)
{
	if (positionX >= 0)
		currentX = positionX;
	if (positionY >= 0)
		currentY = positionY;
}

void PuzzlePiece::mousePressEvent(QMouseEvent *qevent)
{
	myPuzzleArea->movePuzzlePiece(currentX, currentY);
}

/*
W poprzedniej wersji używano nieco zmodyfikowanej wersji, aby korzystać z std::swap. W obecnej wersji zostało to uproszczone i obecnie używamy tylko metody swapPuzzlePiece.
Operator przypisania już był napisany, więc go zostawiłem.
*/
PuzzlePiece& PuzzlePiece::operator=(PuzzlePiece puzzlePiece)
{
	myPuzzleArea = puzzlePiece.myPuzzleArea;
	correctX = puzzlePiece.correctX;
	correctY = puzzlePiece.correctY;
	currentX = puzzlePiece.correctX;
	currentY = puzzlePiece.correctY;
	
	if (puzzlePiece.pixmap())
	{
		QImage tmpImage = puzzlePiece.pixmap()->toImage();
		setPixmap(QPixmap::fromImage(tmpImage));
	}
	setVisible(puzzlePiece.isVisible());
	setGeometry(puzzlePiece.geometry());
	return *this;
}

void PuzzlePiece::swapPuzzlePiece(PuzzlePiece& puzzlePiece)
{
	// zamieniamy elementy tylko wtedy, gdy należą do tej samej układanki
	if (myPuzzleArea == puzzlePiece.myPuzzleArea)
	{
		std::swap(correctX, puzzlePiece.correctX);
		std::swap(correctY, puzzlePiece.correctY);

		if (puzzlePiece.pixmap())
		{
			QImage tmpImage = puzzlePiece.pixmap()->toImage();
			puzzlePiece.setPixmap(*pixmap());
			setPixmap(QPixmap::fromImage(tmpImage));
		}

		bool visibility = puzzlePiece.isVisible();
		puzzlePiece.setVisible(isVisible());
		setVisible(visibility);
	}
}

bool PuzzlePiece::isInCorrectPosition(const int x, const int y)
{
	return correctX == x && correctY == y;
}