/**
  @author:mihhail sidorin
  */
#include <QtGui/QApplication>
#include "qtcalc.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qtCalc w;
    w.show();

    return a.exec();
}
