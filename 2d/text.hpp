#include <GL/glut.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "parameters.hpp"

void text(RGB rgbo, Coordinates p, void *font, const unsigned char* letters)
{
    glColor4f(rgbo.r, rgbo.g, rgbo.b, rgbo.opacity);
    glRasterPos2f(p.high, p.low);
    
    // gluStrokeString will render text in 3D space
    glutBitmapString(font, letters);
}
