#ifndef TRANSFORMATIONDIALOG_H
#define TRANSFORMATIONDIALOG_H

#include <QDialog>
#include <app.h>

namespace Ui {
class TransformationDialog;
}

class TransformationDialog : public QDialog
{
    Q_OBJECT

public:
    explicit TransformationDialog(App* app,QWidget *parent = nullptr);
    ~TransformationDialog();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::TransformationDialog *ui;
    App* _app;
};

#endif // TRANSFORMATIONDIALOG_H
