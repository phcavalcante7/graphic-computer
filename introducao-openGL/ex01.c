/*
    Escreva um programa que imprima um ponto azul de tamanho 5.0 na posição em que houver um clique 
    de botão esquerdo do mouse. Inicialmente, o ponto deve ficar nas coordenadas (0,0).
*/

#include <glut.h>
#define POINT_SIZE 5

float x = 0.0; //first x
float y = 0.0; //first y

void point() 
{   
    glClearColor(0, 0, 0, 0); //black
    glClear(GL_COLOR_BUFFER_BIT);
    glPointSize(POINT_SIZE);
    glColor3f(0.0, 0.0, 1.0); //setting the color as blue
    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
    glFlush();
}

void MouseInt (int button, int state, int mx, int my)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { //left click
        x = (2.0 * mx) / glutGet(GLUT_WINDOW_WIDTH) - 1.0;
        y = 1.0 - (2.0 * my) / glutGet(GLUT_WINDOW_HEIGHT);
        glutPostRedisplay();
    }
}

int main ( int argc , char * argv [] ){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50, 100);
    glutInitWindowSize (400, 400);
    glutCreateWindow ("Exercicio 01");
    glutDisplayFunc(point);
    glutMouseFunc(MouseInt);
    glutMainLoop ();
    return 0;
}