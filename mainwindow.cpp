#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowIcon(QIcon(":/icon/icon.png"));
    this->setFixedSize(WIDTH_UI, HEIGHT_UI);
    this->setWindowTitle("Simulador gravitacional");
    ui->simulacion->hide();
    ui->parar_boton->hide();

    connect(ui->crear, SIGNAL(clicked(bool)), this, SLOT(crearPlaneta()));
    connect(ui->iniciar_boton, SIGNAL(clicked(bool)), this, SLOT(cargarUiSimulacion()));
    connect(ui->parar_boton, SIGNAL(clicked(bool)), this, SLOT(cargarUI()));
}

void MainWindow::simular()
{
    escena = new QGraphicsScene;
    escena->setSceneRect(0, 0, WIDTH_GV, HEIGHT_GV);
    escena->addItem(sistema[0]);
    escena->addItem(sistema[1]);

    ui->simulacion->setScene(escena);

}

void MainWindow::borrarCuerpos()
{
    for(unsigned int i = 0; i < sistema.size(); i++)
    {
        delete sistema[i];
        sistema[i] = nullptr;
    }

    sistema.clear();
}

void MainWindow::crearPlaneta()
{
    planet *planeta = new planet(ui->x0->value(), ui->y0->value(), ui->vx0->value(), ui->vy0->value(), ui->masa->value(), ui->radio->value());

    sistema.push_back(planeta);

    ui->x0->setValue(0);
    ui->y0->setValue(0);
    ui->vx0->setValue(0);
    ui->vy0->setValue(0);
    ui->masa->setValue(0);
    ui->radio->setValue(0);

    ui->n_planets->setText(QString::number(sistema.size()));
}

void MainWindow::cargarUiSimulacion()
{
    QString title = "Simulacion - " + QString::number(sistema.size()) + " cuerpos";
    this->setWindowTitle(title);
    ui->groupBox->hide();
    ui->iniciar_boton->hide();
    this->setFixedSize(WIDTH_GV, HEIGHT_SIM);
    ui->simulacion->show();
    ui->simulacion->setFrameStyle(0);
    ui->simulacion->setFixedSize(WIDTH_GV, HEIGHT_GV);
    ui->parar_boton->show();
    ui->parar_boton->setGeometry(this->width() - ui->parar_boton->width() - 10, this->height() - ui->parar_boton->height() - 23, ui->parar_boton->width(), ui->parar_boton->height());

    simular();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::cargarUI()
{
    borrarCuerpos();
    this->setFixedSize(WIDTH_UI, HEIGHT_UI);
    this->setWindowTitle("Simulador gravitacional");
    ui->simulacion->hide();
    ui->parar_boton->hide();
    ui->groupBox->show();
    ui->iniciar_boton->show();
    ui->n_planets->setText(QString::number(sistema.size()));
}

