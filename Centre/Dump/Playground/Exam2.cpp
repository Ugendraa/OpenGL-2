#include<iostream>
#include<gl/glut.h>
using namespace std;

GLfloat winXmin=0, winXmax=100, winYmin=0, winYmax=100;
GLfloat clipWinbuff=130;

GLfloat x0,y0,x1,y1,x0Clip,y0Clip,x1Clip,y1Clip;

bool liangBarsky()
{
	GLfloat te=0, tl=1;
	GLfloat dx=x1-x0, dy=y1-y0;
	GLfloat p,q,r;
	
	for(int i=0; i<4 ; i++)
	{
		switch(i)
		{
			case 0:
				p=-dx; q=-(winXmin-x0); r=q/p;
				break;
			case 1:
				p=dx; q=(winXmax-x0); r=q/p;
				break;
			case 2:
				p=-dy; q=-(winYmin-y0); r=q/p;
				break;
			case 3:
				p=dy; q=(winYmax-y0); r=q/p;
				break;
		}
		
		if(p==0 && q<0) return false;
		else if(p < 0)
		{
			if(r>tl) return false;
			if(r>te) te=r;
		}
		else if(p > 0)
		{
			if(r<te) return false;
			if(r<tl) tl=r;
		}
		
		
			
	}
	
	x0Clip=x0+te*dx; y0Clip=y0+te*dy;
	x1Clip=x0+tl*dx; y1Clip=y0+tl*dy;
	
	return true;
}

void drawWindow(GLfloat xmin, GLfloat ymin, GLfloat xmax, GLfloat ymax)
{
	glColor3f(1,0,0);
	glBegin(GL_LINE_LOOP);
		glVertex2f(xmin,ymin);
		glVertex2f(xmax,ymin);
		glVertex2f(xmax,ymax);
		glVertex2f(xmin,ymax);
	glEnd();
}

void drawLine(GLfloat x0, GLfloat y0, GLfloat x1, GLfloat y1)
{
	
	glBegin(GL_LINES);
		glVertex2f(x0,y0);
		glVertex2f(x1,y1);
	glEnd();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	drawWindow(winXmin,winYmin,winXmax,winYmax);
	drawWindow(winXmin+clipWinbuff,winYmin+clipWinbuff,winXmax+clipWinbuff,winYmax+clipWinbuff);
	
	glColor3f(0,0,0);
	drawLine(x0,y0,x1,y1);
	
	glColor3f(.4,.7,0);
	if(liangBarsky()) drawLine(x0Clip+clipWinbuff,y0Clip+clipWinbuff,x1Clip+clipWinbuff,y1Clip+clipWinbuff);
	glFlush();
}

void myReshape(int w, int h)
{
	GLfloat aspect;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(w<=h)
	{
		if(w!=0) aspect=(GLfloat)h/(GLfloat)w;
		else aspect=h;
		
		glOrtho(-100,300,-100,(-100 + 400*aspect),-1,1);
	}
	else
	{
		if(h!=0) aspect=(GLfloat)w/(GLfloat)h;
		else aspect=w;
		
		glOrtho(-100,(-100 + 400*aspect),-100,300,-1,1);
	}
	
}

void myInit()
{
	glClearColor(1,1,1,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-100,300,-100,300,-1,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main()
{
	cout<<"\nClipwindow:<0,0,100,100> \nEnter <x0 y0 x1 y1> :\n";
	cin>>x0>>y0>>x1>>y1;
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(400,400);
	glutCreateWindow("Liang Barsky");
	glutDisplayFunc(display);
	glutReshapeFunc(myReshape);
	myInit();
	glutMainLoop();
	return 0;
}
