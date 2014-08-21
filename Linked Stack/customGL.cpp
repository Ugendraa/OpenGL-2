#include<iostream>
#include"numbers.cpp"
#include<GL/glut.h>
using namespace std;


GLfloat topX = 10;
GLfloat topY = 10;
GLfloat nodeHt = 10;

static GLfloat arrow_width=2;
static GLfloat arrow_height=5;

static GLfloat node_color[3]={.7,.7,.7};



int itoa(int n, char s[]);


void print_num(int num, GLfloat scale=1,GLfloat x=0, GLfloat y=0, GLfloat z=0)
{
              char s[20];
              itoa(num,s);
               glPushMatrix();
                              glColor3f(0,0,0);
                              glTranslatef(x,y,z);
                              glScalef(scale,scale,1);
                              for( int i=0 ; s[i]!='\0' ; i++ )
                              {
                                   glutStrokeCharacter(/*GLUT_STROKE_ROMAN*/GLUT_STROKE_MONO_ROMAN, s[i]);
                              }
               glPopMatrix();
}


void draw_square(GLfloat x, GLfloat y, GLfloat l)
{
     glColor3fv(node_color);
     glBegin(GL_QUADS);
                       glVertex2f(x,y);
                       glVertex2f(x+l,y);
                       glVertex2f(x+l,y+l);
                       glVertex2f(x,y+l);
     glEnd();
     
}

void draw_node(StackElement n)
{
     //ht=119.05 wd= 104.76
      GLfloat scale= (nodeHt/119.05)*.5;
      //int num=0;
      int num=n->data;//s.getval(n);
      draw_square(topX,topY, nodeHt);
      print_num(num,scale,topX,topY);  
                                             
      topY-=(nodeHt+2);
      
}

void draw_arrow()
{
	GLfloat half1=(nodeHt/2);
	GLfloat half2=half1/2;
	GLfloat half3=half2/2;
	topX+=half1;
	
	glBegin(GL_TRIANGLES);
		glVertex2f(topX,topY);
		glVertex2f(topX+half2,topY+half2);
		glVertex2f(topX-half2,topY+half2);
	glEnd();
	
	topY+=arrow_height;
	
	glBegin(GL_QUADS);
		glVertex2f(topX-half3,topY);
		glVertex2f(topX+half3,topY);
		glVertex2f(topX+half3,topY-(arrow_height-half3));
		glVertex2f(topX-half3,topY-(arrow_height-half3));
	glEnd();
}		

void draw_base()
{
	glBegin(GL_QUADS);
		glVertex2f(topX,topY);
		glVertex2f(topX+nodeHt*3,topY);
		glVertex2f(topX+nodeHt*3,topY+nodeHt);
		glVertex2f(topX,topY+nodeHt);
	glEnd();
}
