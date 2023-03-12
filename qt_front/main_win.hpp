#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QApplication>
#include <QtCore>
#include <QtGui>
#include "FormCalc.hpp"
#include "tabs.hpp"

class MainWindow : public QMainWindow
{
Q_OBJECT
public:
    MainWindow();
private:
    Tabs *tabs;
};
#endif // MAINWINDOW_H
