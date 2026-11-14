#include <windows.h>
#include <GL/glut.h>

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0); // Set display window colour to white
    glMatrixMode(GL_PROJECTION);      // Set projection parameters
    gluOrtho2D(0.0, 400.0, 0.0, 400.0);
}

void drawShapes(void) {
    glClear(GL_COLOR_BUFFER_BIT); // Clear display window

    // 1. Roof (Dark Blue Triangle)
    glColor3f(0.0, 0.12, 0.45);
    glBegin(GL_TRIANGLES);
        glVertex2i(100, 200);
        glVertex2i(300, 200);
        glVertex2i(200, 300);
    glEnd();

    // 2. Main House Wall (Red Rectangle)
    glColor3f(0.8, 0.0, 0.0);
    glBegin(GL_QUADS);
        glVertex2i(100, 20);
        glVertex2i(300, 20);
        glVertex2i(300, 200);
        glVertex2i(100, 200);
    glEnd();

    // 3. Door (Green Rectangle)
    glColor3f(0.0, 0.68, 0.3);
    glBegin(GL_QUADS);
        glVertex2i(165, 20);
        glVertex2i(235, 20);
        glVertex2i(235, 140);
        glVertex2i(165, 140);
    glEnd();

    // 4. Left Window (Green Square)
    glBegin(GL_QUADS);
        glVertex2i(118, 70);
        glVertex2i(150, 70);
        glVertex2i(150, 115);
        glVertex2i(118, 115);
    glEnd();

    // 5. Right Window (Green Square)
    glBegin(GL_QUADS);
        glVertex2i(250, 70);
        glVertex2i(282, 70);
        glVertex2i(282, 115);
        glVertex2i(250, 115);
    glEnd();

    glFlush(); // Process all OpenGL routines
}

int main(int argc, char* argv[]) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(50, 100);
    glutInitWindowSize(400, 400);
    glutCreateWindow("House in OpenGL");
    init();
    glutDisplayFunc(drawShapes);
    glutMainLoop();
    return 0;
}
