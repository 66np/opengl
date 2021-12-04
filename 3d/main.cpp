#include <GL/glut.h>

void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(550, 550);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("2d graphics");
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}
