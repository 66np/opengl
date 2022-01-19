#ifndef PARAMETERS_H
#define PARAMETERS_H

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

#endif
