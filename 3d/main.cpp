#include <GL/glut.h>

void initGL() {
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClearDepth(1.0f);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void triangularPrism(GLboolean solid) {
	glBegin(solid ? GL_TRIANGLES : GL_LINE_LOOP);
		glColor3f(1.0f, 0.0f, 0.0f);	
		glVertex3f(0.5f, 0.0f, 0.5f);
		glColor3f(0.0f, 1.0f, 0.0f);	
		glVertex3f(0.0f, 1.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);
		glVertex3f(-0.5f, 0.0f, 0.5f);
	glEnd();

	glBegin(solid ? GL_TRIANGLES : GL_LINE_LOOP);
		glColor3f(0.0f, 0.0f, 1.0f);		
		glVertex3f(-0.5f, 0.0f, 0.5f);
		glColor3f(0.0f, 1.0f, 0.0f);	
		glVertex3f(0.0f, 1.0f, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f);	
		glVertex3f(-0.5f, 0.0f, -0.5f);
	glEnd();

	glBegin(solid ? GL_TRIANGLES : GL_LINE_LOOP);
		glColor3f(1.0f, 0.0f, 0.0f);	
		glVertex3f(-0.5f, 0.0f, -0.5f);
		glColor3f(0.0f, 1.0f, 0.0f);	
		glVertex3f(0.0f, 1.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 1.0f);	
		glVertex3f(0.5f, 0.0f, -0.5f);
	glEnd();
	
	glBegin(solid ? GL_TRIANGLES : GL_LINE_LOOP);
		glColor3f(0.0f, 0.0f, 1.0f);	
		glVertex3f(0.5f, 0.0f, -0.5f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(0.0f, 1.0f, 0.0f);
		glColor3f(1.0f, 0.0f, 0.0f);
		glVertex3f(0.5f, 0.0f, 0.5f);
	glEnd();

	glBegin(solid ? GL_QUADS : GL_LINE_LOOP);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-0.5f, 0.0f, -0.5f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(0.5f, 0.0f, -0.5f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(0.5f, 0.0f, 0.5f);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex3f(-0.5f, 0.0f, 0.5f);
	glEnd();

	glutSwapBuffers(); 
}

void display(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	
	glLoadIdentity();

	glTranslatef(0.0f, -0.4f, 0.0f);
	glScalef(0.6f, 0.6f, 0.6f);
	glRotatef(45.3f, 1.3f, 1.3f, 0.0f);	

	glPushMatrix();
	    triangularPrism(true);
	glPopMatrix();
}

void reshape(GLsizei width, GLsizei height) {
	if (height == 0) height = 1;
	GLfloat aspect = (GLfloat)width / (GLfloat)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("3d graphics");
	glutDisplayFunc(display);
//	Commented out since reshape func is not rendering
//	glutReshapeFunc(reshape);
	initGL();
	glutMainLoop();
	return 0;
}
