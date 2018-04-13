#ifndef puzzleareaH
#define puzzleareaH

#include <QtWidgets>
#include "PuzzlePiece.h"
#include "PuzzleAreaBase.h"
#pragma once



class PuzzleArea : public QFrame, public PuzzleAreaBase //QFrame
{
private:
	int SizeX; // ilość elementów układanki w poziomie
	int SizeY; // ilość elementów układanki w pionie
	int EmptyPieceX;
	int EmptyPieceY;
	int puzzlePieceWidth;
	int puzzlePieceHeight;
	int puzzlePieceSpacingX = 1;
	int puzzlePieceSpacingY = 1;
	QVector<PuzzlePiece> PuzzlePieces; // układanka właściwa
	//PuzzlePiece** PuzzlePieces;

protected:
	void mousePressEvent(QMouseEvent *qevent);
public:
	PuzzleArea(QWidget *parent = Q_NULLPTR);
	~PuzzleArea();
	void MovePuzzlePiece(const int rowPosition, const int colPosition, bool shufflingMode = false);
	int getEmptyPieceX();
	int getEmptyPieceY();
	bool setEmptyPieceX(const int x);
	bool setEmptyPieceY(const int y);
	bool setEmptyPiece(const int x, const int y);
	void SwapPieces(PuzzlePiece* puzzlePiece1, PuzzlePiece* puzzlePiece2);
	void Shuffle(const int complexity = 4);
	bool IsFinished();
	void StartGame(const int elementsX, const int elementsY);

public slots:
	void clickOnPuzzleArea();
};

#endif