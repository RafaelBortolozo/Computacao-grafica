#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898
#define window_height 500 
#define window_width 700 

void display(void);
void tela(GLsizei w, GLsizei h);

int main(int argc, char** argv)
{
	glutInit(&argc, argv); 
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 

	glutInitWindowSize(window_width, window_height);
	glutInitWindowPosition(100, 100); 
	glutCreateWindow("Rafael - circulo, push, pop");

	glutReshapeFunc(tela);
	glutDisplayFunc(display);
	glutMainLoop(); 

	return(0);
}

void desenhar() {
	GLfloat circ_pnt = 100;
	GLfloat ang, raioX = 50.0f, raioY = 80.0f;
	GLfloat ballX = 80, ballY = 80;

	glPushMatrix();

	//Sorvete 1
		glTranslatef(-150, 90, 0);
		glColor3f(0.3, 0.1, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < circ_pnt; i++) {
			ang = (2 * PI * i) / circ_pnt;
			glVertex2f(cos(ang) * ballX, sin(ang) * ballY);
		}
		glEnd();

		glTranslatef(0, -90, 0);
		glColor3f(1.0, 0.5, 1.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < circ_pnt; i++) {
			ang = (2 * PI * i) / circ_pnt;
			glVertex2f(cos(ang) * ballX, sin(ang) * ballY);
		}
		glEnd();

		glTranslatef(2, -225, 0);
		glColor3f(0.8, 0.5, 0.3);
		glBegin(GL_TRIANGLES);
			glVertex2f(0, 10);
			glVertex2f(-59, 170);
			glVertex2f(55, 170);
		glEnd();

	glPopMatrix();

	glPushMatrix();
	
	//Sorvete 2
		glTranslatef(20, 90, 0);
		glColor3f(0.7, 1.0, 1.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < circ_pnt; i++) {
			ang = (2 * PI * i) / circ_pnt;
			glVertex2f(cos(ang) * ballX, sin(ang) * ballY);
		}
		glEnd();

		glTranslatef(0, -90, 0);
		glColor3f(0.9, 0.9, 0.0);
		glBegin(GL_POLYGON);
		for (int i = 0; i < circ_pnt; i++) {
			ang = (2 * PI * i) / circ_pnt;
			glVertex2f(cos(ang) * ballX, sin(ang) * ballY);
		}
		glEnd();

		glTranslatef(2, -225, 0);
		glColor3f(0.8, 0.5, 0.3);
		glBegin(GL_TRIANGLES);
		glVertex2f(0, 10);
		glVertex2f(-59, 170);
		glVertex2f(55, 170);
		glEnd();

	glPopMatrix();
	glPushMatrix();

	//Ovo de pascoa 
		glTranslatef(190, -50, 0);
		glColor3f(1, 0.321, 0.341);
		glBegin(GL_POLYGON);
		for (int i = 0; i < circ_pnt; i++) {
			ang = (2 * PI * i) / circ_pnt;
			glVertex2f((cos(ang) * (raioX)), (sin(ang) * (raioY)));
		}
		glEnd();

		glTranslatef(0, 75, 0);
		glColor3f(1, 0.658, 0.239);
		glBegin(GL_POLYGON);
			glVertex2f(0, 0); 
			glVertex2f(-70, 98); 
			glVertex2f(-40, 91); 
			glVertex2f(-28, 107); 
			glVertex2f(-13, 106); 
			glVertex2f(-2, 91); 
			glVertex2f(6, 108); 
			glVertex2f(21, 90); 
			glVertex2f(28, 108); 
			glVertex2f(43, 107); 
			glVertex2f(48, 90); 
			glVertex2f(70, 93); 
		glEnd();

	glPopMatrix();

}

void display()
{
	glMatrixMode(GL_MODELVIEW); 
	glLoadIdentity();

	glClearColor(0.8, 0.9, 1.0, 1.0); 
	glClear(GL_COLOR_BUFFER_BIT); 

	glTranslatef(window_width / 2, window_height / 2, 0);

	glViewport(0, 0, window_width, window_height);
	desenhar();

	glFlush(); 
}

void tela(GLsizei w, GLsizei h)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, window_width, 0, window_height);

	glMatrixMode(GL_MODELVIEW);
}