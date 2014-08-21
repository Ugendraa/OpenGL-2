#include<iostream>
#include<GL/glut.h>
#include<GL/gl.h>
#include<stdio.h>
#include<conio.h>
void triangle(GLfloat *a, GLfloat *b, GLfloat *c);
void myinit();
void tetra(GLfloat *a, GLfloat *b, GLfloat *c,GLfloat *d);
void tetradiv(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d, int m);
void display();
int n;
GLfloat v[4][3]= {{0,0,0},{50,0,0},{25,50,0},{25,25,21}};
//GLfloat v[4][3]= {{0,0,0},{0,50,0},{50,25,0},{25,25,50}};
int main( int argc, char *argv[])
{
   glutInit(&argc,argv);
   glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
   glutInitWindowSize(500,500);
   glutInitWindowPosition(0,0);
   glutCreateWindow("Sierpinski");
   glutDisplayFunc(display);
   myinit();
   printf("Enter the value of n:\n");
   scanf("%d",&n);
   glutMainLoop();
  
   return 0;
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glBegin(GL_TRIANGLES);
    tetradiv(v[0],v[1],v[2],v[3],n);
    glEnd();
    glFlush();
}
void tetradiv(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *d, int m)
{
    GLfloat mid[6][3];
    int i;
    if(m>0)
    {
           for(i=0;i<=2;i++)//for(i=1;i<=2;i++) ----------> !! Missing out v[0] !!
           {
                            mid[0][i]=(a[i]+b[i])/2;
                            mid[1][i]=(a[i]+c[i])/2;
                            mid[2][i]=(a[i]+d[i])/2;
                            mid[3][i]=(c[i]+b[i])/2;
                            mid[4][i]=(c[i]+d[i])/2;
                            mid[5][i]=(d[i]+b[i])/2;
           }
           tetradiv(a,mid[0],mid[1],mid[2],m-1);
           tetradiv(mid[0],b,mid[3],mid[5],m-1);
           tetradiv(mid[1],mid[3],c,mid[4],m-1);
           tetradiv(mid[2],mid[5],mid[4],d,m-1);
    }
    else
    tetra(a,b,c,d);
}
void tetra(GLfloat *a, GLfloat *b, GLfloat *c,GLfloat *d)
{
    glColor3f(0,1,1);
    triangle(a,b,c);
    glColor3f(0,0,1);
    triangle(a,d,b);
    glColor3f(0,1,0);
    triangle(a,d,c);
    glColor3f(1,1,0);
   triangle(b,d,c);
}
void triangle(GLfloat *a, GLfloat *b, GLfloat *c)
{
   
    glVertex3fv(a);
    glVertex3fv(b);
    glVertex3fv(c);
    
}
void myinit()
{
    glClearColor(1,1,1,1);
    //glColor3f(1,0,0);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    //gluOrtho2D(0,400,0,400);
    glOrtho(-100,700,-100,500,-100,100);  //-----------------> Large vvalues will make everything smaller. Give values proportionate to your triangle. try the ortho call below
    //glOrtho(-10,100,-10,100,50,-50);
    glMatrixMode(GL_MODELVIEW);
}
    
