#include "vertex.h"

int Vertex::id_next = 1;

Vertex::Vertex() : position(glm::vec3(0,0,0)), halfEdge(nullptr), id(id_next++)
{
    QListWidgetItem::setText(QString("Vertex ") + QString::number(id));
}

Vertex::Vertex(glm::vec3 pos) : position(pos), halfEdge(nullptr), id(id_next++)
{
    QListWidgetItem::setText(QString("Vertex ") + QString::number(id));
}
