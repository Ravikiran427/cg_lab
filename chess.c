#include <stdio.h>
#include <math.h>
#include <GL/glut.h>

void DDA(int X1, int Y1, int X2, int Y2)
{
    int dx=(X2-X1);
    int dy=(Y2-Y1);
    int steps;
    float xInc,yInc,x=X1,y=Y1;
    steps=(abs(dx)>abs(dy))?(abs(dx)):(abs(dy));
    xInc=dx/(float)steps;
    yInc=dy/(float)steps;

    glBegin(GL_POINTS);
    glVertex2f(x,y);
    int k;
    for(k=0;k<steps;k++)
    {
        x+=xInc;
        y+=yInc;
        glVertex2f(x, y);
    }
    glEnd();
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT);
    int k;
    for(k=0;k<=400;k+=50){
        DDA(0, k, 400, k);
        DDA(k, 0, k, 400);
    }
    glFlush();
}

void Init()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glColor3f(1.0,1.0,0.0);
    gluOrtho2D(-640 , 640 , -480 , 480);
}

void main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("DDA");
    Init();
    glutDisplayFunc(display);
    glutMainLoop();
}