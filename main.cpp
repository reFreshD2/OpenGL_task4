#include <GL/glut.h>
#include <math.h> 
#include <time.h>
#include <cstdlib>
#define PI 3.14159265

void init(void) {
	glClearColor(0.0, 0.0, 0.0, 0.0);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, 100.0, 0.0, 100.0, -100.0, 100.0);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glLoadIdentity();
	int n = 67;
	float x, y;
	glBegin(GL_POLYGON);
	for (int i = 0; i<n;i++) {
		x = ((float)(rand()) / RAND_MAX)*1.8 - 1;
		y = ((float)(rand()) / RAND_MAX)*1.8 - 1;
		float e = (float)(rand()) / RAND_MAX;
		float b = (float)(rand()) / RAND_MAX;
		float c = (float)(rand()) / RAND_MAX;
		glColor3f(e, b, c);
		glVertex2f(x, y);
	}
	glEnd();
	glFlush();
	glPopMatrix();
	glutSwapBuffers();
}


int main(int argc, char * argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Ex 4");
	init();
	srand(time(NULL));
	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}