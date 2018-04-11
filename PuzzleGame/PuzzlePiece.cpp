#include<iostream>
#include "PuzzlePiece.h"
//#include "PuzzleArea.h"
using namespace std;

void PuzzlePiece::clickOnPuzzlePiece()
{
	//if (abs(currentX-))
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
PuzzlePiece::PuzzlePiece(PuzzleAreaBase* puzzleArea)
{
	myPuzzleArea = puzzleArea;
}
void PuzzlePiece::SetPuzzleArea(PuzzleAreaBase* puzzleArea)
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

PuzzlePiece::PuzzlePiece(const PuzzlePiece& puzzlePiece)
{
	myPuzzleArea = puzzlePiece.myPuzzleArea;
	correctX = puzzlePiece.correctX;
	correctY = puzzlePiece.correctY;
	currentX = puzzlePiece.currentX;
	currentY = puzzlePiece.currentY;
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

void PuzzlePiece::SetCurrentPosition(const int positionX, const int positionY)
{
	currentX = positionX;
	currentY = positionY;
}

void PuzzlePiece::mousePressEvent(QMouseEvent *qevent)
{
	//return;
	//this->clicked = true;
	QString textStr = "X: " + QString::number(this->currentX) + ", Y: " + QString::number(this->currentY);
	QMessageBox::information(this, "Information", textStr);
	//PuzzleArea* puzzleArea = (PuzzleArea*)this->parent();
	myPuzzleArea->MovePuzzlePiece(this->currentX, this->currentY);

	
	//	this->puzzlePieceWidth = this->width() / this->SizeX;
//	this->puzzlePieceHeight = this->width() / this->SizeY;
//	if (qevent->button() == Qt::LeftButton)
//	{
//		int x = qevent->pos().x();
//		int y = qevent->pos().y();
//
//		QString textStr = "X: " + QString::number(qevent->pos().x()) + ", Y: " + QString::number(qevent->pos().y());
//		QMessageBox::information(this, "Information", textStr);
//
//		//this->setVisible(!this->isVisible());
//	}
}

PuzzlePiece PuzzlePiece::operator=(PuzzlePiece piece)
{
	PuzzlePiece tmp(piece);
	return tmp;
}
