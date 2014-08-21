#include<windows.h>
#include <glut.h>
// OpenGL toolkit

// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat xRot1 = 0.0f;
static GLfloat yRot1 = 0.0f;
static GLfloat yRot3 = 0.0f;
static GLfloat yRot = 0.0f;
static GLfloat y1Rot = 0.0f;
static GLfloat yRot2 = 0.0f;
//translation co-ordinates
static GLfloat line1 = 0.0f;
static GLfloat line2 = 0.0f;
static GLfloat line3 = 0.0f;

static GLfloat xRestore = 0.06f;
static GLfloat yRestore = 0.06f;
GLint flag=0;
GLint count=0;
GLint count1=0;
GLint turn=0;


/*void myinit()
{

glClearColor(0.0f,1.0f,0.0f,0.0f);

}*/




////////////////////////////////////////////////////////////////////////////
// Change viewing volume and viewport.  Called when window is resized
void ChangeSize(int w, int h)
    {
    GLfloat fAspect;

    // Prevent a divide by zero
    if(h == 0)
        h = 1;

    // Set Viewport to window dimensions
    glViewport(0, 0, w, h);

    fAspect = (GLfloat)w/(GLfloat)h;

    // Reset coordinate system
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Produce the perspective projection
    gluPerspective(35.0f, fAspect, 1.0, 40.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    }
void SetupRC()
    {
    // Light values and coordinates
    GLfloat  whiteLight[] = { 0.05f, 0.05f, 0.05f, 1.0f };
    GLfloat  sourceLight[] = { 0.25f, 0.25f, 0.25f, 1.0f };
    GLfloat      lightPos[] = { -10.f, 5.0f, 5.0f, 1.0f };

    glEnable(GL_DEPTH_TEST);    // Hidden surface removal
    glFrontFace(GL_CCW);                // Counter clock-wise polygons face out
    glEnable(GL_CULL_FACE);             // Do not calculate inside

    // Enable lighting
    glEnable(GL_LIGHTING);

    // Setup and enable light 0
    glLightModelfv(GL_LIGHT_MODEL_AMBIENT,whiteLight);
    glLightfv(GL_LIGHT0,GL_AMBIENT,sourceLight);
    glLightfv(GL_LIGHT0,GL_DIFFUSE,sourceLight);
    glLightfv(GL_LIGHT0,GL_POSITION,lightPos);
    glEnable(GL_LIGHT0);

    // Enable color tracking
    glEnable(GL_COLOR_MATERIAL);
        
    // Set Material properties to follow glColor values
    glColorMaterial(GL_FRONT, GL_AMBIENT_AND_DIFFUSE);

    // Black blue background
    glClearColor(0.25f, 0.25f, 0.50f, 1.0f );
    }
void SpecialKeys(int key, int x, int y)
        {
        if(key == GLUT_KEY_UP && xRot>-85)
{
                xRot-= 2.0f;
        flag=0;
xRot1=2.0*xRot;
count=4;

}

        if(key == GLUT_KEY_DOWN && xRot<85 )
         {
xRot += 2.0f;
     flag=0;
xRot1=2.0*xRot;
count=3;

}

        if(key == GLUT_KEY_LEFT && yRot<85)
{
                yRot += 2.0f;
        flag=0;
yRot1=2.0*yRot;
count=1;



}
        


        if(key == GLUT_KEY_RIGHT && yRot>-85)
{
yRot -= 2.0f;
        flag=0;
yRot1=2.0*yRot;
count=2;

}

     
                
        xRot = (GLfloat)((const int)xRot % 90);
        yRot = (GLfloat)((const int)yRot % 90);



        // Refresh the Window
        glutPostRedisplay();
        }
void SpecialKeysUp(int key, int x, int y)
{
if(key == GLUT_KEY_UP)
                flag=1;

        if(key == GLUT_KEY_DOWN)
                flag=1;

        if(key == GLUT_KEY_LEFT)
{
                flag=1;
count=1;
}
        


        if(key == GLUT_KEY_RIGHT)
        {        flag=1;
count=2;
}
}

void myKey(unsigned char key1,int x,int y)
{
if(key1=='q' || key1=='Q')
line1-=0.5f;
if(key1=='h' || key1=='H')
line3-=0.5f;

glutPostRedisplay();
}


// Called to draw scene
void RenderScene(void)
    {
    GLUquadricObj *pObj;        // Quadric Object
    
    // Clear the window with current clearing color
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Save the matrix state and do the rotations
    glPushMatrix();
        // Move object back and do in place rotation
        glTranslatef(0.0f, -1.0f, -5.0f);
        glRotatef(xRot, 1.0f, 0.0f, 0.0f);
        glRotatef(yRot, 0.0f, 0.0f, 1.0f);
//glRotatef(y1Rot, 0.0f, 0.0f, 1.0f);


        // Draw something
        pObj = gluNewQuadric();
        gluQuadricNormals(pObj, GLU_SMOOTH);
        
        // Main Body
        glPushMatrix();
            glColor3f(1.0f, 1.0f, 1.0f);
            gluSphere(pObj, .40f, 26, 13); 
// Bottom
       
            glTranslatef(0.0f, .550f, 0.0f); // Mid section
            gluSphere(pObj, .3f, 26, 13);


        
            glTranslatef(0.0f, 0.45f, 0.0f); // Head
            gluSphere(pObj, 0.24f, 26, 13);

        
            // Eyes
            glColor3f(0.0f, 0.0f, 0.0f);
            glTranslatef(0.1f, 0.1f, 0.21f);
            gluSphere(pObj, 0.02f, 26, 13);
        
            glTranslatef(-0.2f, 0.0f, 0.0f);
            gluSphere(pObj, 0.02f, 26, 13);
        
            // Nose
            glColor3f(1.0f, 0.3f, 0.3f);
            glTranslatef(0.1f, -0.12f, 0.0f);
            gluCylinder(pObj, 0.04f, 0.0f, 0.3f, 26, 13);
        glPopMatrix();
          // Restore the matrix state
    glPopMatrix();

    // Buffer swap
    glutSwapBuffers();

    }
void display()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
/*if(count==0.0)
{
glClearColor(0.0f,0.0f,0.5f,0.0f);

count=1.0;
}*/


glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();




//glTranslatef(line1, line2, line3);
RenderScene();

glutPostRedisplay();

glFlush();
}
void idler()
{  

   if(count==1)
   {

   if((xRot>=0 && flag==1))
    {
  
           xRot-=xRestore;
   
   
  

    }
else if(  (xRot<=0.0 && flag==1) )
    {
         xRot+=xRestore;
    }
    
  if((yRot>0 && flag==1)||(yRot1>0&&flag==1))
  {
           yRot-=yRestore;
   yRot1-=yRestore;
   }
    else if( ( yRot<0 && flag==1 ))
         {
             yRot+=yRestore;

  



  
  }
   }
    
   if(count==2)
   {

   if((xRot>=0 && flag==1))
    {
  
           xRot-=xRestore;
   
   
  

    }
else if(  (xRot<=0.0 && flag==1) )
    {
         xRot+=xRestore;
    }
    

  if( ( yRot<0 && flag==1 )||(yRot1<0&&flag==1))
         {
             yRot+=yRestore;
yRot1+=yRestore;

  }  
  else if((yRot>0 && flag==1))
  {
           yRot-=yRestore;
   
   }



  
  
   }
if(count==3)
   {

   if((xRot>0 && flag==1)||(xRot1>0&&flag==1))
    {
  
           xRot-=xRestore;
   xRot1-=xRestore;
   
   
  

    }
else if(  (xRot<0.0 && flag==1) )
    {
         xRot+=xRestore;
    }
    
  if((yRot>0 && flag==1))
  {
           yRot-=yRestore;
   
   }
    else if( ( yRot<0 && flag==1 ))
         {
             yRot+=yRestore;

  



  
  }
   } 
   if(count==4)
   {

   
if(  (xRot<=0.0 && flag==1) ||(xRot1<0&&flag==1))
    {
         xRot+=xRestore;
  xRot1+=xRestore;
    }
else if((xRot>=0 && flag==1))
    {
  
           xRot-=xRestore;
   
   
  

    }
    
  if((yRot>0 && flag==1))
  {
           yRot-=yRestore;
  
   }
    else if( ( yRot<0 && flag==1 ))
         {
             yRot+=yRestore;

  



  
  }
   }
  
    glutPostRedisplay();
}


  




  



  
  
   
   

  
   
  
  


  
  



    



    

  


  
  



    

   




    






int main(int argc, char *argv[])
    {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(680, 680);


    glutCreateWindow("Center of gravity Doll");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
glutSpecialUpFunc(SpecialKeysUp);
glutKeyboardFunc(myKey);

glutIdleFunc(idler);



glutDisplayFunc(display);

    
    

    

   SetupRC();

    glutMainLoop();
    
    return 0;
    }

