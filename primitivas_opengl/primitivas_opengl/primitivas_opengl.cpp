#include <stdlib.h>
#include <GL/glut.h> 

void keyboard(unsigned char key, int x, int y);
void resize(GLsizei w, GLsizei y);
void display(void);

int main(int argc, char** argv) {
	glutInit(&argc, argv); // parametros que dizem se o sistema operacional tem interface gráfica
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // Defini a forma que o desenho vai ser mostrado (pode ser double) + a forma que eu vou representar as cores
	glutInitWindowSize(600, 600); //Cria uma janela 600 por 600
	glutInitWindowPosition(10, 300); // posição que a janela vai iniciar 
	glutCreateWindow("GLUT Test RAFAEL---- exercicio de glut");
	glutKeyboardFunc(&keyboard); // Passando a referência da função keyboard para a função do glut
	glutReshapeFunc(&resize); //
	glutDisplayFunc(display);
	glutMainLoop();// Toda vez que eu mudar a janela de lugar ele muda o desenho de acordo com isso
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
	if (h == 0) h = 1; // Evita divisão por 0

	glViewport(0, 0, w, h); // Tamanho que eu quero a camêra

	// Inicia o sistema de coordenadas
	// Configurando coisas de câmera, pois estamos mexendo na matriz e vizualização
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity(); // limpa a memória

	if (w <= h) {
		gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f * h / w);
	}
	else {
		gluOrtho2D(0.0f, 250.0f * w / h, 0.0f, 250.0f);
	}
	glMatrixMode(GL_MODELVIEW);
}

void display() {
	// Matriz de vizualização: Onde eu quero que fique a camera  
	glMatrixMode(GL_MODELVIEW); glLoadIdentity(); // Gere uma matrix mode com esse parâmetro. EU QUERO QUE VOCÊ DESENHE
	glLoadIdentity(); // Limpar toda a matriz
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Use como a cor de limpeza, essa ai.
	glClear(GL_COLOR_BUFFER_BIT);// Limpa tela coma cor que setei 

	glBegin(GL_LINE_STRIP); // Inicie um quadrado
		glColor3f(0.0f, 0.0f, 0.0f);// cor de pintura

		glVertex2f(100, 150); // Vertice 1 
		glVertex2f(150, 150);  // Vertice 2
		glVertex2f(150, 100);// Vertice 3
		glVertex2f(100, 75);
		glVertex2f(75, 100);// Vertice 3
		glVertex2f(100, 150);
		
		

	glEnd();

	glFlush(); // executa o desenho 

}