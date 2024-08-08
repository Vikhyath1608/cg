#include <GL/glut.h>
#include <math.h>

GLsizei winWidth = 500, winHeight = 500;
GLfloat angle = 0.0;  // Rotation angle
bool rotateClockwise = false;
bool rotateCounterClockwise = false;

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);	
    gluOrtho2D(-250.0, 250.0, -250.0, 250.0);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    // Apply rotation
    glTranslatef(0.0, 0.0, 0.0);  // Ensure rotation is around the center
    glRotatef(angle, 0.0, 0.0, 1.0);

    // Draw a rectangle
    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_POLYGON);
        glVertex2f(-50.0, -25.0);
        glVertex2f(50.0, -25.0);
        glVertex2f(50.0, 25.0);
        glVertex2f(-50.0, 25.0);
    glEnd();

    glPopMatrix();

    glFlush();
}


void rotate(void) {
    if (rotateCounterClockwise) {
        angle += 0.1;
    } else if (rotateClockwise) {
        angle -= 0.1;
    }
    if (angle > 360.0) angle -= 360.0;
    if (angle < -360.0) angle += 360.0;
    glutPostRedisplay();
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'q': 
            rotateCounterClockwise = true;
            rotateClockwise = false;
            glutIdleFunc(rotate);
            break;  // Rotate counterclockwise
        case 'e': 
            rotateClockwise = true;
            rotateCounterClockwise = false;
            glutIdleFunc(rotate);
            break;  // Rotate clockwise
        case 's': 
            rotateClockwise = false;
            rotateCounterClockwise = false;
            glutIdleFunc(NULL);
            break;  // Stop rotation
        case 27: exit(0); break;  // Escape key to exit
    }
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("Rectangle Rotation");

    init();
    glutDisplayFunc(display);
    
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}

