// Rafael Bortolozo
#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898
#define janela_altura 400
#define janela_largura 600

float transX = 120;
float transY = -100;
float hipotenusa;

void display(void);
void tela(GLsizei w, GLsizei h);
void keyboard(unsigned char tecla, int x, int y);
float verificarColisao();

int main(int argc, char** argv)
{
	glutInit(&argc, argv);	// suporte a janelas

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	// PADRAO DE CORES

	glutInitWindowSize(janela_largura, janela_altura);  // tamanho da janela
	glutInitWindowPosition(100, 100); // posicao que surge a janela
	glutCreateWindow("Rafael - Colisao em circulos"); // cria janela

	//glutFullScreen();
	glutKeyboardFunc(&keyboard);  // chama teclado
	glutReshapeFunc(tela);  // configura a tela
	glutDisplayFunc(display);
	glutMainLoop(); // redesenhar

	return(0);
}

void keyboard(unsigned char tecla, int x, int y)
{
	//controles: 5123 (mesmo formato do wasd)
	if (tecla == '5') {
		transY = transY + 5;
		printf("\n o valor de translacao e %.2f\n", transY);
	}
	if (tecla == '1'){ 
		transX = transX - 5;
		printf("\n o valor de translacao e %.2f\n", transX);
	}
	if (tecla == '2') {
		transY = transY - 5;
		printf("\n o valor de translacao e %.2f\n", transY);
	}
	if (tecla == '3'){
		transX = transX + 5;
		printf("\n o valor de translacao e %.2f\n", transX);
	}
	glutPostRedisplay();
}

void desenhar()
{
	GLfloat pontos_circulo = 100;
	GLfloat angulo;
	GLfloat raioX = 50, raioY = 50;

	glColor3f(1, 0, 0);
	glTranslatef(0, 0, 0);

	glBegin(GL_POLYGON);
	for (int i = 0; i < pontos_circulo; i++) {
		angulo = (2 * PI * i) / pontos_circulo;
		glVertex2f(cos(angulo) * raioX, sin(angulo) * raioY);
		printf("%f %f\n", cos(angulo) * raioX, sin(angulo) * raioY);
	}
	glEnd();

	glTranslatef(transX, transY, 0);

	glColor3f(0, 0, 1);
	glBegin(GL_POLYGON);
	for (int i = 0; i < pontos_circulo; i++) {
		angulo = (2 * PI * i) / pontos_circulo;
		glVertex2f(cos(angulo) * raioX, sin(angulo) * raioY);
		printf("%f %f\n", cos(angulo) * raioX, sin(angulo) * raioY);
	}
	glEnd();
}

void display(){
	glMatrixMode(GL_MODELVIEW);  //coordenadas de desenho
	glLoadIdentity();

	float distancia = verificarColisao();
	if (distancia <= 100){
		glClearColor(0.0f, 1.0f, 0.0f, 1.0f); // cor do fundo
	}else{
		glClearColor(0.9f, 0.9f, 0.9f, 0.9f); // cor do fundo
	}

	glClear(GL_COLOR_BUFFER_BIT); // EXECUTA LIMPEZA

	// Especificar o local aonde o desenho acontece: bem no centro da janela
	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);

	glViewport(0, 0, janela_largura, janela_altura);
	desenhar();

	glFlush();// execute o desenho
}

void tela(GLsizei w, GLsizei h){
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// cria a janela (esq, direita, embaixo, em cima)
	gluOrtho2D(0, janela_largura, 0, janela_altura);

	glMatrixMode(GL_MODELVIEW);
}

float verificarColisao() {
	hipotenusa = sqrt((transX * transX) + (transY * transY));
	return hipotenusa;
}