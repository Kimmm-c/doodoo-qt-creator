#ifndef DOODOO_H
#define DOODOO_H

#include <QMainWindow>
#include <QPainter>
#include <QMouseEvent>
#include <QFileDialog>
#include <QColor>

QT_BEGIN_NAMESPACE
namespace Ui { class Doodoo; }
QT_END_NAMESPACE

class Doodoo : public QMainWindow
{
    Q_OBJECT

public:
    Doodoo(QWidget *parent = nullptr);
    ~Doodoo();

    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseMoveEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);
    virtual void paintEvent(QPaintEvent *event);
//    virtual void resizeEvent(QResizeEvent *event);

private slots:
    void on_actionBlack_triggered();
    void on_actionWhite_triggered();
    void on_actionCrimson_triggered();
    void on_actionFire_2_triggered();
    void on_actionMahogany_triggered();
    void on_actionOchre_triggered();
    void on_actionLime_triggered();
    void on_actionArtic_triggered();
    void on_actionCerulean_triggered();
    void on_actionTrue_Red_triggered();
    void on_actionMoss_triggered();
    void on_actionLemon_triggered();
    void on_actionPear_triggered();

    void on_action2px_triggered();
    void on_action5px_triggered();
    void on_action10px_triggered();
    void on_action20px_triggered();
    void on_action50px_triggered();

    void on_actionClear_triggered();

private:
    Ui::Doodoo *ui;

    QImage image;
    bool drawing;
    QPoint lastPoint;
    int brushSize;
    QColor brushColor;
};
#endif // DOODOO_H
