 #include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    _screen = new QPixmap(this->size());
    _screen->fill();

    _app = new App(_screen);

    _ellipseDialog = new EllipseSetupDialog(_app);
    _transformDialog = new TransformationDialog(_app);

    _timer = new QTimer();
    _timer->setInterval(33);
    connect(_timer, &QTimer::timeout, this, &MainWindow::Tick);
    _timer->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::SetPixmap(QPixmap pixmap)
{
    *_screen = pixmap;
}

void MainWindow::paintEvent(QPaintEvent* ev)
{
    _app->RenderLoop();

    QPainter painter(this);
    painter.drawPixmap(0,0,this->size().width(),this->size().height(), *_screen);
    painter.end();
}

void MainWindow::mousePressEvent(QMouseEvent *event){
    QPoint pos = event->pos();


    if(event->button() == Qt::RightButton){
        _startDrag = pos;

        if(_rubberBand == nullptr){
            _rubberBand = new QRubberBand(QRubberBand::Rectangle, this);
        }

        _rubberBand->setGeometry(QRect(_startDrag, QSize()));
        _rubberBand->show();
    }


    repaint();
}

void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    if(event->buttons() & Qt::RightButton){
        QPoint pos = event->pos();
        _mouseDrag = pos;

        _rubberBand->setGeometry(QRect(_startDrag, _mouseDrag).normalized());
    }
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    if(_rubberBand != nullptr){
        QRect rect = _rubberBand->rect();
        rect.moveTo(_rubberBand->pos());
        _app->Select(rect);
        delete _rubberBand;
        _rubberBand = nullptr;
    }
}

void MainWindow::SetEllipseDialog(EllipseSetupDialog *dialog)
{
    _ellipseDialog = dialog;
}

void MainWindow::SetTickHandler(std::function<void ()> tickHandler)
{
    _tickHandler = tickHandler;
}

void MainWindow::Tick()
{
    _screen->fill(Qt::white);
    _app->RenderLoop();
}

void MainWindow::resizeEvent(QResizeEvent *)
{
    *_screen = _screen->scaled(this->size());
}



void MainWindow::on_CreateEllipse_triggered()
{
    _ellipseDialog->show();
}


void MainWindow::on_TransformForSelectedFigures_triggered()
{
    _transformDialog->show();
}


void MainWindow::on_OpenProject_triggered()
{
    QString file =  QFileDialog::getOpenFileName(this,"Open",QDir::currentPath(),"(*.kr)");
    _app->Open(file);
    ui->comboBox1->setCurrentIndex(_app->c1);
    ui->comboBox1->setCurrentIndex(_app->c2);
    ui->comboBox1->setCurrentIndex(_app->c3);
}


void MainWindow::on_Save_triggered()
{
    if(!_app->HasOpenedProject())
    {
        on_SaveAs_triggered();
        return;
    }
    _app->Save();
}


void MainWindow::on_SaveAs_triggered()
{
    QString path = QFileDialog::getSaveFileName(this, "Save", QDir::currentPath(), "(*.kr)");
    _app->SaveAs(path);
}


void MainWindow::on_comboBox1_currentIndexChanged(int index)
{
    _app->c1 = index;
}


void MainWindow::on_comboBox__currentIndexChanged(int index)
{
    _app->c2 = index;
}


void MainWindow::on_comboBox3_currentIndexChanged(int index)
{
    _app->c3 = index;
}

