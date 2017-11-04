#include "mygl.h"
#include <la.h>

#include <iostream>
#include <QApplication>
#include <QKeyEvent>


MyGL::MyGL(QWidget *parent)
    : GLWidget277(parent),
      m_geomCylinder(this), m_geomSphere(this), m_geomMesh(this),
      m_geomPoint(this), m_geomLine(this), m_geomFrame(this),
      curF(nullptr), curH(nullptr), curV(nullptr),
      m_progLambert(this), m_progFlat(this),
      m_glCamera()
{}

MyGL::~MyGL()
{
    makeCurrent();
    glDeleteVertexArrays(1, &vao);
    m_geomCylinder.destroy();
    m_geomSphere.destroy();
    m_geomMesh.destroy();
}

void MyGL::initializeGL()
{
    // Create an OpenGL context using Qt's QOpenGLFunctions_3_2_Core class
    // If you were programming in a non-Qt context you might use GLEW (GL Extension Wrangler)instead
    initializeOpenGLFunctions();
    // Print out some information about the current OpenGL context
    debugContextVersion();

    // Set a few settings/modes in OpenGL rendering
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_LINE_SMOOTH);
    glEnable(GL_POLYGON_SMOOTH);
    glHint(GL_LINE_SMOOTH_HINT, GL_NICEST);
    glHint(GL_POLYGON_SMOOTH_HINT, GL_NICEST);
    // Set the size with which points should be rendered
    glPointSize(5);
    // Set the color with which the screen is filled at the start of each render call.
    glClearColor(0.5, 0.5, 0.5, 1);

    printGLErrorLog();

    // Create a Vertex Attribute Object
    glGenVertexArrays(1, &vao);

    //Create the instances of Cylinder and Sphere.
    m_geomCylinder.create();
    m_geomSphere.create();
    m_geomMesh.create();

    // Create and set up the diffuse shader
    m_progLambert.create(":/glsl/lambert.vert.glsl", ":/glsl/lambert.frag.glsl");
    // Create and set up the flat lighting shader
    m_progFlat.create(":/glsl/flat.vert.glsl", ":/glsl/flat.frag.glsl");

    // Set a color with which to draw geometry since you won't have one
    // defined until you implement the Node classes.
    // This makes your geometry render green.
    m_progLambert.setGeometryColor(glm::vec4(0,1,0,1));

    // We have to have a VAO bound in OpenGL 3.2 Core. But if we're not
    // using multiple VAOs, we can just bind one once.
    //    vao.bind();
    glBindVertexArray(vao);
}

void MyGL::resizeGL(int w, int h)
{
    //This code sets the concatenated view and perspective projection matrices used for
    //our scene's camera view.
    m_glCamera = Camera(w, h);
    glm::mat4 viewproj = m_glCamera.getViewProj();

    // Upload the view-projection matrix to our shaders (i.e. onto the graphics card)

    m_progLambert.setViewProjMatrix(viewproj);
    m_progFlat.setViewProjMatrix(viewproj);

    printGLErrorLog();
}

//This function is called by Qt any time your GL window is supposed to update
//For example, when the function updateGL is called, paintGL is called implicitly.
//DO NOT CONSTRUCT YOUR SCENE GRAPH IN THIS FUNCTION!
void MyGL::paintGL()
{
    // Clear the screen so that we only see newly drawn images
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    m_progFlat.setViewProjMatrix(m_glCamera.getViewProj());
    m_progLambert.setViewProjMatrix(m_glCamera.getViewProj());

#define NOPE
#ifndef NOPE
    //Create a model matrix. This one scales the sphere uniformly by 3, then translates it by <-2,0,0>.
    //Note that we have to transpose the model matrix before passing it to the shader
    //This is because OpenGL expects column-major matrices, but you've
    //implemented row-major matrices.??????????What are you talking about. I did not implemented row-major matrices. I use glm matrices and they are column-major.
    glm::mat4 model = glm::translate(glm::mat4(1.0f), glm::vec3(-2,0,0)) * glm::scale(glm::mat4(1.0f), glm::vec3(3,3,3));
    //Send the geometry's transformation matrix to the shader
    m_progLambert.setModelMatrix(model);
    //Draw the example sphere using our lambert shader
    m_progLambert.draw(m_geomSphere);

    //Now do the same to render the cylinder
    //We've rotated it -45 degrees on the Z axis, then translated it to the point <2,2,0>
    model = glm::translate(glm::mat4(1.0f), glm::vec3(2,2,0)) * glm::rotate(glm::mat4(1.0f), glm::radians(-45.0f), glm::vec3(0,0,1));
    m_progLambert.setModelMatrix(model);
    m_progLambert.draw(m_geomCylinder);
#endif
    glm::mat4 model;// = glm::translate(glm::mat4(1.0f), glm::vec3(-2,0,0)) * glm::scale(glm::mat4(1.0f), glm::vec3(3,3,3));
    m_progLambert.setModelMatrix(model);
    m_progLambert.draw(m_geomMesh);

    glDisable(GL_DEPTH_TEST);

    if(curF!=nullptr)
    {
        m_geomFrame.setUp(curF);
        m_progFlat.setModelMatrix(model);
        m_progFlat.draw(m_geomFrame);
    }

    if(curH!=nullptr)
    {
        m_geomLine.setUp(curH);
        m_progFlat.setModelMatrix(model);
        m_progFlat.draw(m_geomLine);
    }

    if(curV!=nullptr)
    {
        m_geomPoint.setUp(curV);
        m_progFlat.setModelMatrix(model);
        m_progFlat.draw(m_geomPoint);
    }

    glEnable(GL_DEPTH_TEST);
}

void MyGL::keyPressEvent(QKeyEvent *e)
{

    float amount = 2.0f;
    if(e->modifiers() & Qt::ShiftModifier){
        amount = 10.0f;
    }
    // http://doc.qt.io/qt-5/qt.html#Key-enum
    // This could all be much more efficient if a switch
    // statement were used, but I really dislike their
    // syntax so I chose to be lazy and use a long
    // chain of if statements instead
    if (e->key() == Qt::Key_Escape) {
        QApplication::quit();
    } else if (e->key() == Qt::Key_Right) {
        m_glCamera.RotateAboutUp(-amount);
    } else if (e->key() == Qt::Key_Left) {
        m_glCamera.RotateAboutUp(amount);
    } else if (e->key() == Qt::Key_Up) {
        m_glCamera.RotateAboutRight(-amount);
    } else if (e->key() == Qt::Key_Down) {
        m_glCamera.RotateAboutRight(amount);
    } else if (e->key() == Qt::Key_1) {
        m_glCamera.fovy += amount;
    } else if (e->key() == Qt::Key_2) {
        m_glCamera.fovy -= amount;
    } else if (e->key() == Qt::Key_W) {
        m_glCamera.TranslateAlongLook(amount);
    } else if (e->key() == Qt::Key_S) {
        m_glCamera.TranslateAlongLook(-amount);
    } else if (e->key() == Qt::Key_D) {
        m_glCamera.TranslateAlongRight(amount);
    } else if (e->key() == Qt::Key_A) {
        m_glCamera.TranslateAlongRight(-amount);
    } else if (e->key() == Qt::Key_Q) {
        m_glCamera.TranslateAlongUp(-amount);
    } else if (e->key() == Qt::Key_E) {
        m_glCamera.TranslateAlongUp(amount);
    } else if (e->key() == Qt::Key_R) {
        m_glCamera = Camera(this->width(), this->height());
    } else if (e->key() == Qt::Key_N) {
        if(curH!=nullptr)
        {
            curH = curH->next;
            emit setClickHalfEdge(curH);
        }
    } else if (e->key() == Qt::Key_M) {
        if(curH!=nullptr)
        {
            curH = curH->sym;
            emit setClickHalfEdge(curH);
        }
    } else if (e->key() == Qt::Key_F) {
        if(curH!=nullptr)
        {
            curF = curH->face;
            emit setClickFace(curF);
        }
    } else if (e->key() == Qt::Key_V) {
        if(curH!=nullptr)
        {
            curV = curH->vert;
            emit setClickVertex(curV);
        }
    } else if (e->key() == Qt::Key_H) {
        if (QApplication::keyboardModifiers().testFlag(Qt::ShiftModifier) == true)
        {
            if(curF!=nullptr)
            {
                curH = curF->halfEdge;
                emit setClickHalfEdge(curH);
            }

        }
        else if(curV!=nullptr)
        {
            curH = curV->halfEdge;
            emit setClickHalfEdge(curH);
        }
    }
    m_glCamera.RecomputeAttributes();
    update();  // Calls paintGL, among other things
}

void MyGL::mousePressEvent(QMouseEvent *e)
{
    glm::vec2 p(e->pos().x(), this->height() - e->pos().y());
    glm::vec4 pos((p.x/(float)m_glCamera.width)*2.f-1.f, (p.y/(float)m_glCamera.height)*2.f-1.f, -1, 1);
    pos = glm::inverse(m_glCamera.getViewProj()) * pos;
    pos = pos/pos.w;

    if(QApplication::keyboardModifiers().testFlag(Qt::AltModifier) == true)
    {
        if(e->buttons() & (Qt::LeftButton | Qt::RightButton))
        {
            m_glCameraPrevPos = glm::vec2(e->pos().x(), e->pos().y());
        }
    }
    else
    {
        if(e->buttons() & Qt::LeftButton)
        {
            rayVertex(m_glCamera.eye, glm::vec3(pos));
        }
        else if(e->buttons() & Qt::RightButton)
        {
            rayHalfEdge(m_glCamera.eye, glm::vec3(pos));
        }
        else if(e->buttons() & Qt::MiddleButton)
        {
            rayFace(m_glCamera.eye, glm::vec3(pos));
        }
    }
}

void MyGL::mouseMoveEvent(QMouseEvent *e)
{
    if(QApplication::keyboardModifiers().testFlag(Qt::AltModifier) == true)
    {
        glm::vec2 pos(e->pos().x(), e->pos().y());
        if(e->buttons() & Qt::RightButton)
        {
            // Rotation
            glm::vec2 diff = 0.01f * (pos - m_glCameraPrevPos);
            m_glCameraPrevPos = pos;
            m_glCamera.RotatePhi(-diff.x);
            m_glCamera.RotateTheta(-diff.y);
            //m_glCamera.RotateAboutUp(-diff.x);
            //m_glCamera.RotateAboutRight(-diff.y);
            m_glCamera.RecomputeAttributes();
            update();
        }
        else if(e->buttons() & Qt::LeftButton)
        {
            // Panning
            glm::vec2 diff = 0.01f * (pos - m_glCameraPrevPos);
            m_glCameraPrevPos = pos;
            m_glCamera.TranslateAlongRight(-diff.x);
            m_glCamera.TranslateAlongUp(diff.y);
            m_glCamera.RecomputeAttributes();
            update();
        }
    }
}

void MyGL::wheelEvent(QWheelEvent *e)
{
    if(QApplication::keyboardModifiers().testFlag(Qt::AltModifier) == true)
    {
        m_glCamera.Zoom(e->delta() * 0.005f);
    }
    else
    {
        m_glCamera.Zoom(e->delta() * 0.02f);
    }
    m_glCamera.RecomputeAttributes();
    update();
}

void MyGL::slot_setCurrentFace(Face* f)
{
    curF = f;
    update();
}

void MyGL::slot_setCurrentHalfEdge(HalfEdge* h)
{
    curH = h;
    update();
}

void MyGL::slot_setCurrentVertex(Vertex* v)
{
    curV = v;
    update();
}

void MyGL::slot_spiltEdge()
{
    if(curH!=nullptr)
    {
        m_geomMesh.splitEdge(curH);
        update();
        emit updateList(m_geomMesh.vVector, m_geomMesh.hVector, m_geomMesh.fVector);
        emit setClickFace(curF);
        emit setClickHalfEdge(curH);
        emit setClickVertex(curV);
    }
}

void MyGL::slot_triangulateFace()
{
    if(curF!=nullptr)
    {
        m_geomMesh.triangulateFace(curF);
        update();
        emit updateList(m_geomMesh.vVector, m_geomMesh.hVector, m_geomMesh.fVector);
        emit setClickFace(curF);
        emit setClickHalfEdge(curH);
        emit setClickVertex(curV);
    }
}

void MyGL::slot_subdivide()
{
    m_geomMesh.subdivide();
    update();
    emit updateList(m_geomMesh.vVector, m_geomMesh.hVector, m_geomMesh.fVector);
    emit setClickFace(curF);
    emit setClickHalfEdge(curH);
    emit setClickVertex(curV);
}

void MyGL::slot_extrude()
{
    if(curF!=nullptr)
    {
        glm::vec3 normal(0,0,0);
        HalfEdge *startE = curF->halfEdge;
        HalfEdge *currentE = curF->halfEdge;
        do
        {
            glm::vec3 a = currentE->sym->vert->position;
            glm::vec3 b = currentE->vert->position;
            glm::vec3 c = currentE->next->vert->position;
            normal = glm::normalize(glm::cross(c-b,a-b));
            currentE = currentE->next;
        }while(glm::length(normal)==0&&currentE!=startE);
        m_geomMesh.extrudeFace(curF, 0.2f*normal);
        update();
        emit updateList(m_geomMesh.vVector, m_geomMesh.hVector, m_geomMesh.fVector);
        emit setClickFace(curF);
        emit setClickHalfEdge(curH);
        emit setClickVertex(curV);
    }
}

void MyGL::slot_bevelEdge()
{
    if(curH!=nullptr)
    {
        m_geomMesh.bevelEdge(curH);
        update();
        emit updateList(m_geomMesh.vVector, m_geomMesh.hVector, m_geomMesh.fVector);
        emit setClickFace(curF);
        emit setClickHalfEdge(curH);
        emit setClickVertex(curV);
    }
}

void MyGL::slot_changeFR(double r)
{
    if(curF!=nullptr)
    {
        curF->col.r = r;
        m_geomMesh.create();
        update();
    }
}

void MyGL::slot_changeFG(double g)
{
    if(curF!=nullptr)
    {
        curF->col.g = g;
        m_geomMesh.create();
        update();
    }
}

void MyGL::slot_changeFB(double b)
{
    if(curF!=nullptr)
    {
        curF->col.b = b;
        m_geomMesh.create();
        update();
    }
}

void MyGL::slot_changeVX(double x)
{
    if(curV!=nullptr)
    {
        curV->position.x = x;
        m_geomMesh.create();
        update();
    }
}

void MyGL::slot_changeVY(double y)
{
    if(curV!=nullptr)
    {
        curV->position.y = y;
        m_geomMesh.create();
        update();
    }
}

void MyGL::slot_changeVZ(double z)
{
    if(curV!=nullptr)
    {
        curV->position.z = z;
        m_geomMesh.create();
        update();
    }
}

void MyGL::rayVertex(glm::vec3 origin, glm::vec3 end)
{
    glm::vec3 dir = glm::normalize(end - origin);
    float minT = std::numeric_limits<float>::max();
    Vertex* minV = nullptr;
    for(int i = 0;i<m_geomMesh.vVector.size();i++)
    {
        glm::vec3 target = m_geomMesh.vVector.at(i)->position;
        float radius = 0.05f;
        float A = dir.x*dir.x + dir.y*dir.y + dir.z*dir.z;
        float B = 2*(glm::dot(dir,origin - target));
        float C = (origin.x - target.x)*(origin.x - target.x) +
                (origin.y - target.y)*(origin.y - target.y) +
                (origin.z - target.z)*(origin.z - target.z) -
                radius*radius;
        float d = B*B - 4*A*C;

        if(d < 0)
        {
            continue;
        }
        else
        {
            float t1 = (-B - sqrt(d))/(2*A);
            float t2 = (-B + sqrt(d))/(2*A);
            float t = glm::min(t1,t2);
            if(t<minT)
            {
                minT = t;
                minV = m_geomMesh.vVector.at(i);
            }
        }
    }

    if(minV!=nullptr){
        curV = minV;
        emit setClickVertex(curV);
        update();
    }
}

void MyGL::rayHalfEdge(glm::vec3 origin, glm::vec3 end)
{
    //assume m = 1
    glm::vec3 dir = glm::normalize(end - origin);
    float minT = std::numeric_limits<float>::max();
    HalfEdge* minH = nullptr;

    for(int i = 0;i<m_geomMesh.hVector.size();i++)
    {
        glm::vec3 a = m_geomMesh.hVector.at(i)->sym->vert->position;
        glm::vec3 b = m_geomMesh.hVector.at(i)->vert->position;

        glm::vec3 z = glm::normalize(b-a);
        glm::vec3 x = glm::normalize(glm::cross(b,a));
        glm::vec3 y = glm::normalize(glm::cross(z,x));
        glm::vec4 offset = glm::vec4(a, 1);
        glm::mat4 R(glm::vec4(x,0),glm::vec4(y,0),glm::vec4(z,0),offset);
        glm::mat4 Q = glm::inverse(R);
        float h = glm::length(b-a);

        glm::vec3 originQ = glm::vec3(Q*glm::vec4(origin,1));
        glm::vec3 dirQ = glm::vec3(Q*glm::vec4(dir,0));

        float radius = 0.05f;
        float A = dirQ.x*dirQ.x + dirQ.y*dirQ.y;
        float B = 2*(dirQ.x * originQ.x + dirQ.y * originQ.y);
        float C = originQ.x * originQ.x +
                originQ.y * originQ.y -
                radius*radius;
        float d = B*B - 4*A*C;

        if(d < 0)
        {
            continue;
        }
        else
        {
            float t1 = (-B - sqrt(d))/(2*A);
            float t2 = (-B + sqrt(d))/(2*A);
            float t = glm::min(t1,t2);
            glm::vec3 p = originQ + t*dirQ;
            if(p.z<h&&p.z>0)
            {
                if(t<minT)
                {
                    minT = t;
                    minH = m_geomMesh.hVector.at(i);
                }

            }
            else
            {
                continue;
            }
        }
    }

    if(minH!=nullptr)
    {
        curH = minH;
        emit setClickHalfEdge(curH);
        update();
    }
}

void MyGL::rayFace(glm::vec3 origin, glm::vec3 end)
{
    glm::vec3 dir = glm::normalize(end - origin);
    float minT = std::numeric_limits<float>::max();
    Face* minF = nullptr;

    for(int i = 0;i<m_geomMesh.fVector.size();i++)
    {
        Face* F = m_geomMesh.fVector.at(i);
        HalfEdge* startH = F->halfEdge;
        HalfEdge* currentH = startH->next;
        while(currentH->next!=startH)
        {
            glm::vec3 a = startH->sym->vert->position;
            glm::vec3 b = currentH->sym->vert->position;
            glm::vec3 c = currentH->vert->position;
            float t = 0;
            if(rayTriangle(origin,dir,a,b,c,&t))
            {
                if(t<minT)
                {
                    minT = t;
                    minF = F;
                }
            }
            currentH = currentH->next;
        }
    }



    if(minF!=nullptr)
    {
        curF = minF;
        emit setClickFace(curF);
        update();
    }
}

bool MyGL::rayTriangle(glm::vec3 origin, glm::vec3 dir, glm::vec3 a, glm::vec3 b, glm::vec3 c, float *t)
{
    glm::vec3 n = glm::normalize(glm::cross(b-a,c-a));
    glm::vec4 L = glm::vec4(n,-glm::dot(n,a));
    glm::vec4 S = glm::vec4(origin,1);
    glm::vec4 V = glm::vec4(dir,0);
    float LV = glm::dot(L,V);
    if(LV == 0)
    {
        return false;
    }
    *t = - glm::dot(L,S) / LV;
    glm::vec3 p = origin + (*t)*dir;
    glm::vec3 R = p - a;
    glm::vec3 Q1 = b - a;
    glm::vec3 Q2 = c - a;

    float Q1S = glm::dot(Q1,Q1);
    float Q2S = glm::dot(Q2,Q2);
    float Q12 = glm::dot(Q1,Q2);

    glm::vec2 w = (glm::mat2(glm::vec2(Q2S,-Q12),
                             glm::vec2(-Q12,Q1S)) *
                   glm::vec2(glm::dot(R,Q1),glm::dot(R,Q2))) /
            (Q1S*Q2S - Q12*Q12);

    if(w.x>=0 && w.y>=0 && w.x+w.y<=1)
    {
        return true;
    }
    else
    {
        return false;
    }

}
