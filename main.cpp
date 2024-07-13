#include "doodoo.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Doodoo w;
    w.show();
    return a.exec();
}
