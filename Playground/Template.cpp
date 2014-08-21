#include<iostream>
#include<GL/glut.h>
using namespace std;




void myinit()
{
     glClearColor(0.0,0.0,0.0,0.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0,250.0,0.0,250.0);
     glMatrixMode(GL_MODELVIEW);
}





     

void display()
{
     
     glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB /*| GLUT_DEPTH*/);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Stack");
    //glutReshapeFunc(myReshape);
    //glutSpecialFunc(keyControl);
    //glutIdleFunc(idler);
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    
    return 0;
}
