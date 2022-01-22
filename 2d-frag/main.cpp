#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void render(void)
{

    glClear(GL_COLOR_BUFFER_BIT);
    
    glDepthFunc(GL_ALWAYS);
    glEnable(GL_DEPTH_TEST);
    
    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    glBegin(GL_TRIANGLES);
    	glColor3f(1, 0, 0);
    	glVertex2f(-0.7, -0.7);
    	glColor3f(0, 1, 0);
    	glVertex2f(0.7, -0.7);
    	glColor3f(0, 0, 1);
    	glVertex2f(0.0, 0.7);
    glEnd();

    glutSwapBuffers();

}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2d frag shader");
    glutDisplayFunc(render);
    glutMainLoop();
    return 0;
}
