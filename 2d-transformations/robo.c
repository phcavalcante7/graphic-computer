// Uma flor cujas pétalas giram ao redor de seu miolo.

#include <glut.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#define PI 3.141592654

float theta = 0.0;
float theta1 = 0.0;
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

void torax()
{
    glBegin(GL_POLYGON);
        glVertex2f(-0.3, 0.33);
        glVertex2f(0.3, 0.33);
        glVertex2f(0.3, -0.5);
        glVertex2f(-0.3, -0.5);
    glEnd();
}

void cabeca()
{
    glBegin(GL_POLYGON);
        glVertex2f(-0.15, 0.6);
        glVertex2f(0.15, 0.6);
        glVertex2f(0.15, 0.33);
        glVertex2f(-0.15, 0.33);
    glEnd();
    glColor3f(0.0, 0.0, 1.0);
    glPointSize(5);
    glBegin(GL_POINTS);
        glVertex2d(-0.08, 0.52);
        glVertex2d(0.08, 0.52);
    glEnd();
    glBegin(GL_POLYGON);
        glVertex2d(-0.08, 0.43);
        glVertex2d(0.08, 0.43);
        glVertex2d(0.08, 0.39);
        glVertex2d(-0.08, 0.39);
    glEnd();
    glLineWidth(5.0);
    glColor3f(1.0, 1.0, 1.0);
    glBegin(GL_LINES);
        glVertex2d(-0.08, 0.6);
        glVertex2d(-0.13, 0.68);
        glVertex2d(-0.13, 0.68);
        glVertex2d(-0.09, 0.74);

        glVertex2d(0.08, 0.6);
        glVertex2d(0.12, 0.66);
        glVertex2d(0.12, 0.66);
        glVertex2d(0.05, 0.68);
        glVertex2d(0.05, 0.68);
        glVertex2d(0.1, 0.75);
    glEnd();
}

void braco1(float x, float y)
{
    glBegin(GL_POLYGON);
        glVertex2f(x * 0.3, 0.33);
        glVertex2f(x * 0.44, 0.2);
        glVertex2f(x * 0.44, -0.33);
        glVertex2f(x * 0.3, -0.33);
    glEnd();
}

void perna(float x, float y)
{
    glBegin(GL_POLYGON);
        glVertex2f(x * 0.2, -0.5);
        glVertex2f(x * 0.06, -0.5);
        glVertex2f(x * 0.06, -0.92);
        glVertex2f(x * 0.2, -0.92);
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
    glTranslatef(0.3, 0.33, 0.0);
    glRotatef(-theta, 0.0, 0.0, 1.0);
    glTranslatef(-0.3, -0.33, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    braco1(1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.3, 0.33, 0.0);
    glRotatef(theta, 0.0, 0.0, 1.0);
    glTranslatef(0.3, -0.33, 0.0);
    glColor3f(0.9, 0.9, 0.9);
    braco1(-1, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(-0.15, -0.92, 0.0);
    glRotatef(-theta1, 0.0, 0.0, 1.0);
    glTranslatef(0.15, 0.92, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    circulo(-0.15, -0.92);
    glPopMatrix();

    glPushMatrix();
    glTranslatef(0.15, -0.92, 0.0);
    glRotatef(-theta1, 0.0, 0.0, 1.0);
    glTranslatef(-0.15, 0.92, 0.0);
    glColor3f(1.0, 1.0, 1.0);
    circulo(0.15, -0.92);
    glPopMatrix();

    cabeca();
    glColor3f(1.0, 1.0, 1.0);
    perna(-1, 1);
    perna(1, 1);
    torax();
    glFlush();
}

void tecladoEspecial(int tecla, int x, int y)
{
    switch (tecla)
    {
    case GLUT_KEY_RIGHT:
        right += 0.05;
        theta1 += 5;
        break;
    case GLUT_KEY_LEFT:
        right -= 0.05;
        theta1 -= 5;
        break;
    case GLUT_KEY_UP:
        if (theta >= -110)
        {
            theta -= 5;
        }
        break;
    case GLUT_KEY_DOWN:
        if (theta < 0)
        {
            theta += 5;
        }
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
    glutSpecialFunc(tecladoEspecial);
    glutMainLoop();
    return 0;
}