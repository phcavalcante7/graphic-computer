//  Um carro que se movimenta para frente e para trás e suas rodas acompanham o movimento de forma coerente ao movimento do carro.                               

#include <glut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.141592654

float theta = 0.0;
float right = 0.0;

void circulo(float x, float y)
{
    glTranslatef(x, y, 0.0);

    int i;

    float angle = 0.0;
    glBegin(GL_POLYGON);
        for (i = 0; i <= 15; i++)
        {
            angle = 2 * PI * i / 10.0;
            glVertex2f((0.125 * cos(angle)), (0.125 * sin(angle)));
        }
    glEnd();
}

void carro()
{
    glBegin(GL_POLYGON);
        glVertex2f(-0.6, 0.4);
        glVertex2f(-0.43, 0.4);
        glVertex2f(-0.34, 0.55);
        glVertex2f(0.07, 0.55);
        glVertex2f(0.23, 0.39);
        glVertex2f(0.44, 0.39);
        glVertex2f(0.6, 0.29);
        glVertex2f(0.6, 0.12);
        glVertex2f(-0.6, 0.12);
    glEnd();
}

void desenha()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0, 0, 0, 0); // Preto
    glClear(GL_COLOR_BUFFER_BIT);

    glTranslatef(right, 0.0, 0.0);

    glPushMatrix();
    glColor3f(0.0, 0.0, 1.0);
    glTranslatef(0.0, 0.0, 0.0);
    carro();
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.4, 0.2, 0.0);
    glRotatef(-theta, 0.0, 0.0, 1.0);
    glTranslatef(0.4, -0.2, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    circulo(-0.4, 0.2);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.4, 0.2, 0.0);
    glRotatef(-theta, 0.0, 0.0, 1.0);
    glTranslatef(-0.4, -0.2, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    circulo(0.4, 0.2);
    glPopMatrix();

    glFlush();
}

void teclado(int tecla, int x, int y)
{
    switch (tecla)
    {
    case GLUT_KEY_RIGHT:
        right += 0.05;
        theta += 5;
        break;
    case GLUT_KEY_LEFT:
        right -= 0.05;
        theta -= 5;
        break;
    default:
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Carro.c");
    glutDisplayFunc(desenha);
    glutSpecialFunc(teclado);
    glutMainLoop();
    return 0;
}