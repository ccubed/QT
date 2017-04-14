#include "vnf.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.setFixedSize(1024, 768);
    w.setWindowTitle("Visual Novel Framework");
    w.show();

    return a.exec();
}
