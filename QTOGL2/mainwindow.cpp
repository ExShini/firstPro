#include <QtGui>
#include <QAction>
#include <QMenu>
#include <QMenuBar>
#include "qmessagebox.h"

#include "mainwindow.h"
#include "scene3D.h"

MainWindow::MainWindow()
{
   scene1 = new Scene3D();

   // проверяем, поддерживается ли мультивыборка (сглаживание)
   if (scene1->format().sampleBuffers()) // мультивыборка поддерживается
      // сообщение-информация:
      QMessageBox::information(0, "Ok", "Multisampling is supported");
   else // мультивыборка не поддерживается
      // сообщение-предупреждение:
      QMessageBox::warning(0, "Problem", "Multisampling does not supported");

   setCentralWidget(scene1);

   this->setWindowTitle(tr("lecture2"));

   createActions();
   createMenus();
}

void MainWindow::createActions()
{

   changeTexAct = new QAction("Change", this);
   connect(changeTexAct, SIGNAL(triggered()), scene1, SLOT(changeTex()));

   stopTimAct = new QAction(tr("Stop"), this);
   connect(stopTimAct, SIGNAL(triggered()), scene1, SLOT(stopTmr()));

   startTimAct = new QAction(tr("Start"), this);
   connect(startTimAct, SIGNAL(triggered()), scene1, SLOT(startTmr()));
}

void MainWindow::createMenus()
{
   texture_menu = menuBar()->addMenu(tr("Texture"));
   texture_menu->addAction(changeTexAct);

   timer_menu = menuBar()->addMenu(tr("Animation"));
   timer_menu->addAction(stopTimAct);
   timer_menu->addAction(startTimAct);
}
