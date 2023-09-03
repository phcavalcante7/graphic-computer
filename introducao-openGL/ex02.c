/*
    Escreva um programa que realize duas funções: a de imprimir o ponto nas coordenadas do mouse do 
    ex01.c e de alterar a cor do ponto. Para mudar a cor, o user digitará as teclas de 0 a 9. Cada 
    tecla deve ter cores indexadas previamente escolhidas.
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

void Keyboard (unsigned char key, int x, int y)
{
    switch(key)
    {   
        case '0': 
            glColor3f(1.0, 0.0, 0.0); //setting color as red
            break;
        case '1': 
            glColor3f(0.0, 1.0, 0.0); //setting color as green
            break;  
        case '2': 
            glColor3f(0.0, 0.0, 1.0); //setting color as blue 
            break;
        case '3':
            glColor3f(1.0, 0.0, 1.0); //setting color as purple
            break;
        case '4': 
            glColor3f(1.0, 1.0, 0.0); //setting color as yellow
            break;
        case '5': 
            glColor3f(0.0, 1.0, 1.0); //setting color as teal
            break;
        case '6': 
            glColor3f(1.0, 1.0, 1.0); //setting color as white
            break;
        case '7': 
            glColor3f(0.5, 0.0, 1.0); //is half red and full blue, giving dark purple.
            break;
        case '8': 
            glColor3f(1.0, 0.5, 0.5); //i dont know the color here, tbh.
            break;
        case '9': 
            glColor3f(0.5, 1.0, 0.0); //i dont know the color here, tbh.
            break;
    }
    glutPostRedisplay();
}

int main ( int argc , char * argv [] ){
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50, 100);
    glutInitWindowSize (400, 400);
    glutCreateWindow ("Exercicio 02");
    glColor3f(0.0, 0.0, 1.0); //setting color as blue 
    glutDisplayFunc(point);
    glutMouseFunc(MouseInt);
    glutKeyboardFunc(Keyboard);
    glutMainLoop ();
    return 0;
}