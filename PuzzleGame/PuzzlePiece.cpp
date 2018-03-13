#include<iostream>
#include "PuzzlePiece.h"
#include "PuzzleArea.h"
using namespace std;

void PuzzlePiece::clickOnPuzzlePiece()
{
	//myPuzzleArea
}

//void PuzzlePiece::resizeEvent(QResizeEvent *event)
//{
//	updatePosition(label, 0.5, 0.5); //50% , 50%
//	updatePosition(lineEdit, 0.3, 0.7); //30% , 70%
//	QWidget::resizeEvent(event);
//}
//
//void PuzzlePiece::updatePosition(QWidget *widget, float xscale, float yscale) {
//	int w = size().width();
//	int h = size().height();
//	widget->move(QPoint(w*xscale, h*yscale) - widget->rect().center());
//}

PuzzlePiece::PuzzlePiece()
{
	
}
PuzzlePiece::SetPuzzleArea(PuzzleArea* puzzleArea)
{
	myPuzzleArea = puzzleArea;

}
PuzzlePiece::PuzzlePiece(const int correctPositionX, const int correctPositionY, const int width, const int height):correctX(correctPositionX), correctY(correctPositionY)
{
	/*correctX = correctPositionX;
	correctY = correctPositionY;*/
	cout << "X: " << correctX << endl;
	cout << "Y: " << correctY << endl;

	this->setFixedWidth(width);
	this->setFixedHeight(height);
}


PuzzlePiece::~PuzzlePiece()
{
}

bool PuzzlePiece::LoadImage(QString fileName)
{
	QImageReader reader(fileName);
	reader.setAutoTransform(true);
	const QImage newImage = reader.read();
	if (newImage.isNull()) {
		/*QMessageBox::information(this, QGuiApplication::applicationDisplayName(),
		tr("Cannot load %1: %2")
		.arg(QDir::toNativeSeparators(fileName), reader.errorString()));*/
		return false;
	}
	//int width = _container->width();
	QPixmap imageMap = QPixmap::fromImage(newImage).scaledToWidth(this->width());
	this->setPixmap(imageMap);
	return true;
}

void PuzzlePiece::SetCorrectPosition(const int positionX, const int positionY)
{
	correctX = positionX;
	correctY = positionY;
}