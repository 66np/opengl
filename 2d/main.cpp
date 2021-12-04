#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include "shapes.hpp"
#include "text.hpp"

void render(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    // Ensures that objects rendered last overlap on top
    glDepthFunc(GL_ALWAYS);
    glEnable(GL_DEPTH_TEST);
    
    glEnable(GL_COLOR_MATERIAL);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);
    
    circle({0.6f, 0.7f, 0.3f, 0.4f}, 300, {-0.5f, 0.5f}, 0.3f);
    triangle({1.0f, 0.3f, 0.5f, 0.3f}, {0.7f, 0.0f});
    triangle({0.2f, 0.4f, 0.6f, 1.0f}, {-0.4f, 0.0f});
    
    const unsigned char* t = reinterpret_cast<const unsigned char*>("trying out new shapes");
    text({0.5f, 0.1f, 0.6f, 1.0f}, {-0.3, -0.8f}, GLUT_BITMAP_HELVETICA_18, t);
    
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2d graphics");
    glutDisplayFunc(render);
    glutMainLoop();
    return 0;
}

