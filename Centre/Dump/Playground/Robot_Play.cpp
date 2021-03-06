#include<iostream>
#include<GL/glut.h>
using namespace std;

float angle = 0.0f;                     // current angle of the rotating triangle   
//HDC g_HDC;                              // global device context   
bool fullScreen = false;                       

enum ROBO_STATE
{
     START,STOP
};
ROBO_STATE state=START; 
ROBO_STATE rot=START;
////// Robot variables   
float legAngle[2] = { 0.0f, 0.0f };     // each leg's current angle   
float armAngle[2] = {0.0f, 0.0f };   
   
// DrawCube   
// desc: since each component of the robot is made up of   
//       cubes, we will use a single function that will   
//       draw a cube at a specified location.   
void DrawCube(float xPos, float yPos, float zPos)   
{   
    glPushMatrix();   
        glTranslatef(xPos, yPos, zPos);   
        glBegin(GL_POLYGON);   
            glVertex3f(0.0f, 0.0f, 0.0f);   // top face   
            glVertex3f(0.0f, 0.0f, -1.0f);   
            glVertex3f(-1.0f, 0.0f, -1.0f);   
            glVertex3f(-1.0f, 0.0f, 0.0f);   
            glVertex3f(0.0f, 0.0f, 0.0f);   // front face   
            glVertex3f(-1.0f, 0.0f, 0.0f);   
            glVertex3f(-1.0f, -1.0f, 0.0f);   
            glVertex3f(0.0f, -1.0f, 0.0f);   
            glVertex3f(0.0f, 0.0f, 0.0f);   // right face   
            glVertex3f(0.0f, -1.0f, 0.0f);   
            glVertex3f(0.0f, -1.0f, -1.0f);   
            glVertex3f(0.0f, 0.0f, -1.0f);   
            glVertex3f(-1.0f, 0.0f, 0.0f);  // left face   
            glVertex3f(-1.0f, 0.0f, -1.0f);   
            glVertex3f(-1.0f, -1.0f, -1.0f);   
            glVertex3f(-1.0f, -1.0f, 0.0f);   
            glVertex3f(0.0f, 0.0f, 0.0f);   // bottom face   
            glVertex3f(0.0f, -1.0f, -1.0f);   
            glVertex3f(-1.0f, -1.0f, -1.0f);   
            glVertex3f(-1.0f, -1.0f, 0.0f);   
            glVertex3f(0.0f, 0.0f, 0.0f);   // back face   
            glVertex3f(-1.0f, 0.0f, -1.0f);   
            glVertex3f(-1.0f, -1.0f, -1.0f);   
            glVertex3f(0.0f, -1.0f, -1.0f);   
        glEnd();   
    glPopMatrix();   
}   
   
// DrawArm   
// desc: draws one arm   
void DrawArm(float xPos, float yPos, float zPos)   
{   
    glPushMatrix();   
        glColor3f(1.0f, 0.0f, 0.0f);    // red   
        glTranslatef(xPos, yPos, zPos);   
        glScalef(1.0f, 4.0f, 1.0f);     // arm is a 1x4x1 cube   
        DrawCube(0.0f, 0.0f, 0.0f);   
    glPopMatrix();   
}   
   
// DrawHead   
// desc: draws the robot head   
void DrawHead(float xPos, float yPos, float zPos)   
{   
    glPushMatrix();   
        glColor3f(1.0f, 1.0f, 1.0f);    // white   
        glTranslatef(xPos, yPos, zPos);   
        glScalef(2.0f, 2.0f, 2.0f);     // head is a 2x2x2 cube   
        DrawCube(0.0f, 0.0f, 0.0f);   
    glPopMatrix();   
}   
   
// DrawTorso   
// desc: draws the robot torso   
void DrawTorso(float xPos, float yPos, float zPos)   
{   
    glPushMatrix();   
        glColor3f(0.0f, 0.0f, 1.0f);    // blue   
        glTranslatef(xPos, yPos, zPos);   
        glScalef(3.0f, 5.0f, 2.0f);     // torso is a 3x5x2 cube   
        DrawCube(0.0f, 0.0f, 0.0f);   
    glPopMatrix();   
}   
   
// DrawLeg   
// desc: draws a single leg   
void DrawLeg(float xPos, float yPos, float zPos)   
{   
    glPushMatrix();   
        glColor3f(1.0f, 1.0f, 0.0f);    // yellow   
        glTranslatef(xPos, yPos, zPos);   
        glScalef(1.0f, 5.0f, 1.0f);     // leg is a 1x5x1 cube   
        DrawCube(0.0f, 0.0f, 0.0f);   
    glPopMatrix();   
}   
   
// DrawRobot   
// desc: draws the robot located at (xpos,ypos,zpos)   
void DrawRobot(float xPos, float yPos, float zPos)   
{   
    static bool leg1 = true;        // robot's leg states   
    static bool leg2 = false;       // true = forward, false = back   
       
    static bool arm1 = true;   
    static bool arm2 = false;   
   
    glPushMatrix();    
   
        glTranslatef(xPos, yPos, zPos); // draw robot at desired coordinates   
   
    // draw components   
        DrawHead(1.0f, 2.0f, 0.0f);        
        DrawTorso(1.5f, 0.0f, 0.0f);   
        glPushMatrix();   
            if(state==START)
            {
                           // if leg is moving forward, increase angle, else decrease angle   
                            if (arm1)   
                              armAngle[0] = armAngle[0] + 0.1f;   
                            else   
                              armAngle[0] = armAngle[0] - 0.1f;   
   
            // once leg has reached its maximum angle in a direction,   
            // reverse it   
                            if (armAngle[0] >= 15.0f)   
                               arm1 = false;   
                            if (armAngle[0] <= -15.0f)   
                            arm1 = true;   
            }
            // move the leg away from the torso and rotate it to give "walking" effect   
            glTranslatef(0.0f, -0.5f, 0.0f);   
            glRotatef(armAngle[0], 1.0f, 0.0f, 0.0f);   
            DrawArm(2.5f, 0.0f, -0.5f);   
        glPopMatrix();   
   
        glPushMatrix();   
            if(state==START)
            {
                           // if leg is moving forward, increase angle, else decrease angle   
                           if (arm2)   
                           armAngle[1] = armAngle[1] + 0.1f;   
                           else   
                           armAngle[1] = armAngle[1] - 0.1f;   
   
            // once leg has reached its maximum angle in a direction,   
            // reverse it   
                            if (armAngle[1] >= 15.0f)   
                            arm2 = false;   
                            if (armAngle[1] <= -15.0f)   
                            arm2 = true;   
            }
            // move the leg away from the torso and rotate it to give "walking" effect   
            glTranslatef(0.0f, -0.5f, 0.0f);   
            glRotatef(armAngle[1], 1.0f, 0.0f, 0.0f);   
            DrawArm(-1.5f, 0.0f, -0.5f);   
        glPopMatrix();   
   
        //DrawArm(-1.5f, 0.0f, -0.5f);   
   
        // we want to rotate the legs relative to the robot's position in the world   
        // this is leg 1, the robot's right leg   
        glPushMatrix();                    
   
            // if leg is moving forward, increase angle, else decrease angle   
            if(state==START)
            {
                           if (leg1)   
                           legAngle[0] = legAngle[0] + 0.1f;   
                           else   
                           legAngle[0] = legAngle[0] - 0.1f;   
   
            // once leg has reached its maximum angle in a direction,   
            // reverse it   
                            if (legAngle[0] >= 15.0f)   
                            leg1 = false;   
                            if (legAngle[0] <= -15.0f)   
                            leg1 = true;   
            }
            // move the leg away from the torso and rotate it to give "walking" effect   
            glTranslatef(0.0f, -0.5f, 0.0f);   
            glRotatef(legAngle[0], 1.0f, 0.0f, 0.0f);   
   
            // draw the leg   
            DrawLeg(-0.5f, -5.0f, -0.5f);   
   
        glPopMatrix();   
   
        // do the same as above with leg 2, the robot's left leg   
        glPushMatrix();   
        if(state==START)
        {    if (leg2)   
                legAngle[1] = legAngle[1] + 0.1f;   
            else   
                legAngle[1] = legAngle[1] - 0.1f;   
   
            if (legAngle[1] >= 15.0f)   
                leg2 = false;   
            if (legAngle[1] <= -15.0f)   
                leg2 = true;   
   }
            glTranslatef(0.0f, -0.5f, 0.0f);   
            glRotatef(legAngle[1], 1.0f, 0.0f, 0.0f);   
            DrawLeg(1.5f, -5.0f, -0.5f);   
   
        glPopMatrix();   
    glPopMatrix(); 
    glutPostRedisplay();  
}   
   
   
// Render   
// desc: handles drawing of scene   
void Render()   
{   
    glEnable(GL_DEPTH_TEST);                // enable depth testing   
   
    // do rendering here   
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);                   // clear to black   
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);     // clear screen and depth buffer   
    glLoadIdentity();                                       // reset modelview matrix   
   
    if(rot==START)
    {
                     angle = angle + 0.05f;                  // increase our rotation angle counter   
                     if (angle >= 360.0f)                 // if we've gone in a circle, reset counter   
                        angle = 0.0f;  
    } 
   
    glPushMatrix();                         // put current matrix on stack   
        glLoadIdentity();                   // reset matrix   
        glTranslatef(0.0f, 0.0f, -30.0f);   // move to (0, 0, -30)   
        glRotatef(angle, 0.0f, 1.0f, 0.0f); // rotate the robot on its y-axis   
        DrawRobot(0.0f, 0.0f, 0.0f);        // draw the robot   
    glPopMatrix();                          // dispose of current matrix   
   
    glFlush();   
   
    glutSwapBuffers();         // bring backbuffer to foreground   
}   


void myinit()
{
     glClearColor(0.0,0.0,0.0,0.0);
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(0.0,250.0,0.0,250.0);
     glMatrixMode(GL_MODELVIEW);
}



void myReshape(int w, int h)
{
     GLfloat fAspect;

    
    if(h == 0) h = 1;

    glViewport(0, 0, w, h);

    fAspect = (GLfloat)w/(GLfloat)h;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    
    gluPerspective(50.0f, fAspect, 1.0, 40.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}

void mouse(int btn, int mstate, int x, int y)
{
     if(btn==GLUT_LEFT_BUTTON && mstate==GLUT_DOWN) 
     {
                              if(state==START) state=STOP;
                              else state=START;
     }
     //if(btn==GLUT_MIDDLE_BUTTON && state=GLUT_DOWN) axis=1;
     if(btn==GLUT_RIGHT_BUTTON && mstate==GLUT_DOWN)
     {
                               if(rot==START) rot=STOP;
                               else rot=START;
     } 
    
     
}
     
void keyControl(int key, int x, int y)
{
     if(key == GLUT_KEY_UP)
                state= START;
     
     if(key == GLUT_KEY_DOWN)
                state= STOP;
     
     if(key == GLUT_KEY_LEFT)
                rot= STOP;
     
     if(key == GLUT_KEY_RIGHT)
                rot =START;
     
     glutPostRedisplay();
}
void display()
{
     
     glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB /*| GLUT_DEPTH*/);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Stack");
    glutReshapeFunc(myReshape);
    glutMouseFunc(mouse);
    glutSpecialFunc( keyControl);
    //glutSpecialFunc(keyControl);
    //glutIdleFunc(idler);
    glutDisplayFunc(Render);
    myinit();
    glutMainLoop();
    
    return 0;
}
