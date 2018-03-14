#ifndef puzzlepieceH
#define puzzlepieceH

#include <QtWidgets>

#pragma once
class PuzzlePiece : public QLabel
{
private:
	int correctX;
	int correctY;
	int currentX;
	int currentY;
	//PuzzleArea* myPuzzleArea;
	//void updatePosition(QWidget *widget, float xscale, float yscale);
	/*void swap(PuzzlePiece& other)
	{
		std::swap(correctX, other.correctX);
		std::swap(correctY, other.correctY);
		std::swap(currentX, other.currentX);
		std::swap(currentY, other.currentY);
	}*/
protected:
	//void resizeEvent(QResizeEvent *event);

	void mousePressEvent(QMouseEvent *qevent);
public:
	PuzzlePiece();
	//PuzzlePiece(PuzzleArea* puzzleArea);
	PuzzlePiece(const int correctPositionX, const int correctPositionY, const int width, const int height);
	PuzzlePiece(const PuzzlePiece& puzzlePiece);
	//void SetPuzzleArea(PuzzleArea* puzzleArea);
	~PuzzlePiece();
	bool LoadImage(QString path);
	void SetCorrectPosition(const int positionX, const int positionY);
	void SetCurrentPosition(const int positionX, const int positionY);
	/*PuzzlePiece& operator=(const PuzzlePiece& other)
	{
		QLabel::operator=(other);
		PuzzlePiece temp(other);
		swap(temp);
		return *this;
	}*/
public slots:
	void clickOnPuzzlePiece();
};

#endif