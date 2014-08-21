#include<iostream>
#include<GL/glut.h>
#include<math.h>
using namespace std;

static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
static GLfloat y1Rot = 0.0f;

static GLfloat xRestore = 0.015f;
static GLfloat yRestore = 0.015f;



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

GLfloat color[21][3]={
{0,0,0},
{255,255,255},
        
{255,239,213},
        
        
{000,191,255},
{000,191,255},
        
{000,100,000},
{154,205,050},
        
{255,255,000},
{255,215,000},
        
{205,92,92},
{139,69,19},
{244,164,96},
{210,180,140},
        
{178,34,34},
{255,140,000},
{255,000,000},
{199,021,133},
        
{255,218,185},
{238,207,161},
{139,121,94},
{139,000,000}};

void set_color(GLfloat vec[],COLORS c)
{
     vec[0]=color[c][0]/255;
     vec[1]=color[c][1]/255;
     vec[2]=color[c][2]/255;
}
 GLfloat vec[3];
GLfloat* get_color(COLORS c)
{
        
         vec[0]=color[c][0]/255;
         vec[1]=color[c][1]/255;
         vec[2]=color[c][2]/255;
         return vec;
}



// angle of rotation for the camera direction
float angle=0.0;
// actual vector representing the camera's direction
float lx=0.0f,lz=-1.0f;
// XZ position of the camera
float x=0.0f,z=5.0f;

void camInit()
{
     // angle of rotation for the camera direction
angle=0.0;
// actual vector representing the camera's direction
lx=0.0f;
lz=-1.0f;
// XZ position of the camera
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

void mouse(int btn, int mstate, int x, int y)
{
     if(btn==GLUT_LEFT_BUTTON && mstate==GLUT_DOWN) 
     {
                              //if(state==START) state=STOP;
                             // else state=START;
     }
     //if(btn==GLUT_MIDDLE_BUTTON && state=GLUT_DOWN) axis=1;
     if(btn==GLUT_RIGHT_BUTTON && mstate==GLUT_DOWN)
     {
                            //   if(rot==START) rot=STOP;
                            //   else rot=START;
     } 
    
     
}

void idler()
{
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


void RenderScene(void)
{
     GLUquadricObj *Obj;
     
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glLoadIdentity();
	// Set the camera
	gluLookAt(	x, 1.0f, z,
			x+lx, 1.0f,  z+lz,
			0.0f, 1.0f,  0.0f);
  
     
     glPushMatrix();
                    glTranslatef(0.0f, -1.0f, -5.0f);
                     // Draw ground
	                 glColor3fv(/*0.7f, 0.4f, 0.0f*/get_color(sandy_brown));
	                 glPushMatrix();
	                 glTranslatef(0.0f, -0.35f, 0.0f);
	                 glBegin(GL_QUADS);
		                               glVertex3f(-10.0f, 0.0f, -10.0f);
		                               glVertex3f(-10.0f, 0.0f,  10.0f);
		                               glVertex3f( 10.0f, 0.0f,  10.0f);
		                               glVertex3f( 10.0f, 0.0f, -10.0f);
                    glEnd();
                    glPopMatrix();
                    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
                    glRotatef(yRot, 0.0f, 0.0f, 1.0f);
                    glRotatef(y1Rot, 0.0f, 0.0f, 1.0f);
                    
                    Obj = gluNewQuadric();
                    gluQuadricNormals(Obj, GLU_SMOOTH);
                    
                    
                    glPushMatrix();
                            //head       
                            glColor3fv(get_color(skin2));
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
                                           glColor3fv(get_color(yellow_green));
                                           glTranslatef(0.0f, 0.0f, 0.0f);
                                           glRotatef(-90,1,0,0);
                                           
                                           gluCylinder(Obj, 0.3f, 0.0f, 1, 26, 2);
                            glPopMatrix();
                            
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

	float fraction = 0.1f;

	switch (key) {
		case 'a' :
        case 'A' :
			angle -= 0.01f;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case 'd' :
        case 'D' :
			angle += 0.01f;
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
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Centre of Gravity Doll");
    glutReshapeFunc(myReshape);
    glutSpecialFunc(keyControl);
    glutKeyboardFunc(processKeys);
    glutIdleFunc(idler);
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    
    return 0;
}
