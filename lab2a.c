#include<stdio.h>
#include<GL/glut.h>

int x1,y1,x2,y2;

void display()
{
    int dx = abs(x2-x1);
    int dy = abs(y2-y1);
    int pk = 2*dy-dx;
    int x=x1;
    int y=y1;
    for(int i=0;i<dx;i++)
    {
        glColor3f(0,1,0);
        glBegin(GL_POINTS);
        glVertex2f(x,y);
        glEnd();

        if(pk<0)
            pk+=2*dy;
        else
        {
            pk=pk+2*(dy-dx);
            y++;
        }
        x++;
        // glColor3f(0,1,0);
        // glBegin(GL_POINTS);
        // glVertex2f(x,y);
        // glEnd();       
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

void main(int argc,char** argv)
{
    printf("enter x1,y1,x2,y2\n");
    scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (500, 500);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Breshanman Line Algorithm ");
    init ();
    glutDisplayFunc(display);
    glutMainLoop();
}