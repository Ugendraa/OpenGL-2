#include<iostream>
#include"ak.h"
#include "Colors.h"
#include "GLNumbers.h"
#include<GL/glut.h>
using namespace std;
GLfloat wleft=0.0,wright=800.0,wbottom=0.0,wtop=600.0;
//GLfloat wwleft=wleft,wwright=(wright-wleft)/2,wwbottom=wbottom,wwtop=wbottom+50;
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

void draw_tree(struct avl_node *node,int level,GLfloat left,GLfloat right,GLfloat ntop)
{
    if(root==NULL) return; 
    GLfloat xc=(left+right)/2,yc=ntop; 
    draw_node(node,xc,yc);
    if(node->left)
    {
              GLfloat xchild= (left+xc)/2,ychild=ntop-div_size;
              draw_arrow(xc,yc,xchild,ychild);
              draw_tree(node->left,level+1,left,xc,ychild);
    }
     if(node->right)
    {
              GLfloat xchild= (right+xc)/2,ychild=ntop-div_size;
              draw_arrow(xc,yc,xchild,ychild);
              draw_tree(node->right,level+1,xc,right,ychild);
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
//int vals[9]={9};
//avlTree T(vals,6);
avlTree T;

void node_balance(struct avl_node* root)                                          /*new*/
{
     int bfactor;
     if(root!=NULL)
     {
                bfactor=T.height(root->left)-T.height(root->right);
                if(bfactor > 1)
                {
                           if(
                
     }
}
                        

void insert()
{
     int n;
     cout<<"\nenter an element";
     cin>>n;
     glutPushWindow();
     root=T.insert(root,n);
     broot=T.insertBal(broot,n );
     
     glutPopWindow();
      
      
     glutPostRedisplay();
}

/*void dfs(struct avl_node *node)
{
     int visited[100];
     if(node!=NULL)
     {
                   s.push(node);
                   visited[0]=1;
                   if(node->left)
                   {
                                s.push(node->left); 
                                visited++;
                                
                   }
                   if(node->right)
                   {
                                  
     
  */   
void balance()
{
     root=broot;
}     
void keys(unsigned char c, int x, int y)
{
     void display();
     switch(c)
     {
              case 'i':
              case 'I':
                   glutPushWindow();
                   insert();
                   break;
              case 'b':
              case 'B':
                   balance();
                   glutPostRedisplay();
                   break;
                   
                   
     }
}

void display()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     
     

     
     draw_tree(root,1,wleft,wright,wtop-80);
     if(root!=NULL) T.display(root, 1);
     glFlush();
}

int main(int argc, char *argv[])
{
    int n,a;
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB /*| GLUT_DEPTH*/);
    glutInitWindowSize(int(wright-wleft),int(wtop-wbottom));
    //glutInitWindowSize(int(wwright-wwleft),int(wwtop-wwbottom));
    glutCreateWindow("AVL");
    //a=glutGetWindow();
    //glutCreateSubWindow(a,wwright,wwleft,wwtop,wwbottom);
    //glutReshapeFunc(myReshape);
    glutKeyboardFunc(keys);
    //glutIdleFunc(idler);
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    
    return 0;
}
