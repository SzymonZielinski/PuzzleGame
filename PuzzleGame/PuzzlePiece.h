#include <QtWidgets>

#pragma once
class PuzzlePiece : public QLabel
{
private:
	int correctX;
	int correctY;
	int currentX;
	int currentY;

	//void updatePosition(QWidget *widget, float xscale, float yscale);

protected:
	//void resizeEvent(QResizeEvent *event);

public:
	PuzzlePiece();
	PuzzlePiece(const int correctPositionX, const int correctPositionY, const int width, const int height);
	PuzzlePiece(const PuzzlePiece& puzzlePiece);
	~PuzzlePiece();
	bool LoadImage(QString path);
	void SetCorrectPosition(const int positionX, const int positionY);
};

