#include<iostream>
#include<string.h>
#include<GL/glut.h>
using namespace std;

int itoa(int n, char s[])
{
    int i, sign,len;

    if ((sign = n) < 0)  /* record sign */
        n = -n;          /* make n positive */
    i = 0;
    do {       /* generate digits in reverse order */
        s[i++] = n % 10 + '0';   /* get next digit */
    } while ((n /= 10) > 0);     /* delete it */
	len=strlen(s);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    strrev(s);
	return len;
}


void myinit()
{
     glClearColor(0.0,0.0,0.0,0.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0,250.0,0.0,250.0);
     glMatrixMode(GL_MODELVIEW);
}



void print_num(int num, GLfloat scale=1,GLfloat x=0, GLfloat y=0, GLfloat z=0)
{
              char s[20];
              itoa(num,s);
               glPushMatrix();
                              
                              glTranslatef(x,y,z);
                              glScalef(scale,scale,1);
                              for( int i=0 ; s[i]!='\0' ; i++ )
                              {
                                   glutStrokeCharacter(/*GLUT_STROKE_ROMAN*/GLUT_STROKE_MONO_ROMAN, s[i]);
                              }
               glPopMatrix();
}
                                   
                              
               
               

     

void display()
{
     //glScalef(.5,.5,1);
     //glutStrokeCharacter(/*GLUT_STROKE_ROMAN*/GLUT_STROKE_MONO_ROMAN, 'C');
     print_num(23987886,.1,100,100);
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
