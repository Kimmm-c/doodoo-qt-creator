#ifndef DD_MAIN_WINDOW_H
#define DD_MAIN_WINDOW_H

#include <QMainWindow>
#include <QToolButton>
#include <QHBoxLayout>

#include "../canvas/DDCanvas.h"
#include "../menubar/DDMenuBar.h"
#include "../toolbar/DDToolBar.h"

#include <iostream>
using namespace std;

class DDMainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit DDMainWindow(QWidget *parent=nullptr);
    ~DDMainWindow() override;

    void renderComponents();

private slots:
    void erase();
    void resizeBrush();
    void changeColor();
    void updateToolBarOrientation(Qt::Orientation orientation);

private:
    DDMenuBar *menuBar;
    QToolBar *mainToolBar;
    DDCanvas *canvas;

    QAction *eraserAct;
    QAction *resizeBrushAct;
    QAction *changeColorAct;

    QBoxLayout *toolBarLayout;
    QWidget *rightAlignedToolContainer;
    QToolButton *eraseButton;
    QToolButton *resizeButton;
    QToolButton *changeColorButton;


    void createMainToolBar();
    DDCanvas * createCanvas();
//    void addCanvas(DDCanvas *canvas);
};

#endif