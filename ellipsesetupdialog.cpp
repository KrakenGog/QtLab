#include "ellipsesetupdialog.h"
#include "ui_ellipsesetupdialog.h"

EllipseSetupDialog::EllipseSetupDialog(App* app,QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::EllipseSetupDialog)
{
    ui->setupUi(this);
    _app = app;
    _ellipseRenderer = dynamic_cast<EllipseRenderer*>(app->GetRenderers()[FigureType::Ellipse]);
    _timer = new QTimer();
    _timer->setInterval(33);
    connect(_timer, &QTimer::timeout, this, &EllipseSetupDialog::Tick);
    _timer->start();

    ui->rXEdit->setText("10");
    ui->rYEdit->setText("10");
    ui->rotEdit->setText("0");
    ui->posXEdit->setText("0");
    ui->posYEdit->setText("0");
    ui->scaleXEdit->setText("1");
    ui->scaleYEdit->setText("1");
    ui->outlineCheckbox->setChecked(true);
    ui->fillCheckbox->setChecked(true);

    QString qss = QString("background-color: %1").arg(_outline.name());
    ui->outlineButton->setStyleSheet(qss);

    qss = QString("background-color: %1").arg(_filling.name());
    ui->fillingButton->setStyleSheet(qss);
}

EllipseSetupDialog::~EllipseSetupDialog()
{
    delete ui;
}



void EllipseSetupDialog::paintEvent(QPaintEvent *)
{
    QPainter painter(this);

    QPoint offset =QPoint(ui->preview->size().width(), ui->preview->size().height()) / 2;


    QPixmap pixmap(ui->preview->size());
    pixmap.fill(Qt::white);
    Figure* ellipse = GetEllipseByValues();
    ellipse->GetTransform().SetPositon(offset);
    _ellipseRenderer->RenderToPixmap(*ellipse, &pixmap);
    painter.drawPixmap(ui->preview->pos().x(),ui->preview->pos().y(),ui->preview->size().width(),ui->preview->size().height(), pixmap);


    painter.end();
}

Ellipse *EllipseSetupDialog::GetEllipseByValues()
{
    Ellipse* ellipse = new Ellipse(ui->rXEdit->text().toInt(), ui->rYEdit->text().toInt());
    ellipse->GetTransform().SetPositon({ui->posXEdit->text().toInt(), ui->posYEdit->text().toInt()});
    ellipse->GetTransform().SetRotation(ui->rotEdit->text().toDouble());
    ellipse->GetTransform().SetScale({ui->scaleXEdit->text().toDouble(), ui->scaleYEdit->text().toDouble()});

    ellipse->SetOutlineColor(_outline);
    ellipse->SetFillingColor(_filling);

    ellipse->SetFillingEnabled(ui->fillCheckbox->isChecked());
    ellipse->SetOutlineEnabled(ui->outlineCheckbox->isChecked());

    return ellipse;
}

void EllipseSetupDialog::Tick()
{
    update();
}

void EllipseSetupDialog::on_outlineButton_clicked()
{
    _outline = QColorDialog::getColor(_outline,this, "Set outline color");
    QString qss = QString("background-color: %1").arg(_outline.name());
    ui->outlineButton->setStyleSheet(qss);
    update();
}


void EllipseSetupDialog::on_fillingButton_clicked()
{
    _filling = QColorDialog::getColor(_filling,this, "Set filling color");
    QString qss = QString("background-color: %1").arg(_filling.name());
    ui->fillingButton->setStyleSheet(qss);
    update();
}


void EllipseSetupDialog::on_buttonBox_accepted()
{
    _app->EllipseAdded(GetEllipseByValues());
}

