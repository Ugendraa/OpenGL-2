#include<iostream>
#include"ak.h"
#include "Colors.h"
#include "GLNumbers.h"
#include<GL/glut.h>
#include<math.h>
using namespace std;
GLfloat wleft=0.0,wright=250.0,wbottom=0.0,wtop=250.0;
GLfloat wwidth=wright-wleft;
GLfloat wheight=wtop-wbottom;
//GLfloat xc,yc;
GLfloat div_size=10;
int div_num;



GLfloat PointSize=10.0;

COLORS node_color= black;
COLORS arrow_color=black;
COLORS number_color= white;
COLORS bg_color= yellow;

void draw_node(struct avl_node *node,GLfloat x,GLfloat y)
{
     GLfloat adjust=0,scale=0.1;
     glPointSize(PointSize);
     //glPointSize(10);
     glColor3fv(get_color(node_color));
     glBegin(GL_POINTS);
                        glVertex2f(x,y);
     glEnd();
     glColor3fv(get_color(node_color));
     print_num(node->data,scale,x-adjust,y-adjust);
}
 
void draw_arrow(GLfloat x1,GLfloat y1,GLfloat x2,GLfloat y2)
{
     glColor3fv(get_color(arrow_color));
     glBegin(GL_LINE_LOOP);
                          glVertex2f(x1,y1);
                          glVertex2f(x2,y2);
     glEnd();
}
int vals[9]={1,2,3,4,5,6,7,8,9};
avlTree T(vals,9);
GLfloat nDivX=pow(2,9)*2+1;
GLfloat nDivY=9*2+1;
int divX=wwidth/nDivX;
int divY=wheight/nDivY;

void reInitWindowVariables()
{
     GLfloat nDivX=pow(2,T.height(root))*2+1;
     GLfloat nDivY=T.height(root)*2+1;
     int divX=wwidth/nDivX;
     int divY=wheight/nDivY;
}
void draw_tree(struct avl_node *node,int level,GLfloat x,GLfloat y,GLfloat ntop)
{
     
    GLfloat xc=x,yc=y; 
    draw_node(node,xc,yc);
     
    GLfloat ychild=yc-(2*divY);
    GLfloat dSib=pow(2,T.height(root)-level+1)-1;
    
    if(node->left)
    {
              GLfloat xchild= (xc-dSib/2);
              draw_arrow(xc,yc,xchild,ychild);
              draw_tree(node->left,level+1,xchild,ychild,ychild);
    }
     if(node->right)
    {
              //GLfloat xchild= (right+xc)/2,ychild=ntop-div_size;
              GLfloat xchild= (xc+dSib/2);
              draw_arrow(xc,yc,xchild,ychild);
              draw_tree(node->right,level+1,xchild,ychild,ychild);
    }
    
   
}


void myinit()
{
     glClearColor(0.5,0.0,0.0,0.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(wleft,wright,wbottom,wtop);
     glMatrixMode(GL_MODELVIEW);
}



     

void display()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     
     

     
     draw_tree(root,0,wwidth/2,wtop-100,wtop-100);
     T.display(root, 1);
     glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB /*| GLUT_DEPTH*/);
    glutInitWindowSize(wright-wleft, wtop-wbottom);
    glutCreateWindow("Stack");
    //glutReshapeFunc(myReshape);
    //glutSpecialFunc(keyControl);
    //glutIdleFunc(idler);
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    
    return 0;
}
