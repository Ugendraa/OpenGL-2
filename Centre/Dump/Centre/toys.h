#include<iostream>
#include<gl/glut.h>
//#include"Colors.h"
using namespace std;


//CAP_MAN COLORS
COLORS CAP_MAN_CAP=red;
COLORS CAP_MAN_FACE=skin1;
COLORS CAP_MAN_EYES=black;

enum DOLL_TYPE { CAP_MAN };

DOLL_TYPE dollType=CAP_MAN;




void drawToy()
{
     if(dollType==CAP_MAN)
     {
                          GLUquadricObj *Obj;
                          Obj = gluNewQuadric();
                          gluQuadricNormals(Obj, GLU_SMOOTH);
                    
                    
                          glPushMatrix();
                                         //head       
                                         glColor3fv(get_color(CAP_MAN_FACE));
                                         gluSphere(Obj, 0.24f, 26, 13);
            
                                         // Eyes
                                         glPushMatrix();
                                                        glColor3fv(get_color(CAP_MAN_EYES));
                                                        
                                                        glTranslatef(0.1f, -0.02f, 0.21f);
                                                        gluSphere(Obj, 0.02f, 26, 13);
        
                                                        glTranslatef(-0.2f, 0.0f, 0.0f);
                                                        gluSphere(Obj, 0.02f, 26, 13);
                                         glPopMatrix();
            
                            
                            glPopMatrix();
                            
                            glPushMatrix();
                                           glColor3fv(get_color(CAP_MAN_CAP));
                                           
                                           glRotatef(-90,1,0,0);
                                           
                                           gluCylinder(Obj, 0.3f, 0.0f, 1, 26, 2);
                            glPopMatrix();
 
     }
}






