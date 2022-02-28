#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFrame>
#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

   public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

   private:
    Ui::MainWindow *ui;
    bool setCarouselImages();
    void showDefaultScreensaver();

    int m_carouselInterval; /**< Carousel interval for changing images */

    int m_posX;
    int m_posY;
    int m_speedX;
    int m_speedY;

    int m_sizeX;
    int m_sizeY;
    int m_windowX;
    int m_windowY;

    QTimer *m_moveTimer;

    void checkBoundary();
    void moveLabel();
    void changeColor();
};
#endif  // MAINWINDOW_H
