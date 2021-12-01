#include <GL/glut.h>
#include <GL/freeglut.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>

struct RGB {
	GLfloat r;
	GLfloat g;
	GLfloat b;
	GLfloat opacity;
};

struct Coordinates {
	GLfloat high;
	GLfloat low;
};

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

void text(RGB rgbo, Coordinates p, void *font, const unsigned char* letters)
{
    glColor4f(rgbo.r, rgbo.g, rgbo.b, rgbo.opacity);
    glRasterPos2f(p.high, p.low);
    
    // gluStrokeString will render text in 3D space
    glutBitmapString(font, letters);
}

void draw(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    
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
    glutDisplayFunc(draw);
    glutMainLoop();
    return 0;
}

