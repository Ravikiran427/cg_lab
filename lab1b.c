#include<stdio.h>
#include<GL/glut.h>

float x1,y1,x2,y2;

void display()
{
    float dx = abs(x1-x2);
    float dy = abs(y2-y1);
    float steps = dx > dy ? dx : dy;
    float inx = dx/steps;
    float iny = dy/steps;

    float x = x1;
    float y = y1;


glBegin(GL_POINTS);
        glColor3f(1,1,0);
        glVertex2i(x,y);
        glEnd();
    for(int i=0; i<steps; i++)
    {
        glBegin(GL_POINTS);
        glColor3f(1,1,0);
        glVertex2i(x,y);
        glEnd();
        x+=inx;
        y+=iny;
    }

    glFlush();
}

void init(void)
{
    glClear ( GL_COLOR_BUFFER_BIT ) ;
    glClearColor(0.7,0.7,0.7,0.7);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
}

void main(int argc, char** argv)
{
    printf("enter x1,y1,x2,y2\n");
    scanf("%f%f%f%f",&x1,&y1,&x2,&y2);

    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100,100);
    glutCreateWindow ("DDA");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
}