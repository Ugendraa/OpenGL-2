#include<iostream>
#include<GL/glut.h>
using namespace std;

static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
static GLfloat y1Rot = 0.0f;

static GLfloat xRestore = 0.01f;
static GLfloat yRestore = 0.01f;




void myinit()
{
glClearColor(0.0f,0.0f,0.0f,0.0f);
glEnable(GL_DEPTH_TEST);
}


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

void keyControl(int key, int x, int y)
{
     if(key == GLUT_KEY_UP && xRot>-85)
                xRot-= 5.0f;
     
     if(key == GLUT_KEY_DOWN && xRot<85)
                xRot += 5.0f;
     
     if(key == GLUT_KEY_LEFT && yRot<85)
                yRot += 5.0f;
     
     if(key == GLUT_KEY_RIGHT && yRot>-85)
                yRot -= 5.0f;
     
     glutPostRedisplay();
}

void idler()
{
     if(xRot>0)
     {
            xRot-=xRestore;
     }
     else if(  xRot<0 )
     {
          xRot+=xRestore;
     }
     
     if(yRot>0)
     {
            yRot-=yRestore;
     }
     else if(  yRot<0 )
     {
          yRot+=yRestore;
     }
     
     glutPostRedisplay();
}


void RenderScene(void)
{
     GLUquadricObj *Obj;
     
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     
     glPushMatrix();
                    glTranslatef(0.0f, -1.0f, -5.0f);
                    glRotatef(xRot, 1.0f, 0.0f, 0.0f);
                    glRotatef(yRot, 0.0f, 0.0f, 1.0f);
                    glRotatef(y1Rot, 0.0f, 0.0f, 1.0f);
                    
                    Obj = gluNewQuadric();
                    gluQuadricNormals(Obj, GLU_SMOOTH);
                    
                    
                    glPushMatrix();
                            //head       
                            glColor3f(1.0f, 1.0f, 1.0f);
                            gluSphere(Obj, 0.24f, 26, 13);
            
                            // Eyes
                            glPushMatrix();
                                           glColor3f(0.0f, 0.0f, 0.0f);
                                           glTranslatef(0.1f, -0.02f, 0.21f);
                                           gluSphere(Obj, 0.02f, 26, 13);
        
                                           glTranslatef(-0.2f, 0.0f, 0.0f);
                                           gluSphere(Obj, 0.02f, 26, 13);
                            glPopMatrix();
            
                            
                            glPopMatrix();
                                glPushMatrix();
                                           glColor3f(1.0f, 0.3f, 0.3f);
                                           glTranslatef(0.0f, 0.0f, 0.0f);
                                           glRotatef(-90,1,0,0);
                                           
                                           gluCylinder(Obj, 0.3f, 0.0f, 1, 26, 2);
                            glPopMatrix();
                            
     glPopMatrix();
     glutSwapBuffers();
   
}

void display()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();

     RenderScene();
     
     glutPostRedisplay();

     glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Centre of Gravity Doll");
    glutReshapeFunc(myReshape);
    glutSpecialFunc(keyControl);
    glutIdleFunc(idler);
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    
    return 0;
}
