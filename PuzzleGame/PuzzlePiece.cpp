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
	this->setGeometry(puzzlePiece.geometry());
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
	//QString textStr = "X: " + QString::number(this->currentX) + ", Y: " + QString::number(this->currentY);
	//QMessageBox::information(this, "Information", textStr);
	//PuzzleArea* puzzleArea = (PuzzleArea*)this->parent();
	myPuzzleArea->MovePuzzlePiece(currentX, currentY);

	
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

PuzzlePiece& PuzzlePiece::operator=(PuzzlePiece puzzlePiece)
{
	//PuzzlePiece tmp(piece);
	myPuzzleArea = puzzlePiece.myPuzzleArea;
	correctX = puzzlePiece.correctX;
	correctY = puzzlePiece.correctY;
	//currentX = puzzlePiece.currentX;
	//currentY = puzzlePiece.currentY;
	
	this->setGeometry(puzzlePiece.geometry());
	return *this;
}

void PuzzlePiece::Swap(PuzzlePiece& puzzlePiece)
{
	QImage tmpImage = puzzlePiece.pixmap()->toImage();
	puzzlePiece.setPixmap(*pixmap());
	//if (tmpMap)
	setPixmap(QPixmap::fromImage(tmpImage));// ->toImage()));

	bool visibility = puzzlePiece.isVisible();
	bool isVis = isVisible();
	puzzlePiece.setVisible(isVisible());
	setVisible(visibility);

	QRect tmpGeometry = puzzlePiece.geometry();
	puzzlePiece.setGeometry(geometry());
	setGeometry(tmpGeometry);


	//const QPixmap* pixmap = ui.Picture->pixmap();
	//PuzzleAreaBase* tmpmyPuzzleArea = puzzlePiece.myPuzzleArea;
	///*int tmpcorrectX = puzzlePiece.correctX;
	//int tmpcorrectY = puzzlePiece.correctY;*/
	//int tmpcurrentX = puzzlePiece.currentX;
	//int tmpcurrentY = puzzlePiece.currentY;
	//QRect tmpGeometry = puzzlePiece.geometry();
	//QRect thisGeometry = geometry();

	//puzzlePiece.myPuzzleArea = myPuzzleArea;
	////puzzlePiece.correctX = correctX;
	////puzzlePiece.correctY = correctY;
	//puzzlePiece.currentX = currentX;
	//puzzlePiece.currentY = currentY;
	//puzzlePiece.setGeometry(geometry());

	//myPuzzleArea = tmpmyPuzzleArea;
	////correctX = tmpcorrectX;
	////correctY = tmpcorrectY;
	//currentX = tmpcurrentX;
	//currentY = tmpcurrentY;
	//this->setGeometry(tmpGeometry);

	//tmpGeometry = puzzlePiece.geometry();
	//thisGeometry = geometry();
	//

}
bool PuzzlePiece::IsInCorrectPosition(const int x, const int y)
{
	return correctX == x && correctY == y;
}