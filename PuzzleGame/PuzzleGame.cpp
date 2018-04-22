#include "PuzzleGame.h"

/**
Ładowanie obrazku puzzli z pliku (przycisk) - korzystamy z wbudowanych funkcji Qt. Obsługiwane formaty: png, jpg, bmp.
Jeśli załadowano nowy obrazek, rozpoczynamy grę.
*/
void PuzzleGame::loadImagePushButtonClick()
{
	QString fileName = QFileDialog::getOpenFileName(this, tr("Open Image"), QDir::currentPath(),tr("Image Files (*.png *.jpg *.bmp)"));
	if (!fileName.isNull())
	{
		ui.puzzleGameArea->newGame(ui.puzzleElementsXSpinBox->value(), ui.puzzleElementsYSpinBox->value(), ui.difficultySpinBox->value(), ui.randomizeEmptyPieceCheckBox->isChecked(), fileName);
	}
}

/**
Rozpoczęcie nowej gry (przycisk) z bieżącymi ustawieniami.
*/
void PuzzleGame::startGamePushButtonClick()
{
	ui.puzzleGameArea->newGame(ui.puzzleElementsXSpinBox->value(), ui.puzzleElementsYSpinBox->value(), ui.difficultySpinBox->value(), ui.randomizeEmptyPieceCheckBox->isChecked(), "", ui.puzzleSpacingXSpinBox->value(), ui.puzzleSpacingYSpinBox->value());
}

void PuzzleGame::showAnimationsCheckBoxStateChanged(bool checkState)
{
	ui.puzzleGameArea->setAnimation(checkState);
}

void PuzzleGame::animationSpeedSpinBoxValueChanged(int animationSpeed)
{
	ui.puzzleGameArea->setAnimationSpeed(animationSpeed);// ui.animationSpeedSpinBox->value());
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
	connect(ui.showAnimationsCheckBox, SIGNAL(toggled(bool)), this, SLOT(showAnimationsCheckBoxStateChanged(bool)));
	connect(ui.animationSpeedSpinBox, SIGNAL(valueChanged(int)), this, SLOT(animationSpeedSpinBoxValueChanged(int)));

	/**
	Wyświetlenie planszy z grą - bez rozpoczynania gry (ostatni parametr - false)
	*/
	ui.puzzleGameArea->newGame(ui.puzzleElementsXSpinBox->value(), ui.puzzleElementsYSpinBox->value(), ui.difficultySpinBox->value(), ui.randomizeEmptyPieceCheckBox->isChecked(), "", ui.puzzleSpacingXSpinBox->value(), ui.puzzleSpacingYSpinBox->value(), false);
}

PuzzleGame::~PuzzleGame()
{
	delete ui.puzzleGameArea;
	delete puzzleGameLayout;
}