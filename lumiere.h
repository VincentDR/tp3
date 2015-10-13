#ifndef LUMIERE
#define LUMIERE

#include "openglwindow.h"


class Lumiere
{
public:
    Lumiere();

    void setPosition(GLfloat*);
    GLfloat* getPosition();

private :
    GLfloat *position;
    GLfloat couleurAmbiante[4];
    GLfloat couleurDiffuse[4];
    GLfloat couleurSpeculaire[4];
    float shininess ;
    float attenuationConstante ;
    float attenuationLineaire ;
    float attenuationQuadratique ;

    GLfloat direction[3];
    float angle ;
    float exposition;
    float limite;
};

#endif // LUMIERE

