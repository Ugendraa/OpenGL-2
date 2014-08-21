#include<iostream>
#include<GL/glut.h>
#include<windows.h>
using namespace std;
// OpenGL toolkit

// Rotation amounts
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
static GLfloat y1Rot = 0.0f;
/*
//translation co-ordinates
static GLfloat line1 = 0.0f;
static GLfloat line2 = 0.0f;
static GLfloat line3 = 0.0f;
*/
void myinit()
{
glClearColor(0.0f,0.0f,0.0f,0.0f);
}


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
void SpecialKeys(int key, int x, int y)
        {
        if(key == GLUT_KEY_UP && xRot>-85)
                xRot-= 5.0f;

        if(key == GLUT_KEY_DOWN && xRot<85)
                xRot += 5.0f;

        if(key == GLUT_KEY_LEFT && yRot<85)
                yRot += 5.0f;

        if(key == GLUT_KEY_RIGHT && yRot>-85)
                yRot -= 5.0f;
        
        

                
     
                
        //xRot = (GLfloat)((const int)xRot % 90);
        //yRot = (GLfloat)((const int)yRot % 90);

        // Refresh the Window
        glutPostRedisplay();
        }
void idler()
{
     if(xRot>0)
     {
            xRot-=0.01;
     }
     else if(  xRot<0 )
     {
          xRot+=0.01;
     }
     
     if(yRot>0)
     {
            yRot-=0.01;
     }
     else if(  yRot<0 )
     {
          yRot+=0.01;
     }
     
     glutPostRedisplay();
}
        /*
void myKey(unsigned char key1,int x,int y)
{
if(key1=='q' || key1=='Q')
line1-=0.5f;
if(key1=='h' || key1=='H')
line3-=0.5f;

glutPostRedisplay();
}

*/
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
        gluQuadricOrientation(	pObj, GLU_INSIDE);

        
        // Main Body
        glPushMatrix();
            glColor3f(1.0f, 1.0f, 1.0f);
            gluSphere(pObj, 0.24f, 26, 13);
            
            // Eyes
            glPushMatrix();
            glColor3f(0.0f, 0.0f, 0.0f);
            glTranslatef(0.1f, -0.02f, 0.21f);
            gluSphere(pObj, 0.02f, 26, 13);
        
            glTranslatef(-0.2f, 0.0f, 0.0f);
            gluSphere(pObj, 0.02f, 26, 13);
            glPopMatrix();
            
            glPushMatrix();
            glColor3f(1.0f, 0.3f, 0.3f);
            //glRotatef(-90,1,0,0);
            //glTranslatef(0,.8,0);
            glRotatef(-90,1,0,0);
            gluCylinder(pObj, 0.3f, 0.0f, 1, 26, 2);
            glPopMatrix();
        glPopMatrix();
          // Restore the matrix state
    glPopMatrix();

    // Buffer swap
    glutSwapBuffers();
    }
void display()
{
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

//glTranslatef(line1, line2, line3);
RenderScene();
glutPostRedisplay();

glFlush();
}




int main(int argc, char *argv[])
    {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Modeling with Quadrics");
    glutReshapeFunc(ChangeSize);
    glutSpecialFunc(SpecialKeys);
    glutIdleFunc(idler);
//glutKeyboardFunc(myKey);
    glutDisplayFunc(display);
myinit();
   // SetupRC();
    glutMainLoop();
    
    return 0;
    }
