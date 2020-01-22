#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
 
#define WIDTH 640
#define HEIGHT 480


void reshape(int width, int height){
glViewport(0,0,width,height);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(-WIDTH/2,WIDTH/2-1,-HEIGHT/2,HEIGHT/2-1,-1,1);
glMatrixMode(GL_MODELVIEW);
glLoadIdentity();
}
 
void init(void){
glClearColor(0.0,0.0,0.0,1.0);
glPointSize(2.0);
}
 
void Timer(int ex)
{
glutPostRedisplay();
glutTimerFunc(30,Timer,0);
}
 

void circle(int p,int r)
{
int x=0,y,d;
y=r;
d=3-2*r;
while(x<=y)
{
glVertex2i(x,y+p);
glVertex2i(y,x+p);
glVertex2i(-x,y+p);
glVertex2i(-y,x+p);
glVertex2i(-x,-y+p);
glVertex2i(-y,-x+p);
glVertex2i(y,-x+p);
glVertex2i(x,-y+p);
if(d<0)
d=d+4*x+6;
else
{
d=d+4*(x-y)+10;
y--;
}
x++;
}
}
 
int r=30,flag=0;
int k=10;
 
void display(void)
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glColor4f(0.0,1.0,1.0,1.0);
glBegin(GL_POINTS);
 
circle(k,r);
 
    if(flag==0)
    {
        if((k+r)<180)
        {
            k=k+5;
        }
        if((k+r)>=180){
            flag=1;
        }
    }
 
    if(flag==1)
    {
        k=k-5;
        if((k-r)<=-180)
        {
            flag=0;
        }
    }
 
glEnd();
glutSwapBuffers();
 
}
 
int main(int argc, char **argv){
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
glutInitWindowPosition(0,0);
glutInitWindowSize(WIDTH,HEIGHT);
glutCreateWindow(argv[0]);
init();
glutReshapeFunc(reshape);
glutDisplayFunc(display);
glutTimerFunc(0,Timer,0);
glutMainLoop();
return(1);
}