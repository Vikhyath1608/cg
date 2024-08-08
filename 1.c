#include <GL/glut.h>
#include <stdio.h>

int x1, y11, x2, y2;

void myInit() {
    glClear(GL_COLOR_BUFFER_BIT);
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(0, 500, 0, 500);
}

void draw_pixel(int x, int y) {
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();
}

void draw_line(int x1, int y11, int x2, int y2) {
    int dx = abs(x2 - x1), dy = abs(y2 - y11);
    int incx = (x2 > x1) ? 1 : -1;
    int incy = (y2 > y11) ? 1 : -1;
    int x = x1, y = y11;
    int e = (dx > dy) ? dx / 2 : dy / 2;
    
    for (int i = 0; i <= ((dx > dy) ? dx : dy); i++) {
        draw_pixel(x, y);
        if (dx > dy) {
            x += incx;
            e -= dy;
            if (e < 0) {
                y += incy;
                e += dx;
            }
        } else {
            y += incy;
            e -= dx;
            if (e < 0) {
                x += incx;
                e += dy;
            }
        }
    }
}

void myDisplay() {
    draw_line(x1, y11, x2, y2);
    glFlush();
}

int main(int argc, char **argv) {
    printf("Enter (x1, y1, x2, y2):\n");
    scanf("%d %d %d %d", &x1, &y11, &x2, &y2);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(0, 0);
    glutCreateWindow("Bresenham's Line Drawing");
    myInit();
    glutDisplayFunc(myDisplay);
    glutMainLoop(); 
    return 0;
}
