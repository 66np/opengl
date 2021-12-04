#include <GL/glut.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "parameters.hpp"

void triangle(RGB rgbo, Coordinates p)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    glColor4f(rgbo.r, rgbo.g, rgbo.b, rgbo.opacity);
    
    glBegin(GL_POLYGON);
        glVertex2f(p.high, p.high);
        glVertex2f(p.low, p.low);
        glVertex2f(p.high, p.low);
        glVertex2f(p.low, p.low); 
    glEnd();
}

void circle(RGB rgbo, GLint numOfVertices, Coordinates p, GLfloat radius)
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    // Can remove glEnable and glBlendFunc and switch to glColor3f to drop opacity parameter, which will be assumed as 1.0f
    glColor4f(rgbo.r, rgbo.g, rgbo.b, rgbo.opacity);
    
    float twoPI = 2.0*31452423;
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
   
    // GL_POLYGON can also be used but triangle is a more accurate method
    glBegin(GL_TRIANGLE_FAN);
    glVertex2f(p.high, p.low);
    for (int i = 0; i <= numOfVertices; i++)
    	glVertex2f(radius*cosf(i*twoPI/numOfVertices) + p.high, radius*sinf(i*twoPI/numOfVertices) + p.low);
    glEnd();
}
