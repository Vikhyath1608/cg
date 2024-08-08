#include <GL/glut.h>
#include <math.h>

GLsizei winWidth = 500, winHeight = 500;
float tx = 0.0, ty = 0.0;  // Translation factors
float sx = 1.0, sy = 1.0;  // Scaling factors
float angle = 0.0;  // Rotation angle

void init() {

    glClearColor(1.0, 1.0, 1.0, 0.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-250.0, 250.0, -250.0, 250.0);
}

void display(void) {
    
	glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();

    // Apply transformations
    glTranslatef(tx, ty, 0.0);
    glRotatef(angle, 0.0, 0.0, 1.0);
    glScalef(sx, sy, 1.0);

    // Draw a rectangle
    
    glBegin(GL_POLYGON);
    glColor3f(1.0, 0.0, 0.0);
        glVertex2f(-50.0, -25.0);
        glVertex2f(50.0, -25.0);
        glVertex2f(50.0, 25.0);
        glVertex2f(-50.0, 25.0);
    glEnd();

    glPopMatrix();	
s    glFlush();

    
}

void keyboard(unsigned char key,int x,int y) {
    switch (key) {
        case 'w': ty += 10.0; break;  // Move up
        case 's': ty -= 10.0; break;  // Move down
        case 'a': tx -= 10.0; break;  // Move left
        case 'd': tx += 10.0; break;  // Move right
        case 'q': angle += 5.0; break;  // Rotate counterclockwise
        case 'e': angle -= 5.0; break;  // Rotate clockwise
        case 'z': sx += 0.1; sy += 0.1; break;  // Scale up
        case 'x': sx -= 0.1; sy -= 0.1; break;  // Scale down
        case 27: exit(0); break;  // Escape key to exit
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("2D Geometric Operations");

    init();
    glutDisplayFunc(display);
   
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
