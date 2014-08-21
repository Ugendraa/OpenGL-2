#include<iostream>
#include<GL/glut.h>
using namespace std;

enum MENU_TYPE
{
        MENU_POP,
        MENU_PUSH,
        //MENU_BACK,
        //MENU_BACK_FRONT,
};

MENU_TYPE show = MENU_POP;
void myinit()
{
     glClearColor(0.0,0.0,0.0,0.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0,250.0,0.0,250.0);
     glMatrixMode(GL_MODELVIEW);
}


void myReshape(int w, int h)
{
     GLfloat fAspect;

    
    if(h == 0) h = 1;

    glViewport(0, 0, w, h);

    fAspect = (GLfloat)w/(GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    
    gluPerspective(35.0f, fAspect, 1.0, 40.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}


     

void display()
{
     
     glFlush();
}
void menu(int item)
{
        switch (item)
        {
        case MENU_POP:
             //pop()
             //break;
        case MENU_PUSH:
             //push()
             //break;
;        }

        glutPostRedisplay();
        //drawStack()
        return;
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB /*| GLUT_DEPTH*/);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Stack");
    
    // Create a menu
        glutCreateMenu(menu);

        // Add menu items
        glutAddMenuEntry("Pop", MENU_POP);
        glutAddMenuEntry("Push", MENU_PUSH);
       // glutAddMenuEntry("Spotlight", MENU_SPOT);
      //  glutAddMenuEntry("Blend 'em all", MENU_BACK_FRONT);

        // Associate a mouse button with menu
        glutAttachMenu(GLUT_RIGHT_BUTTON);
    
    glutReshapeFunc(myReshape);
    //glutSpecialFunc(keyControl);
    //glutIdleFunc(idler);
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    
    return 0;
}
