#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "shapes.hpp"

void render(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    
    glDepthFunc(GL_ALWAYS);
    glEnable(GL_DEPTH_TEST);
    
    glEnable(GL_COLOR_MATERIAL);



    glutSwapBuffers();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("3d graphics");
    glutDisplayFunc(render);
    glutMainLoop();
    return 0;
}
