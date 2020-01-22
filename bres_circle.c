#include<stdio.h>
#include<GL/glut.h>

void Init()
{
    glClearColor(0.0,0.0,0.0,1.0);
    glColor3f(1.0,1.0,0.0);
    gluOrtho2D(-640 , 640 , -480 , 480);
}

void draw(int x, int y)
{
    glBegin(GL_POINTS);
        glVertex2i(x,y);
        glVertex2i(-x,y);
        glVertex2i(x,-y);
        glVertex2i(-x,-y);
        glVertex2i(y,x);
        glVertex2i(-y,x);
        glVertex2i(y,-x);
        glVertex2i(-y,-x);
    glEnd();
}

void bres_circle(int r)
{
    int x=0,y=r;
    float d = 3.0-2.0*r;

    draw(x,y);
    //while(x<=y)
    {
        x++;
        if(d<0)
            d+=4*x+6;
        else
        {
            y--;
            d+=4*(x-y)+10;
        }
        draw(x,y);
        
    }

    glFlush();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int radius = 300;
    bres_circle(radius);
}

void main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(640,480);
    glutCreateWindow("Bresenham's Circle");
    Init();
    glutDisplayFunc(display);
    glutMainLoop();
}