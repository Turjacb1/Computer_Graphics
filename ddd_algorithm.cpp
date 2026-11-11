
#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>

float x1, y1, x2, y2, m, i, j;
int dx = 0, dy = 0;

void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glPointSize(2.0);

    glBegin(GL_POINTS);

    dx = x2 - x1;
    dy = y2 - y1;

    i = x1;
    j = y1;

    if (abs(dx) >= abs(dy))
    {
        m = (float)dy / dx;

        if (dx > 0)
        {
            while (i <= x2)
            {
                printf("%.2f %.2f\n", i, j);
                glVertex3f(i / 100, j / 100, 0.0);

                i = i + 1;
                j = j + m;
            }
        }
        else
        {
            while (i >= x2)
            {
                printf("%.2f %.2f\n", i, j);
                glVertex3f(i / 100, j / 100, 0.0);

                i = i - 1;
                j = j - m;
            }
        }
    }
    else
    {
        m = (float)dy / dx;

        if (dy > 0)
        {
            while (j <= y2)
            {
                printf("%.2f %.2f\n", i, j);
                glVertex3f(i / 100, j / 100, 0.0);

                i = i + 1 / m;
                j = j + 1;
            }
        }
        else
        {
            while (j >= y2)
            {
                printf("%.2f %.2f\n", i, j);
                glVertex3f(i / 100, j / 100, 0.0);

                i = i - 1 / m;
                j = j - 1;
            }
        }
    }

    glEnd();

    glFlush();
}

void init(void)
{
    glClearColor(0.0, 0.0, 0.0, 0.0);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0.0, 1.0, 0.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv)
{
    printf("Enter first point: ");
    scanf("%f %f", &x1, &y1);

    printf("Enter second point: ");
    scanf("%f %f", &x2, &y2);

    glutInit(&argc, argv);


    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);

    glutCreateWindow("DDA Line Drawing Algorithm");

    init();

    glutDisplayFunc(display);

    glutMainLoop();

    return 0;
}

