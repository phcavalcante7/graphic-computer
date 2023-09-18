// Uma flor cujas pétalas giram ao redor de seu miolo.

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

void petala1(int x, int y)
{
    glBegin(GL_POLYGON);
        glVertex2f(-0.1, y * 0.05);
        glVertex2f(0.1, y * 0.05);
        glVertex2f(0, y * 0.5);
    glEnd();
}

void petala2(int x, int y)
{
    glBegin(GL_POLYGON);
        glVertex2f(0.22 * x, 0.13);
        glVertex2f(0.22 * x, -0.13);
        glVertex2f(-0.5 * x, 0);
    glEnd();
}

void petala3(int x, int y)
{
    glBegin(GL_POLYGON);
        glVertex2f(0.19 * x, 0);
        glVertex2f(0, y * 0.19);
        glVertex2f(0.44 * x, y * 0.44);
    glEnd();
}

void desenha()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glClearColor(0, 0, 0, 0); // Preto
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glRotatef(-theta, 0.0, 0.0, 1.0);
    glColor3f(1.0, 0.4, 0.0);
    petala3(1, 1);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-theta, 0.0, 0.0, 1.0);
    petala3(-1, -1);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-theta, 0.0, 0.0, 1.0);
    glColor3f(1.0, 0.4, 0.0);
    petala3(-1, 1);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-theta, 0.0, 0.0, 1.0);
    petala3(1, -1);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-theta, 0.0, 0.0, 1.0);
    glColor3f(1.0, 1.0, 0.0);
    petala1(1, 1);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-theta, 0.0, 0.0, 1.0);
    petala1(1, -1);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-theta, 0.0, 0.0, 1.0);
    petala2(1, -1);
    glPopMatrix();

    glPushMatrix();
    glRotatef(-theta, 0.0, 0.0, 1.0);
    petala2(-1, 1);
    glPopMatrix();

    glPushMatrix();
    glColor3f(1.0, 1.0, 1.0);
    glTranslatef(0.0, 0.0, 0.0);
    circulo(0.0, 0.0);
    glPopMatrix();
    glFlush();
}

void tecladoEspecial(int tecla, int x, int y)
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
    glutCreateWindow("Flor.c");
    glutDisplayFunc(desenha);
    glutSpecialFunc(tecladoEspecial);
    glutMainLoop();
    return 0;
}