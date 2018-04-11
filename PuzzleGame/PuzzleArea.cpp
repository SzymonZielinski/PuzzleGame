#include "PuzzleArea.h"


PuzzleArea::PuzzleArea(QWidget *parent)
{
	this->setParent(parent);
	EmptyPieceX = -1;
	EmptyPieceY = -1;

	QString fileName = "d:\\s.png";
	QImage puzzleImage;// = new QImage();
	if (puzzleImage.load(fileName))
	{
		QPixmap imageMap = QPixmap::fromImage(puzzleImage).scaled(this->size(), Qt::KeepAspectRatio);// QPixmap::fromImage(newPiece->pixmap()->toImage());
		this->setBaseSize(imageMap.size());
		//imageMap.res
		this->SizeX = 5;
		this->SizeY = 5;
		int puzzlePieceWidth = imageMap.width() / this->SizeY;
		int puzzlePieceHeight = imageMap.height() / this->SizeX;

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
				PuzzlePieces[i*SizeX + j].SetPuzzleArea(this);
				PuzzlePieces[i*SizeX + j].SetCorrectPosition(i, j);
				PuzzlePieces[i*SizeX + j].SetCurrentPosition(i, j);
				QPixmap newMap = imageMap.copy(j * puzzlePieceWidth, i * puzzlePieceHeight, puzzlePieceWidth, puzzlePieceHeight);// 100, 100);
				PuzzlePieces[i*SizeX + j].setPixmap(newMap);
				PuzzlePieces[i*SizeX + j].setParent(this);
				PuzzlePieces[i*SizeX + j].setGeometry(j * puzzlePieceWidth + j * puzzlePieceSpacingX, i * puzzlePieceHeight + i * puzzlePieceSpacingY, puzzlePieceWidth, puzzlePieceHeight);
				PuzzlePieces[i*SizeX + j].show();
				//layout->addWidget(&puzzleBoard[i][j], i, j);
				//this->layout()->addWidget(&puzzleBoard[i][j]);
				//puzzleBoard[i][j].setGeometry(j * puzzlePieceWidth + 10, i * puzzlePieceHeight + 10, puzzlePieceWidth, puzzlePieceHeight);
				//this->layout()->invalidate();// repaint();
			}
		}
		//PuzzlePieces[sizeX]
		this->EmptyPieceX = this->SizeX - 1;
		this->EmptyPieceY = this->SizeY - 1;
		PuzzlePiece* missingPiece = &PuzzlePieces[this->EmptyPieceX*this->SizeX + this->EmptyPieceY];
		missingPiece->setVisible(false);

	}

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

void PuzzleArea::MovePuzzlePiece(const int rowPosition, const int colPosition)
{
	QMessageBox::information(this, "Information", "Something");
	if (abs(rowPosition - this->EmptyPieceX) == 1 || abs(colPosition - this->EmptyPieceY) == 1)
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
		PuzzlePiece tmp = PuzzlePieces[this->EmptyPieceX*this->SizeX + this->EmptyPieceY];
		PuzzlePieces[this->EmptyPieceX*this->SizeX + this->EmptyPieceY] = PuzzlePieces[rowPosition*this->SizeX + colPosition];
		PuzzlePieces[rowPosition*this->SizeX+colPosition] = tmp;
		
		//PuzzlePiece* tmpPiece = &PuzzlePieces[this->EmptyPieceX][this->EmptyPieceY];
		//this->PuzzlePieces[this->EmptyPieceX][this->EmptyPieceY] = this->PuzzlePieces[rowPosition][colPosition];
	//	PuzzlePieces[rowPosition][colPosition] = *tmpPiece;
	}
	//PuzzlePieces[rowPosition][colPosition];
}

int PuzzleArea::getEmptyPieceX()
{
	return EmptyPieceX;
}
int PuzzleArea::getEmptyPieceY()
{
	return EmptyPieceY;
}
bool PuzzleArea::setEmptyPieceX(int x)
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
bool PuzzleArea::setEmptyPieceY(int y)
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

//void mouseRelessedEvent(QMouseEvent *me)
//{
//	if (me->button()) { QFrame::mouseReleasedEvent(me); return; }
//
//	// here emit released and click signal if clicked... if not just call mouseReleasedEvent
//	// from the base class and forget about clicked, if clicked... 
//
//	// Anyway each widget receives those events, not only QFrame.... 
//}