#include <iostream>
#include <GL/glut.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

void render(void)
{

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glDepthFunc(GL_ALWAYS);
    glEnable(GL_DEPTH_TEST);
    
    glEnable(GL_COLOR_MATERIAL);

    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    
    
    // Takes in x, y, z arguments
    glTranslatef(-0.3, 0.5, 0.0);
    glScalef(0.5, 0.5, 1.1);
    glRotatef(45.0, 1.0, 1.0, 0.0);
    
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

void reshape(int w, int h)
{
    if(h == 0)
    	h = 1;
    
    float ratio = 1.0*w/h;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, ratio, 1000.0f, 1000.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    render();
    
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2d frag shader");
    glutDisplayFunc(render);
    glutReshapeFunc(reshape);
    
    glutMainLoop();
    return 0;
}
