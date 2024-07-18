#ifndef DD_CANVAS_H
#define DD_CANVAS_H

#include <QObject>
#include <QPainter>
#include <QWidget>

class DDCanvasWidget : public QWidget
{
    Q_OBJECT

public:
    explicit DDCanvasWidget(QWidget *parent);

public:
    void paintEvent(QPaintEvent *event) override;

};

#endif