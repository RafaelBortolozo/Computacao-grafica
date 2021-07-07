#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h> 
#define janela_altura 400
#define janela_largura 400
float transVertical = 1;
float transHorizontal = 1;

void keyboard(unsigned char key, int x, int y);
void resize(GLsizei w, GLsizei y);
void display(void);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(janela_altura, janela_largura);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("GLUT Test RAFAEL BORTOLOZO---- exercicio de glut");
	glutKeyboardFunc(&keyboard);
	glutReshapeFunc(&resize);
	glutDisplayFunc(display);
	glutMainLoop();
	return EXIT_SUCCESS;
}

void keyboard(unsigned char key, int x, int y) {
	if (key == '8') {
		transVertical += 4; //cima
	}if (key == '2') {
		transVertical -= 4; //baixo
	}if (key == '4') {
		transHorizontal -= 4; //esquerda
	}if (key == '6') {
		transHorizontal += 4; //direita
	}
	
	glutPostRedisplay();
}

void desenhar() {
	glBegin(GL_QUADS);
		glColor3f(1.0, 0.0, 0.0);
		glVertex2f(-30, -30);
		glVertex2f(-30, 30);
		glVertex2f(30, 30);
		glVertex2f(30, -30);
	glEnd();

	glTranslatef(transHorizontal, transVertical, 0);

	glBegin(GL_QUADS);
		glColor3f(0.0, 0.0, 1.0);
		glVertex2f(-20, 80);
		glVertex2f(-20, 100);
		glVertex2f(0, 100);
		glVertex2f(0, 80);
	glEnd();

	glTranslatef(1, 1, 0);
}

void resize(GLsizei w, GLsizei h) {
	if (h == 0) h = 1;

	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (w <= h) {
		gluOrtho2D(0.0f, janela_altura, 0.0f, janela_largura * h / w);
	}
	else {
		gluOrtho2D(0.0f, janela_altura * w / h, 0.0f, janela_largura);
	}
	glMatrixMode(GL_MODELVIEW);
}

void display() {
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.8f, 0.8f, 0.8f, 0.5f);
	glClear(GL_COLOR_BUFFER_BIT);
	
	// Centralizar o plano cartesiano 
	glTranslatef(janela_altura / 2, janela_largura / 2, 0);
	glViewport(0, 0, janela_largura, janela_altura);
	desenhar();

	glFlush(); //executa o desenho 
}

