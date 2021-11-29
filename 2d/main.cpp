#include <GL/glut.h>

void triangle(float r, float g, float b, float p1, float p2)
{
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
        glVertex2f(p1, p1);
        glVertex2f(p2, p2);
        glVertex2f(p1, p2);
        glVertex2f(p1, p1); 
    glEnd();
}

void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
    triangle(1.0f, 0.3f, 0.5f, 0.7f, 0.0f);
    triangle(0.2f, 0.4f, 0.6f, -0.4f, 0.0f);
    
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2d graphics");
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}

