#ifndef DD_MAIN_WINDOW_H
#define DD_MAIN_WINDOW_H

#include <QMainWindow>
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

private:
    DDMenuBar *menuBar;
    DDToolBar *mainToolBar;
    DDCanvas *canvas;

    DDToolBar * createMainToolBar();
    DDCanvas * createCanvas();
//    void addCanvas(DDCanvas *canvas);
};

#endif