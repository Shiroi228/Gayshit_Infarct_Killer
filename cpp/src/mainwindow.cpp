#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), intervalSpinBox_(new QSpinBox(this)),
    toggleButton_(new QPushButton(tr("Destroy shit!"), this)), timer_(new QTimer(this)) {
    setupUI();
    setupTimer();

    setWindowFlags(
        Qt::Tool |
        Qt::CustomizeWindowHint |
        Qt::WindowStaysOnTopHint
    );

    resize(150, 100);

    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->availableGeometry();

    int x = screenGeometry.right() - width() - 20;
    int y = screenGeometry.bottom() - height() - 20;

    move(x, y);
}

void MainWindow::sendKeyPress() {
    INPUT input[2] = {0};
    
    input[0].type = INPUT_KEYBOARD;
    input[0].ki.wVk = 0x46;
    
    input[1].type = INPUT_KEYBOARD;
    input[1].ki.wVk = 0x46;
    input[1].ki.dwFlags = KEYEVENTF_KEYUP;
    
    SendInput(2, input, sizeof(INPUT));
}

void MainWindow::setupUI() {
    QWidget *centralWidget = new QWidget(this);
    QVBoxLayout *layout = new QVBoxLayout(centralWidget);
    QHBoxLayout *hLayout = new QHBoxLayout();
    QPushButton *quit = new QPushButton(tr("Quit"), this);

    QLabel *intervalLabel = new QLabel("Interval (ms):", this);
    intervalSpinBox_->setRange(50, 5000);
    intervalSpinBox_->setValue(1000);

    hLayout->addWidget(intervalLabel);
    hLayout->addWidget(intervalSpinBox_);
    layout->addLayout(hLayout);
    layout->addWidget(toggleButton_);
    layout->addWidget(quit);

    setCentralWidget(centralWidget);

    connect(toggleButton_, &QPushButton::clicked, this, &MainWindow::toggleAutoClicker);
    connect(quit, &QPushButton::clicked, QCoreApplication::quit);
    connect(intervalSpinBox_, QOverload<int>::of(&QSpinBox::valueChanged), [=](int value){
        timer_->start(value);
    });
}

void MainWindow::setupTimer() {
    connect(timer_, &QTimer::timeout, this, &MainWindow::sendKeyPress);
}

void MainWindow::toggleAutoClicker() {
    if (timer_->isActive()) {
        timer_->stop();
        toggleButton_->setText("Destroy shit!");
    } else {
        timer_->start(intervalSpinBox_->value());
        toggleButton_->setText("Chill...");
    }
}
