#ifndef puzzleareaH
#define puzzleareaH

#include <QtWidgets>
#include "PuzzlePiece.h"

#pragma once
class PuzzleArea : public QFrame
{
private:
	int SizeX; // ilość elementów układanki w poziomie
	int SizeY; // ilość elementów układanki w pionie
	PuzzlePiece** PuzzlePieces;

public:
	PuzzleArea();
	~PuzzleArea();
};

#endif