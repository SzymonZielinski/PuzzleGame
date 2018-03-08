#include "PuzzleGame.h"
#include "PuzzlePiece.h"
#include "PuzzleArea.h"

void PuzzleGame::clickButton()
{
	PuzzleArea* newGameArea = new PuzzleArea();
	newGameArea->setBaseSize(500, 500);
	this->layout()->addWidget(newGameArea);
	
	QPalette framePalette = ui.frame->palette();
	framePalette.setColor(QPalette::Background, Qt::red);
	ui.frame->setAutoFillBackground(true);
	ui.frame->setPalette(framePalette);
	ui.frame->show();
	return;
	QPalette pal = newGameArea->palette();

	// set black background
	pal.setColor(QPalette::Background, Qt::black);
	newGameArea->setAutoFillBackground(true);
	newGameArea->setPalette(pal);
	newGameArea->show();

	newGameArea->setGeometry(10, 10, 600, 600);

	PuzzlePiece* newPiece = new PuzzlePiece(2, 3, 500, 500);

	QString fileName = "d:\\s.png";

	/*QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open Image"),
		QDir::currentPath(),
		tr("Image Files (*.png *.jpg *.bmp)"));
*/
	QImage* puzzleImage = new QImage();
	if (puzzleImage->load(fileName))
	{

	}
	delete puzzleImage;

	newPiece->LoadImage(fileName);
	//newPiece->setText("New Piece");
	//this->layout()->addWidget(newPiece);
	//ui.centralWidget->layout()->addWidget(new QLabel("aaaa"));// addItem(newPiece);
	//newPiece->setGeometry(QRect(10, 10, 500, 500));
	//this->

	QPixmap imageMap = QPixmap::fromImage(newPiece->pixmap()->toImage());
	int rowCount = 5;
	int colCount = 5;
	int puzzlePieceWidth = imageMap.width() / colCount;
	int puzzlePieceHeight = imageMap.height() / rowCount;

	PuzzlePiece** puzzleBoard = new PuzzlePiece*[rowCount];
	for (int i = 0; i < rowCount; i++)
		puzzleBoard[i] = new PuzzlePiece[colCount];
	
	auto layout = new QGridLayout();// QBoxLayout::LeftToRight);// QVBoxLayout();
	newGameArea->setLayout(layout);
	for (int i = 0; i < rowCount; i++)
	{
		layout->setRowMinimumHeight(i, puzzlePieceHeight + 10);

		//layout.row
		for (int j = 0; j < colCount; j++)
		{
			layout->setColumnMinimumWidth(j, puzzlePieceWidth + 10);
			puzzleBoard[i][j].SetCorrectPosition(i, j);
			QPixmap newMap = imageMap.copy(j * puzzlePieceWidth, i * puzzlePieceHeight, puzzlePieceWidth, puzzlePieceHeight);// 100, 100);
			puzzleBoard[i][j].setPixmap(newMap);
			layout->addWidget(&puzzleBoard[i][j],i,j);
			//this->layout()->addWidget(&puzzleBoard[i][j]);
			//puzzleBoard[i][j].setGeometry(j * puzzlePieceWidth + 10, i * puzzlePieceHeight + 10, puzzlePieceWidth, puzzlePieceHeight);
			//this->layout()->invalidate();// repaint();
		}
	}

	return;
	delete newPiece;
	for (int i = 0; i < rowCount; i++)
	{
		delete[] puzzleBoard[i];
	}
	delete[] puzzleBoard;
	

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
