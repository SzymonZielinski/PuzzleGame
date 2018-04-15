#include "PuzzleArea.h"

PuzzleArea::PuzzleArea(QWidget *parent)
{
	this->setParent(parent);
	emptyPieceX = -1;
	emptyPieceY = -1;

	//StartGame(5, 5);

	//delete puzzleImage;
}

PuzzleArea::~PuzzleArea()
{
}

void PuzzleArea::movePuzzlePiece(const int x, const int y, bool shufflingMode)
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
		QString finishMessage = "You solved the puzzle!\nIt took you " + QString::number(moveCount) + " moves.";
		QMessageBox::information(this, "Congratulations", finishMessage);
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
	return setEmptyPieceX(x) && setEmptyPieceY(y);
}

// used for debugging only - delete
//void PuzzleArea::mousePressEvent(QMouseEvent *qevent)
//{
//	this->puzzlePieceWidth = this->width() / this->sizeX;
//	this->puzzlePieceHeight = this->width() / this->sizeY;
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
		PuzzlePieces[emptyPieceX*sizeY + emptyPieceY].setVisible(false);
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

	sizeX = elementsX;
	sizeY = elementsY;
	QSize newSize(this->size());
	newSize.setWidth(newSize.width() - sizeX * puzzlePieceSpacingX);
	newSize.setHeight(newSize.height() - sizeY * puzzlePieceSpacingY);
	QPixmap imageMap = QPixmap::fromImage(puzzleImage).scaled(newSize, Qt::KeepAspectRatio);// QPixmap::fromImage(newPiece->pixmap()->toImage());
	this->setBaseSize(imageMap.size());

	QSize s1 = imageMap.size();
	QSize s2 = this->size();
	//imageMap.res
	int puzzlePieceWidth = imageMap.width() / sizeY;// (this->width() < imageMap.width()) ? this->width() / this->sizeX : imageMap.width() / this->sizeX;
	int puzzlePieceHeight = imageMap.height() / sizeX;//(this->height() < imageMap.height()) ? this->height() / this->sizeY : imageMap.height() / this->sizeY;

	PuzzlePieces.resize(this->sizeX*this->sizeY);
	//PuzzlePieces = new PuzzlePiece*[this->sizeX];
	/*for (int i = 0; i < this->sizeX; i++)
	PuzzlePieces[i] = new PuzzlePiece[this->sizeY];
	*/
	//auto layout = new QGridLayout();// QBoxLayout::LeftToRight);// QVBoxLayout();
	//layout->setSpacing(1);
	//layout->setmSetMinAndMaxthis->Size
	//newGameArea->setLayout(layout);
	for (int i = 0; i < sizeX; i++)
	{
		//layout->setRowMinimumHeight(i, puzzlePieceHeight);// +1);
		//layout->setRowStretch(i, 1);
		//layout.row
		for (int j = 0; j < sizeY; j++)
		{
			PuzzlePieces[i*sizeY + j].setPuzzleArea(this);
			PuzzlePieces[i*sizeY + j].setCorrectPosition(i, j);
			PuzzlePieces[i*sizeY + j].setCurrentPosition(i, j);
			//QPixmap newMap = imageMap.copy(j * puzzlePieceWidth, i * puzzlePieceHeight, puzzlePieceWidth, puzzlePieceHeight);// 100, 100);
			QPixmap newMap = imageMap.copy(j * puzzlePieceWidth, i * puzzlePieceHeight, puzzlePieceWidth, puzzlePieceHeight);// 100, 100);
			PuzzlePieces[i*sizeY + j].setPixmap(newMap);
			PuzzlePieces[i*sizeY + j].setParent(this);
			//PuzzlePieces[i*sizeY + j].setGeometry(j * puzzlePieceWidth + i * puzzlePieceSpacingX, j * puzzlePieceHeight + j * puzzlePieceSpacingY, puzzlePieceWidth, puzzlePieceHeight);
			PuzzlePieces[i*sizeY + j].setGeometry(j * puzzlePieceWidth + j * puzzlePieceSpacingX, i * puzzlePieceHeight + i * puzzlePieceSpacingY, puzzlePieceWidth, puzzlePieceHeight);
			PuzzlePieces[i*sizeY + j].show();
			//layout->addWidget(&puzzleBoard[i][j], i, j);
			//this->layout()->addWidget(&puzzleBoard[i][j]);
			//puzzleBoard[i][j].setGeometry(j * puzzlePieceWidth + 10, i * puzzlePieceHeight + 10, puzzlePieceWidth, puzzlePieceHeight);
			//this->layout()->invalidate();// repaint();
		}
	}
	//PuzzlePieces[sizeX]
	emptyPieceX = sizeX - 1;
	emptyPieceY = sizeY - 1;

	//PuzzlePieces[emptyPieceX*sizeY + emptyPieceY].setVisible(false);

	/*PuzzlePiece* missingPiece = &PuzzlePieces[this->emptyPieceX*this->sizeY + this->emptyPieceY];
	missingPiece->setVisible(false);*/
}

int PuzzleArea::getMoveCount()
{
	return moveCount;
}