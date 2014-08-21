//CAMERA INITIALIZER
void camInit()
{
     tspd=TRNSPD;
     wspd=WLKSPD;
     angle=0.0;
     lx=0.0f;
     lz=-1.0f;
     x=0.0f;
     z=5.0f;
     invert=1;
     
     
}

//GENERAL INITIALIZER
void myinit()
{
     glClearColor(0.0f,0.7f,1,0.0f);
     glEnable(GL_DEPTH_TEST);
     camInit();
     //if(FULLSCREEN) 
     //glutFullScreen();
     
     
      
}

//WINDOW RESHAPE HANDLER
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

//HANDLER FOR TILTING USING SPECIAL KEYS
void upKeyControl(int key, int x, int y)
{
     if(key == GLUT_KEY_UP)
                restore=1;
     
     if(key == GLUT_KEY_DOWN)
                restore=1;
     
     if(key == GLUT_KEY_LEFT)
                restore=1;
     
     if(key == GLUT_KEY_RIGHT)
                restore=1;
     
     glutPostRedisplay();
}

void keyControl(int key, int x, int y)
{
     if(key == GLUT_KEY_UP && xRot>-rotLim)
     {
            restore=0;
            xRot-= 5.0f;
     }       
     
     if(key == GLUT_KEY_DOWN && xRot<rotLim)
     {
            restore=0;
            xRot += 5.0f;
     }   
                
     
     if(key == GLUT_KEY_LEFT && yRot<rotLim)
     {
            restore=0;
            yRot += 5.0f;
     }   
                
     
     if(key == GLUT_KEY_RIGHT && yRot>-rotLim)
     {
            restore=0;
            yRot -= 5.0f;
     }   
                
     
     glutPostRedisplay();
}

//IDLER : RESTORING FUNCTION
void idler()
{
     if(xRot>0 && restore)
     {
            if(xRot-xRestore>=0) xRot-=xRestore;
            else xRot=0;
     }
     else if(  xRot<0 && restore)
     {
          xRot+=xRestore;
          if(xRot-xRestore<=0) xRot+=xRestore;
          else xRot=0;
     }
     
     if(yRot>0 && restore)
     {
            yRot-=yRestore;
            if(yRot-xRestore>=0) yRot-=yRestore;
            else yRot=0;
     }
     else if(  yRot<0 && restore)
     {
          yRot+=yRestore;
          if(yRot-yRestore<=0) yRot+=yRestore;
          else yRot=0;
     }
     
     glutPostRedisplay();
}



//SET CAMERA VALUES
void setCam()
{
     gluLookAt(	x, 1.0f, z,
			    x+lx, 1.0f,  z+lz,
			    0.0f, invert,  0.0f);
     
}    

//DRAW THE SCENE
void RenderScene(void)
{
     
     get_color(COLOR_WRLD_SKY);
     glClearColor(vec[0],vec[1],vec[2],0.0f);
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     glLoadIdentity();

     setCam();
     
     glPushMatrix();
                    glTranslatef(0.0f, -1.0f, -5.0f);
                    drawGround();
	                if(dollType==CAP_MAN) drawToyCapman();
	                else if(dollType==DANCER) drawToyDancer();
	                
     glPopMatrix();
     
     glutSwapBuffers();
     
   
}

//HANDLER FOR NORMAL KEYBOARD INPUT
void processKeys(unsigned char key, int xx, int yy) {

	float fraction = 0.1f;

	switch (key) {
		case 'a' :
        case 'A' :
			angle -= tspd;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case 'd' :
        case 'D' :
			angle += tspd;
			lx = sin(angle);
			lz = -cos(angle);
			break;
		case 'w' :
        case 'W' :
			x += lx * wspd;
			z += lz * wspd;
			glutPostRedisplay();
			break;
		case 's' :
        case 'S' :
             x -= lx * wspd;
			z -= lz * wspd;
			break;
		case 'r' :
        case 'R' :
			camInit();
			break;
		case '+' :
			xRestore+=.1;
			yRestore+=.1;
			break;
		case '-' :
			xRestore-=.1;
			yRestore-=.1;
			break;
		case '*' :
			xRestore=.02;
			yRestore=.02;
			xRot=0;
			yRot=0;
			break;
		case 27 :     //ESC KEY
             exit(0);
             break;
			
	}
}



void CoG()
{
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Centre of Gravity Doll");
    glutReshapeFunc(myReshape);
    glutSpecialFunc(keyControl);
    glutSpecialUpFunc(upKeyControl);
    glutKeyboardFunc(processKeys);
    menuInit();
    glutIdleFunc(idler);
    glutDisplayFunc(RenderScene);
    myinit();
}
