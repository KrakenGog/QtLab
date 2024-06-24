#ifndef ELLIPSESETUPDIALOG_H
#define ELLIPSESETUPDIALOG_H

#include <QDialog>
#include <functional>
#include <Model/Headers/ellipse.h>
#include <QCloseEvent>
#include <QColor>
#include <QPaintEvent>
#include <View/Headers/ellipserenderer.h>
#include <QPixmap>
#include <QTimer>
#include <QColorDialog>
#include <app.h>

namespace Ui {
class EllipseSetupDialog;
}

class EllipseSetupDialog : public QDialog
{
    Q_OBJECT

public:
    explicit EllipseSetupDialog(App* app,QWidget *parent = nullptr);
    ~EllipseSetupDialog();


    void paintEvent(QPaintEvent*) override;
    Ellipse* GetEllipseByValues();
    void Tick();

private slots:
    void on_outlineButton_clicked();

    void on_fillingButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::EllipseSetupDialog *ui;

    QColor _outline = Qt::black;
    QColor _filling = Qt::white;
    EllipseRenderer* _ellipseRenderer;
    QTimer* _timer;
    App* _app;
};

#endif // ELLIPSESETUPDIALOG_H
