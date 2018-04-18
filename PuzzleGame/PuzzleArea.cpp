#include "PuzzleArea.h"

PuzzleArea::PuzzleArea(QWidget *parent)
{
	setParent(parent);
	emptyPieceX = -1;
	emptyPieceY = -1;
	
	//StartGame(5, 5);

}

PuzzleArea::~PuzzleArea()
{
}

void PuzzleArea::resizeEvent(QResizeEvent *event)
{
	resizePuzzlePieces();
	/*int a = 2;
	if (PuzzlePieces.count() > 0)
	{
		for (int i = 0; i < sizeX; i++)
		{
			for (int j = 0; j < sizeY; j++)
			{
				PuzzlePieces[i*sizeY + j].resizePuzzlePiece();
			}
		}
	}*/
	//QMessageBox::information(this, "Congratulations", "Resize event fired");
}

void PuzzleArea::movePuzzlePiece(const int x, const int y, bool shufflingMode)
{
	if (!gameOver)
	{
		// przesuwamy element tylko wtedy, gdy to możliwe (tzn. sąsiadujacy element jest pusty)
		if (!(abs(x - emptyPieceX) == 1 && abs(y - emptyPieceY) == 0) != !(abs(y - emptyPieceY) == 1 && abs(x - emptyPieceX) == 0))
		{
			// zamieniamy miejscami elementy w wektorze PuzzlePieces...
			std::swap(PuzzlePieces[emptyPieceX*sizeY + emptyPieceY], PuzzlePieces[x*sizeY + y]);
			// ...oraz zamieniamy informacje o ich pozycji na obszarze gry
			PuzzlePieces[emptyPieceX*sizeY + emptyPieceY].swapVisibleImageData(PuzzlePieces[x*sizeY + y]);
			// zwiększamy licznik ruchów, jeśli gra się toczy
			if (!shufflingMode)
				moveCount++;
			// ustawiamy nowe współrzędne dla "pustego" elementu
			setEmptyPiece(x, y);
		}
		// jeśli gra była w trakcie i układanka została rozwiązana, wyświetlamy komunikat
		if (!shufflingMode && isFinished())
		{
			qint64 timeElapsed = finishGame() / 1000;
			QString finishMessage = "You solved the puzzle!\nIt took you " + QString::number(moveCount) + " moves\nor "+QString::number(timeElapsed) + " seconds.";
			QMessageBox::information(this, "Congratulations", finishMessage);
		}
	}
}

int PuzzleArea::getEmptyPieceX()
{
	return emptyPieceX;
}

int PuzzleArea::getEmptyPieceY()
{
	return emptyPieceY;
}

bool PuzzleArea::setEmptyPieceX(const int x)
{
	if (x >= 0 && x < sizeX)
	{
		emptyPieceX = x;
		return true;
	}
	else
	{
		return false;
	}
}

bool PuzzleArea::setEmptyPieceY(const int y)
{
	if (y >= 0 && y < sizeY)
	{
		emptyPieceY = y;
		return true;
	}
	else
	{
		return false;
	}
}

bool PuzzleArea::setEmptyPiece(const int x, const int y)
{
	if (setEmptyPieceX(x) && setEmptyPieceY(y))
	{
		PuzzlePieces[x*sizeY + y].setVisible(false);
		return true;
	}
	return false;
}

/**
Parametr complexity określa, jak wiele ruchów zostaje wykonanych podczas mieszania (liczone jako complexity*ilość elementów układanki).
*/
void PuzzleArea::shuffle(int complexity)
{
	// nawet 1000 to pewnie za dużo, no ale jeśli ktoś bardzo chce...
	if (complexity < 1 || complexity > 1000)
		complexity = defaultComplexity;
	// mieszamy tak długo, aż układanka nie będzie w stanie "rozwiązanym"
	while (isFinished())
	{
		int currentX = emptyPieceX;
		int currentY = emptyPieceY;
		for (int i = 0; i < PuzzlePieces.size()*complexity; i++)
		{
			while (currentX == emptyPieceX && currentY == emptyPieceY)
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
						if (currentX != sizeX - 1)
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
						if (currentY != sizeY - 1)
							currentY++;
					}
				}
			}
			movePuzzlePiece(currentX, currentY, true);
		}
		/*PuzzlePieces[emptyPieceX*sizeY + emptyPieceY].setVisible(false);*/
	}
}

bool PuzzleArea::isFinished()
{
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			if (!PuzzlePieces[i*sizeY + j].isInCorrectPosition(i, j))
				return false;
		}
	}
	PuzzlePieces[emptyPieceX*sizeY + emptyPieceY].setVisible(true);
	return true;
}

void PuzzleArea::resizePuzzlePieces()
{
	QSize newSize;
	newSize.setWidth(width() - (sizeY - 1) * puzzlePieceSpacingX);
	newSize.setHeight(height() - (sizeX - 1) * puzzlePieceSpacingY);
	QPixmap imageMap = QPixmap::fromImage(puzzleImage).scaled(newSize, Qt::KeepAspectRatio);
	
	int puzzlePieceWidth = imageMap.width() / sizeY;// (this->width() < imageMap.width()) ? this->width() / this->sizeX : imageMap.width() / this->sizeX;
	int puzzlePieceHeight = imageMap.height() / sizeX;
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			//PuzzlePieces[i*sizeY + j].setPuzzleArea(this);
			//PuzzlePieces[i*sizeY + j].setCorrectPosition(i, j);
			//PuzzlePieces[i*sizeY + j].setCurrentPosition(i, j);
			QPixmap newMap = imageMap.copy(PuzzlePieces[i*sizeY + j].getCorrectPositionY() * puzzlePieceWidth, PuzzlePieces[i*sizeY + j].getCorrectPositionX() * puzzlePieceHeight, puzzlePieceWidth, puzzlePieceHeight);
			PuzzlePieces[i*sizeY + j].setPixmap(newMap);
			//PuzzlePieces[i*sizeY + j].setParent(this);
			PuzzlePieces[i*sizeY + j].setGeometry(j * puzzlePieceWidth + j * puzzlePieceSpacingX, i * puzzlePieceHeight + i * puzzlePieceSpacingY, puzzlePieceWidth, puzzlePieceHeight);
			//PuzzlePieces[i*sizeY + j].show();
		}
	}
}

void PuzzleArea::startGame(int elementsX, int elementsY, int complexity, bool randomizeEmptyPiece, QString fileName)
{
	moveCount = 0;
	// jeśli nie podano nazwy pliku to sprawdzamy, czy już mamy jakiś obrazek załadowany
	/*if (fileName.isNull() || fileName.isEmpty())
	{
		if (!puzzlePictureFileName.isNull() && !puzzlePictureFileName.isEmpty())
			fileName = puzzlePictureFileName;
	}*/

	QPalette framePalette = palette();
	framePalette.setColor(QPalette::Background, Qt::red);
	setAutoFillBackground(true);
	setPalette(framePalette);

	PuzzlePieces.resize(0);
	//QImage puzzleImage;

	// jeśli nie ma załadowanego obrazku lub podany plik nie jest obsługiwany, ustawiamy domyślny obrazek
	if (fileName.isNull() || fileName.isEmpty() || !puzzleImage.load(fileName))
	{
		if (puzzleImage.isNull())
		{
			QString defaultImage = "";
			for (int i = 0; i < defaultImageBase64.count(); i++)
			{
				defaultImage += defaultImageBase64[i];
			}
			QByteArray imageData = QByteArray::fromBase64(defaultImage.toLatin1());
			puzzleImage.loadFromData(imageData);
		}
	}
	/*else
	{
		puzzlePictureFileName = fileName;
	}*/

	sizeX = elementsX;
	sizeY = elementsY;
	//QSize newSize(size());
	//newSize.setWidth(newSize.width() - (sizeX - 1) * puzzlePieceSpacingX);
	//newSize.setHeight(newSize.height() - (sizeY - 1) * puzzlePieceSpacingY);
	//QPixmap imageMap = QPixmap::fromImage(puzzleImage).scaled(newSize, Qt::KeepAspectRatio);
	//setBaseSize(imageMap.size());

	//int puzzlePieceWidth = imageMap.width() / sizeY;// (this->width() < imageMap.width()) ? this->width() / this->sizeX : imageMap.width() / this->sizeX;
	//int puzzlePieceHeight = imageMap.height() / sizeX;//(this->height() < imageMap.height()) ? this->height() / this->sizeY : imageMap.height() / this->sizeY;

	PuzzlePieces.resize(sizeX*sizeY);

	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			PuzzlePieces[i*sizeY + j].setPuzzleArea(this);
			PuzzlePieces[i*sizeY + j].setCorrectPosition(i, j);
			PuzzlePieces[i*sizeY + j].setCurrentPosition(i, j);
			//QPixmap newMap = imageMap.copy(j * puzzlePieceWidth, i * puzzlePieceHeight, puzzlePieceWidth, puzzlePieceHeight);
			//PuzzlePieces[i*sizeY + j].setPixmap(newMap);
			PuzzlePieces[i*sizeY + j].setParent(this);
			//PuzzlePieces[i*sizeY + j].setGeometry(j * puzzlePieceWidth + j * puzzlePieceSpacingX, i * puzzlePieceHeight + i * puzzlePieceSpacingY, puzzlePieceWidth, puzzlePieceHeight);
			PuzzlePieces[i*sizeY + j].show();
		}
	}

	resizePuzzlePieces();//imageMap, puzzlePieceWidth, puzzlePieceHeight);

	/*emptyPieceX = sizeX - 1;
	emptyPieceY = sizeY - 1;*/

	QMessageBox::information(this, "Information", "Get ready!");
	int emptyX = sizeX - 1;
	int emptyY = sizeY - 1;
	if (randomizeEmptyPiece)
	{
		emptyX = qrand() % sizeX;
		emptyY = qrand() % sizeY;
	}
	setEmptyPiece(emptyX, emptyY);
	QMessageBox::information(this, "Information", "I took one puzzle piece away. Remember its position!");
	beginGame();
	shuffle(complexity);
	timer.start();
}

int PuzzleArea::getMoveCount()
{
	return moveCount;
}

void PuzzleArea::beginGame()
{
	gameOver = false;
}

qint64 PuzzleArea::finishGame()
{
	gameOver = true;
	return timer.elapsed();
}
