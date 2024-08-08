#include <GL/glut.h>

// Initial size of the window
GLsizei winWidth = 500, winHeight = 500;

// Transformation parameters
GLfloat tx = 0.0, ty = 0.0, tz = 0.0;  // Translation factors
GLfloat sx = 1.0, sy = 1.0, sz = 1.0;  // Scaling factors
GLfloat angleX = 0.0, angleY = 0.0, angleZ = 0.0;  // Rotation angles

void init(void) {
    glClearColor(1.0, 1.0, 1.0, 0.0);
    glEnable(GL_DEPTH_TEST);  // Enable depth testing
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();

    // Apply transformations
    glTranslatef(tx, ty, tz);
    glRotatef(angleX, 1.0, 0.0, 0.0);
    glRotatef(angleY, 0.0, 1.0, 0.0);
    glRotatef(angleZ, 0.0, 0.0, 1.0);
    glScalef(sx, sy, sz);

    // Draw a cube with different colors for each face
    glBegin(GL_QUADS);

    // Front face (red)
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(-0.5, -0.5,  0.5);
    glVertex3f( 0.5, -0.5,  0.5);
    glVertex3f( 0.5,  0.5,  0.5);
    glVertex3f(-0.5,  0.5,  0.5);

    // Back face (green)
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f( 0.5, -0.5, -0.5);
    glVertex3f( 0.5,  0.5, -0.5);
    glVertex3f(-0.5,  0.5, -0.5);

    // Left face (blue)
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f(-0.5, -0.5,  0.5);
    glVertex3f(-0.5,  0.5,  0.5);
    glVertex3f(-0.5,  0.5, -0.5);

    // Right face (yellow)
    glColor3f(1.0, 1.0, 0.0);
    glVertex3f( 0.5, -0.5, -0.5);
    glVertex3f( 0.5, -0.5,  0.5);
    glVertex3f( 0.5,  0.5,  0.5);
    glVertex3f( 0.5,  0.5, -0.5);

    // Top face (cyan)
    glColor3f(0.0, 1.0, 1.0);
    glVertex3f(-0.5,  0.5, -0.5);
    glVertex3f( 0.5,  0.5, -0.5);
    glVertex3f( 0.5,  0.5,  0.5);
    glVertex3f(-0.5,  0.5,  0.5);

    // Bottom face (magenta)
    glColor3f(1.0, 0.0, 1.0);
    glVertex3f(-0.5, -0.5, -0.5);
    glVertex3f( 0.5, -0.5, -0.5);
    glVertex3f( 0.5, -0.5,  0.5);
    glVertex3f(-0.5, -0.5,  0.5);

    glEnd();

    glPopMatrix();

    glutSwapBuffers();
}


void keyboard(unsigned char key, int x, int y) {
    switch (key) {
        case 'w': ty += 0.1; break;  
        case 's': ty -= 0.1; break;  
        case 'a': tx -= 0.1; break;  
        case 'd': tx += 0.1; break;  
        case 'i': tz += 0.1; break;  
        case 'k': tz -= 0.1; break; 
        case 'q': angleX += 5.0; break; 
        case 'e': angleX -= 5.0; break; 
        case 'r': angleY += 5.0; break;  
        case 'f': angleY -= 5.0; break;  
        case 't': angleZ += 5.0; break;  
        case 'g': angleZ -= 5.0; break; 
        case 'z': sx += 0.1; sy += 0.1; sz += 0.1; break;  
        case 'x': sx -= 0.1; sy -= 0.1; sz -= 0.1; break; 
        case 27: exit(0); break;  
            }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(winWidth, winHeight);
    glutCreateWindow("3D Transformations");

    init();
    glutDisplayFunc(display);
    
    glutKeyboardFunc(keyboard);
    glutMainLoop();

    return 0;
}
