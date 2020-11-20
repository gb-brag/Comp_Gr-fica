#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <math.h>
#include <GL/glut.h>

using namespace std;
#define	WIDTH	400
#define	HEIGHT	400

int a, b, r;

int main(int argc, char* argv[]);
void Calcula(int a, int b, int r);
void Inicializa(void);
void Desenho(int x, int y);
void Funcao(void);

void Calcula(int a, int b, int r)
{
    int x;
    float y;
    

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.8f, 0.0f);	
   
    for (x = a - r; x <= a + r; x++)
    {
        y = -sqrt(r * r - (x - a) * (x - a)) + b;
        Desenho(x, round(y));
        y= sqrt(r * r - (x - a) * (x - a)) + b;
        Desenho(x, round(y));
    }


}

void Desenho(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

}

void Inicializa(void)
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

void AlteraTamanhoJanela(GLsizei w, GLsizei h)
{
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    if (w <= h)
        gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f * h / w);
    else
        gluOrtho2D(0.0f, 250.0f * w / h, 0.0f, 250.0f);
}

void Funcao()
{
    Calcula(a, b, r);
    glFlush();
}

int main(int argc, char* argv[])
{
    cout << "Digite X e Y central\n";
    cin >> a;
    cin >> b;
    cout << "Digite o raio\n";
    cin >> r;

    glutInit(&argc, argv);	 					
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 10);
    glutCreateWindow("Circunferencia");
    glutDisplayFunc(Funcao);
    glutReshapeFunc(AlteraTamanhoJanela);
    Inicializa();
    glutMainLoop();

}
