#include <QtGui>
#include "QApplication"

#include "mainwindow.h"

int main(int argc, char** argv)
{
   QApplication app(argc, argv);

   MainWindow mainwindow1;
   mainwindow1.resize(500, 500);
   mainwindow1.showMaximized();

   return app.exec();
}
