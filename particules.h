#ifndef PARTICULES
#define PARTICULES

#include <QtCore>

#include "openglwindow.h"
#include "point.h"
class Particules{
public:
    Particules();
    Particules(QImage*);

    //taux entre 0 et 1 pour connaitre le nombre de particules à afficher par
    //rapport aux nombres de points représentant la map
    void init(GLfloat taux, GLfloat vitesseMin, GLfloat vitesseMax);

    Point** getPoint();
    void update();

    void setParticuleSize(int);
    void setParticuleColor(GLfloat*);

private :
    Point **points; //le tableau de points
    int nbParticules; //le nombre de points/particules affichées
    QImage *image; //l'image sur laquelle tombent les particules
    GLfloat width; //tailles de l'image
    GLfloat height;

    int particuleSize; //taille des particules
    GLfloat *particuleColor; //couleur des particules
};

#endif // PARTICULES

