#include "lumiere.h"

Lumiere::Lumiere(){

}

void Lumiere::setPosition(GLfloat *p){
    qDebug("fucl");
    position = p;
    qDebug("fuck");
}

GLfloat* Lumiere::getPosition(){
    return position;
}
