#include<GL/glut.h>
#include<GL/gl.h>
#include<iostream>
#include<stdio.h>
using namespace std;
int n;
void myinit();
void display();
void tetraDiv(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d,int m);
void tetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d);
void triangle(GLfloat *a,GLfloat *b,GLfloat *c);
int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowPosition(0,0);
	glutInitWindowSize(300,300);
	glutCreateWindow("3d");
	glutDisplayFunc(display);
	myinit();
	cout<<"Enter the value of n:";
	cin>>n;
	glutMainLoop();
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	GLfloat v[4][3]={{0,0,0},{50,0,0},{25,50,0},{25,25,21}};
	glBegin(GL_TRIANGLES);
	tetraDiv(v[0],v[1],v[2],v[3],n);
	glEnd();
	glFlush();
}
void tetraDiv(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d,int m)
{
	GLfloat mid[6][3];
	if(m>0)
	{
		for(int i=0;i<=2;i++)
		{
			mid[0][i]=(a[i]+b[i])/2;
			mid[1][i]=(a[i]+d[i])/2;
			mid[2][i]=(a[i]+c[i])/2;
			mid[3][i]=(d[i]+b[i])/2;
			mid[4][i]=(c[i]+b[i])/2;
			mid[5][i]=(d[i]+c[i])/2;
		}
		tetraDiv(a,mid[0],mid[2],mid[1],m-1);
		tetraDiv(mid[0],b,mid[4],mid[3],m-1);
		tetraDiv(mid[2],mid[4],c,mid[5],m-1);
		tetraDiv(mid[1],mid[3],mid[5],d,m-1);
	}
	else
	tetra(a,b,c,d);
}
void tetra(GLfloat *a,GLfloat *b,GLfloat *c,GLfloat *d)
{
	glColor3f(0,1,1);
	triangle(a,b,c);
	glColor3f(0,1,0);
	triangle(a,c,d);
	glColor3f(0,0,1);
	triangle(c,d,b);
	glColor3f(1,1,0);
	triangle(a,d,b);
}
void triangle(GLfloat *a,GLfloat *b,GLfloat *c)
{
	glVertex3fv(a);
	glVertex3fv(b);
	glVertex3fv(c);
}
void myinit()
{
	glClearColor(1,1,1,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-50,50,-50,50,-50,50);
	glMatrixMode(GL_MODELVIEW);

}
