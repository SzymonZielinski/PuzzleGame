#pragma once
class PuzzleAreaBase
{
public:
	PuzzleAreaBase();
	~PuzzleAreaBase();
	virtual void MovePuzzlePiece(const int rowPosition, const int colPosition, bool shufflingMode = false) = 0;
};

