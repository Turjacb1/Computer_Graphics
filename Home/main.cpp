
/*
 * 3D Residential House Environment
 * OpenGL + GLUT
 *
 * Features:
 * 1. House
 * 2. Garage with Car
 * 3. Swimming Pool
 * 4. Main Gate and Fence
 * 5. Garden with Trees and Flowers
 *
 * Controls:
 * ESC / Q : Exit
 * +       : Increase roof detail
 * -       : Decrease roof detail
 */

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include <math.h>

static int slices = 16;
static int stacks = 16;

// --------------------------------------------------
// BASIC OBJECT FUNCTION
// --------------------------------------------------

void drawCube(double x, double y, double z,
              double sx, double sy, double sz,
              double r, double g, double b)
{
    glPushMatrix();

    glTranslated(x, y, z);
    glScaled(sx, sy, sz);

    glColor3d(r, g, b);
    glutSolidCube(1.0);

    glPopMatrix();
}

// --------------------------------------------------
// DRAW HOUSE
// --------------------------------------------------

void drawHouse()
{
    // Main house body
    drawCube(0, 0, 0, 2.0, 1.5, 1.6,
             0.9, 0.8, 0.65);

    // Red roof
    glPushMatrix();
    glTranslated(0, 0.75, 0);
    glRotated(-90, 1, 0, 0);
    glColor3d(0.8, 0.1, 0.1);
    glutSolidCone(1.4, 0.9, slices, stacks);
    glPopMatrix();

    // Main door
    drawCube(0, -0.35, 0.81,
             0.4, 0.8, 0.08,
             0.35, 0.15, 0.05);

    // Door handle
    drawCube(0.12, -0.35, 0.87,
             0.04, 0.04, 0.03,
             1.0, 0.8, 0.1);

    // Left window
    drawCube(-0.65, 0.25, 0.82,
             0.45, 0.4, 0.06,
             0.1, 0.4, 0.8);

    // Right window
    drawCube(0.65, 0.25, 0.82,
             0.45, 0.4, 0.06,
             0.1, 0.4, 0.8);

    // Window frames
    drawCube(-0.65, 0.25, 0.86,
             0.48, 0.04, 0.02,
             0.2, 0.1, 0.05);

    drawCube(0.65, 0.25, 0.86,
             0.48, 0.04, 0.02,
             0.2, 0.1, 0.05);
}

// --------------------------------------------------
// DRAW GARAGE
// --------------------------------------------------

void drawGarage()
{
    // Garage building
    drawCube(2.2, -0.15, 0,
             1.7, 1.2, 1.6,
             0.85, 0.82, 0.75);

    // Garage roof
    glPushMatrix();
    glTranslated(2.2, 0.45, 0);
    glRotated(-90, 1, 0, 0);
    glColor3d(0.8, 0.1, 0.1);
    glutSolidCone(1.25, 0.65, slices, stacks);
    glPopMatrix();

    // Garage shutter
    drawCube(2.2, -0.25, 0.82,
             1.25, 0.85, 0.05,
             0.55, 0.58, 0.62);

    // Shutter horizontal lines
    for (int i = 0; i < 5; i++)
    {
        drawCube(2.2, -0.65 + i * 0.18, 0.86,
                 1.23, 0.015, 0.015,
                 0.25, 0.27, 0.3);
    }

    // Simple car inside garage
    drawCube(2.2, -0.65, 0.15,
             0.95, 0.35, 0.75,
             0.85, 0.05, 0.03);

    // Car upper body
    drawCube(2.2, -0.42, 0.15,
             0.55, 0.3, 0.6,
             0.1, 0.25, 0.65);

    // Wheels
    for (int i = -1; i <= 1; i += 2)
    {
        for (int j = -1; j <= 1; j += 2)
        {
            glPushMatrix();
            glTranslated(2.2 + i * 0.32,
                         -0.82,
                         0.15 + j * 0.35);
            glScaled(0.13, 0.13, 0.08);
            glColor3d(0.05, 0.05, 0.05);
            glutSolidSphere(1, 16, 16);
            glPopMatrix();
        }
    }
}

// --------------------------------------------------
// DRAW SWIMMING POOL
// --------------------------------------------------

void drawPool()
{
    // Pool border
    drawCube(-2.4, -1.0, 0.1,
             2.4, 0.18, 1.9,
             0.85, 0.85, 0.8);

    // Blue water
    drawCube(-2.4, -0.89, 0.1,
             2.15, 0.06, 1.65,
             0.0, 0.55, 0.95);

    // Pool decorative edges
    drawCube(-2.4, -0.85, -0.85,
             2.4, 0.08, 0.08,
             0.9, 0.9, 0.9);

    drawCube(-2.4, -0.85, 1.05,
             2.4, 0.08, 0.08,
             0.9, 0.9, 0.9);

    // Pool ladder
    for (int i = 0; i < 2; i++)
    {
        glPushMatrix();
        glTranslated(-3.0 + i * 0.35, -0.55, 0.95);
        glScaled(0.04, 0.7, 0.04);
        glColor3d(0.7, 0.7, 0.75);
        glutSolidCube(1);
        glPopMatrix();
    }
}

// --------------------------------------------------
// DRAW TREE
// --------------------------------------------------

void drawTree(double x, double z)
{
    // Tree trunk
    drawCube(x, -0.65, z,
             0.18, 0.9, 0.18,
             0.4, 0.2, 0.05);

    // Tree leaves
    glPushMatrix();
    glTranslated(x, 0.0, z);
    glColor3d(0.05, 0.45, 0.08);
    glutSolidSphere(0.65, 20, 20);
    glPopMatrix();
}

// --------------------------------------------------
// DRAW FLOWERS
// --------------------------------------------------

void drawFlower(double x, double z)
{
    // Flower stem
    drawCube(x, -0.65, z,
             0.035, 0.3, 0.035,
             0.0, 0.5, 0.0);

    // Flower head
    glPushMatrix();
    glTranslated(x, -0.45, z);
    glColor3d(1.0, 0.1, 0.5);
    glutSolidSphere(0.12, 12, 12);
    glPopMatrix();
}

// --------------------------------------------------
// DRAW GARDEN
// --------------------------------------------------

void drawGarden()
{
    // Green grass
    drawCube(0, -1.3, 0,
             8.5, 0.2, 5.5,
             0.15, 0.55, 0.12);

    // Trees around the garden
    drawTree(-3.7, -0.8);
    drawTree(-3.8, 1.2);
    drawTree(3.8, -0.8);
    drawTree(3.8, 1.2);

    // Flowers
    for (int i = 0; i < 6; i++)
    {
        drawFlower(-3.2 + i * 0.3, 1.6);
        drawFlower(3.0 + i * 0.3, 1.6);
    }

    // Garden bushes
    for (int i = 0; i < 5; i++)
    {
        glPushMatrix();
        glTranslated(-3.0 + i * 0.35, -1.0, 1.8);
        glColor3d(0.0, 0.35, 0.05);
        glutSolidSphere(0.2, 12, 12);
        glPopMatrix();
    }
}

// --------------------------------------------------
// DRAW GATE AND FENCE
// --------------------------------------------------

void drawGate()
{
    // Left gate pillar
    drawCube(1.1, -0.65, 2.25,
             0.25, 1.3, 0.25,
             0.55, 0.2, 0.1);

    // Right gate pillar
    drawCube(3.2, -0.65, 2.25,
             0.25, 1.3, 0.25,
             0.55, 0.2, 0.1);

    // Gate top decorations
    glPushMatrix();
    glTranslated(1.1, 0.1, 2.25);
    glColor3d(1.0, 0.9, 0.4);
    glutSolidSphere(0.14, 16, 16);
    glPopMatrix();

    glPushMatrix();
    glTranslated(3.2, 0.1, 2.25);
    glColor3d(1.0, 0.9, 0.4);
    glutSolidSphere(0.14, 16, 16);
    glPopMatrix();

    // Main gate horizontal bars
    for (int i = 0; i < 3; i++)
    {
        drawCube(2.15, -1.05 + i * 0.35, 2.25,
                 1.85, 0.06, 0.08,
                 0.08, 0.08, 0.1);
    }

    // Gate vertical bars
    for (int i = 0; i < 9; i++)
    {
        drawCube(1.3 + i * 0.21, -0.65, 2.25,
                 0.045, 1.0, 0.07,
                 0.08, 0.08, 0.1);
    }

    // Side fence left
    for (int i = 0; i < 7; i++)
    {
        drawCube(-4.0 + i * 0.75, -0.95, 2.25,
                 0.05, 0.65, 0.05,
                 0.1, 0.1, 0.1);
    }

    // Side fence right
    for (int i = 0; i < 6; i++)
    {
        drawCube(3.5 + i * 0.1, -0.95, 2.25,
                 0.05, 0.65, 0.05,
                 0.1, 0.1, 0.1);
    }

    // Fence horizontal bars
    drawCube(-1.8, -0.85, 2.25,
             2.5, 0.05, 0.05,
             0.1, 0.1, 0.1);

    drawCube(3.7, -0.85, 2.25,
             1.1, 0.05, 0.05,
             0.1, 0.1, 0.1);
}

// --------------------------------------------------
// COMPLETE ENVIRONMENT
// --------------------------------------------------

void drawEnvironment()
{
    drawGarden();
    drawPool();
    drawHouse();
    drawGarage();
    drawGate();
}

// --------------------------------------------------
// WINDOW RESIZE
// --------------------------------------------------

static void resize(int width, int height)
{
    if (height == 0)
        height = 1;

    const float ar = (float)width / (float)height;

    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// --------------------------------------------------
// DISPLAY
// --------------------------------------------------

static void display(void)
{
    const double t = glutGet(GLUT_ELAPSED_TIME) / 1000.0;
    const double angle = t * 15.0;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();

    // Camera position
    glTranslated(0.0, 0.0, -10.5);

    // Rotate complete environment
    glRotated(12, 1, 0, 0);
    glRotated(angle, 0, 1, 0);

    drawEnvironment();

    glPopMatrix();

    glutSwapBuffers();
}

// --------------------------------------------------
// KEYBOARD CONTROLS
// --------------------------------------------------

static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:
        case 'q':
        case 'Q':
            exit(0);
            break;

        case '+':
            slices++;
            stacks++;
            break;

        case '-':
            if (slices > 3 && stacks > 3)
            {
                slices--;
                stacks--;
            }
            break;
    }

    glutPostRedisplay();
}

// --------------------------------------------------
// IDLE
// --------------------------------------------------

static void idle(void)
{
    glutPostRedisplay();
}

// --------------------------------------------------
// LIGHTING
// --------------------------------------------------

const GLfloat light_ambient[] =
    {0.3f, 0.3f, 0.3f, 1.0f};

const GLfloat light_diffuse[] =
    {1.0f, 1.0f, 1.0f, 1.0f};

const GLfloat light_specular[] =
    {1.0f, 1.0f, 1.0f, 1.0f};

const GLfloat light_position[] =
    {2.0f, 5.0f, 5.0f, 1.0f};

// --------------------------------------------------
// MAIN FUNCTION
// --------------------------------------------------

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);

    glutInitWindowSize(1000, 700);
    glutInitWindowPosition(100, 50);

    glutInitDisplayMode(
        GLUT_RGB |
        GLUT_DOUBLE |
        GLUT_DEPTH
    );

    glutCreateWindow("3D Dream House Environment");

    glutReshapeFunc(resize);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutIdleFunc(idle);

    // Background sky blue
    glClearColor(0.55, 0.75, 0.95, 1.0);

    // Depth and lighting
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);

    glColorMaterial(
        GL_FRONT_AND_BACK,
        GL_AMBIENT_AND_DIFFUSE
    );

    glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glEnable(GL_SMOOTH);

    glutMainLoop();

    return EXIT_SUCCESS;
}
