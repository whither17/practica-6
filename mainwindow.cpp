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
    data = new database;
    data->set_database_name("resultados.txt");
    datos = "";
    timer = new QTimer;

    connect(ui->crear, SIGNAL(clicked(bool)), this, SLOT(crearPlaneta()));
    connect(ui->iniciar_boton, SIGNAL(clicked(bool)), this, SLOT(cargarUiSimulacion()));
    connect(ui->parar_boton, SIGNAL(clicked(bool)), this, SLOT(cargarUI()));

    connect(timer, SIGNAL(timeout()), this, SLOT(velocidades()));
}

void MainWindow::simular()
{
    escena = new QGraphicsScene;
    escena->setSceneRect(0, 0, WIDTH_GV, HEIGHT_GV);
    escena->addItem(sistema[0]);
    escena->addItem(sistema[1]);

    ui->simulacion->setScene(escena);
    n = 0;
    timer->start();
}

void MainWindow::velocidades()
{
    /*
     * No funciona, está mala la ecuacion, no sé si es la ecuacion de aceleracion o la ecuacion de
     * velocidad, solo sé que la ecuacion de distancia si trabaja
     * correctamente
    */
    double aceleracion_suma_x = 0;
    double aceleracion_suma_y = 0;
    double r_cubo = 0;

    for(unsigned int i = 0; i < sistema.size(); i++)
    {
        for(unsigned int j = 0; j < sistema.size(); j++)
        {
            if(i != j)
            {
                r_cubo = std::pow(distancia(sistema[j], sistema[i]), 3);
                aceleracion_suma_x = aceleracion_suma_x + G*((sistema[j]->getMasa()/r_cubo)*(sistema[j]->getX_i() - sistema[i]->getX_i()));
                aceleracion_suma_y = aceleracion_suma_y + G*((sistema[j]->getMasa()/r_cubo)*(sistema[j]->getY_i() - sistema[i]->getY_i()));
                qDebug() << aceleracion_suma_x;
            }
        }

        sistema[i]->setVx_i(sistema[i]->getVx_i()+aceleracion_suma_x*T*n);
        sistema[i]->setVy_i(sistema[i]->getVy_i()+aceleracion_suma_y*T*n);

        aceleracion_suma_x = 0;
        aceleracion_suma_y = 0;


        sistema[i]->setPosicion((sistema[i]->getX_i()+sistema[i]->getVx_i()*T*n*k), (sistema[i]->getY_i()+sistema[i]->getVy_i()*T*n*k));
        datos = datos + "\t" + std::to_string(sistema[i]->x()) + "\t" + std::to_string(sistema[i]->y());
    }
    datos = datos + "\n";
    n++;

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

double MainWindow::distancia(planet *p1, planet *p2)
{
    double dist = 0;

    dist = std::sqrt(std::pow((p2->getX_i() - p1->getX_i()), 2) + std::pow((p2->getY_i() - p1->getY_i()), 2));

    return dist;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete data;
}

void MainWindow::cargarUI()
{
    timer->stop();
    n = 0;
    borrarCuerpos();
    this->setFixedSize(WIDTH_UI, HEIGHT_UI);
    this->setWindowTitle("Simulador gravitacional");
    ui->simulacion->hide();
    ui->parar_boton->hide();
    ui->groupBox->show();
    ui->iniciar_boton->show();
    ui->n_planets->setText(QString::number(sistema.size()));

    data->append_database_info(datos);
}

