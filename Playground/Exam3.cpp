#include<iostream>
#include<gl/glut.h>
using namespace std;

GLfloat v[8][3]=
{ {-1,-1,1}, {1,-1,1},{1,1,1},{-1,1,1},
  {-1,1,-1}, {1,1,-1},{1,-1,-1},{-1,-1,-1}};

GLfloat co[8][3]=
{ {0,0,1}, {1,0,1},{1,1,1},{0,1,1},
  {0,1,0}, {1,1,0},{1,0,0},{0,0,0}};
  
int spin=0,axis=0;
GLfloat theta[3]={0,0,0};

void idler()
{
	
	GLfloat i=0.01;
	if(spin)
	{
		theta[axis]+=i;
		if(theta[axis]>=360) theta[axis]=0;
		
		glutPostRedisplay();
	}
	
}

void mouse(int button, int state, int x, int y)
{
	if(button==GLUT_LEFT_BUTTON && state==GLUT_DOWN)
		spin=(spin+1)%2;
	if(button==GLUT_RIGHT_BUTTON && state==GLUT_DOWN)
		axis=(axis+1)%3;
	
}

void drawSquare(int a, int b, int c, int d)
{
	glBegin(GL_POLYGON);
		glColor3fv(co[a]);
		glVertex3fv(v[a]);
		glColor3fv(co[b]);
		glVertex3fv(v[b]);
		glColor3fv(co[c]);
		glVertex3fv(v[c]);
		glColor3fv(co[d]);
		glVertex3fv(v[d]);
	glEnd();
}

void drawCube()
{
	drawSquare(0,1,2,3);
	drawSquare(1,6,5,2);
	drawSquare(6,7,4,5);
	drawSquare(0,3,4,7);
	drawSquare(3,2,5,4);
	drawSquare(0,7,6,1);
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
//	gluLookAt(0,0,5,0,0,0,0,1,0);
	//glTranslatef(1,1,1);
	glRotatef(theta[0],1,0,0);
	glRotatef(theta[1],0,1,0);
	glRotatef(theta[2],0,0,1);
	
	drawCube();
	//glFlush();
	glutSwapBuffers();
	
}
void myInit()
{
	glClearColor(0,0,0,1);
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

    
    //gluPerspective(50.0, 1.0, 3.0, 7.0);
    //glOrtho(-5,5,-5,5,-2,2);
    glFrustum(-5,5,-5,5,2,200);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,0,5,0,0,0,0,1,0);
	
}

int main()
{
	glutInitDisplayMode(GLUT_DEPTH|GLUT_RGB|GLUT_DOUBLE);
	glutInitWindowSize(700,700);
	glutCreateWindow("Cube");
	glEnable(GL_DEPTH_TEST);
	glutDisplayFunc(display);
	glutIdleFunc(idler);
	glutMouseFunc(mouse);
	glutReshapeFunc(myReshape);
	glutMainLoop();
	myInit();
	return 0;
}
