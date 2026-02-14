#ifndef VISITEURFORME_H
#define VISITEURFORME_H

class Segment;
class Cercle;
class Triangle;
class Polygone;
class Groupe;

class VisiteurForme
{
public:
    virtual ~VisiteurForme() {}

    virtual void visit(Segment &s) = 0;
    virtual void visit(Cercle &c) = 0;
    virtual void visit(Triangle &t) = 0;
    virtual void visit(Polygone &p) = 0;
    virtual void visit(Groupe &g) = 0;
};

#endif
