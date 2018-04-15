#include "PuzzleArea.h"

PuzzleArea::PuzzleArea(QWidget *parent)
{
	this->setParent(parent);
	EmptyPieceX = -1;
	EmptyPieceY = -1;

	//StartGame(5, 5);

	//delete puzzleImage;
}

PuzzleArea::~PuzzleArea()
{
}

void PuzzleArea::movePuzzlePiece(const int x, const int y, bool shufflingMode)
{
	// przesuwamy element tylko wtedy, gdy to możliwe (tzn. sąsiadujacy element jest pusty)
	if (!(abs(x - EmptyPieceX) == 1 && abs(y - EmptyPieceY) == 0) != !(abs(y - EmptyPieceY) == 1 && abs(x - EmptyPieceX) == 0))
	{
		// zamieniamy miejscami elementy w wektorze PuzzlePieces...
		std::swap(PuzzlePieces[EmptyPieceX*SizeY + EmptyPieceY], PuzzlePieces[x*SizeY + y]);
		// ...oraz zamieniamy informacje o ich pozycji na obszarze gry
		PuzzlePieces[this->EmptyPieceX*SizeY + EmptyPieceY].swapVisibleImageData(PuzzlePieces[x*SizeY + y]);
		// zwiększamy licznik ruchów, jeśli gra się toczy
		if (!shufflingMode)
			moveCount++;
		// ustawiamy nowe współrzędne dla "pustego" elementu
		setEmptyPiece(x, y);
	}
	// jeśli gra była w trakcie i układanka została rozwiązana, wyświetlamy komunikat
	if (!shufflingMode && isFinished())
	{
		QString finishMessage = "You solved the puzzle!\nIt took you " + QString::number(moveCount) + " moves.";
		QMessageBox::information(this, "Congratulations", finishMessage);
	}
}

int PuzzleArea::getEmptyPieceX()
{
	return EmptyPieceX;
}

int PuzzleArea::getEmptyPieceY()
{
	return EmptyPieceY;
}

bool PuzzleArea::setEmptyPieceX(const int x)
{
	if (x >= 0 && x < SizeX)
	{
		EmptyPieceX = x;
		return true;
	}
	else
	{
		return false;
	}
}

bool PuzzleArea::setEmptyPieceY(const int y)
{
	if (y >= 0 && y < SizeY)
	{
		EmptyPieceY = y;
		return true;
	}
	else
	{
		return false;
	}
}

bool PuzzleArea::setEmptyPiece(const int x, const int y)
{
	return setEmptyPieceX(x) && setEmptyPieceY(y);
}

// used for debugging only - delete
//void PuzzleArea::mousePressEvent(QMouseEvent *qevent)
//{
//	this->puzzlePieceWidth = this->width() / this->SizeX;
//	this->puzzlePieceHeight = this->width() / this->SizeY;
//	if (qevent->button() == Qt::LeftButton)
//	{
//		int x = qevent->pos().x();
//		int y = qevent->pos().y();
//
//		QString textStr = "X: " + QString::number(qevent->pos().x()) + ", Y: " + QString::number(qevent->pos().y());
//		QMessageBox::information(this, "Information", textStr);
//	}
//}

/**
Parametr complexity określa, jak wiele ruchów zostaje wykonanych podczas mieszania (liczone jako complexity*ilość elementów układanki).
*/
void PuzzleArea::shuffle(const int complexity)
{
	// mieszamy tak długo, aż układanka nie będzie w stanie "rozwiązanym"
	while (isFinished())
	{
		int currentX = EmptyPieceX;
		int currentY = EmptyPieceY;
		for (int i = 0; i < PuzzlePieces.size()*complexity; i++)
		{
			while (currentX == EmptyPieceX && currentY == EmptyPieceY)
			{
				int xory = qrand() % 2;
				if (xory == 0) // przesuwamy po x
				{
					int leftOrRight = qrand() % 2;
					if (leftOrRight == 0) // w lewo
					{
						if (currentX != 0)
							currentX--;
					}
					else // w prawo
					{
						if (currentX != SizeX - 1)
							currentX++;
					}
				}
				else // przesuwamy po y
				{
					int upOrDown = qrand() % 2;
					if (upOrDown == 0) // w górę
					{
						if (currentY != 0)
							currentY--;
					}
					else // w dół
					{
						if (currentY != SizeY - 1)
							currentY++;
					}
				}
			}
			movePuzzlePiece(currentX, currentY, true);
		}
		PuzzlePieces[EmptyPieceX*SizeY + EmptyPieceY].setVisible(false);
	}
}

bool PuzzleArea::isFinished()
{
	for (int i = 0; i < SizeX; i++)
	{
		for (int j = 0; j < SizeY; j++)
		{
			if (!PuzzlePieces[i*SizeY + j].isInCorrectPosition(i, j))
				return false;
		}
	}
	PuzzlePieces[EmptyPieceX*SizeY + EmptyPieceY].setVisible(true);
	return true;
}

void PuzzleArea::startGame(const int elementsX, const int elementsY, QString fileName)
{
	moveCount = 0;
	// jeśli nie podano nazwy pliku to sprawdzamy, czy już mamy jakiś obrazek załadowany
	if (fileName.isNull() || fileName.isEmpty())
	{
		if (!puzzlePictureFileName.isNull() && !puzzlePictureFileName.isEmpty())
			fileName = puzzlePictureFileName;
	}

	//QPalette framePalette = palette();
	//framePalette.setColor(QPalette::Background, Qt::red);
	//setAutoFillBackground(true);
	//setPalette(framePalette);

	PuzzlePieces.resize(0);
	QImage puzzleImage;

	// jeśli nie ma załadowanego obrazku lub podany plik nie jest obsługiwany, ustawiamy domyślny obrazek
	if (fileName.isNull() || fileName.isEmpty() || !puzzleImage.load(fileName))
	{
		QString defaultImage = "";
		for (int i = 0; i < defaultImageBase64.count(); i++)
		{
			defaultImage += defaultImageBase64[i];
		}
		QByteArray imageData = QByteArray::fromBase64(defaultImage.toLatin1());
		puzzleImage.loadFromData(imageData);
	}
	else
	{
		puzzlePictureFileName = fileName;
	}

	SizeX = elementsX;
	SizeY = elementsY;
	QSize newSize(this->size());
	newSize.setWidth(newSize.width() - SizeX * puzzlePieceSpacingX);
	newSize.setHeight(newSize.height() - SizeY * puzzlePieceSpacingY);
	QPixmap imageMap = QPixmap::fromImage(puzzleImage).scaled(newSize, Qt::KeepAspectRatio);// QPixmap::fromImage(newPiece->pixmap()->toImage());
	this->setBaseSize(imageMap.size());

	QSize s1 = imageMap.size();
	QSize s2 = this->size();
	//imageMap.res
	int puzzlePieceWidth = imageMap.width() / SizeY;// (this->width() < imageMap.width()) ? this->width() / this->SizeX : imageMap.width() / this->SizeX;
	int puzzlePieceHeight = imageMap.height() / SizeX;//(this->height() < imageMap.height()) ? this->height() / this->SizeY : imageMap.height() / this->SizeY;

	PuzzlePieces.resize(this->SizeX*this->SizeY);
	//PuzzlePieces = new PuzzlePiece*[this->SizeX];
	/*for (int i = 0; i < this->SizeX; i++)
	PuzzlePieces[i] = new PuzzlePiece[this->SizeY];
	*/
	//auto layout = new QGridLayout();// QBoxLayout::LeftToRight);// QVBoxLayout();
	//layout->setSpacing(1);
	//layout->setmSetMinAndMaxthis->Size
	//newGameArea->setLayout(layout);
	for (int i = 0; i < SizeX; i++)
	{
		//layout->setRowMinimumHeight(i, puzzlePieceHeight);// +1);
		//layout->setRowStretch(i, 1);
		//layout.row
		for (int j = 0; j < SizeY; j++)
		{
			PuzzlePieces[i*SizeY + j].setPuzzleArea(this);
			PuzzlePieces[i*SizeY + j].setCorrectPosition(i, j);
			PuzzlePieces[i*SizeY + j].setCurrentPosition(i, j);
			//QPixmap newMap = imageMap.copy(j * puzzlePieceWidth, i * puzzlePieceHeight, puzzlePieceWidth, puzzlePieceHeight);// 100, 100);
			QPixmap newMap = imageMap.copy(j * puzzlePieceWidth, i * puzzlePieceHeight, puzzlePieceWidth, puzzlePieceHeight);// 100, 100);
			PuzzlePieces[i*SizeY + j].setPixmap(newMap);
			PuzzlePieces[i*SizeY + j].setParent(this);
			//PuzzlePieces[i*SizeY + j].setGeometry(j * puzzlePieceWidth + i * puzzlePieceSpacingX, j * puzzlePieceHeight + j * puzzlePieceSpacingY, puzzlePieceWidth, puzzlePieceHeight);
			PuzzlePieces[i*SizeY + j].setGeometry(j * puzzlePieceWidth + j * puzzlePieceSpacingX, i * puzzlePieceHeight + i * puzzlePieceSpacingY, puzzlePieceWidth, puzzlePieceHeight);
			PuzzlePieces[i*SizeY + j].show();
			//layout->addWidget(&puzzleBoard[i][j], i, j);
			//this->layout()->addWidget(&puzzleBoard[i][j]);
			//puzzleBoard[i][j].setGeometry(j * puzzlePieceWidth + 10, i * puzzlePieceHeight + 10, puzzlePieceWidth, puzzlePieceHeight);
			//this->layout()->invalidate();// repaint();
		}
	}
	//PuzzlePieces[sizeX]
	this->EmptyPieceX = SizeX - 1;
	this->EmptyPieceY = SizeY - 1;

	//PuzzlePieces[EmptyPieceX*SizeY + EmptyPieceY].setVisible(false);

	/*PuzzlePiece* missingPiece = &PuzzlePieces[this->EmptyPieceX*this->SizeY + this->EmptyPieceY];
	missingPiece->setVisible(false);*/
}

int PuzzleArea::getMoveCount()
{
	return moveCount;
}