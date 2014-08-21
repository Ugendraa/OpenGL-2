#include<iostream>
#include<gl/glut.h>
using namespace std;

void drawObj( GLfloat tx, GLfloat ty, GLfloat tz,
			  GLfloat sx, GLfloat sy, GLfloat sz )
{
	glPushMatrix();
		glTranslatef(tx,ty,tz);
		glScalef(sx,sy,sz);
		glutSolidCube(1.0);
	glPopMatrix();
}

void renderScene()
{
	//Walls
	drawObj(0.0,0.0,0.5,1,1,0.04);
	drawObj(0.0,-0.5,0.0,1,0.04,1);
	drawObj(-0.5,0.0,0.0,0.04,1,1);
	
	//Legs
	drawObj(-0.2,-0.3,-0.2,0.02,0.2,0.02);
	drawObj(0.2,-0.3,-0.2,0.02,0.2,0.02);
	drawObj(-0.2,-0.3,0.2,0.02,0.2,0.02);
	drawObj(0.2,-0.3,0.2,0.02,0.2,0.02);
	
	//Table top
	drawObj(0,-0.2,0,0.6,0.02,0.6);
	
	//Teapot
	glTranslatef(0,-0.1,0.05);
	glutSolidTeapot(0.09);
	
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glTranslatef(1,1,1);
	glRotatef(50,0,1,0);
	glRotatef(10,-1,0,0);
	glRotatef(11.7,0,0,-1);
	
	renderScene();
	
	
	glFlush();
}
	

void myReshape(int w, int h)
{
	GLfloat aspect;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	
	if(w <= h)
	{
		if(w!=0)
			aspect=(GLfloat)h/(GLfloat)w;
		else
			aspect=h;
		glOrtho(0.0, 2.0 , 0.0 , aspect*2.0, 2.0, -2.0 );
	}
	else
	{
		if(h!=0)
			aspect=(GLfloat)w/(GLfloat)h;
		else
			aspect=w;
		glOrtho(0.0, aspect*2.0 , 0.0 , 2.0, 2.0, -2.0 );
	}
	
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
		

void myInit()
{
	glClearColor(0,0,0,0);
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	
	GLfloat m_amb[]={.7,.7,.7,1};
	GLfloat l_pos[]={0.5,3,-1,0};
	
	glMaterialfv(GL_FRONT,GL_AMBIENT,m_amb);
	glMaterialf(GL_FRONT,GL_SHININESS,50);
	
	glLightfv(GL_LIGHT0,GL_POSITION,l_pos);
	
}


int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(500,500);
	glutCreateWindow("Teapot");
	glutDisplayFunc(display);
	glutReshapeFunc(myReshape);
	myInit();
	glutMainLoop();
}
		
	
	
	
