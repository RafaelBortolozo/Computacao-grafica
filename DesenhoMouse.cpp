#include <stdio.h>
#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#define WINDOW_HEIGHT 400
#define WINDOW_WIDTH 500

void keyboard(int key, int x, int y);
void resize(GLsizei w, GLsizei h);
void display(void);
void mouse(int button, int state, int mousex, int mousey);

float x=0, y=0, red, green, blue;

bool check = false;

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WINDOW_WIDTH, WINDOW_HEIGHT);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Rafael - desenho com o mouse");

    glutSpecialFunc(&keyboard);
    glutReshapeFunc(&resize);
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMainLoop();

    return EXIT_SUCCESS;
}

void resize(GLsizei w, GLsizei h) {
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (w <= h) {
        gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
    }
    else {
        gluOrtho2D(0.0, WINDOW_WIDTH, 0.0, WINDOW_HEIGHT);
    }
    glMatrixMode(GL_MODELVIEW);
}


void mouse(int button, int state, int mousex, int mousey)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        check = true;

        x = mousex;
        y = 400 - mousey;
    }else{
        check = false;
    }
}

void keyboard(int key, int x, int y){
    if (key == GLUT_KEY_F1) {
        red = 0;
        green = 0;
        blue = 0;
    }

    if (key == GLUT_KEY_F2){
        red = 0;
        green = 0;
        blue = 1;
    }

    if (key == GLUT_KEY_F3){
        red = 0;
        green = 1;
        blue = 0;
    }
    if (key == GLUT_KEY_F4){
        red = 1;
        green = 0;
        blue = 0;
    }
    glutPostRedisplay();
}

void display() {
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClearColor(1, 1, 1, 1);
    glClear(GL_COLOR_BUFFER_BIT);

    if (check){
        glColor3f(red, green, blue);
        glPointSize(50);
        glEnable(GL_POINT_SMOOTH);

        glBegin(GL_POINTS);
        glVertex2f(x, y);

        glEnd();
    }

    glFlush(); 
}