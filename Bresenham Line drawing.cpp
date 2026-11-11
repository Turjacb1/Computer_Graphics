#include <stdio.h>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>

int x1_pt, y1_pt, x2_pt, y2_pt;

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 0.0); // Green color
    glPointSize(3.0);

    int x = x1_pt;
    int y = y1_pt;

    int dx = abs(x2_pt - x1_pt);
    int dy = abs(y2_pt - y1_pt);

    // Determine step direction (+1 or -1) for both axes
    int sx = (x2_pt >= x1_pt) ? 1 : -1;
    int sy = (y2_pt >= y1_pt) ? 1 : -1;

    glBegin(GL_POINTS);

    // Case 1: Gentle slope (|m| <= 1, dx >= dy)
    if (dx >= dy) {
        int p = 2 * dy - dx; // Initial decision parameter

        for (int i = 0; i <= dx; i++) {
            printf("(%d, %d)\n", x, y);
            glVertex2i(x, y);

            x += sx;
            if (p < 0) {
                p = p + 2 * dy;
            } else {
                y += sy;
                p = p + 2 * dy - 2 * dx;
            }
        }
    }
    // Case 2: Steep slope (|m| > 1, dy > dx)
    else {
        int p = 2 * dx - dy; // Initial decision parameter

        for (int i = 0; i <= dy; i++) {
            printf("(%d, %d)\n", x, y);
            glVertex2i(x, y);

            y += sy;
            if (p < 0) {
                p = p + 2 * dx;
            } else {
                x += sx;
                p = p + 2 * dx - 2 * dy;
            }
        }
    }

    glEnd();
    glFlush();
}

void init(void) {
    glClearColor(0.0, 0.0, 0.0, 0.0); // Black background
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char** argv) {
    printf("Enter first point (x1 y1) between 0 and 500: ");
    scanf("%d %d", &x1_pt, &y1_pt);
    printf("Enter second point (x2 y2) between 0 and 500: ");
    scanf("%d %d", &x2_pt, &y2_pt);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Bresenham Line Drawing Algorithm");

    init();
    glutDisplayFunc(display);
    glutMainLoop();

    return 0;
}
