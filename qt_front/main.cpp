#include <QApplication>
#include "main_win.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    MainWindow mainWindow;
    mainWindow.showNormal();
    return app.exec();
}