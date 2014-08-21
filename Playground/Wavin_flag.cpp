#include<windows.h>
#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
float points[45][45][3];
int wiggle_count =0;
GLfloat xrot;
GLfloat yrot;
GLfloat zrot;
GLfloat hold;
void init(void) 
{
   glClearColor (0.0, 0.0, 0.0, 0.0);   
   glEnable(GL_DEPTH_TEST);
   glShadeModel (GL_SMOOTH);
   glDepthFunc(GL_LEQUAL);								// The Type Of Depth Testing To Do
 
 
   for(int x=0; x<45; x++)
	{
		for(int y=0; y<45; y++)
		{
			points[x][y][0]=float((x/5.0f)-4.5f);
			points[x][y][1]=float((y/5.0f)-4.5f);
			points[x][y][2]=float(sin((((x/5.0f)*40.0f)/360.0f)*3.141592654*2.0f));
		}
	}
}
void display(void)
{

	int x, y;
	float float_x, float_y, float_xb, float_yb;
 
	glClear (GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity ();
 
	glTranslatef(0.0f,0.0f,-12.0f);
	glPushMatrix();
	glColor3f(1.0,.5,.5);
	glTranslatef(-4.5,-1.0f,0.0f);
	glScalef(1,11,1);
    glutSolidCube(1);
    glPopMatrix();
    glColor3f(1.0,1.0,.5);
	glRotatef(xrot,1.0f,0.0f,0.0f);
	glRotatef(yrot,0.0f,1.0f,0.0f);  
	glRotatef(zrot,0.0f,0.0f,1.0f);
	
	
 
	glBegin(GL_QUADS);
	for( x = 0; x < 44; x++ )
	{
		for( y = 0; y < 44; y++ )
		{
			float_x = float(x)/44.0f;
			float_y = float(y)/44.0f;
			float_xb = float(x+1)/44.0f;
			float_yb = float(y+1)/44.0f;
 
			glVertex3f( points[x][y][0], points[x][y][1], points[x][y][2] );
 
			glVertex3f( points[x][y+1][0], points[x][y+1][1], points[x][y+1][2] );
 
            glVertex3f( points[x+1][y+1][0], points[x+1][y+1][1], points[x+1][y+1][2] );
 
			glVertex3f( points[x+1][y][0], points[x+1][y][1], points[x+1][y][2] );
		}
	}
	glEnd();
 
	
 
	Sleep(5);
	glutSwapBuffers();
 
}
void idler()
{
     if( wiggle_count == 2 )
	{
		for(int y = 0; y < 45; y++ )
		{
			hold=points[0][y][2];
			for( int x = 0; x < 44; x++)
			{
				points[x][y][2] = points[x+1][y][2];
			}
			points[44][y][2]=hold;
		}
		wiggle_count = 0;
	}
 
	wiggle_count++;
 
	//xrot+=0.3f;
	//yrot+=0.2f;
	//zrot+=0.4f;
	glutPostRedisplay();
}
void reshape (int w, int h)
{
   glViewport (0, 0, (GLsizei) w, (GLsizei) h); 
   glMatrixMode (GL_PROJECTION);
   glLoadIdentity ();
 
   gluPerspective(60.0, (GLfloat) w/(GLfloat) h, 1.0, 20.0);
 
   glMatrixMode (GL_MODELVIEW);
   glLoadIdentity();
 
   glutPostRedisplay();
}

int main(int argc, char** argv)
{
   glutInit(&argc, argv);
   glutInitDisplayMode (GLUT_RGB | GLUT_DEPTH | GLUT_DOUBLE);
   glutInitWindowSize (500, 500); 
   glutInitWindowPosition (100, 100);
   glutCreateWindow (argv[0]);
   init ();
   glutDisplayFunc(display); 
   glutReshapeFunc(reshape);
   glutIdleFunc(idler);
   //glutKeyboardFunc(keyboard);
 
   glutMainLoop();
   return 0;
}
