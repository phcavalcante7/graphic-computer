/*
    Crie um programa com duas funções: a de imprimir uma linha entre dois pontos quaisquer e a de alterar a cor da
    linha. Uma linha inicial entre os pontos (0,0) e (0,0) azul deve ser traçada. A linha muda de posição de acordo com
    as coordenadas dadas por um clique inicial e um clique final com o botão esquerdo do mouse. As cores são selecionadas 
    da mesma maneira que no ex02.c
*/

#include <glut.h>

float x = 0.0; // primeiro x
float y = 0.0; // primeiro y
float x2 = 0.0; // segundo x
float y2 = 0.0; // segundo y
int primeiroClique = 1; // flag para controlar o primeiro clique

void point()
{
    glClearColor(0, 0, 0, 0); // preto
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x2, y2);
    glEnd();
    glFlush();
}

void MouseInt(int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) { //left click
        if (primeiroClique) {
            x = (2.0 * mx) / glutGet(GLUT_WINDOW_WIDTH) - 1.0;
            y = 1.0 - (2.0 * my) / glutGet(GLUT_WINDOW_HEIGHT);
            primeiroClique = 0; //primeiro clique ocorre
        } else {
            x2 = (2.0 * mx) / glutGet(GLUT_WINDOW_WIDTH) - 1.0;
            y2 = 1.0 - (2.0 * my) / glutGet(GLUT_WINDOW_HEIGHT);
            primeiroClique = 1;
        }
        glutPostRedisplay();
    }
}

void Keyboard(unsigned char key, int x, int y)
{
    switch (key)
    {
    case '0':
        glColor3f(1.0, 0.0, 0.0);
        break;
    case '1':
        glColor3f(0.0, 1.0, 0.0);
        break;
    case '2':
        glColor3f(0.0, 0.0, 1.0);
        break;
    case '3':
        glColor3f(1.0, 0.0, 1.0);
        break;
    case '4':
        glColor3f(1.0, 1.0, 0.0);
        break;
    case '5':
        glColor3f(0.0, 1.0, 1.0);
        break;
    case '6':
        glColor3f(1.0, 1.0, 1.0);
        break;
    case '7':
        glColor3f(0.5, 0.0, 1.0);
        break;
    case '8':
        glColor3f(1.0, 0.5, 0.5);
        break;
    case '9':
        glColor3f(0.5, 1.0, 0.0);
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("Exercicio 03");
    glColor3f(0.0, 0.0, 1.0); // Primeira cor é azul
    glutDisplayFunc(point);
    glutMouseFunc(MouseInt);
    glutKeyboardFunc(Keyboard);
    glutMainLoop();
    return 0;
}
