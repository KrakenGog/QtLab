#include "transformationdialog.h"
#include "ui_transformationdialog.h"

TransformationDialog::TransformationDialog(App* app, QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::TransformationDialog)
{
    ui->setupUi(this);
    _app = app;
}

TransformationDialog::~TransformationDialog()
{
    delete ui;
}

void TransformationDialog::on_buttonBox_accepted()
{
    std::vector<Figure*>* figures = _app->GetFigures();

    for(Figure* figure : *figures){
        if(figure->Selected()){
            figure->GetTransform().Translate(QPoint(ui->trX->text().toInt(), ui->trY->text().toInt()));
            figure->GetTransform().Rotate(ui->rot->text().toDouble());
            figure->GetTransform().AddScale(QPoint(ui->scX->text().toInt(), ui->scY->text().toInt()));
        }
    }
}

