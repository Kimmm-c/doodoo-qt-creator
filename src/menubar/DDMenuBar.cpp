#include "DDMenuBar.h"

DDMenuBar::DDMenuBar(QWidget *parent)
: QObject(parent)
, mainMenuBar(new QMenuBar(parent))
{
    createActions();
    createMenus();
}

void DDMenuBar::initializeAction(QAction **action, const QString &label, void (DDMenuBar::*slot)())
{
    cout<<"action's address "<<action<<endl;
    cout<<"action's value "<<*action<<endl;
    *action = new QAction(label, this);
    cout<<"action's value after creating action"<<action<<endl;
    connect(*action, &QAction::triggered, this, slot);
}

void DDMenuBar::createActions()
{
    initializeAction(&saveAct, tr("&Save"), &DDMenuBar::save);
    initializeAction(&expToJPEGAct, tr("JPEG"), &DDMenuBar::exportToJPEG);
    initializeAction(&expToPNGAct, tr("PNG"), &DDMenuBar::exportToPNG);
    initializeAction(&undoAct, tr("Undo"), &DDMenuBar::undo);
    initializeAction(&redoAct, tr("Redo"), &DDMenuBar::redo);
}

void DDMenuBar::createMenus()
{
    fileMenu = mainMenuBar->addMenu("File");
    fileMenu->addAction(saveAct);

    exportMenu = fileMenu->addMenu("Export As...");
    exportMenu->addAction(expToJPEGAct);
    exportMenu->addAction(expToPNGAct);

    editMenu = mainMenuBar->addMenu("Edit");
    editMenu->addAction(undoAct);
    editMenu->addAction(redoAct);
}

QMenuBar *DDMenuBar::menuBar() const
{
    return mainMenuBar;
}

void DDMenuBar::save()
{

}

void DDMenuBar::exportToJPEG()
{

}

void DDMenuBar::exportToPNG()
{

}

void DDMenuBar::undo()
{

}

void DDMenuBar::redo()
{

}