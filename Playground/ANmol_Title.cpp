#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
using namespace std;
static GLfloat spin=45.0,spin1=200.0,bail=1.0,ball=1.0,bat_ang=0;
int ball_hit=0;
enum DIRECTION{LEFT,RIGHT,DOWN,STOP}HIT=STOP;
const float DEG2RAD = 3.14159/180;

void drawCircle(float radius)
{
  glBegin(GL_LINE_LOOP);

  for (int i=0; i < 360; i++)
  {
     float degInRad = i*DEG2RAD;
     glVertex2f(cos(degInRad)*radius,sin(degInRad)*radius);
  }

  glEnd();
}
void reset()
{
    spin=45.0,spin1=200.0,bail=1.0,ball=1.0,bat_ang=0;
    HIT=STOP;
    ball_hit=0;
    glutPostRedisplay();
}


void Sprint( int x, int y, char *st)
{
int l,i;

l=strlen( st ); // see how many characters are in text string.
glRasterPos2i( x, y); // location to start printing text
for( i=0; i < l; i++)  // loop until i is greater then l
{
glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, st[i]); // Print a character on the screen
}

}

void display()
{
glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//CODE FOR BOUNDRY   
glColor3f(1.0,1.0,1.0);
glLineWidth(5.0);
glBegin(GL_LINES);
glVertex2f(20.0,1.0);
glVertex2f(10.0,50.0);
glVertex2f(10.0,50.0);
glVertex2f(1.0,200.0);
glVertex2f(1.0,200.0);
glVertex2f(1.0,350.0);
glVertex2f(1.0,350.0);
glVertex2f(10.0,475.0);
glVertex2f(10.0,475.0);
glVertex2f(30.0,525.0);
glVertex2f(30.0,525.0);
glVertex2f(70.0,525.0);
glVertex2f(70.0,525.0);
glVertex2f(85.0,475.0);
glVertex2f(85.0,475.0);
glVertex2f(95.0,350.0);
glVertex2f(95.0,350.0);
glVertex2f(95.0,100.0);
glVertex2f(95.0,100.0);
glVertex2f(85.0,1.0);
glVertex2f(85.0,1.0);
glVertex2f(20.0,1.0);
glEnd();

//CODE FOR PITCH
glColor3f(0.5,0.7,0.0);
glBegin(GL_POLYGON);
  glVertex3f(45.0,405.0,0.0); 
  glVertex3f(45.0,132.0,0.0);
  glVertex3f(55.0,132.0,0.0);
  glVertex3f(55.0,405.0,0.0);
glEnd();
//CODE FOR LBW REFERENCE LINE
glColor3f(1.5,1.5,0.0);
glBegin(GL_POLYGON);
glVertex2f(49.0,187.0);
glVertex2f(51.0,187.0);
  glVertex2f(51.0,370.0);
glVertex2f(49.0,370.0);
glEnd();
//CODE FOR CREASE and bat
  glColor3f(1.0,1.0,1.0);
  glBegin(GL_LINES);
  glVertex2f(40.0,350.0);
  glVertex2f(60.0,350.0);
  glVertex2f(40.0,187.0);
  glVertex2f(60.0,187.0);
glVertex2f(45.0,370.0);
glVertex2f(55.0,370.0);
  glVertex2f(45.0,157.0);
glVertex2f(55.0,157.0);
glVertex2f(45.0,405.0);
glVertex2f(45.0,350.0);
glVertex2f(55.0,405.0);
glVertex2f(55.0,350.0);
glVertex2f(45.0,132.0);
glVertex2f(45.0,187.0);
glVertex2f(55.0,132.0);
  glVertex2f(55.0,187.0);
glEnd();


                 
//CODE FOR WICKETS ON STRIKER SIDE
glBegin(GL_LINES);
//FIRST WICKET
glColor3f(0.9,0.9,0.9);
glVertex2f(51.0,410.0);
glVertex2f(51.0,370.0);
  
//SECOND WICKET
  glColor3f(0.9,0.9,0.9);
glVertex2f(50.0,410.0);
glVertex2f(50.0,370.0);
 
//THIRD WICKET
glColor3f(0.9,0.9,0.9);
  glVertex2f(49.0,410.0);
glVertex2f(49.0,370.0);

  glEnd();
glPushMatrix();

glRotatef(bat_ang,0,1,1);

glBegin(GL_QUADS);
                 glColor3f(1.0,0.7,0.4);
                 glVertex2f(48,350);
                 glVertex2f(50.25,350);
                 glVertex2f(50.25,390);
                 glVertex2f(48,390);

                 glColor3f(1.0,0.4,0.4);
                 glVertex2f(48.75,390);
                 glVertex2f(49.5,390);
                 glVertex2f(49.5,405);
                 glVertex2f(48.75,405);
                 
                 
glEnd();
glColor3f(0.9,0.9,0.9);
glPopMatrix();
//CODE FOR WICKET ON NON STRIKER SIDE
glBegin(GL_LINES);
//FIRST WICKET
glColor3f(0.9,0.9,0.9);
  glVertex2f(51.0,157.0);
glVertex2f(51.0,197.0);
  glColor3f(0.0,0.0,0.0);
  glVertex2f(51.0,157.0);
glVertex2f(49.0,177.0);
//SECOND WICKET
glColor3f(0.9,0.9,0.9);
  glVertex2f(50.0,157.0);
glVertex2f(50.0,197.0);
glColor3f(0.0,0.0,0.0);
  glVertex2f(50.0,157.0);
glVertex2f(48.0,177.0);
//THIRD WICKET
glColor3f(0.9,0.9,0.9);
  glVertex2f(49.0,157.0);
glVertex2f(49.0,197.0);
  glColor3f(0.0,0.0,0.0);
  glVertex2f(49.0,157.0);
glVertex2f(47.0,177.0);
glEnd();
//CODE FOR BAILS
glColor3f(1.0,1.0,1.0);
glLineWidth(1.0);
glBegin(GL_LINES);
glVertex2f(49.0,197.0);
glVertex2f(49.2,197.0);
glEnd();
  glLineWidth(5.0);
glBegin(GL_LINES);
glVertex2f(49.2,197.0);
glVertex2f(49.8,197.0);
glEnd();
glLineWidth(1.0);
glBegin(GL_LINES);
glVertex2f(49.8,197.0);
glVertex2f(50.0,197.0);
glEnd();
glLineWidth(1.0);
glBegin(GL_LINES);
glVertex2f(50.0,197.0);
glVertex2f(50.2,197.0);
glEnd();
glLineWidth(5.0);
glBegin(GL_LINES);
glVertex2f(50.2,197.0);
glVertex2f(50.8,197.0);
glEnd();
glLineWidth(1.0);
glBegin(GL_LINES);
glVertex2f(50.8,197.0);
glVertex2f(51.0,197.0);
glEnd();
if(bail==1.0)
{
 glLineWidth(1.0);
 glBegin(GL_LINES);
 glVertex2f(49.0,410.0);
 glVertex2f(49.2,410.0);
 glEnd();
     glLineWidth(5.0);
 glBegin(GL_LINES);
     glVertex2f(49.2,410.0);
 glVertex2f(49.8,410.0);
 glEnd();
 glLineWidth(1.0);
 glBegin(GL_LINES);
 glVertex2f(49.8,410.0);
 glVertex2f(50.0,410.0);
 glEnd();
     glLineWidth(1.0);
 glBegin(GL_LINES);
 glVertex2f(50.0,410.0);
 glVertex2f(50.2,410.0);
 glEnd();
 glLineWidth(5.0);
 glBegin(GL_LINES);
 glVertex2f(50.2,410.0);
 glVertex2f(50.8,410.0);
 glEnd();
 glLineWidth(1.0);
 glBegin(GL_LINES);
 glVertex2f(50.8,410.0);
 glVertex2f(51.0,410.0);
 glEnd();
}

  glEnd();
//MESSAGE DISPLAY
glColor3f(0.0,0.0,0.0);
Sprint(10, 100, "press left mouse button to move ball");


//CODE FOR BALL AND ITS TRANSLATION
  if(ball==1.0)
{
 glPushMatrix();
 glTranslatef(spin,spin1,0.0);//specify the position where the translation should start.
 glColor3f(1.0,0.0,0.0); 
 glutSolidSphere(1.58,400,421);//ball
 
 glPopMatrix();
 glutSwapBuffers();
}
glFlush();
}
//CODE FOR MOVEMENT OF BALL BEFORE PITCHING.
void spindisplay()
{
   
  if(spin1<350 && !ball_hit)
               spin1=spin1+1.0;
               else
               {
                   ball_hit=1;
                   
                   if(HIT==RIGHT)
                   {
                                spin=spin+1.0;
                                bat_ang=.80;
                   }
                   else if(HIT==LEFT)
                   {
                                spin=spin-1.0;
                                bat_ang=-.80;
                   }
                   else if(HIT==DOWN)
                   {
                                spin1=spin1-10;
                                
                   }
                   else if(HIT==STOP)
                   {
                       spin1=350;
                       spin=50;
                   }
   
               }

  glutPostRedisplay();
}
//CODE FOR MOVEMENT OF BALL AFTER PITCHING
/*void spindisplayy()
{   
static GLfloat spiny=spin1,spinx=spin;
ball=0.0;
if(spinx>=49.0&&spinx<=51.0)
{   
glColor3f(0.0,0.0,0.0);
Sprint(53,310,"pitched inside");
}
else
{   
glColor3f(0.0,0.0,0.0); 
Sprint(30,260,"pitched outside");
}
  glPushMatrix();
glTranslatef(spinx,spiny,-15.0);
glColor3f(1.0,0.0,0.0); 
glutSolidSphere(1.58,400,421);
glPopMatrix();
glutSwapBuffers();
spiny=spiny+0.5;
if(spinx>=49.0&&spinx<=51.0&&spiny>=410.0)
{
bail=0.0;//make the bails disappear.
}
glutPostRedisplay();

}*/
//CODE FOR MOUSE INTERACTION
void mouse(int button,int state,int x,int y)
{
switch(button)
{
case GLUT_LEFT_BUTTON: 
if(state==GLUT_DOWN)
glutIdleFunc(spindisplay);
break;

  case GLUT_RIGHT_BUTTON:

if(state==GLUT_DOWN)
      glutIdleFunc(NULL);
      spin=45.0,spin1=200.0,bail=1.0,ball=1.0;
break;




default:
break;
}
}


void splKeys(int c, int x, int y)
{
    if(!ball_hit)
    switch(c)
    {
             case GLUT_KEY_LEFT:
                  HIT=LEFT;
                  break;
             case GLUT_KEY_RIGHT:
                  HIT=RIGHT;
                  break;
             case GLUT_KEY_DOWN:
                  HIT=DOWN;
                  break;
             case GLUT_KEY_UP:
                  HIT=STOP;
                  break;
    }
}
void normKeys(unsigned char c, int x, int y)
{
    switch(c)
    {
             case 'r':
             case 'R':
                  reset();
                  break;
    }
}
             
    
void *currentfont;
//FUNCTION TO SELECT BITMAP FONT
void setFont(void *font)
{
     currentfont=font;
}
//FUNCTION TO DRAW BITMAP string at (x,y)
void drawstring(GLfloat x,GLfloat y,char *string)
{
   char *c;
   glRasterPos2f(x,y);

   for(c=string;*c!='\0';c++)
   {
                              glutBitmapCharacter(currentfont,*c);
   }
}
void title_display()
{
	glClear(GL_COLOR_BUFFER_BIT);
     glLineWidth(3.0);
     glColor3f(0.0,0.0,0.0);
    
     glBegin(GL_LINE_LOOP);
                           glVertex2f(10,10);
                           glVertex2f(10,490);
                           glVertex2f(490,490);
                           glVertex2f(490,10);
     glEnd();
     
     setFont(GLUT_BITMAP_HELVETICA_18);
     int adjust=700;
     glColor3f(1.0,0.0,0.0);
     //glColor3fv(get_color(COLOR_TITLE_H1));
     drawstring(100,440,"CENTRE OF GRAVITY DOLL");
     

     glColor3f(0.0,0.0,1.0);
     //glColor3fv(get_color(COLOR_TITLE_H2));
     drawstring(100,400,"Submitted by");

     //delay();
     glColor3f(0.0,1.0,0.0);
     //glColor3fv(get_color(COLOR_TITLE_TEXT1));
     drawstring(100,360,"Chirag Ravindra");
     
     //delay();
     
     //glColor3f(0.0,1.0,0.0);
     drawstring(100,320,"VI CSE A");
     //delay();

     //glColor3f(0.0,1.0,0.0);
     drawstring(100,280,"1BG11CS027");
    
     //delay();
     //glColor3fv(get_color(COLOR_TITLE_TEXT2));
     setFont(GLUT_BITMAP_HELVETICA_12);
     glColor3f(1.0,1.0,0.0);
     drawstring(100,250,"Right click for options");
     //glutPostRedisplay();
glFlush();
}

void cricket()
{
	
glEnable(GL_DEPTH_TEST);
glutInitDisplayMode(GLUT_DOUBLE|GLUT_RGB|GLUT_DEPTH);
glutInitWindowSize(500,500);
  glutInitWindowPosition(30,30);
glutCreateWindow("ppp");
glClearColor(0.0,0.6,0.0,0.0);
glOrtho(0.0,100.0,0.0,550.0,-15.0,50.0);
glutDisplayFunc(display);
glutSpecialFunc(splKeys);
glutKeyboardFunc(normKeys);
glutMouseFunc(mouse);

}

void title_menu(int choice)
{
     switch(choice)
     {
                   case 1:
                        cricket();
                        break;
                   case 0:
                        exit(0);
                        break;
     }
}
//Title INITIALIZER
void titleInit()
{
     
     glClearColor(1,1,1,0);
     glClear(GL_COLOR_BUFFER_BIT);
     glViewport( 0,0, 500, 500 );
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0,500,0,500);
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     //glEnable(GL_DEPTH_TEST);
    
}
int WIN_TITLE;     
void title()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    WIN_TITLE=glutCreateWindow("Computer Graphics Project (1BG11CS027)");
    glutDisplayFunc(title_display);
    glutCreateMenu(title_menu);
    glutAddMenuEntry("Start Program",1);
    glutAddMenuEntry("Exit",0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    titleInit();
}


int main(int argc,char**argv)
{
glutInit(&argc,argv);
title();
glutMainLoop();
return(0);
}

