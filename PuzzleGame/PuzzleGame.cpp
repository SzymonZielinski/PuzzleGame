#include "PuzzleGame.h"
#include "PuzzlePiece.h"
//#include "PuzzleArea.h"

void PuzzleGame::loadImagePushButtonClick()
{
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open Image"),
		QDir::currentPath(),
		tr("Image Files (*.png *.jpg *.bmp)"));

	if (!fileName.isNull())
	{
		ui.puzzleGameArea->StartGame(ui.puzzleElementsXSpinBox->value(), ui.puzzleElementsYSpinBox->value(), fileName);
	}
}

void PuzzleGame::clickButton()
{

	qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);

	ui.puzzleGameArea->StartGame(ui.puzzleElementsXSpinBox->value(), ui.puzzleElementsYSpinBox->value());
	QMessageBox::information(this, "Information", "Get ready!");
	ui.puzzleGameArea->Shuffle(ui.shuffleComplexitySpinBox->value());
	
	return;
	PuzzleArea* newGameArea = ui.puzzleGameArea;// new PuzzleArea();
	
	//newGameArea->setBaseSize(1000, 1000);
	//this->layout()->addWidget(newGameArea);
	//newGameArea->setGeometry(10, 10, 500, 500);

	/*QPalette framePalette = ui.frame->palette();
	framePalette.setColor(QPalette::Background, Qt::red);
	ui.frame->setAutoFillBackground(true);
	ui.frame->setPalette(framePalette);
	ui.frame->show();
	*///return;
	
	QPalette pal = newGameArea->palette();

	// set black background
	pal.setColor(QPalette::Background, Qt::black);
	newGameArea->setAutoFillBackground(true);
	newGameArea->setPalette(pal);
	newGameArea->show();

	//ui.frame = newGameArea;
	PuzzlePiece* newPiece = new PuzzlePiece(2, 3, 500, 500);

	QString fileName = "d:\\s.png";

	/*QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open Image"),
		QDir::currentPath(),
		tr("Image Files (*.png *.jpg *.bmp)"));
*/
	QImage* puzzleImage = new QImage();
	/*
	
	puzzleImage->load("c:\\Users\\Szaman\\source\\repos\\PuzzleGame\\gmachglowny.jpg");
	QByteArray ba;
	QBuffer buffer(&ba);
	buffer.open(QIODevice::WriteOnly);
	puzzleImage->save(&buffer);*/

	
	if (puzzleImage->load(fileName))
	{
		QPixmap imageMap = QPixmap::fromImage(*puzzleImage).scaled(newGameArea->size(), Qt::KeepAspectRatio);// QPixmap::fromImage(newPiece->pixmap()->toImage());
		newGameArea->setBaseSize(imageMap.size());
		//imageMap.res
		int rowCount = 5;
		int colCount = 5;
		int puzzlePieceWidth = imageMap.width() / colCount;
		int puzzlePieceHeight = imageMap.height() / rowCount;

		PuzzlePiece** puzzleBoard = new PuzzlePiece*[rowCount];
		for (int i = 0; i < rowCount; i++)
			puzzleBoard[i] = new PuzzlePiece[colCount];

		//auto layout = new QGridLayout();// QBoxLayout::LeftToRight);// QVBoxLayout();
		//layout->setSpacing(1);
		//layout->setmSetMinAndMaxSize
		//newGameArea->setLayout(layout);
		for (int i = 0; i < rowCount; i++)
		{
			//layout->setRowMinimumHeight(i, puzzlePieceHeight);// +1);
			//layout->setRowStretch(i, 1);
			//layout.row
			for (int j = 0; j < colCount; j++)
			{
				//layout->setColumnMinimumWidth(j, puzzlePieceWidth);// +1);
				//puzzleBoard[i][j].SetPuzzleArea(newGameArea);
				puzzleBoard[i][j].SetCorrectPosition(i, j);
				QPixmap newMap = imageMap.copy(j * puzzlePieceWidth, i * puzzlePieceHeight, puzzlePieceWidth, puzzlePieceHeight);// 100, 100);
				puzzleBoard[i][j].setPixmap(newMap);
				puzzleBoard[i][j].setParent(newGameArea);
				puzzleBoard[i][j].setGeometry(j * puzzlePieceWidth + j * 1, i * puzzlePieceHeight + i * 1, puzzlePieceWidth, puzzlePieceHeight);
				puzzleBoard[i][j].show();
				//layout->addWidget(&puzzleBoard[i][j], i, j);
				//this->layout()->addWidget(&puzzleBoard[i][j]);
				//puzzleBoard[i][j].setGeometry(j * puzzlePieceWidth + 10, i * puzzlePieceHeight + 10, puzzlePieceWidth, puzzlePieceHeight);
				//this->layout()->invalidate();// repaint();
			}
		}
		PuzzlePiece* missingPiece = &puzzleBoard[rowCount - 1][colCount - 1];
		missingPiece->setVisible(false);
		
	}

	delete puzzleImage;

	return;
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
	connect(ui.loadImagePushButton, SIGNAL(clicked()), this, SLOT(loadImagePushButtonClick()));
}

PuzzleGame::~PuzzleGame()
{
	//	delete ui.puzzleGameArea;
}