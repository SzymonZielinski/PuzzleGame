﻿#ifndef puzzleareaH
#define puzzleareaH

#include <QtWidgets>
#include "PuzzlePiece.h"

#pragma once
class PuzzleArea : public QFrame
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
	QVector<PuzzlePiece> PuzzlePieces;
	//PuzzlePiece** PuzzlePieces;

protected:
	void mousePressEvent(QMouseEvent *qevent);
public:
	PuzzleArea(QWidget *parent = Q_NULLPTR);
	~PuzzleArea();
	void MovePuzzlePiece(const int rowPosition, const int colPosition);
	int getEmptyPieceX();
	int getEmptyPieceY();
	bool setEmptyPieceX(int x);
	bool setEmptyPieceY(int y);

public slots:
	void clickOnPuzzleArea();
};

#endif