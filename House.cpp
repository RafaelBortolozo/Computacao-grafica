#include <stdlib.h>
#include <GL/glut.h> 
#define janela_altura 400
#define janela_largura 400

void keyboard(unsigned char key, int x, int y);
void resize(GLsizei w, GLsizei y);
void display(void);

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(janela_altura, janela_largura);
	glutInitWindowPosition(10, 300);
	glutCreateWindow("GLUT Test RAFAEL BORTOLOZO---- exercicio de glut");
	glutKeyboardFunc(&keyboard);
	glutReshapeFunc(&resize);
	glutDisplayFunc(display);
	glutMainLoop();
	return EXIT_SUCCESS;
}

void keyboard(unsigned char key, int x, int y) {
	switch (key)
	{
	case '\x1B':
		exit(EXIT_SUCCESS);
		break;
	}
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
	glMatrixMode(GL_MODELVIEW); glLoadIdentity();
	glLoadIdentity();
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	// Centralizar o plano cartesiano 
	glTranslatef(janela_altura / 2, janela_largura / 2, 0);

	//fundo
	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);

	glVertex2f(-200, -200);
	glVertex2f(-200, 200);
	glVertex2f(200, 200);
	glVertex2f(200, -200);
	glEnd();

	//grama
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);

	glVertex2f(-200, -200);
	glVertex2f(-200, -100);
	glVertex2f(200, -100);
	glVertex2f(200, -200);
	glEnd();

	//parede da casa
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);

	glVertex2f(-110, -100);
	glVertex2f(-110, 100);
	glVertex2f(110, 100);
	glVertex2f(110, -100);
	glEnd();

	//telhado
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f);

	glVertex2f(-110, 100);
	glVertex2f(0, 140);
	glVertex2f(110, 100);
	glEnd();

	//porta
	glBegin(GL_QUADS);
	glColor3f(0.87f, 0.765f, 0.34f);

	glVertex2f(-110, -100);
	glVertex2f(-110, -25);
	glVertex2f(-50, -25);
	glVertex2f(-50, -100);
	glEnd();

	//macaneta da porta
	glPointSize(12.0f);
	glEnable(GL_POINT_SMOOTH);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0);
	glVertex2f(-100.0f, -75.0f);
	glEnd();

	//janela
	glBegin(GL_LINE_LOOP);
	glColor3f(0, 0, 1);
	glVertex2f(0, 0);
	glColor3f(0, 0, 1);
	glVertex2f(0, 50);
	glColor3f(1, 1, 1);
	glVertex2f(50, 50);
	glColor3f(1, 1, 1);
	glVertex2f(50, 0);
	glEnd();
	glLineWidth(3.0);

	glFlush(); //executa o desenho 
}
