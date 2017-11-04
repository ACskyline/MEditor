#ifndef MYGL_H
#define MYGL_H

#include <glwidget277.h>
#include <utils.h>
#include <shaderprogram.h>
#include <scene/cylinder.h>
#include <scene/sphere.h>
#include "mesh.h"
#include "point.h"
#include "line.h"
#include "frame.h"
#include "camera.h"

#include <QOpenGLVertexArrayObject>
#include <QOpenGLShaderProgram>


class MyGL
    : public GLWidget277
{
    Q_OBJECT
private:
    Cylinder m_geomCylinder;// The instance of a unit cylinder we can use to render any cylinder
    Sphere m_geomSphere;// The instance of a unit sphere we can use to render any sphere

    ShaderProgram m_progLambert;// A shader program that uses lambertian reflection
    ShaderProgram m_progFlat;// A shader program that uses "flat" reflection (no shadowing at all)

    GLuint vao; // A handle for our vertex array object. This will store the VBOs created in our geometry classes.
                // Don't worry too much about this. Just know it is necessary in order to render geometry.

    Camera m_glCamera;
    glm::vec2 m_glCameraPrevPos;

    void rayVertex(glm::vec3 origin, glm::vec3 end);
    void rayHalfEdge(glm::vec3 origin, glm::vec3 end);
    void rayFace(glm::vec3 origin, glm::vec3 end);
    bool rayTriangle(glm::vec3 origin, glm::vec3 dir, glm::vec3 a, glm::vec3 b, glm::vec3 c, float* t);
public:
    Mesh m_geomMesh;
    Point m_geomPoint;
    Line m_geomLine;
    Frame m_geomFrame;

    Face* curF;
    HalfEdge* curH;
    Vertex* curV;

    explicit MyGL(QWidget *parent = 0);
    ~MyGL();

    void initializeGL();
    void resizeGL(int w, int h);
    void paintGL();
protected:
    void keyPressEvent(QKeyEvent *e);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void wheelEvent(QWheelEvent *e);

public slots:
    void slot_setCurrentFace(Face* f);
    void slot_setCurrentHalfEdge(HalfEdge* h);
    void slot_setCurrentVertex(Vertex* v);
    void slot_spiltEdge();
    void slot_triangulateFace();
    void slot_subdivide();
    void slot_extrude();
    void slot_bevelEdge();
    void slot_changeFR(double r);
    void slot_changeFG(double g);
    void slot_changeFB(double b);
    void slot_changeVX(double x);
    void slot_changeVY(double y);
    void slot_changeVZ(double z);
signals:
    void setClickFace(Face* f);
    void setClickHalfEdge(HalfEdge* h);
    void setClickVertex(Vertex* v);
    void updateList(std::vector<Vertex*> &vV, std::vector<HalfEdge*> &hV, std::vector<Face*> &fV);
};


#endif // MYGL_H
