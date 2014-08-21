#include<iostream>
#include<gl/glut.h>
using namespace std;

int eno;

struct edge {
	GLfloat x1,x2,y1,y2,xmin,ymin,xmax,ymax,m;
	bool activated;
};

struct edge* ET=NULL;

struct active_edge
{
	struct edge e;
	GLfloat xs;
};


	
struct active_edge* AET=NULL;
int aetEmpty=1;
int aetCount=0;


void sortET()
{
	GLfloat min;
	int pos;
	struct edge temp;
	for(int i=0; i<eno-1 ; i++)
	{
		min=ET[i].ymin;
		pos=i;
		for(int j=i+1;j<eno;j++)
		{
			if(ET[j].ymin<min)
			{
				min=ET[j].ymin;
				pos=j;
			}
		}
		temp=ET[i];
		ET[i]=ET[pos];
		ET[pos]=temp;
	}
}



bool pendingET()
{
	
	for(int i=0; i<eno; i++)
	{
		if(ET[i].activated==0) 
		return true;
	}
	return false;
}

void input()
{
	int n;
	cout<<"\nEnter number of edges: ";
	cin>>n;
	eno=n;
	
	ET=new struct edge[n];
	AET=new struct active_edge[n];
	aetEmpty=1;
	aetCount=0;
	
	cout<<"\nEnter the edge vertices' coordinates <x1 y1 x2 y2> for "<<n<<" edges ( 0 <= x,y <= 500 ): ";
	GLfloat x1,x2,y1,y2;
	for(int i=0; i<n; i++)
	{
		cin>>x1>>y1>>x2>>y2;
		ET[i].activated=0;
		if(y1>y2)
		{
			ET[i].ymin=y2;
			ET[i].xmin=x2;
			ET[i].ymax=y1;
			ET[i].xmax=x1;
		}
		else if(y2>y1)
		{
			ET[i].ymin=y1;
			ET[i].xmin=x1;
			ET[i].ymax=y2;
			ET[i].xmax=x2;
		}
		else
		{
			ET[i].activated=1;
			//continue;
		}
		
		ET[i].x1=x1;
		ET[i].y1=y1;
		ET[i].x2=x2;
		ET[i].y2=y2;
		
		if(ET[i].xmax!=ET[i].xmin) ET[i].m=(ET[i].ymax-ET[i].ymin)/(ET[i].xmax-ET[i].xmin);
		else ET[i].m=0;
	}
	sortET();
}

void removeFromAET(GLfloat s)
{
	for(int i=0;i<aetCount;i++)
	{
		if(AET[i].e.ymax<=s)
		{
			int k=i;
			while(k<aetCount-1)
			{
				AET[k]=AET[k+1];
				k++;
			}
			aetCount--;
			i--;
		}
	}
}
void addToAET(struct edge e)
{
	AET[aetCount].e=e;
	AET[aetCount].xs=e.xmin;
	aetCount++;
}
	

void ETtoAET(GLfloat s)
{
	for(int i=0; i<eno ; i++)
	{
		if(ET[i].ymin<=s && !ET[i].activated)
		{
			addToAET(ET[i]);
			ET[i].activated=1;
		}
	}
}
			
void loadXArray(GLfloat *xarray)
{
	GLfloat inc=1;
	for(int i=0; i<aetCount ; i++)
	{
		if(AET[i].e.m!=0) AET[i].xs+=(inc/AET[i].e.m);
		xarray[i]=AET[i].xs;
	}
	for(int i=0; i<aetCount-1 ; i++)
	{
		GLfloat min=xarray[i];
		int pos=i;
		for(int j=i;j<aetCount;j++)
		{
			if(xarray[j]<min)
			{
				min=xarray[j];
				pos=j;
			}
		}
		GLfloat temp=xarray[i];
		xarray[i]=min;
		xarray[pos]=temp;
	}
}

void fillLine(GLfloat *xarray, GLfloat s)
{
	glBegin(GL_LINES);
		for(int i=0; i<aetCount ; i++)
		{
			glVertex2f(xarray[i],s);
		}
	glEnd();
}
void drawPoly()
{
	glColor3f(0,0,0);
	glBegin(GL_LINES);
		for(int i=0;i<eno;i++)
		{
			glVertex2f(ET[i].x1,ET[i].y1);
			glVertex2f(ET[i].x2,ET[i].y2);
		}
	glEnd();
}
void scanFill()
{
	GLfloat s,inc;
	s=ET[0].ymin;
	inc=1;
	GLfloat xarray[eno];
	glColor3f(1,0,0);
	while(pendingET() || aetCount)
	{
		removeFromAET(s);
		ETtoAET(s);
		s+=inc;
		loadXArray(xarray);
		fillLine(xarray,s);
		//s+=inc;
	
	}

		
}

void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	
	drawPoly();
	scanFill();
	
	glFlush();
}

void myInit()
{
	glClearColor(1,1,1,1);
	glViewport(0,0,500,500);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0,500,0,500,-1,1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(int argc, char **argv)
{
	input();
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutCreateWindow("Scanfill");
	glutDisplayFunc(display);
	myInit();
	glutMainLoop();
	return 0;
}
	
	
