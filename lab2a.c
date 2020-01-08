#include<GL/glut.h>

float angle=0.0;

void update(int value){
    angle+=0.2f;
    glutPostRedisplay();
    glutTimerFunc(10,update,0);

}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(0.3f,0,0);
    glRotatef(angle,0,1,0);
    glTranslatef(-0.3f,0,0);

    glBegin(GL_TRIANGLES);
        glVertex2f(0,0);
        glVertex2f(0.6,0);
        glVertex2f(0.3,0.5);
    glEnd();
    glPopMatrix();

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glRotatef(angle,1,0.1,0);
    glBegin(GL_POLYGON);
        glVertex2f(-0.5,0);
        glVertex2f(-0.8,0);
        glVertex2f(-0.8,0.5);
        glVertex2f(-0.5,0.5);
    glEnd();
    glPopMatrix();

    glFlush();
}


int main (int argc, char** argv) 
{ 
    glutInit(&argc, argv); 
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); 
      
    // giving window size in X- and Y- direction 
    glutInitWindowSize(1366, 768); 
    glutInitWindowPosition(0, 0); 
      
    // Giving name to window 
    glutCreateWindow("Circle Drawing"); 
      
    glutDisplayFunc(display);
    glutTimerFunc(10,update,0);
    glutMainLoop(); 
} 