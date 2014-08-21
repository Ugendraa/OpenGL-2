#include<iostream>
#include<gl/glut.h>
using namespace std;

GLfloat color[4][3]={{1,0,0},{1,1,0},{0,1,0},{0,0,1}};

GLfloat v[4][3]={{0,0,0},{100,0,0},{50,100,0},{50,50,100}};


void drawTriangle(GLfloat* a,GLfloat* b ,GLfloat* c)
{
	glBegin(GL_TRIANGLES);
		glVertex3fv(a);
		glVertex3fv(b);
		glVertex3fv(c);
	glEnd();
}

void drawTetra(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *o)
{
	glColor3fv(color[0]);
	drawTriangle(a,c,b);
	
	glColor3fv(color[1]);
	drawTriangle(a,b,o);
	
	glColor3fv(color[2]);
	drawTriangle(b,c,o);
	
	glColor3fv(color[3]);
	drawTriangle(a,o,c);
}

void drawGasket(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *o, int k)
{
	
	if(k>0)
	{
		GLfloat oam[3],obm[3],ocm[3],abm[3],acm[3],bcm[3];
		for(int i=0; i<3; i++)
		{
			oam[i]=(o[i]+a[i])/2;
			obm[i]=(o[i]+b[i])/2;
			ocm[i]=(o[i]+c[i])/2;
			abm[i]=(b[i]+a[i])/2;
			acm[i]=(c[i]+a[i])/2;
			bcm[i]=(b[i]+c[i])/2;
		}
		drawGasket(a,abm,acm,oam,k-1);
		drawGasket(abm,b,bcm,obm,k-1);
		drawGasket(acm,bcm,c,ocm,k-1);
		drawGasket(oam,obm,ocm,o,k-1);
	}
	else
		drawTetra(a,b,c,o);
}
int n;			
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	glTranslatef(30,30,0);
	drawGasket(v[0], v[1], v[2], v[3], n);
	glFlush();
}

void myInit()
{
	glClearColor(1,1,1,1);
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,150,0,150,-150,150);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main()
{
	cout<<"\nEnter number of recursions: ";
	cin>>n;
	
	glutInitDisplayMode(GLUT_RGB|GLUT_DEPTH);
	glutInitWindowSize(700,700);
	glViewport(0,0,700,700);
	glutCreateWindow("Gasket 3D");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
	return 0;
}
			
	
		
