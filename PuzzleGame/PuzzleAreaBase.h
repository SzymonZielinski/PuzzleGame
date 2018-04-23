#pragma once
/** PuzzleAreaBase
	Klasa abstrakcyjna, bazowa dla PuzzleArea, jej jedyną funkcją jest dostarczenie prototypu metody MovePuzzlePiece.
*/
class PuzzleAreaBase
{
public:
	/** MovePuzzlePiece - metoda czysto wirtualna, zdefiniowana w klasie pochodnej PuzzleArea
		\param x pozycja wiersza elementu
		\param y pozycja kolumny elementu
		\param shufflingMode czy jesteśmy w trybie sortowania?
	*/
	virtual void movePuzzlePiece(const int x, const int y, bool shufflingMode = false) = 0;
};