#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QApplication>
#include <QMainWindow>
#include <QPushButton>
#include <QSpinBox>
#include <QLabel>
#include <QLayout>
#include <QTimer>
#include <QGuiApplication>
#include <QScreen>
#include <Windows.h>
#include <QMessageBox>

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override = default;

private slots:
    void toggleAutoClicker();
    void sendKeyPress();

private:
    void setupUI();
    void setupTimer();

    QSpinBox *intervalSpinBox_;
    QPushButton *toggleButton_;
    QTimer *timer_;
};

#endif // MAINWINDOW_H