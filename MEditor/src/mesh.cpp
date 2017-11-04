#include "mesh.h"
#include <stack>
#include <sstream>
#include <cstdlib>
#include <ctime>

Mesh::Mesh(GLWidget277 *context) : Drawable(context)
{
    initializeCube();
}

Mesh::~Mesh()
{
    destroy();
    freeMemory();
}

void Mesh::freeMemory()
{
    for(int i = 0;i<vVector.size();i++)
    {
        if(vVector.at(i)!=nullptr)
        {
            delete vVector.at(i);
        }
    }
    for(int i = 0;i<hVector.size();i++)
    {
        if(hVector.at(i)!=nullptr)
        {
            delete hVector.at(i);
        }
    }
    for(int i = 0;i<fVector.size();i++)
    {
        if(fVector.at(i)!=nullptr)
        {
            delete fVector.at(i);
        }
    }

    vVector.clear();
    hVector.clear();
    fVector.clear();
}

void Mesh::initializeCube()
{
    freeMemory();
    //Vertex
    //counter clock-wise
    vVector.push_back(new Vertex(glm::vec3(-0.5,-0.5,-0.5)));//0
    vVector.push_back(new Vertex(glm::vec3(0.5,-0.5,-0.5)));//1
    vVector.push_back(new Vertex(glm::vec3(0.5,-0.5,0.5)));//2
    vVector.push_back(new Vertex(glm::vec3(-0.5,-0.5,0.5)));//3
    vVector.push_back(new Vertex(glm::vec3(-0.5,0.5,0.5)));//4
    vVector.push_back(new Vertex(glm::vec3(0.5,0.5,0.5)));//5
    vVector.push_back(new Vertex(glm::vec3(0.5,0.5,-0.5)));//6
    vVector.push_back(new Vertex(glm::vec3(-0.5,0.5,-0.5)));//7

    //HalfEdge
    //counter clock-wise
    //bottom
    hVector.push_back(new HalfEdge(vVector.at(1)));
    hVector.push_back(new HalfEdge(vVector.at(2)));
    hVector.push_back(new HalfEdge(vVector.at(3)));
    hVector.push_back(new HalfEdge(vVector.at(0)));
    //top
    hVector.push_back(new HalfEdge(vVector.at(5)));
    hVector.push_back(new HalfEdge(vVector.at(6)));
    hVector.push_back(new HalfEdge(vVector.at(7)));
    hVector.push_back(new HalfEdge(vVector.at(4)));
    //front
    hVector.push_back(new HalfEdge(vVector.at(2)));
    hVector.push_back(new HalfEdge(vVector.at(5)));
    hVector.push_back(new HalfEdge(vVector.at(4)));
    hVector.push_back(new HalfEdge(vVector.at(3)));
    //right
    hVector.push_back(new HalfEdge(vVector.at(1)));
    hVector.push_back(new HalfEdge(vVector.at(6)));
    hVector.push_back(new HalfEdge(vVector.at(5)));
    hVector.push_back(new HalfEdge(vVector.at(2)));
    //back
    hVector.push_back(new HalfEdge(vVector.at(0)));
    hVector.push_back(new HalfEdge(vVector.at(7)));
    hVector.push_back(new HalfEdge(vVector.at(6)));
    hVector.push_back(new HalfEdge(vVector.at(1)));
    //left
    hVector.push_back(new HalfEdge(vVector.at(3)));
    hVector.push_back(new HalfEdge(vVector.at(4)));
    hVector.push_back(new HalfEdge(vVector.at(7)));
    hVector.push_back(new HalfEdge(vVector.at(0)));

    //new Face
    //bottom
    fVector.push_back(new Face(hVector.at(0),glm::vec3(.99f,.47f,.82f)));
    //top
    fVector.push_back(new Face(hVector.at(4),glm::vec3(.95f,.67f,0.f)));
    //front
    fVector.push_back(new Face(hVector.at(8),glm::vec3(0.f,.49f,.23f)));
    //right
    fVector.push_back(new Face(hVector.at(12),glm::vec3(.26f,.60f,.87f)));
    //back
    fVector.push_back(new Face(hVector.at(16),glm::vec3(.39f,.82f,.24f)));
    //left
    fVector.push_back(new Face(hVector.at(20),glm::vec3(.49f,.53f,.93f)));

    //complete vertex
    vVector.at(0)->halfEdge = hVector.at(0);
    vVector.at(1)->halfEdge = hVector.at(1);
    vVector.at(2)->halfEdge = hVector.at(2);
    vVector.at(3)->halfEdge = hVector.at(3);
    vVector.at(4)->halfEdge = hVector.at(4);
    vVector.at(5)->halfEdge = hVector.at(5);
    vVector.at(6)->halfEdge = hVector.at(6);
    vVector.at(7)->halfEdge = hVector.at(7);

    //complete halfedge
    //bottom
    hVector.at(0)->next = hVector.at(1);
    hVector.at(0)->sym = hVector.at(16);
    hVector.at(0)->face = fVector.at(0);
    hVector.at(1)->next = hVector.at(2);
    hVector.at(1)->sym = hVector.at(12);
    hVector.at(1)->face = fVector.at(0);
    hVector.at(2)->next = hVector.at(3);
    hVector.at(2)->sym = hVector.at(8);
    hVector.at(2)->face = fVector.at(0);
    hVector.at(3)->next = hVector.at(0);
    hVector.at(3)->sym = hVector.at(20);
    hVector.at(3)->face = fVector.at(0);
    //top
    hVector.at(4)->next = hVector.at(5);
    hVector.at(4)->sym = hVector.at(10);
    hVector.at(4)->face = fVector.at(1);
    hVector.at(5)->next = hVector.at(6);
    hVector.at(5)->sym = hVector.at(14);
    hVector.at(5)->face = fVector.at(1);
    hVector.at(6)->next = hVector.at(7);
    hVector.at(6)->sym = hVector.at(18);
    hVector.at(6)->face = fVector.at(1);
    hVector.at(7)->next = hVector.at(4);
    hVector.at(7)->sym = hVector.at(22);
    hVector.at(7)->face = fVector.at(1);
    //front
    hVector.at(8)->next = hVector.at(9);
    hVector.at(8)->sym = hVector.at(2);
    hVector.at(8)->face = fVector.at(2);
    hVector.at(9)->next = hVector.at(10);
    hVector.at(9)->sym = hVector.at(15);
    hVector.at(9)->face = fVector.at(2);
    hVector.at(10)->next = hVector.at(11);
    hVector.at(10)->sym = hVector.at(4);
    hVector.at(10)->face = fVector.at(2);
    hVector.at(11)->next = hVector.at(8);
    hVector.at(11)->sym = hVector.at(21);
    hVector.at(11)->face = fVector.at(2);
    //right
    hVector.at(12)->next = hVector.at(13);
    hVector.at(12)->sym = hVector.at(1);
    hVector.at(12)->face = fVector.at(3);
    hVector.at(13)->next = hVector.at(14);
    hVector.at(13)->sym = hVector.at(19);
    hVector.at(13)->face = fVector.at(3);
    hVector.at(14)->next = hVector.at(15);
    hVector.at(14)->sym = hVector.at(5);
    hVector.at(14)->face = fVector.at(3);
    hVector.at(15)->next = hVector.at(12);
    hVector.at(15)->sym = hVector.at(9);
    hVector.at(15)->face = fVector.at(3);
    //back
    hVector.at(16)->next = hVector.at(17);
    hVector.at(16)->sym = hVector.at(0);
    hVector.at(16)->face = fVector.at(4);
    hVector.at(17)->next = hVector.at(18);
    hVector.at(17)->sym = hVector.at(23);
    hVector.at(17)->face = fVector.at(4);
    hVector.at(18)->next = hVector.at(19);
    hVector.at(18)->sym = hVector.at(6);
    hVector.at(18)->face = fVector.at(4);
    hVector.at(19)->next = hVector.at(16);
    hVector.at(19)->sym = hVector.at(13);
    hVector.at(19)->face = fVector.at(4);
    //left
    hVector.at(20)->next = hVector.at(21);
    hVector.at(20)->sym = hVector.at(3);
    hVector.at(20)->face = fVector.at(5);
    hVector.at(21)->next = hVector.at(22);
    hVector.at(21)->sym = hVector.at(11);
    hVector.at(21)->face = fVector.at(5);
    hVector.at(22)->next = hVector.at(23);
    hVector.at(22)->sym = hVector.at(7);
    hVector.at(22)->face = fVector.at(5);
    hVector.at(23)->next = hVector.at(20);
    hVector.at(23)->sym = hVector.at(17);
    hVector.at(23)->face = fVector.at(5);
}

void Mesh::create()
{
    destroy();
    std::vector<GLuint> mesh_idx;
    std::vector<glm::vec4> mesh_vert_pos;
    std::vector<glm::vec4> mesh_vert_nor;
    std::vector<glm::vec4> mesh_vert_col;

    for(int i = 0;i<fVector.size();i++)
    {
        HalfEdge* startEdge = fVector.at(i)->halfEdge;
        HalfEdge* curEdge = startEdge;
        int vperf = 0;
        glm::vec3 fcol = fVector.at(i)->col;
        glm::vec3 fnor = glm::cross(startEdge->next->vert->position-startEdge->vert->position,
                                    startEdge->sym->vert->position-startEdge->vert->position);


        HalfEdge* he = startEdge->next;
        while(glm::length(fnor)==0&&he!=startEdge)
        {
            fnor = glm::cross(he->next->vert->position-he->vert->position,
                              he->sym->vert->position-he->vert->position);
            he = he->next;
        }
        fnor = glm::normalize(fnor);


        do
        {
            mesh_vert_pos.push_back(glm::vec4(curEdge->vert->position,1));
            mesh_vert_nor.push_back(glm::vec4(fnor,1));
            mesh_vert_col.push_back(glm::vec4(fcol,1));
            vperf++;
            if(vperf>2)
            {
                mesh_idx.push_back(mesh_vert_pos.size()-vperf);
                mesh_idx.push_back(mesh_vert_pos.size()-2);
                mesh_idx.push_back(mesh_vert_pos.size()-1);
            }
            curEdge = curEdge->next;
        }
        while(curEdge!=startEdge);
    }
    count = mesh_idx.size();

    generateIdx();
    mp_context->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bufIdx);
    mp_context->glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh_idx.size() * sizeof(GLuint), mesh_idx.data(), GL_STATIC_DRAW);

    generatePos();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufPos);
    mp_context->glBufferData(GL_ARRAY_BUFFER, mesh_vert_pos.size() * sizeof(glm::vec4), mesh_vert_pos.data(), GL_STATIC_DRAW);

    generateNor();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufNor);
    mp_context->glBufferData(GL_ARRAY_BUFFER, mesh_vert_nor.size() * sizeof(glm::vec4), mesh_vert_nor.data(), GL_STATIC_DRAW);

    generateCol();
    mp_context->glBindBuffer(GL_ARRAY_BUFFER, bufCol);
    mp_context->glBufferData(GL_ARRAY_BUFFER, mesh_vert_col.size() * sizeof(glm::vec4), mesh_vert_col.data(), GL_STATIC_DRAW);

}

void Mesh::splitEdge(HalfEdge* h)
{
    //assume h is he1 in the slide
    if(h!=nullptr)
    {
        vVector.push_back(new Vertex((h->vert->position+h->sym->vert->position)/2.f));//v3
        hVector.push_back(new HalfEdge(h->vert));//he1b->vert = he1->vert
        hVector.push_back(new HalfEdge(h->sym->vert));//he2b->vert = he2->vert

        HalfEdge *he1 = h;
        HalfEdge *he2 = h->sym;
        HalfEdge *he1b = hVector.at(hVector.size()-2);
        HalfEdge *he2b = hVector.at(hVector.size()-1);
        Vertex *v3 = vVector.at(vVector.size()-1);

        //v3
        v3->halfEdge = he1b;//he1b

        //he1b
        he1b->sym = he2;//he2
        he1b->next = he1->next;//he1->next
        he1b->face = he1->face;//he1->face

        //he2b
        he2b->sym = he1;//he1
        he2b->next = he2->next;//he2->next
        he2b->face = he2->face;//he2->face

        //he1
        he1->sym = he2b;//he2b
        he1->next = he1b;//he1b
        he1->vert = v3;//v3

        //he2
        he2->sym = he1b;//he1b
        he2->next = he2b;//he2b
        he2->vert = v3;//v3

        create();
    }
}

void Mesh::triangulateFace(Face* f)
{
    if(f!=nullptr)
    {
        HalfEdge* startE = f->halfEdge;
        HalfEdge* curE = startE->next;
        HalfEdge* h1next = startE;

        Face* f1 = f;

        while(curE->next->next!=startE)
        {
            hVector.push_back(new HalfEdge(startE->sym->vert));
            hVector.push_back(new HalfEdge(curE->vert));

            HalfEdge* h1 = hVector.at(hVector.size()-2);
            HalfEdge* h2 = hVector.at(hVector.size()-1);

            h1->next = h1next;
            h1->sym = h2;
            h1->face = f1;

            fVector.push_back(new Face(h2,f->col));
            Face* f2 = fVector.at(fVector.size()-1);

            h2->next = curE->next;
            h2->sym = h1;
            h2->face = f2;

            curE->next = h1;
            curE->face = f1;
            //need to change curE->face

            h1next = h2;

            curE = h2->next;

            f1 = fVector.at(fVector.size()-1);
        }

        //for last face
        curE->face = f1;
        curE->next->face = f1;
        curE->next->next = h1next;

        create();
    }
}

void Mesh::subdivide()
{
    // step 1: save centroid
    std::map<Face*,glm::vec3> FtoC;
    for(int i = 0;i<fVector.size();i++)
    {
        HalfEdge* startH = fVector.at(i)->halfEdge;
        HalfEdge* currentH = startH;
        float numV = 0;
        glm::vec3 sumV(0,0,0);
        while(currentH->next != startH)
        {
            numV++;
            sumV += currentH->vert->position;
            currentH = currentH->next;
        }
        numV++;
        sumV += currentH->vert->position;

        glm::vec3 centroid = sumV/numV;
        FtoC[fVector.at(i)] = centroid;
    }

    // step 2: add mid point
    int hVsize = hVector.size();
    int vVsize = vVector.size();
    std::map<HalfEdge*, bool> HtoB;
    for(int i = 0;i<hVsize;i++)
    {
        HtoB[hVector.at(i)] = false;
    }
    for(int i = 0;i<hVsize;i++)
    {
        if(HtoB[hVector.at(i)]==false)
        {
            HtoB[hVector.at(i)] = true;
            HtoB[hVector.at(i)->sym] = true;
            smoothMidPoint(hVector.at(i),FtoC);
        }
    }

    // step 3: adjust position of each original vertex(excluding mid point)
    for(int i = 0;i<vVsize;i++)
    {
        Vertex* startV = vVector.at(i);
        HalfEdge* startH = startV->halfEdge;
        if(startH->vert==startV)
            startH = startH->sym;//this makes sure that the half edge is the one pointing out of the vertex
        HalfEdge* currentH = startH;
        glm::vec3 sumE(0,0,0);
        glm::vec3 sumH(0,0,0);
        float n = 0;
        while(currentH->sym->next!=startH)
        {
            n++;
            sumE += currentH->vert->position;
            sumH += FtoC[currentH->face];
            currentH = currentH->sym->next;
        }
        n++;
        sumE += currentH->vert->position;
        sumH += FtoC[currentH->face];

        vVector.at(i)->position = (n-2)*vVector.at(i)->position / n +
                sumE / (n*n) +
                sumH / (n*n);
    }

    // step 4: quadrangulate each face with respect to its centroid
    int fVsize = fVector.size();
    for(int i = 0;i<fVsize;i++)
    {
        HalfEdge* startH = fVector.at(i)->halfEdge;
        HalfEdge* currentH = startH;
        Face* f1 = fVector.at(i);
        vVector.push_back(new Vertex(FtoC[f1]));
        Vertex* c = vVector.at(vVector.size()-1);
        HalfEdge* h1next = nullptr;
        while(currentH->next->next != startH)
        {
            hVector.push_back(new HalfEdge(c));
            hVector.push_back(new HalfEdge(currentH->vert));

            HalfEdge* h1 = hVector.at(hVector.size()-2);
            HalfEdge* h2 = hVector.at(hVector.size()-1);

            h1->next = h1next;
            h1->sym = h2;
            h1->face = f1;

            fVector.push_back(new Face(currentH->next->next,f1->col));
            Face* f2 = fVector.at(fVector.size()-1);

            h2->next = currentH->next;
            h2->sym = h1;
            h2->face = f2;

            currentH->next->face = f2;

            currentH->next = h1;
            currentH->face = f1;

            currentH = h2->next->next;
            f1 = f2;
            h1next = h2;
        }
        //don't forget last time
        //for last face
        hVector.push_back(new HalfEdge(c));
        hVector.push_back(new HalfEdge(currentH->vert));

        HalfEdge* h1 = hVector.at(hVector.size()-2);
        HalfEdge* h2 = hVector.at(hVector.size()-1);

        h1->next = h1next;
        h1->sym = h2;
        h1->face = f1;

        Face* f2 = fVector.at(i);

        h2->next = currentH->next;
        h2->sym = h1;
        h2->face = f2;

        currentH->next->face = f2;

        currentH->next = h1;
        currentH->face = f1;

        currentH = h2->next->next;//not necessary
        f1 = f2;//not necessary
        h1next = h2;//not necessary

        //also don't forget to assaign centorid's half edge
        c->halfEdge = h2;
        //the first h1next is null because it did not exist at that time
        f2->halfEdge->next->next = h1next;
    }

    create();

}

void Mesh::smoothMidPoint(HalfEdge *h, std::map<Face*, glm::vec3>& FtoC)
{
    if(h!=nullptr)
    {
        glm::vec3 v1 = h->vert->position;
        glm::vec3 v2 = h->sym->vert->position;
        glm::vec3 v3 = FtoC[h->face];
        glm::vec3 v4 = FtoC[h->sym->face];
        vVector.push_back(new Vertex((v1+v2+v3+v4)/4.f));//v
        hVector.push_back(new HalfEdge(h->vert));//he1b->vert = he1->vert
        hVector.push_back(new HalfEdge(h->sym->vert));//he2b->vert = he2->vert

        HalfEdge *he1 = h;
        HalfEdge *he2 = h->sym;
        HalfEdge *he1b = hVector.at(hVector.size()-2);
        HalfEdge *he2b = hVector.at(hVector.size()-1);
        Vertex *v = vVector.at(vVector.size()-1);

        //v
        v->halfEdge = he1b;//he1b

        //he1b
        he1b->sym = he2;//he2
        he1b->next = he1->next;//he1->next
        he1b->face = he1->face;//he1->face

        //he2b
        he2b->sym = he1;//he1
        he2b->next = he2->next;//he2->next
        he2b->face = he2->face;//he2->face

        //he1
        he1->sym = he2b;//he2b
        he1->next = he1b;//he1b
        he1->vert = v;//v

        //he2
        he2->sym = he1b;//he1b
        he2->next = he2b;//he2b
        he2->vert = v;//v
    }
}

void Mesh::extrudeFace(Face *f, glm::vec3 offset)
{
    HalfEdge *startEdge = f->halfEdge;
    HalfEdge *currentEdge = startEdge;
    HalfEdge *lastSym = nullptr;
    Vertex *lastV = nullptr;

    do{
        HalfEdge *he1 = currentEdge;
        HalfEdge *he2 = currentEdge->sym;

        Vertex *v1 = he1->vert;
        Vertex *v2 = he2->vert;

        Vertex *v3 = new Vertex(v1->position+offset);
        vVector.push_back(v3);
        Vertex *v4 = lastV;

        he1->vert = v3;

        HalfEdge *he1b = new HalfEdge(v4);
        hVector.push_back(he1b);
        HalfEdge *he2b = new HalfEdge(v1);
        hVector.push_back(he2b);

        v2->halfEdge = he2b;//this is important
        v3->halfEdge = he1b;//this is important

        he1->sym = he1b;
        he1b->sym = he1;

        he2->sym = he2b;
        he2b->sym = he2;

        HalfEdge *he3 = new HalfEdge(v3);
        hVector.push_back(he3);
        HalfEdge *he4 = new HalfEdge(v2);
        hVector.push_back(he4);

        Face *f1 = new Face(he1b,f->col);
        fVector.push_back(f1);

        he1b->face = f1;
        he2b->face = f1;
        he3->face = f1;
        he4->face = f1;

        he1b->next = he4;
        he4->next = he2b;
        he2b->next = he3;
        he3->next = he1b;

        he4->sym = lastSym;
        if(lastSym!=nullptr)
        {
            lastSym->sym = he4;
        }
        lastSym = he3;
        lastV = v3;

        currentEdge = currentEdge->next;
    }while(currentEdge!=startEdge);

    //set lastSym and lastV for the first face
    //lastSym
    startEdge->sym->next->sym = lastSym;
    lastSym->sym = startEdge->sym->next;
    //lastV
    startEdge->sym->vert = lastV;

    create();
}

void Mesh::bevelEdge(HalfEdge *h)
{
    //need to check if there are only 3 edge come out of both ends
    HalfEdge *h1 = h;
    HalfEdge *h2 = h->sym;
    Vertex* v1 = h1->vert;
    Vertex* v2 = h2->vert;

    HalfEdge* test1 = v1->halfEdge;
    if(test1->vert==v1) test1 = test1->sym;
    HalfEdge* test2 = v2->halfEdge;
    if(test2->vert==v2) test2 = test2->sym;

    HalfEdge* test1_cur = test1->sym->next;
    int count1 = 1;
    while(test1_cur!=test1)
    {
        count1++;
        test1_cur = test1_cur->sym->next;
    }
    if(count1!=3) return;

    HalfEdge* test2_cur = test2->sym->next;
    int count2 = 1;
    while(test2_cur!=test2)
    {
        count2++;
        test2_cur = test2_cur->sym->next;
    }
    if(count2!=3) return;

    HalfEdge* h1Next = h1->next;
    HalfEdge* h2Next = h2->next;
    HalfEdge* h1Last = h1;
    HalfEdge* h2Last = h2;
    while(h1Last->next!=h1) h1Last=h1Last->next;
    while(h2Last->next!=h2) h2Last=h2Last->next;
    Vertex* v3 = h1Next->vert;
    Vertex* v4 = h2Next->vert;
    Vertex* v5 = h1Last->sym->vert;
    Vertex* v6 = h2Last->sym->vert;
    glm::vec3 v1p = v1->position + (v3->position-v1->position)*0.25f;
    glm::vec3 v2p = v2->position + (v4->position-v2->position)*0.25f;
    Vertex* v1b = new Vertex(glm::vec3(v1->position + (v6->position-v1->position)*0.25f));
    Vertex* v2b = new Vertex(glm::vec3(v2->position + (v5->position-v2->position)*0.25f));
    v1->position = v1p;
    v2->position = v2p;
    HalfEdge* h1b = new HalfEdge(v2b);
    HalfEdge* h2b = new HalfEdge(v1b);
    HalfEdge* h3 = new HalfEdge(v2);
    HalfEdge* h4 = new HalfEdge(v1);
    HalfEdge* h5 = new HalfEdge(v2b);
    HalfEdge* h6 = new HalfEdge(v1b);
    Face* f = new Face(h1b,h1->face->col);
    v1b->halfEdge = h4;
    v2b->halfEdge = h3;
    h1b->next = h3;
    h1b->sym = h1;
    h1b->face = f;
    h2b->next = h4;
    h2b->sym = h2;
    h2b->face = f;
    h3->next = h2b;
    h3->sym = h5;
    h3->face = f;
    h4->next = h1b;
    h4->sym = h6;
    h4->face = f;
    h5->next = h1Last->sym;
    h5->sym = h3;
    h5->face = h1Last->sym->face;
    h6->next = h2Last->sym;
    h6->sym = h4;
    h6->face = h2Last->sym->face;
    h1->sym = h1b;
    h2->sym = h2b;
    h1Last->vert = v2b;
    h2Last->vert = v1b;
    h1Next->sym->next = h6;
    h2Next->sym->next = h5;
    v1->halfEdge = h1b;//important
    v2->halfEdge = h2b;//important
    vVector.push_back(v1b);
    vVector.push_back(v2b);
    hVector.push_back(h1b);
    hVector.push_back(h2b);
    hVector.push_back(h3);
    hVector.push_back(h4);
    hVector.push_back(h5);
    hVector.push_back(h6);
    fVector.push_back(f);

    create();
}

void Mesh::parseFile(QFile* file)
{
    freeMemory();
    QTextStream in(file);
    std::srand(std::time(0));

    while (!in.atEnd()) {
        QString line = in.readLine();
        std::string str = line.toStdString();

        if (str.substr(0, 2) == "v ")
        {
            std::stringstream ss;
            ss << str.substr(2);
            glm::vec3 v;
            ss >> v.x;
            ss >> v.y;
            ss >> v.z;
            Vertex* V = new Vertex(v);
            V->halfEdge = nullptr;//explicitly set to nullptr to remind me setting it later even not necessary
            vVector.push_back(V);
        }
        else if (str.substr(0, 3) == "vt ")
        {
            //texture coord
        }
        else if (str.substr(0, 3) == "vn ")
        {
            //normal coord
        }
        else if (str.substr(0, 2) == "f ")
        {
            std::stringstream ss;
            ss << str.substr(2);

            //Parsing
            parseObjFace(ss);
        }
        else if (str[0] == '#')
        {
            //comment
        }
        else
        {
            //others
        }

    }

    setSyms();
    create();
}

void Mesh::parseObjFace(std::stringstream &ss)
{
    char discard;
    char peek;
    int data;
    std::stack<int> indexStack;

    //One vertex in one loop
    do
    {
        ss >> peek;
        if (peek >= '0' && peek <= '9')
        {
            ss.putback(peek);
            ss >> data;
            indexStack.push(--data);
            ss >> discard;
        }
        else
        {
            //no position coord
        }

        ss >> peek;
        if (peek >= '0' && peek <= '9')
        {
            ss.putback(peek);
            ss >> data;
            //texture coord
            ss >> discard;
        }
        else
        {
            //no texture coord
        }

        ss >> peek;
        if (peek >= '0' && peek <= '9')
        {
            ss.putback(peek);
            ss >> data;
            //normal coord
            //no discard here because it is the end for this vertex
        }
        else
        {
            //no normal coord
        }
    } while (!ss.eof());

    HalfEdge* lastH = nullptr;
    Face* f = new Face();
    int count = indexStack.size();
    while(!indexStack.empty())
    {
        int index = indexStack.top();
        indexStack.pop();

        Vertex* v1 = vVector.at(index);
        HalfEdge* h1 = new HalfEdge(v1);
        h1->next = lastH;
        h1->face = f;
        h1->sym = nullptr;//explicitly set to nullptr to remind me setting it later even not necessary

        hVector.push_back(h1);

        if(v1->halfEdge==nullptr)
            v1->halfEdge = lastH;//always keep vertex's halfedge pointing out of the vertex, which is not necessary but good habit

        lastH = h1;
    }
    f->halfEdge = lastH;
    f->col = glm::vec3((float)std::rand()/RAND_MAX, (float)std::rand()/RAND_MAX, (float)std::rand()/RAND_MAX);
    fVector.push_back(f);
    HalfEdge* firstH = hVector.at(hVector.size()-count);
    firstH->next = lastH;
    if(firstH->vert->halfEdge==nullptr)
        firstH->vert->halfEdge=lastH;//always keep vertex's halfedge pointing out of the vertex, which is not necessary but good habit
}

void Mesh::setSyms()
{
    for(int i = 0;i<fVector.size();i++)
    {
        for(int j = i+1;j<fVector.size();j++)
        {
            Face* f1 = fVector.at(i);
            Face* f2 = fVector.at(j);

            HalfEdge* f1_LastE = f1->halfEdge;
            HalfEdge* f2_LastE = f2->halfEdge;

            HalfEdge* f1_StartE = f1->halfEdge->next;
            HalfEdge* f2_StartE = f2->halfEdge->next;

            HalfEdge* f1_CurrentE = f1_StartE;
            HalfEdge* f2_CurrentE = f2_StartE;

            do
            {
                do
                {

                    if(f1_CurrentE->vert == f2_LastE->vert && f1_LastE->vert == f2_CurrentE->vert)
                    {
                        f1_CurrentE->sym = f2_CurrentE;
                        f2_CurrentE->sym = f1_CurrentE;
                    }

                    f2_CurrentE = f2_CurrentE->next;
                    f2_LastE = f2_LastE->next;
                }while(f2_CurrentE!=f2_StartE);
                f1_CurrentE = f1_CurrentE->next;
                f1_LastE = f1_LastE->next;
            }while(f1_CurrentE!=f1_StartE);
        }
    }
}
