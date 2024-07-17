#include "DDMainWindow.h"

DDMainWindow::DDMainWindow(QWidget *parent)
: QMainWindow(parent)
, menuBar(new DDMenuBar(this))
, mainToolBar(createMainToolBar())
, canvas(createCanvas())
{
    renderComponents();
}

DDMainWindow::~DDMainWindow()
{
    delete menuBar;
    delete mainToolBar;
    delete canvas;
}

void DDMainWindow::renderComponents() {
    setMenuBar(menuBar->menuBar());
//    addToolBar(Qt::TopToolBarArea, mainToolBar);
//    addCanvas(canvas);
}

//DDMenuBar * DDMainWindow::createMenuBar()
//{
//    auto *menubar = new DDMenuBar();
//    return menubar;
//}

DDToolBar * DDMainWindow::createMainToolBar()
{
    auto toolbar = new DDToolBar();
    return toolbar;
}

DDCanvas * DDMainWindow::createCanvas()
{
    auto ddCanvas = new DDCanvas();
    return ddCanvas;
}