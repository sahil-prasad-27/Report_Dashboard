#include <QApplication>
#include <QFile>
#include <QTextStream>
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Load QSS file
    QFile file(":/style.qss");
    if (file.open(QFile::ReadOnly | QFile::Text)) {
        QTextStream stream(&file);
        QString styleSheet = stream.readAll();
        a.setStyleSheet(styleSheet);
        file.close();
    } else {
        qWarning("Could not open QSS file");
    }

    MainWindow w;
    w.showMaximized();
    return a.exec();
}
