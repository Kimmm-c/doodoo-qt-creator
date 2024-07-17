#ifndef DD_MENU_BAR_H
#define DD_MENU_BAR_H

#include <QObject>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <iostream>
using namespace std;


class DDMenuBar : public QObject
{
    Q_OBJECT

public:
    explicit DDMenuBar(QWidget *parent);
    QMenuBar* menuBar() const;

private:
    void createActions();
    void createMenus();
    void initializeAction(QAction** action, const QString &label, void (DDMenuBar::*slot)());

private slots:
    void save();
    void exportToJPEG();
    void exportToPNG();
    void undo();
    void redo();

private:
    QMenuBar *mainMenuBar;

    QMenu *fileMenu;
    QAction *saveAct;

    QMenu *exportMenu;
    QAction *expToJPEGAct;
    QAction *expToPNGAct;

    QMenu *editMenu;
    QAction *undoAct;
    QAction *redoAct;
};

#endif