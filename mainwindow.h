#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPoint>
#include <QMouseEvent>
#include <QPaintEvent>
#include <QPainter>
#include <functional>
#include <QPixmap>
#include <QTimer>
#include <ellipsesetupdialog.h>
#include <app.h>
#include <QRubberBand>
#include <transformationdialog.h>
#include <QFileDialog>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    QPixmap* GetScreen(){return _screen;}
    void SetPixmap(QPixmap pixmap);
    QPoint dragStart;
    bool drag = false;
    void paintEvent(QPaintEvent*);
    void mousePressEvent(QMouseEvent*);
    void mouseMoveEvent(QMouseEvent*);
    void mouseReleaseEvent(QMouseEvent*);
    void SetEllipseDialog(EllipseSetupDialog* dialog);
    void SetTickHandler(std::function<void()> tickHandler);
    void Tick();

    void resizeEvent(QResizeEvent*) override;


private slots:




    void on_CreateEllipse_triggered();

    void on_TransformForSelectedFigures_triggered();

    void on_OpenProject_triggered();

    void on_Save_triggered();

    void on_SaveAs_triggered();

    void on_comboBox1_currentIndexChanged(int index);

    void on_comboBox__currentIndexChanged(int index);

    void on_comboBox3_currentIndexChanged(int index);

private:
    Ui::MainWindow *ui;

    std::function<void(QPainter*)> _paint;
    std::function<void()> _tickHandler;
    QPixmap* _screen;
    EllipseSetupDialog* _ellipseDialog;
    QTimer* _timer;
    App* _app;
    QRubberBand* _rubberBand = nullptr;
    QPoint _startDrag;
    QPoint _mouseDrag;
    TransformationDialog* _transformDialog;
};
#endif // MAINWINDOW_H
