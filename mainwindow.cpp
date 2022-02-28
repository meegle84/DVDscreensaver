#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui->setupUi(this);
    this->showDefaultScreensaver();
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::showDefaultScreensaver() {
    m_speedX = 1;
    m_speedY = 1;

    m_sizeX = ui->label->size().width();
    m_sizeY = ui->label->size().height();
    m_windowX = this->size().width();
    m_windowY = this->size().height();

    m_posX = rand() % m_windowX;
    m_posY = rand() % m_windowY;

    m_moveTimer = new QTimer(this);
    connect(m_moveTimer, &QTimer::timeout, this, &MainWindow::moveLabel, Qt::UniqueConnection);
    m_moveTimer->start(5);

    this->setStyleSheet("background-color: white;");
    ui->label->setPixmap(QPixmap(":/DVD_logo.svg"));
}

void MainWindow::checkBoundary() {
    if ((m_posX + m_sizeX >= m_windowX) || (m_posX <= 0)) {
        m_speedX = -m_speedX;
        changeColor();
    }
    if ((m_posY + m_sizeY >= m_windowY) || (m_posY <= 0)) {
        m_speedY = -m_speedY;
        changeColor();
    }
}

void MainWindow::moveLabel() {
    m_posX += m_speedX;
    m_posY += m_speedY;

    checkBoundary();
    ui->label->move(m_posX, m_posY);
}

void MainWindow::changeColor() {
    QString randomHex;

    for (int i = 0; i < 6; i++) {
        int n = qrand() % 16;
        randomHex.append(QString::number(n, 16));
    }
    ui->label->setStyleSheet("background: #" + randomHex);
}
