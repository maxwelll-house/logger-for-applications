#include "LoggerForApplications.h"
#include "LogMain.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    LogMain::init();

    QApplication a(argc, argv);
    LoggerForApplications w;
    w.show();
    bool state = a.exec();

    LogMain::clean();
    return state;
}
