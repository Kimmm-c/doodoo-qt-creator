#include <QtWidgets>
#include "DDMainWindow/DDMainWindow.h"

int main(int argc, char *argv[])
{
    QApplication doodoo(argc, argv);

    DDMainWindow window;
    window.resize(900, 900);
    window.show();

    return doodoo.exec();
}