#include <QCoreApplication>
#include "request.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    Request::request();
    return a.exec();
}
