// main.cpp
#include <QApplication>
#include "autoclicker.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    AutoClicker w;
    w.show();
    return a.exec();
}
