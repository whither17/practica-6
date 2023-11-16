#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <vector>
#include "macros.h"
#include "planet.h"

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

private:
    Ui::MainWindow *ui;
    std::vector<planet*> sistema;
    QGraphicsScene *escena;
    float x,y,T,k;

};
#endif // MAINWINDOW_H
