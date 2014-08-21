#include<gl/glut.h>

void drawObj( GLfloat tx, GLfloat ty, GLfloat tz,
			  GLfloat sx, GLfloat sy, GLfloat sz) {
			  	
			  	glPushMatrix();
			  		glTranslatef(tx,ty,tz);
			  		glScalef(sx,sy,sz);
			  		glutSolidCube(1.0);
			  	glPopMatrix();
}

void renderScene()
{
	//Two walls, Floor
	drawObj(0.0,0.0,0.5,1,1,0.04); //x-y plane
	drawObj(-0.5,0.0,0.0,0.04,1,1); //y-z plane
	drawObj(0.0,-0.5,0.0,1,0.04,1);//x-z plane
//obj(0,0,0.5,1,1,0.04);  // three walls
//obj(0,-0.5,0,1,0.04,1);
//obj(-0.5,0,0,0.04,1,1);	
	drawObj(0,-0.3,0,0.02,0.2,0.02);   // four table legs
	drawObj(0,-0.3,-0.4,0.02,0.2,0.02);
	drawObj(0.4,-0.3,0,0.02,0.2,0.02);
	drawObj(0.4,-0.3,-0.4,0.02,0.2,0.02);	
	
	drawObj(0.2,-0.18,-0.2,0.6,0.02,0.6);  // table top



	glTranslated(0.3,-0.1,-0.3);
	glutSolidTeapot(0.09);
	
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
	//glPushMatrix();
	glTranslatef(1,1,1);
	//glRotatef(10,-1,0,0);
    //glRotatef(50,0,1,0);
	//glRotatef(5.5,0,0,-1);
	
	glRotated(50,0,1,0); 
	glRotated(10,-1,0,0);
	glRotated(11.7,0,0,-1);


	
	
	
	renderScene();
	//glPopMatrix();
	glFlush();
}
void reshape(int w, int h)
{
	GLfloat aspect;
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	if(h<=w)
	{
		if(h!=0)
			aspect=(GLfloat)w/(GLfloat)h;
		else
			aspect=w;
		
		glOrtho(0.0,aspect*2.0,0.0,2.0,2,-2);
	}
	else
	{
		if(w!=0)
			aspect=(GLfloat)h/(GLfloat)w;
		else
			aspect=h;
		
		glOrtho(0.0,2.0,0.0,aspect*2.0,2,-2);
	
	}
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void myInit()
{
	glClearColor(0,0,0,1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0,3.0,0.0,3.0,3,-3);
	glMatrixMode(GL_MODELVIEW);
	
	glShadeModel(GL_SMOOTH);
	
	GLfloat mat_ambient[]={.7,.7,.7,1};
	GLfloat mat_specular[]={1,1,1,1};
	GLfloat mat_diffuse[]={.9,.9,.9,1};
	GLfloat mat_shininess[]={100};
	
	glMaterialfv(GL_FRONT,GL_AMBIENT,mat_ambient );
	glMaterialfv(GL_FRONT,GL_SPECULAR,mat_specular );
	glMaterialfv(GL_FRONT,GL_DIFFUSE,mat_diffuse );
	glMaterialfv(GL_FRONT,GL_SHININESS,mat_shininess );
	
	GLfloat l_pos[]={2.9,5,1,0};
	GLfloat l_ambient[]={.2,.2,.2,1};
	GLfloat l_specular[]={1,1,1,1};
	GLfloat l_diffuse[]={.9,.9,.9,1};
	glLightfv(GL_LIGHT0,GL_POSITION,l_pos);
	//glLightfv(GL_LIGHT0,GL_AMBIENT,l_ambient);
	//glLightfv(GL_LIGHT0,GL_SPECULAR,l_specular);
	//glLightfv(GL_LIGHT0,GL_DIFFUSE,l_diffuse);
	
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_DEPTH_TEST);
	
	
}


int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB| GLUT_DEPTH );
	glutInitWindowSize(500,500);
	glutCreateWindow("Teapot");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	myInit();
	glutMainLoop();
}
	
	
			  		
			  	
