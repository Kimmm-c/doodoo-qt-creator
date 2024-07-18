#include "DDCanvasWidget.h"


DDCanvasWidget::DDCanvasWidget(QWidget *parent)
: QWidget(parent)
{
    setFixedSize(700, 700);
}

void DDCanvasWidget::paintEvent(QPaintEvent *event)
{
    QPainter painter = QPainter(this);
    painter.setBrush(Qt::white);
    painter.drawRect(this->rect());
}
