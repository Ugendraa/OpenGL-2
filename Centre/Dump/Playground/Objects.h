//DRAW THE REQUIRED DOLL
void drawToyCapman()
{
     glRotatef(xRot, 1.0f, 0.0f, 0.0f);
     glRotatef(yRot, 0.0f, 0.0f, 1.0f);
     glRotatef(y1Rot, 0.0f, 0.0f, 1.0f);
     
     GLUquadricObj *Obj;
     Obj = gluNewQuadric();
                         
     
                         
                          rotLim=85;
                          
                          gluQuadricNormals(Obj, GLU_SMOOTH);
                    
                    
                          glPushMatrix();
                                         //head       
                                         glColor3fv(get_color(COLOR_CAP_MAN_FACE));
                                         gluSphere(Obj, 0.24f, 26, 13);
            
                                         // Eyes
                                         glPushMatrix();
                                                        glColor3fv(get_color(COLOR_CAP_MAN_EYES));
                                                        
                                                        glTranslatef(0.1f, -0.02f, 0.21f);
                                                        gluSphere(Obj, 0.02f, 26, 13);
        
                                                        glTranslatef(-0.2f, 0.0f, 0.0f);
                                                        gluSphere(Obj, 0.02f, 26, 13);
                                         glPopMatrix();
            
                            
                            glPopMatrix();
                            
                            glPushMatrix();
                                           glColor3fv(get_color(COLOR_CAP_MAN_CAP));
                                           //glColor3fv(get_color(curr_color));
                                           
                                           glRotatef(-90,1,0,0);
                                           
                                           gluCylinder(Obj, 0.3f, 0.0f, 1, 26, 2);
                            glPopMatrix();
 
     
    glFlush();
}

void drawToyDancer()
{
     glRotatef(xRot, 1.0f, 0.0f, 0.0f);
     glRotatef(yRot, 0.0f, 0.0f, 1.0f);
     glRotatef(y1Rot, 0.0f, 0.0f, 1.0f);
     
     GLUquadricObj *Obj;
     Obj = gluNewQuadric();
                         
     
     
                          
                          rotLim=30;
                          GLfloat fine=0;
                          gluQuadricNormals(Obj, GLU_SMOOTH);
                          
                    
                          glPushMatrix();
                                         //base       
                                         glColor3fv(get_color(COLOR_DANCER_BASE));
                                         gluSphere(Obj, 0.3f, 26, 13);
            
                            
                            glPopMatrix();
                            
                            glPushMatrix();
                                          
                            glPushMatrix();
                                           glColor3fv(get_color(COLOR_DANCER_BOT));
                                           glRotatef(-90,1,0,0);
                                           gluCylinder(Obj, 0.5f, 0.2f, .7, 26, 2);
                             glPopMatrix();
                             glPushMatrix();             
                                           //glRotatef(-180,1,0,0);
                                           glColor3fv(get_color(COLOR_DANCER_TOP));
                                           glTranslatef(0.0f, 1.0f, 0.0); 
                                           glRotatef(+90,1,0,0);
                                          gluCylinder(Obj, 0.5f, 0.2f,  .5, 26, 2);
                             glPopMatrix();
                             glPushMatrix();             
                                           //glRotatef(-180,1,0,0);
                                           glColor3fv(get_color(COLOR_DANCER_CROWN));
                                           glTranslatef(0.0f, 1.5f, 0.0); 
                                           glRotatef(+90,1,0,0);
                                          gluCylinder(Obj,0.3f, 0.24f,   .3, 26, 2);
                             glPopMatrix();
                             /*glPushMatrix();
                            
                                           glColor3fv(get_color(COLOR_DANCER_CROWN)); 
                                           glTranslatef(0.0f, 1.0f, 0.0); 
                                           glRotatef(+90,1,0,0);
                                           gluCylinder(Obj, 0.5f, 0.2f,  .5, 26, 2);
                            glPopMatrix();*/
                            glPushMatrix();
                                         //head 
                                         
                                         glTranslatef(0.0f, 1.2f, 0.0f);      
                                         glColor3fv(get_color(COLOR_DANCER_FACE));
                                         gluSphere(Obj, 0.24f, 26, 13);
            
                                         // Eyes
                                         glPushMatrix();
                                                        glColor3fv(get_color(COLOR_DANCER_EYES));
                                                        
                                                        glTranslatef(0.1f, -0.02f, 0.21f);
                                                        gluSphere(Obj, 0.02f, 26, 13);
        
                                                        glTranslatef(-0.2f, 0.0f, 0.0f);
                                                        gluSphere(Obj, 0.02f, 26, 13);
                                         glPopMatrix();
            
                            
                            glPopMatrix();
 
     
}

//DRAW THE SURFACE
void drawGround()
{
                     glColor3fv(get_color(COLOR_WRLD_GRND));
	                 glPushMatrix();
	                 glTranslatef(0.0f, -0.35f, 0.0f);
	                 glBegin(GL_QUADS);
		                               glVertex3f(-10.0f, 0.0f, -10.0f);
		                               glVertex3f(-10.0f, 0.0f,  10.0f);
		                               glVertex3f( 10.0f, 0.0f,  10.0f);
		                               glVertex3f( 10.0f, 0.0f, -10.0f);
                    glEnd();
                    glPopMatrix();
}
