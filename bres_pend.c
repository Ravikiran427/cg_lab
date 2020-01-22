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
    while(x<=y)
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

    //glFlush();
}

void bres_line(int r)
{
    int x1=0,y1=r;
    int x2=0,y2=3*r;

    int dx = abs(x2-x1);
    int dy = abs(y2-y1);
    int d = 2*dy-dx;
    int x=x1;
    int y=y1;

    for(int i=0;i<dy;i++)
    {
        glBegin(GL_POINTS);
            glVertex2d(x,y);
        glEnd();
        if(d>0)
            d+=2*dx;
        else
        {
            d+=2*(dx-dy);
            x++;
        }
        y++;
        
    }
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    int radius = 300;
    bres_circle(radius);
    bres_line(radius);
    glFlush();
}

void main(int argc, char **argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(1080,720);
    glutCreateWindow("Bresenham's Circle");
    Init();
    glutDisplayFunc(display);
    glutMainLoop();
}