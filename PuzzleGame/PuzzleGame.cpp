#include "PuzzleGame.h"

/**
Ładowanie obrazku puzzli z pliku (przycisk) - korzystamy z wbudowanych funkcji Qt. Obsługiwane formaty: png, jpg, bmp.
Jeśli załadowano nowy obrazek, rozpoczynamy grę.
*/
void PuzzleGame::loadImagePushButtonClick()
{
	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Open Image"),
		QDir::currentPath(),
		tr("Image Files (*.png *.jpg *.bmp)"));

	if (!fileName.isNull())
	{
		ui.puzzleGameArea->startGame(ui.puzzleElementsXSpinBox->value(), ui.puzzleElementsYSpinBox->value(), fileName);
		QMessageBox::information(this, "Information", "Get ready!");
		ui.puzzleGameArea->shuffle(ui.shuffleComplexitySpinBox->value());
	}
}

/**
Rozpoczęcie nowej gry (przycisk) z bieżącymi ustawieniami.

*/
void PuzzleGame::startGamePushButtonClick()
{
	ui.puzzleGameArea->startGame(ui.puzzleElementsXSpinBox->value(), ui.puzzleElementsYSpinBox->value());
	QMessageBox::information(this, "Information", "Get ready!");
	ui.puzzleGameArea->shuffle(ui.shuffleComplexitySpinBox->value());
}

PuzzleGame::PuzzleGame(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);
	puzzleGameLayout = new QHBoxLayout;
	ui.puzzleGameArea->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
	puzzleGameLayout->addWidget(ui.puzzleGameArea);
	puzzleGameLayout->addWidget(ui.settingsFrame);
	ui.centralWidget->setLayout(puzzleGameLayout);

	/**
	Inicjalizacja generatora liczb pseudolosowych
	*/
	qsrand(QDateTime::currentMSecsSinceEpoch() / 1000);

	/**
	Podłączanie slotów do przycisków
	*/
	connect(ui.startGamePushButton, SIGNAL(clicked()), this, SLOT(startGamePushButtonClick()));
	connect(ui.loadImagePushButton, SIGNAL(clicked()), this, SLOT(loadImagePushButtonClick()));
}

PuzzleGame::~PuzzleGame()
{
	delete ui.puzzleGameArea;
	delete puzzleGameLayout;
}