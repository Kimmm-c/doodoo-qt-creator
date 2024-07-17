#include "DDMainWindow.h"

DDMainWindow::DDMainWindow(QWidget *parent)
: QMainWindow(parent)
, menuBar(new DDMenuBar(this))
, canvas(createCanvas())
{
    mainToolBar = addToolBar("Main Toolbar");
    createMainToolBar();
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

void DDMainWindow::createMainToolBar()
{
    // Initialize the rightAlignedWidget.
    // rightAlignedWidget contains a QHBoxLayout, which controls the arrangement of its child widgets.
    rightAlignedToolContainer = new QWidget();
    toolBarLayout = new QBoxLayout(QBoxLayout::Direction::LeftToRight, rightAlignedToolContainer);
    toolBarLayout->setContentsMargins(0, 0, 0, 0);
    toolBarLayout->addStretch();

    // Initialize the actions
    eraserAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::WeatherSnow), tr("Eraser"), this);
    connect(eraserAct, &QAction::triggered, this, &DDMainWindow::erase);

    resizeBrushAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::WeatherSnow), tr("Size"),this);
    connect(resizeBrushAct, &QAction::triggered, this, &DDMainWindow::resizeBrush);

    changeColorAct = new QAction(QIcon::fromTheme(QIcon::ThemeIcon::WeatherSnow), tr("Color"),this);
    connect(changeColorAct, &QAction::triggered, this, &DDMainWindow::changeColor);

    // Add the actions to the QToolButton widgets
    eraseButton = new QToolButton();
    eraseButton->setDefaultAction(eraserAct);

    resizeButton = new QToolButton();
    resizeButton->setDefaultAction(resizeBrushAct);

    changeColorButton = new QToolButton();
    changeColorButton->setDefaultAction(changeColorAct);

    // Add the button widgets to the layout
    toolBarLayout->addWidget(eraseButton);
    toolBarLayout->addWidget(resizeButton);
    toolBarLayout->addWidget(changeColorButton);

    // Set the layout controller of rightAlignedWidget to toolBarLayout
    rightAlignedToolContainer->setLayout(toolBarLayout);

    // Add the rightAlignedWidget to the toolbar
    mainToolBar->addWidget(rightAlignedToolContainer);

    // Connect the toolbar widget to slot for toolbar orientation update.
    connect(mainToolBar, &QToolBar::orientationChanged, this, &DDMainWindow::updateToolBarOrientation);
}

DDCanvas * DDMainWindow::createCanvas()
{
    auto ddCanvas = new DDCanvas();
    return ddCanvas;
}

void DDMainWindow::erase()
{

}

void DDMainWindow::resizeBrush()
{

}

void DDMainWindow::changeColor()
{

}

void DDMainWindow::updateToolBarOrientation(Qt::Orientation orientation)
{
    if (orientation == Qt::Horizontal) {
        toolBarLayout->setDirection(QBoxLayout::LeftToRight);
    } else {
        toolBarLayout->setDirection(QBoxLayout::BottomToTop);
    }
}