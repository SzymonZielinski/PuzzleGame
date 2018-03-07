#include "PuzzleGame.h"
#include "PuzzlePiece.h"



void PuzzleGame::clickButton()
{
	PuzzlePiece* newPiece = new PuzzlePiece(2, 3, 500, 500);

	QString fileName = "d:\\s.png";
	newPiece->LoadImage(fileName);
	//newPiece->setText("New Piece");
	//this->layout()->addWidget(newPiece);
	//ui.centralWidget->layout()->addWidget(new QLabel("aaaa"));// addItem(newPiece);
	//newPiece->setGeometry(QRect(10, 10, 500, 500));
	//this->

	QPixmap imageMap = QPixmap::fromImage(newPiece->pixmap()->toImage());


	int rowCount = 5;
	int colCount = 5;
	PuzzlePiece** puzzleBoard = new PuzzlePiece*[rowCount];
	for (int i = 0; i < rowCount; i++)
		puzzleBoard[i] = new PuzzlePiece[colCount];
	
	for (int i = 0; i < rowCount; i++)
		for (int j = 0; j < colCount; j++)
	{
			puzzleBoard[i][j].SetCorrectPosition(i, j);
			QPixmap newMap = imageMap.copy(i*100, j*100, 100, 100);
			puzzleBoard[i][j].setPixmap(newMap);
			this->layout()->addWidget(&puzzleBoard[i][j]);
			puzzleBoard[i][j].setGeometry(i * 100 + 10, j * 100 + 10, 100, 100);
			this->layout()->invalidate();// repaint();
	}

/*
	PuzzlePiece* piece2 = new PuzzlePiece(1, 1, 100, 100);
	QPixmap imageMap = QPixmap::fromImage(newPiece->pixmap()->toImage());
	QPixmap newMap = imageMap.copy(QRect(0, 0, 100, 100));
	piece2->setPixmap(newMap);
	this->layout()->addWidget(piece2);
	piece2->setGeometry(QRect(20, 20, 100, 100));*/
}

PuzzleGame::PuzzleGame(QWidget *parent)
	: QMainWindow(parent)
{
	
	ui.setupUi(this);
	
	connect(ui.testPushButton, SIGNAL(clicked()), this, SLOT(clickButton()));
}
