#include <stdio.h>
#include <stdlib.h>
#include <iostream> 
#include <math.h>
#include <GL/glut.h>

using namespace std;
#define	WIDTH	400
#define	HEIGHT	400

int r, contr, brese, xi, yi, xf, yf;

int main(int argc, char* argv[]);
void Calcula_circun();
void Calcula_reta();
void Inicializa(void);
void Desenho(int x, int y);
void Funcao(void);

void Calcula_circun()
{
    int a = 125;
    int b = 125;
    int x;
    float y;


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.8f, 0.77f);

    for (x = a - r; x <= a + r; x++)
    {
        y = -sqrt(r * r - (x - a) * (x - a)) + b;
        Desenho(x, round(y));
        y = sqrt(r * r - (x - a) * (x - a)) + b;
        Desenho(x, round(y));
    }


}

void Calcula_reta()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(1.0f, 0.8f, 0.0f);
    if (brese == 2)
    {
        float x = xi;
        float y = yf;
        float m = (yf - yi) / (xf - xi);

        if (0 < m < 1)
        {
            for (x = xi; x <= xf; x++)
            {
                y += m;
                Desenho(round(x), round(y));
            }
        }
        else
        {
            for (y = yi; y <= yf; y++)
            {
                x += 1 / m;
                Desenho(round(x), round(y));
            }
        }
    }
    else
    {
        int x;
        int y = xi;
        int a = yf - yi;
        int b = xi - xf;
        int V = 2 * a + b;

        for (x = xi; x <= xf; x++)
        {
            Desenho(x, y);
            if (V <= 0)
            {
                V += 2 * a;
            }
            else
            {
                V += 2 * (a + b);
                y += 1;
            }

        }
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
    if (contr == 2)
    {
        Calcula_circun();
        glFlush();
    }
    else
    {
        Calcula_reta();
        glFlush();
    }
}

int main(int argc, char* argv[])
{
    cout << "Desenhar uma reta (1) ou uma circunferencia (2): ";
    cin >> contr;
    if (contr == 2)
    {
        cout << "Digite o raio\n";
        cin >> r;
    }
    else {
        cout << "Reta Bresenham (1) ou DDA (2): ";
        cin >> brese;
        cout << "Digite o X e Y inicial:\n";
        cout << "X:";
        cin >> xi;
        cout << "Y:";
        cin >> yi;
        cout << "Digite o X e Y final:\n";
        cout << "X:";
        cin >> xf;
        cout << "Y:";
        cin >> yf;
    }


    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(100, 10);
    glutCreateWindow("Desenho");
    glutDisplayFunc(Funcao);
    glutReshapeFunc(AlteraTamanhoJanela);
    Inicializa();
    glutMainLoop();

}
