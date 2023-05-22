#include "oodc.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    oodc w;
    w.show();
    return a.exec();
}
