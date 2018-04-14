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
	/*for (int i = 0; i < this->SizeY; i++)
	{
		delete[] PuzzlePieces[i];
	}
	delete[] PuzzlePieces;*/
}

void PuzzleArea::MovePuzzlePiece(const int rowPosition, const int colPosition, bool shufflingMode)
{
	//QMessageBox::information(this, "Information", "Something");
	if (!(abs(rowPosition - EmptyPieceX) == 1 && abs(colPosition - EmptyPieceY) == 0) != !(abs(colPosition - EmptyPieceY) == 1 && abs(rowPosition - EmptyPieceX) == 0))
	{
		int tmpX = rowPosition;
		int tmpY = colPosition;
		// TODO: SWAP PUZZLE ELEMENTS


		/*PuzzlePieces[this->EmptyPieceX*this->SizeX + this->EmptyPieceY].SetCurrentPosition(rowPosition, colPosition);

		PuzzlePieces[rowPosition*this->SizeX + colPosition].SetCurrentPosition(this->EmptyPieceX, this->EmptyPieceY);

		this->EmptyPieceX = rowPosition;
		this->EmptyPieceY = colPosition;
*/


		//PuzzlePieces[this->EmptyPieceX*this->SizeX + this->EmptyPieceY]
		//TODO********************************

		QRect g1 = PuzzlePieces[EmptyPieceX*SizeY + EmptyPieceY].geometry();
		QRect g2 = PuzzlePieces[rowPosition*SizeY + colPosition].geometry();

		std::swap(PuzzlePieces[EmptyPieceX*SizeY + EmptyPieceY], PuzzlePieces[rowPosition*SizeY + colPosition]);
		PuzzlePieces[this->EmptyPieceX*SizeY + EmptyPieceY].Swap(PuzzlePieces[rowPosition*SizeY + colPosition]);
		if (!shufflingMode)
			moveCount++;

		//SwapPieces(&PuzzlePieces[this->EmptyPieceX*this->SizeX + this->EmptyPieceY], &PuzzlePieces[rowPosition*this->SizeX + colPosition]);
		g1 = PuzzlePieces[this->EmptyPieceX*this->SizeY + this->EmptyPieceY].geometry();
		g2 = PuzzlePieces[rowPosition*this->SizeY + colPosition].geometry();

		setEmptyPieceX(rowPosition);
		setEmptyPieceY(colPosition);

		g1 = PuzzlePieces[this->EmptyPieceX*this->SizeY + this->EmptyPieceY].geometry();
		int a = 2; // delete, used for debugging
		//PuzzlePiece tmp = PuzzlePieces[this->EmptyPieceX*this->SizeX + this->EmptyPieceY];
		//PuzzlePieces[this->EmptyPieceX*this->SizeX + this->EmptyPieceY] = PuzzlePieces[rowPosition*this->SizeX + colPosition];
		//PuzzlePieces[rowPosition*this->SizeX+colPosition] = tmp;
		
		//PuzzlePiece* tmpPiece = &PuzzlePieces[this->EmptyPieceX][this->EmptyPieceY];
		//this->PuzzlePieces[this->EmptyPieceX][this->EmptyPieceY] = this->PuzzlePieces[rowPosition][colPosition];
	//	PuzzlePieces[rowPosition][colPosition] = *tmpPiece;
	}
	//QMessageBox::information(this, "Congratulations", "A");
	//PuzzlePieces[rowPosition][colPosition];
	if (!shufflingMode && IsFinished())
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

void PuzzleArea::clickOnPuzzleArea()
{
//	if (abs(currentX - ))
		//myPuzzleArea
}

//void mousePressedEvent(QMouseEvent *me) 
//{
//	if (me->buttons() ^ me->button())
//	{
//		QFrame::mousePressedEvent(me);
//		return;
//	}
//
//	if (me->button() == QMouseEvent::left:LeftMouse)
//	{
//		emit(myMousePressedSignal());
//		// here you shoud remember click event...
//		me->accept();
//		return;
//	}
//
//	QFrame::mousePressedEvent(me);
//}

void PuzzleArea::mousePressEvent(QMouseEvent *qevent)
{
	//return;
	this->puzzlePieceWidth = this->width() / this->SizeX;
	this->puzzlePieceHeight = this->width() / this->SizeY;
	if (qevent->button() == Qt::LeftButton)
	{
		int x = qevent->pos().x();
		int y = qevent->pos().y();

		QString textStr = "X: " + QString::number(qevent->pos().x()) + ", Y: " + QString::number(qevent->pos().y());
		QMessageBox::information(this, "Information", textStr);
		
		//this->setVisible(!this->isVisible());
	}
	for (int i = 0; i < this->SizeX; i++)
	{
		//layout->setRowMinimumHeight(i, puzzlePieceHeight);// +1);
		//layout->setRowStretch(i, 1);
		//layout.row
		for (int j = 0; j < this->SizeY; j++)
		{
			//layout->setColumnMinimumWidth(j, puzzlePieceWidth);// +1);
			//puzzleBoard[i][j].SetPuzzleArea(newGameArea);

			//if (PuzzlePieces[i*SizeX + j].clicked)
			//{
			//	QMessageBox::information(this, "Information", "Time to move the piece");
			//}
		}
	}

}

void PuzzleArea::SwapPieces(PuzzlePiece* puzzlePiece1, PuzzlePiece* puzzlePiece2)
{
	//PuzzlePiece* tmpPiece = puzzlePiece1;
	//puzzlePiece1 = puzzlePiece2;
	//puzzlePiece2 = tmpPiece;

	PuzzlePiece tmpPiece = *puzzlePiece1;
	*puzzlePiece1 = *puzzlePiece2;
	*puzzlePiece2 = tmpPiece;
}

//void mouseRelessedEvent(QMouseEvent *me)
//{
//	if (me->button()) { QFrame::mouseReleasedEvent(me); return; }
//
//	// here emit released and click signal if clicked... if not just call mouseReleasedEvent
//	// from the base class and forget about clicked, if clicked... 
//
//	// Anyway each widget receives those events, not only QFrame.... 
//}

void PuzzleArea::Shuffle(const int complexity)
{
	while (IsFinished())
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
					if (leftOrRight == 0) // left
					{
						if (currentX != 0)
							currentX--;
					}
					else
					{
						if (currentX != SizeX - 1)
							currentX++;
					}
				}
				else // przesuwamy po y
				{
					int upOrDown = qrand() % 2;
					if (upOrDown == 0) // up
					{
						if (currentY != 0)
							currentY--;
					}
					else
					{
						if (currentY != SizeY - 1)
							currentY++;
					}
				}
			}
			//if (currentX != EmptyPieceX || currentY != EmptyPieceY)

			MovePuzzlePiece(currentX, currentY, true);

			/*std::swap(PuzzlePieces[this->EmptyPieceX*this->SizeX + this->EmptyPieceY], PuzzlePieces[currentX*this->SizeX + currentY]);
			PuzzlePieces[this->EmptyPieceX*this->SizeX + this->EmptyPieceY].Swap(PuzzlePieces[currentX*this->SizeX + currentY]);
			setEmptyPiece(currentX, currentY);*/

		}
		PuzzlePieces[EmptyPieceX*SizeY + EmptyPieceY].setVisible(false);
	}

}
bool PuzzleArea::IsFinished()
{
	for (int i = 0; i < this->SizeX; i++)
	{
		//layout->setRowMinimumHeight(i, puzzlePieceHeight);// +1);
		//layout->setRowStretch(i, 1);
		//layout.row
		for (int j = 0; j < this->SizeY; j++)
		{
			if (!PuzzlePieces[i*this->SizeY + j].IsInCorrectPosition(i, j))
				return false;
		}
	}
	PuzzlePieces[EmptyPieceX*SizeY+EmptyPieceY].setVisible(true);
	return true;
}

void PuzzleArea::StartGame(const int elementsX, const int elementsY, QString fileName)
{
	moveCount = 0;
	if (fileName.isNull() || fileName.isEmpty())
	{
		if (!puzzlePictureFileName.isNull() && !puzzlePictureFileName.isEmpty())
			fileName = puzzlePictureFileName;
	}
	QPalette framePalette = palette();
	framePalette.setColor(QPalette::Background, Qt::red);
	setAutoFillBackground(true);
	setPalette(framePalette);
	
	PuzzlePieces.resize(0);
	//QString fileName = "d:\\ss.png";
	QImage puzzleImage;// = new QImage();

	//QFileInfo check_file(fileName);
	//// check if file exists and if yes: Is it really a file and not a directory
	//if (!check_file.exists() || !check_file.isFile())
	//{
	//	QString defaultImage = "";
	//	for (int i = 0; i < defaultImageBase64.count(); i++)
	//	{
	//		defaultImage += defaultImageBase64[i];
	//	}
	//	QByteArray imageData = QByteArray::fromBase64(defaultImage.toLatin1());
	//}

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

		this->SizeX = elementsX;
		this->SizeY = elementsY;
		QSize newSize(this->size());
		newSize.setWidth(newSize.width() - SizeX * puzzlePieceSpacingX);
		newSize.setHeight(newSize.height() - SizeY * puzzlePieceSpacingY);
		QPixmap imageMap = QPixmap::fromImage(puzzleImage).scaled(newSize, Qt::KeepAspectRatio);// QPixmap::fromImage(newPiece->pixmap()->toImage());
		this->setBaseSize(imageMap.size());
		
		QSize s1 = imageMap.size();
		QSize s2 = this->size();
		//imageMap.res
		int puzzlePieceWidth = imageMap.width() / this->SizeY;// (this->width() < imageMap.width()) ? this->width() / this->SizeX : imageMap.width() / this->SizeX;
		int puzzlePieceHeight = imageMap.height() / this->SizeX;//(this->height() < imageMap.height()) ? this->height() / this->SizeY : imageMap.height() / this->SizeY;

		PuzzlePieces.resize(this->SizeX*this->SizeY);
		//PuzzlePieces = new PuzzlePiece*[this->SizeX];
		/*for (int i = 0; i < this->SizeX; i++)
		PuzzlePieces[i] = new PuzzlePiece[this->SizeY];
		*/
		//auto layout = new QGridLayout();// QBoxLayout::LeftToRight);// QVBoxLayout();
		//layout->setSpacing(1);
		//layout->setmSetMinAndMaxthis->Size
		//newGameArea->setLayout(layout);
		for (int i = 0; i < this->SizeX; i++)
		{
			//layout->setRowMinimumHeight(i, puzzlePieceHeight);// +1);
			//layout->setRowStretch(i, 1);
			//layout.row
			for (int j = 0; j < this->SizeY; j++)
			{
				//layout->setColumnMinimumWidth(j, puzzlePieceWidth);// +1);
				PuzzlePieces[i*SizeY + j].SetPuzzleArea(this);
				PuzzlePieces[i*SizeY + j].SetCorrectPosition(i, j);
				PuzzlePieces[i*SizeY + j].SetCurrentPosition(i, j);
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
		this->EmptyPieceX = this->SizeX - 1;
		this->EmptyPieceY = this->SizeY - 1;

		//PuzzlePieces[EmptyPieceX*SizeY + EmptyPieceY].setVisible(false);

		/*PuzzlePiece* missingPiece = &PuzzlePieces[this->EmptyPieceX*this->SizeY + this->EmptyPieceY];
		missingPiece->setVisible(false);*/


	
}
int PuzzleArea::getMoveCount()
{
	return moveCount;
}