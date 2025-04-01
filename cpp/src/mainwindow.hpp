#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow {
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;
};

#endif // MAINWINDOW_H