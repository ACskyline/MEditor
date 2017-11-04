#ifndef FACE_H
#define FACE_H

#include "la.h"
#include "halfedge.h"
#include <QListWidgetItem>

class HalfEdge;

class Face : public QListWidgetItem
{
public:
    Face();
    Face(HalfEdge* h);
    Face(HalfEdge *h, glm::vec3 _col);

    HalfEdge* halfEdge;
    glm::vec3 col;
    int id;

    static int id_next;
};

#endif // FACE_H
