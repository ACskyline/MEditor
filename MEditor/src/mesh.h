#ifndef MESH_H
#define MESH_H

#include "drawable.h"
#include "halfedge.h"
#include <QFile>

class Mesh : public Drawable
{
private:
    void parseObjFace(std::stringstream &ss);
    void setSyms();
public:
    std::vector<HalfEdge*> hVector;
    std::vector<Vertex*> vVector;
    std::vector<Face*> fVector;
    Mesh(GLWidget277 *context);
    ~Mesh();
    void freeMemory();
    void initializeCube();
    void virtual create();
    void splitEdge(HalfEdge* h);
    void triangulateFace(Face* f);
    void subdivide();
    void smoothMidPoint(HalfEdge* h, std::map<Face*, glm::vec3>& FtoC);
    void extrudeFace(Face*f, glm::vec3 offset);
    void bevelEdge(HalfEdge* h);
    void parseFile(QFile* F);
};

#endif // MESH_H
