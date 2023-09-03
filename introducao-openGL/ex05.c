/*
    Escreva um programa que contenha três funções: as funções de traçar uma linha e de mudar a cor do 
    ex03.c e uma função de traçar triangulos. Inicialmente, deve ser impressa uma linha azul de coordenadas (0,0) - (0,0).
    Apenas uma figura deve ser apresentada de cada vez na tela. As figuras anteriores são apagadas. Caso o usuário
    clique a tecla ’r’ ou ’R’, a função de traçar retas é ativada. Caso o usuário clique a tecla ’t’ ou ’T’ a função
    de traçar triangulos é ativada. O traçado da reta continua da mesma maneira do ex03.c. No traçado de
    triangulos, os três vértices são determinados por três cliques seguidos com o botão esquerdo do mouse.
*/

#include <glut.h>

float x = 0.0; 
float y = 0.0; 
float x2 = 0.0; 
float y2 = 0.0; 
float xTriangulo, yTriangulo;
float pontosDoTriangulo[6];  //array with (x,y) of triangle
int numClicks; //counter clicks
int primeiroClique = 1, controle = 0;

void reta() 
{   
    glClearColor(0, 0, 0, 0); 
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_LINES);
        glVertex2f(x, y);
        glVertex2f(x2, y2);
    glEnd();
    glFlush();
}

void triangulo()
{
    glClearColor(0, 0, 0, 0);
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
        for (int i = 0; i < 6; i += 2)
            glVertex2f(pontosDoTriangulo[i], pontosDoTriangulo[i + 1]);
    glEnd();
    glFlush();
}

void MouseInt (int button, int state, int mx, int my)
{
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        if(controle) { //TRIANGLE
            pontosDoTriangulo[numClicks * 2] = (2.0 * mx) / glutGet(GLUT_WINDOW_WIDTH) - 1.0;
            pontosDoTriangulo[numClicks * 2 + 1] = 1.0 - (2.0 * my) / glutGet(GLUT_WINDOW_HEIGHT);

            numClicks++;

            if (numClicks == 3) { //all vertex was gaved          
                //resets:
                numClicks = 0;
                controle = 0;  
            }
        } else if(primeiroClique) { 
            x = (2.0 * mx) / glutGet(GLUT_WINDOW_WIDTH) - 1.0;
            y = 1.0 - (2.0 * my) / glutGet(GLUT_WINDOW_HEIGHT);
            primeiroClique = 0;
        }
        else { 
            x2 = (2.0 * mx) / glutGet(GLUT_WINDOW_WIDTH) - 1.0;
            y2 = 1.0 - (2.0 * my) / glutGet(GLUT_WINDOW_HEIGHT);
            primeiroClique = 1;
        }
        glutPostRedisplay();
    }
}

void Keyboard (unsigned char key, int x, int y)
{
    switch(key)
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
        case 't':
        case 'T':   
            controle = 1; 
            glutDisplayFunc(triangulo);
            break;
        case 'r':
        case 'R':   
            controle = 0;
            glutDisplayFunc(reta); 
            break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition (50, 100);
    glutInitWindowSize (400, 400);
    glutCreateWindow ("Exercicio 03");
    glColor3f(0.0, 0.0, 1.0); //First color is blue
    glutDisplayFunc(reta);
    glutMouseFunc(MouseInt);
    glutKeyboardFunc(Keyboard);
    glutMainLoop ();
    return 0;
}