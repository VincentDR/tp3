#include "particules.h"

Particules::Particules(){

}

Particules::Particules(QImage *q){
    image = q;
    width = q->width();
    height = q->height();

    particuleSize = 1;
    particuleColor = (GLfloat*) malloc(sizeof(GLfloat) * 3);
    particuleColor[0] = 0.8f;
    particuleColor[1] = 0.8f;
    particuleColor[2] = 0.8f;
}

void Particules::setParticuleSize(int i){
    particuleSize = i;
}

void Particules::setParticuleColor(GLfloat* f){
    particuleColor = (GLfloat*) malloc(sizeof(GLfloat) * 3);
    particuleColor[0] = f[0];
    particuleColor[1] = f[1];
    particuleColor[2] = f[2];
}


void  Particules::init(GLfloat taux, GLfloat vitesseMin, GLfloat vitesseMax){
    nbParticules = width * height * taux;
    points = (Point**)malloc(sizeof(Point*) * nbParticules);


    for(int i = 0; i < nbParticules ; i++){
        points[i] = (Point*)malloc(sizeof(Point) * 1);
        float x = (float) ((qrand() % (int)width) - width * 0.5) / width;
        float y = (float) ((qrand() % (int)height) - height * 0.5) / height;
        float z = (qrand() % 100) * 0.02f;
        float v = (float) ((qrand() % (int)vitesseMax) + vitesseMin) / 100000.0f;//trop rapide sinon
        points[i] = new Point(x,y,z,v);
        //qDebug()<<i<<" "<<x<<" "<<y<<" "<<z<<" "<<v<<endl;

    }
   // qDebug("Fin de l'init");
}

void Particules::update(){

    for(int i = 0; i < nbParticules; i++){
        points[i]->setZ(points[i]->getZ() - points[i]->getSpeed());

        //tester si on est sous le Z de la map
        int x = points[i]->getX() * image->width() + image->width() * 0.5;
        int y = points[i]->getY() * image->width() + image->width() * 0.5;
        float value = image->pixel(x, y);
        if(value > points[i]->getZ()) {
            float xB = (float) ((qrand() % (int)width) - width * 0.5) / width;
            float yB = (float) ((qrand() % (int)height) - height * 0.5) / height;
            float zB = (qrand() % 100) * 0.02f;
            float vB = points[i]->getSpeed();
            points[i] = new Point(xB,yB,zB,vB);
        }
/* Simuler le vent, résultat bof
        int alea = qrand()%5;
        switch(alea){
        case 0:
            points[i]->setX(points[i]->getX() + points[i]->getSpeed());
            if(points[i]->getX() > height){
                points[i]->setX(height - 1);
            }
            break;
        case 1:
            points[i]->setX(points[i]->getX() - points[i]->getSpeed());
            if(points[i]->getX() < 0){
                points[i]->setX(0);
            }
            break;
        case 2:
            points[i]->setY(points[i]->getY() + points[i]->getSpeed());
            if(points[i]->getY() > width){
                points[i]->setY(width - 1);
            }
            break;
        case 3:
            points[i]->setY(points[i]->getY() - points[i]->getSpeed());
            if(points[i]->getY() < 0){
                points[i]->setY(0);
            }
            break;
        }*/
    }


    glPointSize(particuleSize);
    glBegin(GL_POINTS);
    glColor3f(particuleColor[0], particuleColor[1], particuleColor[2]);
    for(int i = 0; i < nbParticules; i++){
        glVertex3f(points[i]->getX(), points[i]->getY(), points[i]->getZ());
    }

    glEnd();
 }
