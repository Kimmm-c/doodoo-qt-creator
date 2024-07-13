#include "doodoo.h"
#include "ui_doodoo.h"


Doodoo::Doodoo(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Doodoo)
{
    ui->setupUi(this);

    image = QImage(this->size(), QImage::Format_RGB32);
    image.fill(Qt::white);
    drawing = false;
    brushColor = Qt::black;
    brushSize = 2;
}

Doodoo::~Doodoo()
{
    delete ui;
}

void Doodoo::mousePressEvent(QMouseEvent *event)
{
    if (event->button() == Qt::LeftButton)
    {
      drawing = true;
      lastPoint = event->pos();
    }
}


void Doodoo::mouseMoveEvent(QMouseEvent *event)
{
    if ((event->buttons() & Qt::LeftButton) && drawing)
    {
      QPainter painter(&image);
      painter.setPen(QPen(brushColor, brushSize, Qt::SolidLine,
        Qt::RoundCap, Qt::RoundJoin));
      painter.drawLine(lastPoint, event->pos());
      lastPoint = event->pos();
      this->update();
    }
}

void Doodoo::mouseReleaseEvent(QMouseEvent *event)
{
     if (event->button() == Qt::LeftButton)
     {
       drawing = false;
     }
}

void Doodoo::paintEvent(QPaintEvent *event)
{
     QPainter canvasPainter(this);
     canvasPainter.drawImage(this->rect(), image, image.rect());
}

void Doodoo::on_actionBlack_triggered()
{
    brushColor = Qt::black;
}


void Doodoo::on_actionWhite_triggered()
{
    brushColor = Qt::white;
}


void Doodoo::on_actionCrimson_triggered()
{
    brushColor = QColor(153, 0, 0);
}

void Doodoo::on_actionFire_2_triggered()
{
    brushColor = QColor(226, 88, 34);
}

void Doodoo::on_actionMahogany_triggered()
{
    brushColor = QColor(192, 64, 0);
}

void Doodoo::on_actionOchre_triggered()
{
    brushColor = QColor(237, 181, 37);
}

void Doodoo::on_actionLime_triggered()
{
    brushColor = QColor(50, 205, 50);
}

void Doodoo::on_actionArtic_triggered()
{
    brushColor = QColor(185, 211, 213);
}

void Doodoo::on_actionCerulean_triggered()
{
    brushColor = QColor(42, 82, 190);
}

void Doodoo::on_actionTrue_Red_triggered()
{
    brushColor = QColor(255, 139, 142);
}

void Doodoo::on_actionMoss_triggered()
{
    brushColor = QColor(138, 154, 91);
}

void Doodoo::on_actionLemon_triggered()
{
    brushColor = QColor(254, 242, 80);
}

void Doodoo::on_actionPear_triggered()
{
    brushColor = QColor(137, 181, 89);
}


void Doodoo::on_action2px_triggered()
{
    brushSize = 2;
}

void Doodoo::on_action5px_triggered()
{
    brushSize = 5;
}

void Doodoo::on_action10px_triggered()
{
    brushSize = 10;
}

void Doodoo::on_action20px_triggered()
{
    brushSize = 20;
}

void Doodoo::on_action50px_triggered()
{
    brushSize = 50;
}

void Doodoo::on_actionClear_triggered()
{
    image.fill(Qt::white);
    this->update();
}

