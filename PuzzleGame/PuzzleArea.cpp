#include "PuzzleArea.h"

PuzzleArea::PuzzleArea(QWidget *parent)
{
	setParent(parent);
	emptyPieceX = -1;
	emptyPieceY = -1;
}

PuzzleArea::~PuzzleArea()
{
	PuzzlePieces.resize(0);
}

void PuzzleArea::resizeEvent(QResizeEvent *event)
{
	resizePuzzlePieces();
}

void PuzzleArea::movePuzzlePiece(const int x, const int y, bool shufflingMode)
{
	if (!gameOver && !animationInProgress)
	{
		// przesuwamy element tylko wtedy, gdy to możliwe (tzn. sąsiadujacy element jest pusty)
		if (!(abs(x - emptyPieceX) == 1 && abs(y - emptyPieceY) == 0) != !(abs(y - emptyPieceY) == 1 && abs(x - emptyPieceX) == 0))
		{
			if (useAnimations && !shufflingMode)
			{				
				animation = new QPropertyAnimation(&PuzzlePieces[x*sizeY + y], "geometry");
				animation->setDuration(animationSpeed);
				animation->setStartValue(PuzzlePieces[x*sizeY + y].geometry());
				animation->setEndValue(PuzzlePieces[emptyPieceX*sizeY + emptyPieceY].geometry());
				PuzzlePieces[emptyPieceX*sizeY + emptyPieceY].setGeometry(PuzzlePieces[x*sizeY + y].geometry());
				connect(animation, SIGNAL(finished()), this, SLOT(swapPiecesAfterAnimation()));
				lastX = x;
				lastY = y;
				animationInProgress = true;
				animation->start(QPropertyAnimation::DeleteWhenStopped);
			}
			else
			{
				// zamieniamy elementy miejscami
				PuzzlePieces[emptyPieceX*sizeY + emptyPieceY].swapPuzzlePiece(PuzzlePieces[x*sizeY + y]);
				// ustawiamy nowe współrzędne dla "pustego" elementu
				setEmptyPiece(x, y);
			}
						
			// zwiększamy licznik ruchów, jeśli gra się toczy
			if (!shufflingMode)
				moveCount++;
		}
		// jeśli gra była w trakcie i układanka została rozwiązana, wyświetlamy komunikat
		if (!shufflingMode)
			checkIfFinished();
	}
}

void PuzzleArea::checkIfFinished()
{
	if (isFinished())
	{
		timeElapsed = finishGame() / 1000;
		if (useAnimations)
		{
			animationInProgress = true;
			QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(&PuzzlePieces[emptyPieceX*sizeY + emptyPieceY]);
			PuzzlePieces[emptyPieceX*sizeY + emptyPieceY].setGraphicsEffect(eff);
			animation = new QPropertyAnimation(eff, "opacity");
			animation->setDuration(animationSpeed);
			animation->setStartValue(0);
			animation->setEndValue(1);
			animation->setEasingCurve(QEasingCurve::InQuad);
			connect(animation, SIGNAL(finished()), this, SLOT(endGame()));
			animation->start(QPropertyAnimation::DeleteWhenStopped);
			PuzzlePieces[emptyPieceX*sizeY + emptyPieceY].setVisible(true);
		}
		else
		{
			PuzzlePieces[emptyPieceX*sizeY + emptyPieceY].setVisible(true);
			showSummary();
		}
	}
}

void PuzzleArea::showSummary()
{
	QString finishMessage = "You solved the puzzle!\nIt took you " + QString::number(moveCount) + " moves\nor " + QString::number(timeElapsed) + " seconds.";
	QMessageBox::information(this, "Congratulations", finishMessage);
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
Parametr difficulty określa, jak wiele ruchów zostaje wykonanych podczas mieszania (liczone jako difficulty*ilość elementów układanki).
*/
void PuzzleArea::shuffle(int difficulty)
{
	// nawet 1000 to pewnie za dużo, no ale jeśli ktoś bardzo chce...
	if (difficulty < 1 || difficulty > 1000)
		difficulty = defaultDifficulty;
	// mieszamy tak długo, aż układanka nie będzie w stanie "rozwiązanym"
	while (isFinished(true))
	{
		int currentX = emptyPieceX;
		int currentY = emptyPieceY;
		for (int i = 0; i < PuzzlePieces.size()*difficulty; i++)
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
	}
}

bool PuzzleArea::isFinished(bool shufflingMode)
{
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			if (!PuzzlePieces[i*sizeY + j].isInCorrectPosition(i, j))
				return false;
		}
	}
	return true;
}

void PuzzleArea::resizePuzzlePieces()
{
	QSize newSize;
	newSize.setWidth(width() - (sizeY - 1) * puzzlePieceSpacingY);
	newSize.setHeight(height() - (sizeX - 1) * puzzlePieceSpacingX);
	QPixmap imageMap = QPixmap::fromImage(puzzleImage).scaled(newSize, Qt::KeepAspectRatio);
	
	int puzzlePieceWidth = imageMap.width() / sizeY;
	int puzzlePieceHeight = imageMap.height() / sizeX;
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			QPixmap newMap = imageMap.copy(PuzzlePieces[i*sizeY + j].getCorrectPositionY() * puzzlePieceWidth, PuzzlePieces[i*sizeY + j].getCorrectPositionX() * puzzlePieceHeight, puzzlePieceWidth, puzzlePieceHeight);
			PuzzlePieces[i*sizeY + j].setPixmap(newMap);
			PuzzlePieces[i*sizeY + j].setGeometry(j * puzzlePieceWidth + j * puzzlePieceSpacingY, i * puzzlePieceHeight + i * puzzlePieceSpacingX, puzzlePieceWidth, puzzlePieceHeight);
		}
	}
}

void PuzzleArea::newGame(int elementsX, int elementsY, int difficulty, bool randomizeEmptyPiece, QString fileName, int spacingX, int spacingY, bool startImmediately)
{
	//QPalette framePalette = palette();
	//framePalette.setColor(QPalette::Background, Qt::red);
	//setAutoFillBackground(true);
	//setPalette(framePalette);

	difficultyLevel = difficulty;
	// prawdopodobnie można pominąć tą linijkę
	PuzzlePieces.resize(0);

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

	sizeX = elementsX;
	sizeY = elementsY;
	puzzlePieceSpacingX = spacingX;
	puzzlePieceSpacingY = spacingY;

	// sprawdzamy poprawność parametrów
	if (puzzlePieceSpacingX < minPuzzlePieceSpacingX)
		puzzlePieceSpacingX = minPuzzlePieceSpacingX;
	if (puzzlePieceSpacingY < minPuzzlePieceSpacingY)
		puzzlePieceSpacingY = minPuzzlePieceSpacingY;
	if (puzzlePieceSpacingX > maxPuzzlePieceSpacingX)
		puzzlePieceSpacingX = maxPuzzlePieceSpacingX;
	if (puzzlePieceSpacingY > maxPuzzlePieceSpacingY)
		puzzlePieceSpacingY = maxPuzzlePieceSpacingY;

	int puzzlePieceWidthCheck = width() / sizeY - (sizeY - 1)*puzzlePieceSpacingY;
	int puzzlePieceHeightCheck = height() / sizeX - (sizeX - 1)*puzzlePieceSpacingX;

	// jeśli podano tak dużą liczbę wierszy lub kolumn, że elementy byłyby zbyt małe, dostosowujemy parametry
	if (puzzlePieceWidthCheck < minPuzzlePieceWidth)
	{
		puzzlePieceWidthCheck = minPuzzlePieceWidth;
		sizeY = width() / minPuzzlePieceWidth;
		while (sizeY*minPuzzlePieceWidth + (sizeY - 1)*puzzlePieceSpacingY > width())
		{
			sizeY--;
		}
	}
	if (puzzlePieceHeightCheck < minPuzzlePieceHeight)
	{
		puzzlePieceHeightCheck = minPuzzlePieceHeight;
		sizeX = height() / minPuzzlePieceHeight;
		while (sizeX*minPuzzlePieceHeight + (sizeX - 1)*puzzlePieceSpacingX > height())
		{
			sizeX--;
		}
	}

	PuzzlePieces.resize(sizeX*sizeY);

	// pokazujemy wszystkie elementy
	for (int i = 0; i < sizeX; i++)
	{
		for (int j = 0; j < sizeY; j++)
		{
			PuzzlePieces[i*sizeY + j].setPuzzleArea(this);
			PuzzlePieces[i*sizeY + j].setCorrectPosition(i, j);
			PuzzlePieces[i*sizeY + j].setCurrentPosition(i, j);
			PuzzlePieces[i*sizeY + j].setParent(this);
			PuzzlePieces[i*sizeY + j].show();
		}
	}

	resizePuzzlePieces();

	if (startImmediately)
		beginGame(randomizeEmptyPiece);
}

int PuzzleArea::getMoveCount()
{
	return moveCount;
}

void PuzzleArea::beginGame(bool randomizeEmptyPiece)
{
	gameOver = false;
	animationInProgress = false;

	// wyświetlamy komunikat
	QMessageBox::information(this, "Information", "Get ready!");
	// domyślnie ustawiamy pusty element na dolny prawy róg
	int emptyX = sizeX - 1;
	int emptyY = sizeY - 1;
	// jeśli pozycja pustego elementu ma być losowa, to ją losujemy
	if (randomizeEmptyPiece)
	{
		emptyX = qrand() % sizeX;
		emptyY = qrand() % sizeY;
	}
	setEmptyPiece(emptyX, emptyY);

	if (useAnimations)
	{
		animationInProgress = true;
		QGraphicsOpacityEffect *eff = new QGraphicsOpacityEffect(&PuzzlePieces[emptyPieceX*sizeY + emptyPieceY]);
		PuzzlePieces[emptyPieceX*sizeY + emptyPieceY].setGraphicsEffect(eff);
		animation = new QPropertyAnimation(eff, "opacity");
		animation->setDuration(animationSpeed);
		animation->setStartValue(1);
		animation->setEndValue(0);
		animation->setEasingCurve(QEasingCurve::OutQuad);
		connect(animation, SIGNAL(finished()), this, SLOT(veryBeginGame()));
		animation->start(QPropertyAnimation::DeleteWhenStopped);
		PuzzlePieces[emptyPieceX*sizeY + emptyPieceY].setVisible(true);
	}
	else
	{
		startGame();
	}
}

void PuzzleArea::startGame()
{
	// po ustawieniu pustego elementu wyświetlamy kolejny komunikat, aby użytkownik mógł zauważyć zmianę
	QMessageBox::information(this, "Information", "I took one puzzle piece away. Remember its position!");
	// mieszamy ukladankę i rozpoczynamy odliczanie czasu
	shuffle(difficultyLevel);
	moveCount = 0;
	timer.start();
}

qint64 PuzzleArea::finishGame()
{
	gameOver = true;
	return timer.elapsed();
}

void PuzzleArea::swapPiecesAfterAnimation()
{
	// w przypadku animacji musimy jeszcze raz zamienić właściwość geometry(), aby były takie jak przed animacją
	QRect g = PuzzlePieces[lastX*sizeY + lastY].geometry();
	PuzzlePieces[lastX*sizeY + lastY].setGeometry(PuzzlePieces[emptyPieceX*sizeY + emptyPieceY].geometry());
	PuzzlePieces[emptyPieceX*sizeY + emptyPieceY].setGeometry(g);
	// po czym zastępujemy je tak, jak w przypadku, gdyby nie było animacji
	PuzzlePieces[emptyPieceX*sizeY + emptyPieceY].swapPuzzlePiece(PuzzlePieces[lastX*sizeY + lastY]);
	// ustawiamy nowe współrzędne dla "pustego" elementu
	setEmptyPiece(lastX, lastY);
	animationInProgress = false;
	// sprawdzamy, czy zakończono układanie
	checkIfFinished();
}

void PuzzleArea::endGame()
{
	animationInProgress = false;
	// usuwamy efekt fade in
	PuzzlePieces[emptyPieceX*sizeY + emptyPieceY].setGraphicsEffect(Q_NULLPTR);
	showSummary();
}

void PuzzleArea::veryBeginGame()
{
	animationInProgress = false;
	// usuwamy efekt fade out
	PuzzlePieces[emptyPieceX*sizeY + emptyPieceY].setGraphicsEffect(Q_NULLPTR);
	PuzzlePieces[emptyPieceX*sizeY + emptyPieceY].setVisible(false);
	startGame();
}

void PuzzleArea::setAnimation(bool animate)
{
	useAnimations = animate;
}

bool PuzzleArea::setAnimationSpeed(int speed)
{
	if (speed >= minAnimationSpeed && speed <= maxAnimationSpeed)
	{
		animationSpeed = speed;
		return true;
	}
	return false;
}