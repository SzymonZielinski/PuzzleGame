#include<iostream>
#include "PuzzlePiece.h"

//void PuzzlePiece::resizeEvent(QResizeEvent *event)
//{
//	updatePosition(label, 0.5, 0.5); //50% , 50%
//	updatePosition(lineEdit, 0.3, 0.7); //30% , 70%
//	QWidget::resizeEvent(event);
//}
//
//void PuzzlePiece::updatePosition(QWidget *widget, float xscale, float yscale) {
//	int w = size().width();
//	int h = size().height();
//	widget->move(QPoint(w*xscale, h*yscale) - widget->rect().center());
//}
PuzzlePiece::PuzzlePiece()
{

}

PuzzlePiece::PuzzlePiece(PuzzleAreaBase* puzzleArea)
{
	myPuzzleArea = puzzleArea;
}

PuzzlePiece::PuzzlePiece(const int correctPositionX, const int correctPositionY, const int width, const int height):correctX(correctPositionX), correctY(correctPositionY)
{
	setFixedWidth(width);
	setFixedHeight(height);
}

PuzzlePiece::PuzzlePiece(const PuzzlePiece& puzzlePiece)
{
	myPuzzleArea = puzzlePiece.myPuzzleArea;
	correctX = puzzlePiece.correctX;
	correctY = puzzlePiece.correctY;
	currentX = puzzlePiece.currentX;
	currentY = puzzlePiece.currentY;
	this->setGeometry(puzzlePiece.geometry());
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
	correctX = positionX;
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
	currentX = positionX;
	currentY = positionY;
}

void PuzzlePiece::mousePressEvent(QMouseEvent *qevent)
{
	myPuzzleArea->movePuzzlePiece(currentX, currentY);
}

PuzzlePiece& PuzzlePiece::operator=(PuzzlePiece puzzlePiece)
{
	myPuzzleArea = puzzlePiece.myPuzzleArea;
	correctX = puzzlePiece.correctX;
	correctY = puzzlePiece.correctY;

	//wartości bieżącej pozycji nie należy przepisywać, gdyż zamieniamy elementy miejscami, więc bieżąca pozycja się nie zmienia
	//currentX = puzzlePiece.currentX;
	//currentY = puzzlePiece.currentY;
	
	setGeometry(puzzlePiece.geometry());
	return *this;
}

void PuzzlePiece::swapVisibleImageData(PuzzlePiece& puzzlePiece)
{
	QImage tmpImage = puzzlePiece.pixmap()->toImage();
	puzzlePiece.setPixmap(*pixmap());
	setPixmap(QPixmap::fromImage(tmpImage));

	bool visibility = puzzlePiece.isVisible();
	puzzlePiece.setVisible(isVisible());
	setVisible(visibility);

	QRect tmpGeometry = puzzlePiece.geometry();
	puzzlePiece.setGeometry(geometry());
	setGeometry(tmpGeometry);
}

bool PuzzlePiece::isInCorrectPosition(const int x, const int y)
{
	return correctX == x && correctY == y;
}

void PuzzlePiece::resizePuzzlePiece()
{

}