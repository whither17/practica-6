#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <vector>
#include "macros.h"
#include "planet.h"
#include "database.h"
#include <cmath>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void simular();

    void borrarCuerpos();
    ~MainWindow();

public slots:
    void cargarUI();
    void crearPlaneta();
    void cargarUiSimulacion();
    void velocidades();

private:
    double distancia(planet *p1, planet *p2);
    Ui::MainWindow *ui;
    std::vector<planet*> sistema;
    QGraphicsScene *escena;
    float x,y;
    int n;
    QTimer *timer;
    database *data;
    std::string datos;
};
#endif // MAINWINDOW_H
