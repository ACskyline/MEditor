#include "mainwindow.h"
#include <ui_mainwindow.h>
#include <QDesktopWidget>
#include <QFileDialog>
#include "cameracontrolshelp.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    g(new gui())
{
    ui->setupUi(this);
    ui->mygl->setFocus();

    g->show();
    g->move(QApplication::desktop()->screen()->rect().center() - this->rect().center() + QPoint(this->width(), 0));
    g->updateFaceList(ui->mygl->m_geomMesh.fVector);
    g->updateHalfEdgeList(ui->mygl->m_geomMesh.hVector);
    g->updateVertexList(ui->mygl->m_geomMesh.vVector);

    connectSignalSlot();
}

MainWindow::~MainWindow()
{
    if(g!=nullptr)
    {
        delete g;
    }
    delete ui;
}

void MainWindow::on_actionQuit_triggered()
{
    g->close();
    QApplication::exit();
}

void MainWindow::on_actionCamera_Controls_triggered()
{
    CameraControlsHelp* c = new CameraControlsHelp();
    c->show();
}

void MainWindow::closeEvent(QCloseEvent *e)
{
    g->close();
    QMainWindow::closeEvent(e);
}

void MainWindow::on_actionEditor_triggered()
{
    g->close();
    delete g;
    g = new gui();
    g->show();
    g->move(QApplication::desktop()->screen()->rect().center() - this->rect().center() + QPoint(this->width(), 0));
    g->updateFaceList(ui->mygl->m_geomMesh.fVector);
    g->updateHalfEdgeList(ui->mygl->m_geomMesh.hVector);
    g->updateVertexList(ui->mygl->m_geomMesh.vVector);
    g->slot_setClickFace(ui->mygl->curF);
    g->slot_setClickHalfEdge(ui->mygl->curH);
    g->slot_setClickVertex(ui->mygl->curV);

    connectSignalSlot();
}

void MainWindow::on_actionOpen_triggered()
{
    QString fileName = QFileDialog::getOpenFileName(this,tr("Open File"),"./",tr("Obj Files (*.obj)"));
    if(fileName!=QString::null)
    {
        QFile file(fileName);
        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
            return;

        // clear previous stuff
        ui->mygl->curF = nullptr;
        ui->mygl->curH = nullptr;
        ui->mygl->curV = nullptr;
        if(g!=nullptr)
        {
            g->freeList();
        }
        ///////////////////////
        ui->mygl->m_geomMesh.parseFile(&file);
        ui->mygl->update();
        g->slot_updateList(ui->mygl->m_geomMesh.vVector,ui->mygl->m_geomMesh.hVector,ui->mygl->m_geomMesh.fVector);
        g->slot_setClickFace(ui->mygl->curF);
        g->slot_setClickHalfEdge(ui->mygl->curH);
        g->slot_setClickVertex(ui->mygl->curV);
    }
}

void MainWindow::connectSignalSlot()
{
    connect(g,SIGNAL(selectFace(Face*)), ui->mygl, SLOT(slot_setCurrentFace(Face*)));
    connect(g,SIGNAL(selectHalfEdge(HalfEdge*)), ui->mygl, SLOT(slot_setCurrentHalfEdge(HalfEdge*)));
    connect(g,SIGNAL(selectVertex(Vertex*)), ui->mygl, SLOT(slot_setCurrentVertex(Vertex*)));
    connect(g,SIGNAL(splitEdge()),ui->mygl,SLOT(slot_spiltEdge()));
    connect(g,SIGNAL(triangulateFace()),ui->mygl,SLOT(slot_triangulateFace()));
    connect(g,SIGNAL(subdivide()),ui->mygl,SLOT(slot_subdivide()));
    connect(g,SIGNAL(extrude()),ui->mygl,SLOT(slot_extrude()));
    connect(g,SIGNAL(bevelEdge()),ui->mygl,SLOT(slot_bevelEdge()));
    connect(g,SIGNAL(changeFR(double)),ui->mygl,SLOT(slot_changeFR(double)));
    connect(g,SIGNAL(changeFG(double)),ui->mygl,SLOT(slot_changeFG(double)));
    connect(g,SIGNAL(changeFB(double)),ui->mygl,SLOT(slot_changeFB(double)));
    connect(g,SIGNAL(changeVX(double)),ui->mygl,SLOT(slot_changeVX(double)));
    connect(g,SIGNAL(changeVY(double)),ui->mygl,SLOT(slot_changeVY(double)));
    connect(g,SIGNAL(changeVZ(double)),ui->mygl,SLOT(slot_changeVZ(double)));

    connect(ui->mygl,SIGNAL(setClickFace(Face*)),g,SLOT(slot_setClickFace(Face*)));
    connect(ui->mygl,SIGNAL(setClickHalfEdge(HalfEdge*)),g,SLOT(slot_setClickHalfEdge(HalfEdge*)));
    connect(ui->mygl,SIGNAL(setClickVertex(Vertex*)),g,SLOT(slot_setClickVertex(Vertex*)));
    connect(ui->mygl,SIGNAL(updateList(std::vector<Vertex*>&,std::vector<HalfEdge*>&,std::vector<Face*>&)),
            g,SLOT(slot_updateList(std::vector<Vertex*>&,std::vector<HalfEdge*>&,std::vector<Face*>&)));
}
