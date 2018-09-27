#include "face.h"

int Face::id_next = 1;

Face::Face() : halfEdge(nullptr), col(glm::vec3(0,0,1)), id(id_next++)
{
    needToDelete = false;
    QListWidgetItem::setText(QString("Face ") + QString::number(id));
}

Face::Face(HalfEdge* h) : halfEdge(h), col(glm::vec3(0,0,1)), id(id_next++)
{
    needToDelete = false;
    QListWidgetItem::setText(QString("Face ") + QString::number(id));
}

Face::Face(HalfEdge* h, glm::vec3 _col) : Face(h, _col, glm::vec3(0,0,0), false)
{
    needToDelete = false;
}

Face::Face(HalfEdge *h, glm::vec3 _col, glm::vec3 _nor, bool _hasNor)
    : halfEdge(h), col(_col), id(id_next++), nor(_nor), hasNor(_hasNor)
{
    needToDelete = false;
    QListWidgetItem::setText(QString("Face ") + QString::number(id));
}

Face::~Face()
{

}
