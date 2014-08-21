#include<iostream>
#include<GL/glut.h>
#include<math.h>
#define NUM_COLORS (21)
//#include"Colors.h"
using namespace std;


enum COLORS
{
        black,
        white,
        
        papaya_whip,
        
        
        deep_sky_blue,
        light_sky_blue,
        
        dark_green,
        yellow_green,
        
        yellow,
        gold,
        
        indian_red,
        saddle_brown,
        sandy_brown,
        tannish,
        
        fire_brick,
        dark_orange,
        red,
        violet_red,
        
        skin1,
        skin2,
        skin3,
        skin4
     
};    

GLfloat color[NUM_COLORS][3]={
        {0,0,0}       /*black*/,
        {255,255,255} /*white*/,
        {255,239,213} /*papaya_whip*/,
        {000,191,255} /*deep_sky_blue*/,
        {000,191,255} /*light_sky_blue*/,
        {000,100,000} /*dark_green*/,
        {154,205,050} /*yellow_green*/,
        {255,255,000} /*yellow*/,
        {255,215,000} /*gold*/,
        {205,92,92}   /*indian_red*/,
        {139,69,19}   /*saddle_brown*/,
        {244,164,96}  /*sandy_brown*/,
        {210,180,140} /*tannish*/,
        {178,34,34}   /*fire_brick*/,
        {255,140,000} /*dark_orange*/,
        {255,000,000} /*red*/,
        {199,021,133} /*violet_red*/,
        {255,218,185} /*skin1*/,
        {238,207,161} /*skin2*/,
        {139,121,94}  /*skin3*/,
        {139,000,000} /*skin4*/
};

GLfloat vec[3];

void set_color(GLfloat vec[],COLORS c)
{
     vec[0]=color[c][0]/255;
     vec[1]=color[c][1]/255;
     vec[2]=color[c][2]/255;
}
 
GLfloat* get_color(COLORS c)
{
        
         vec[0]=color[c][0]/255;
         vec[1]=color[c][1]/255;
         vec[2]=color[c][2]/255;
         return vec;
}


static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
static GLfloat y1Rot = 0.0f;
static const GLfloat restoreSpeed=.04;
static GLfloat xRestore = 0.05f;
static GLfloat yRestore = 0.05f;

float angle=0.0;
float lx=0.0f,lz=-1.0f;
float x=0.0f,z=5.0f;

float deltaAngle = 0.0f;
int xOrigin = -1;

void camInit()
{
     angle=0.0;

     lx=0.0f;
     lz=-1.0f;

     x=0.0f;
     z=5.0f;
}

void myinit()
{
     glClearColor(0.0f,0.7f,1,0.0f);
     glEnable(GL_DEPTH_TEST);
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

void keyControl(int key, int x, int y)
{
     if(key == GLUT_KEY_UP && xRot>-85)
                xRot-= 5.0f;
     
     if(key == GLUT_KEY_DOWN && xRot<85)
                xRot += 5.0f;
     
     if(key == GLUT_KEY_LEFT && yRot<85)
                yRot += 5.0f;
     
     if(key == GLUT_KEY_RIGHT && yRot>-85)
                yRot -= 5.0f;
     
     glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {

	// only start motion if the left button is pressed
	if (button == GLUT_LEFT_BUTTON) {

		// when the button is released
		if (state == GLUT_UP) {
			angle += deltaAngle;
			xOrigin = -1;
		}
		else  {// state = GLUT_DOWN
			xOrigin = x;
		}
	}
}

void idler()
{
     //xRestore=restoreSpeed*(1-(90-((xRot<0)?(-xRot):xRot))/90);
     //yRestore=restoreSpeed*(1-(90-((yRot<0)?(-yRot):yRot))/90);
     if(xRot>0)
     {
            xRot-=xRestore;
     }
     else if(  xRot<0 )
     {
          xRot+=xRestore;
     }
     
     if(yRot>0)
     {
            yRot-=yRestore;
     }
     else if(  yRot<0 )
     {
          yRot+=yRestore;
     }
     
     glutPostRedisplay();
}

void setCamera()
{
     // Set the camera
	gluLookAt(	x, 1.0f, z,
			x+lx, 1.0f,  z+lz,
			0.0f, 1.0f, 0.0f);
}

void drawGround()
{
     glColor3fv(get_color(sandy_brown));
     glPushMatrix();
	                 glTranslatef(0.0f, -0.35f, 0.0f);
	                 glBegin(GL_QUADS);
		                               glVertex3f(-10.0f, 0.0f, -10.0f);
		                               glVertex3f(-10.0f, 0.0f,  10.0f);
		                               glVertex3f( 10.0f, 0.0f,  10.0f);
		                               glVertex3f( 10.0f, 0.0f, -10.0f);
                    glEnd();
     glPopMatrix();
}

void drawToy()
{
     GLUquadricObj *Obj;
     Obj = gluNewQuadric();
     gluQuadricNormals(Obj, GLU_SMOOTH);
                    
                    
     glPushMatrix();
                            //head       
                            glColor3fv(get_color(skin1));
                            gluSphere(Obj, 0.24f, 26, 13);
            
                            // Eyes
                            glPushMatrix();
                                           glColor3fv(get_color(fire_brick));
                                           glTranslatef(0.1f, -0.02f, 0.21f);
                                           gluSphere(Obj, 0.02f, 26, 13);
        
                                           glTranslatef(-0.2f, 0.0f, 0.0f);
                                           gluSphere(Obj, 0.02f, 26, 13);
                            glPopMatrix();
            
                            
     glPopMatrix();
     glPushMatrix();
                            glColor3fv(get_color(violet_red));
                            glRotatef(-90,1,0,0);
                            gluCylinder(Obj, 0.35f, 0.0f, 1, 26, 2);
     glPopMatrix();
     
}
void RenderScene(void)
{
     
     
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glLoadIdentity();
     
     setCamera();
	
  
     
     glPushMatrix();
                    glTranslatef(0.0f, -1.0f, -5.0f);
                    
                    drawGround();
	                 
                    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
                    glRotatef(yRot, 0.0f, 0.0f, 1.0f);
                    glRotatef(y1Rot, 0.0f, 0.0f, 1.0f);
                    
                    drawToy();
                    
                    
                            
     glPopMatrix();
     glutSwapBuffers();
   
}

void display()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     RenderScene();
     
     glutPostRedisplay();

     glFlush();
}
void processKeys(unsigned char key, int xx, int yy) {

	float fraction = 0.5f;

	switch (key) {
		case 'a' :
        case 'A' :
			angle -= 0.05f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case 'd' :
        case 'D' :
			angle += 0.05f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case 'w' :
        case 'W' :
			x += lx * fraction;
			z += lz * fraction;
			break;
		case 's' :
        case 'S' :
             x -= lx * fraction;
			z -= lz * fraction;
			break;
		case 'r' :
        case 'R' :
			camInit();
			break;
			
	}
}
void mouseMove(int x, int y) {

	// this will only be true when the left button is down
	if (xOrigin >= 0) {

		// update deltaAngle
		deltaAngle = (x - xOrigin) * 0.001f;

		// update camera's direction
		lx = sin(angle + deltaAngle);
		lz = -cos(angle + deltaAngle);
	}
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Centre of Gravity Doll");
    glutReshapeFunc(myReshape);
    glutSpecialFunc(keyControl);
    glutMouseFunc(mouse);
    glutMotionFunc(mouseMove);
    glutKeyboardFunc(processKeys);
    glutIdleFunc(idler);
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    
    return 0;
}
