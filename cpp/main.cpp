#include <QApplication>

#include "src/mainwindow.hpp"

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    QApplication::setOrganizationName("Vadeev");
    QApplication::setApplicationName("Gayshit-Infarct-Killer");

    MainWindow w;

    w.setWindowTitle(QObject::tr("GIK"));
    w.show();

    return app.exec();
}