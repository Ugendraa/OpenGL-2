#include<iostream>
#include<GL/glut.h>
#include<math.h>
#include"Colors.h"
//#include"toys.h"
using namespace std;

//PROGRAM MODE
enum MODE{TITLE,COG}mode=TITLE;
void *currentfont;

//WINDOW CONTROL
int WIN_TITLE;
int FULLSCREEN=1;

//Angle values for rotating the doll
static GLfloat xRot = 0.0f;
static GLfloat yRot = 0.0f;
static GLfloat y1Rot = 0.0f;
static GLfloat rotLim;

//Restore speed to centre
static GLfloat xRestore = 0.05f;
static GLfloat yRestore = 0.05f;
static int restore=1;

//WORLD COLORS
COLORS COLOR_WRLD_GRND=dark_green;
COLORS COLOR_WRLD_SKY=light_sky_blue;

//TITLE SCREEN COLORS and CONSTANTS
COLORS COLOR_TITLE_BG=black;
COLORS COLOR_TITLE_H1=fire_brick;
COLORS COLOR_TITLE_H2=indian_red;
COLORS COLOR_TITLE_TEXT1=dark_orange;
COLORS COLOR_TITLE_TEXT2=yellow_green;
const int title_left=0,title_right=500,title_bottom=0,title_top=500;
     

//CAP_MAN COLORS
COLORS COLOR_CAP_MAN_CAP=red;
COLORS COLOR_CAP_MAN_FACE=skin1;
COLORS COLOR_CAP_MAN_EYES=black;

//DANCER COLORS
COLORS COLOR_DANCER_BASE=sandy_brown;
COLORS COLOR_DANCER_EYES=saddle_brown;
COLORS COLOR_DANCER_BOT=indian_red;
COLORS COLOR_DANCER_TOP=white;
COLORS COLOR_DANCER_CROWN=indian_red;
COLORS COLOR_DANCER_FACE=skin1;

//AVAILABLE DOLLS
enum { CAP_MAN , DANCER}dollType=DANCER;


//MENU MANAGEMENT
int MENU_COLORS,MENU_CAPMAN_APPEARANCE,MENU_APPEARANCE,MENU_WORLD_APPEARANCE,MENU_CAMERA,MENU_MAIN,MENU_DOLL,MENU_DANCER_APPEARANCE;

enum {APPEARANCE,CAMERA,mDOLL,EXIT};
enum {CAM_RESET,ZOOMIN,ZOOMOUT,INVERT,WLKSPD_UP,WLKSPD_DOWN,TRNSPD_UP,TRNSPD_DOWN};
enum {WORLD,DOLL};
enum {GROUND,SKY};
enum {CAP,EYES,FACE,CROWN,TOP,BOTTOM,BASE};
COLORS curr_color=white;


//CAMERA MANAGEMENT
float angle=0.0;           // angle of rotation for the camera direction
float lx=-1.0f,lz=0.0f;    // actual vector representing the camera's direction
float x=0.0f,z=5.0f;      // XZ position of the camera
float invert=1;
float tspd,wspd;
const float TRNSPD=.01,WLKSPD=0.1;

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

void main_menu(int choice)
{
     void title();
     if(choice==-1) exit(0);
     else if(choice==1) 
     {
          glutDestroyWindow(glutGetWindow());
          glutSetWindow(WIN_TITLE);
     }
}


void color_menu(int choice)
{
     
     curr_color=(COLORS)choice;
     
}


void capman_appearance_menu(int item)
{
 

     
     
     switch(item)
     {
                                   case CAP:
                                        COLOR_CAP_MAN_CAP=curr_color;
                                        break;
                                   case EYES:
                                        COLOR_CAP_MAN_EYES=curr_color;
                                        break;
                                   case FACE:
                                        COLOR_CAP_MAN_FACE=curr_color;
                                        break;
     }
                                        
}

void world_appearance_menu(int item)
{
 

 
     
     switch(item)
     {
                                   case GROUND:
                                        COLOR_WRLD_GRND=curr_color;
                                        break;
                                   case EYES:
                                        COLOR_WRLD_SKY=curr_color;
                                        break;
                                   
     }
                                        
} 
                                                 
void appearance_menu(int choice)
{}

void camera_menu(int choice)
{
    
     
     switch(choice)
     {
                   case CAM_RESET:
                        camInit();
                        break;
                   case WLKSPD_DOWN:
                        wspd-=.1;
                        break;
                   case WLKSPD_UP:
                        wspd+=.1;
                        break;
                   case TRNSPD_DOWN:
                        tspd-=.01;
                        break;
                   case TRNSPD_UP:
                        tspd+=.01;
                        break;
                   case INVERT:
                        invert=-invert;
                        break;
                   case ZOOMIN:
                        x += lx * 1;
                        z += lz * 1;
                        break;
                   case ZOOMOUT:
                        x -= lx * 1;
                        z -= lz * 1;
                        break;
     }
                        
}
void doll_menu(int choice)
{
     void set_menu();
     switch(choice)
     {
                   case 1:
                        dollType=CAP_MAN;
                        //glutDisplayFunc();
                        set_menu();
                        break;
                   case 2:
                        dollType=DANCER;
                        set_menu();
                        break;
     }
}
void dancer_appearance_menu(int item)
{

     switch(item)
     {
                                   case CROWN:
                                        COLOR_DANCER_CROWN=curr_color;
                                        break;
                                   case EYES:
                                        COLOR_DANCER_EYES=curr_color;
                                        break;
                                   case FACE:
                                        COLOR_DANCER_FACE=curr_color;
                                        break;
                                   case TOP:
                                        COLOR_DANCER_TOP=curr_color;
                                        break;
                                   case BOTTOM:
                                        COLOR_DANCER_BOT=curr_color;
                                        break;
                                   case BASE:
                                        COLOR_DANCER_BASE=curr_color;
                                        break;
     }
}

void set_menu()
{
     glutSetMenu(MENU_APPEARANCE);
     if(dollType==CAP_MAN)
                           (1, "Capman", MENU_CAPMAN_APPEARANCE);
     else
                          glutChangeToSubMenu(1, "Russian Dancer", MENU_DANCER_APPEARANCE);	
}	                                                          
void menuInit()
{
//******************APPEARANCE MENU CREATION*********************************//
    
    //COLOR PALETTE
    MENU_COLORS=glutCreateMenu(color_menu);
    glutAddMenuEntry("Black",black);
    glutAddMenuEntry("White",white);
    glutAddMenuEntry("Papaya Whip",papaya_whip);
    glutAddMenuEntry("Deep  Sky Blue",deep_sky_blue);
    glutAddMenuEntry("Light Sky Blue",light_sky_blue);
    glutAddMenuEntry("Dark Green",dark_green);
    glutAddMenuEntry("Yellow Green",yellow_green);
    glutAddMenuEntry("Yellow",yellow);
    glutAddMenuEntry("Gold",gold);    
    glutAddMenuEntry("Indian Red",indian_red);
    glutAddMenuEntry("Saddle Brown",saddle_brown);
    glutAddMenuEntry("Sandy Brown",sandy_brown);
    glutAddMenuEntry("Tan",tannish);
    glutAddMenuEntry("Fire Brick",fire_brick);
    glutAddMenuEntry("Dark Orange",dark_orange);
    glutAddMenuEntry("Red",red);
    glutAddMenuEntry("Violet Red",violet_red);
    glutAddMenuEntry("Skin 1",skin1);
    glutAddMenuEntry("Skin 2",skin2);
    glutAddMenuEntry("Skin 3",skin3);
    glutAddMenuEntry("Skin 4",skin4);
    
    //CAPMAN APPEARANCE
    MENU_CAPMAN_APPEARANCE=glutCreateMenu(capman_appearance_menu);
    glutAddMenuEntry("Cap",CAP);
    glutAddMenuEntry("Face",FACE);
    glutAddMenuEntry("Eyes",EYES);
    
    //CAPMAN APPEARANCE
    MENU_DANCER_APPEARANCE=glutCreateMenu(dancer_appearance_menu);
    glutAddMenuEntry("Crown",CROWN);
    glutAddMenuEntry("Face",FACE);
    glutAddMenuEntry("Eyes",EYES);
    glutAddMenuEntry("Top",TOP);
    glutAddMenuEntry("Bottom",BOTTOM);
    glutAddMenuEntry("Base",BASE);
    
    //WORLD APPEARANCE
    MENU_WORLD_APPEARANCE=glutCreateMenu(world_appearance_menu);
    glutAddMenuEntry("Sky",SKY);
    glutAddMenuEntry("Ground",GROUND);
    
    
    
    //APPEARANCE MENU
    MENU_APPEARANCE=glutCreateMenu(appearance_menu);
    //glutAddSubMenu("Cap Man Toy",MENU_CAPMAN_APPEARANCE);
    
    if(dollType==CAP_MAN) glutAddSubMenu("Cap Man Toy",MENU_CAPMAN_APPEARANCE);
    else if(dollType==DANCER) glutAddSubMenu("Dancer Toy",MENU_DANCER_APPEARANCE);
    glutAddSubMenu("Color World",MENU_WORLD_APPEARANCE);
    glutAddSubMenu("Set Color",MENU_COLORS);
    
//******************APPEARANCE MENU CREATION*********************************//


//******************CAMERA MENU CREATION*********************************//


    MENU_CAMERA=glutCreateMenu(camera_menu);
    glutAddMenuEntry("Reset Camera",CAM_RESET);
    glutAddMenuEntry("Invert",INVERT);
    glutAddMenuEntry("Zoom In",ZOOMIN);
    glutAddMenuEntry("Zoom Out",ZOOMOUT);
    glutAddMenuEntry("Increase Walk Speed",WLKSPD_UP);
    glutAddMenuEntry("Decrease Walk Speed",WLKSPD_DOWN);
    glutAddMenuEntry("Increase Turn Speed",TRNSPD_UP);
    glutAddMenuEntry("Decrease Turn Speed",TRNSPD_DOWN);
    
//******************CAMERA MENU CREATION*********************************//


//******************DOLL MENU CREATION*********************************//

    MENU_DOLL=glutCreateMenu(doll_menu);
    glutAddMenuEntry("Cap Man", 1);
    glutAddMenuEntry("Russian Dancer", 2);

//******************DOLL MENU CREATION*********************************// 


//******************MAIN MENU CREATION*********************************//   
    MENU_MAIN=glutCreateMenu(main_menu);
    glutAddSubMenu("Appearance", MENU_APPEARANCE);
    glutAddSubMenu("Camera", MENU_CAMERA);
    glutAddSubMenu("Select Doll", MENU_DOLL);
    glutAddMenuEntry("Title", 1);
    glutAddMenuEntry("Exit", -1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
//******************MAIN MENU CREATION*********************************// 


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
//FUNCTION TO SELECT BITMAP FONT
void setFont(void *font)
{
     currentfont=font;
}
//FUNCTION TO DRAW BITMAP string at (x,y)
void drawstring(GLfloat x,GLfloat y,char *string)
{
   char *c;
   glRasterPos2f(x,y);

   for(c=string;*c!='\0';c++)
   {
                              glutBitmapCharacter(currentfont,*c);
   }
}
void title_display()
{
     glLineWidth(3.0);
     //glColor3f(1.0,1.0,0.0);
     glColor3fv(get_color(COLOR_TITLE_H1));
     glBegin(GL_LINE_LOOP);
                           glVertex2f(10,10);
                           glVertex2f(10,490);
                           glVertex2f(490,490);
                           glVertex2f(490,10);
     glEnd();
     
     setFont(GLUT_BITMAP_HELVETICA_18);
     int adjust=700*(title_top/500);
     //glColor3f(1.0,1.0,1.0);
     glColor3fv(get_color(COLOR_TITLE_H1));
     drawstring(100,adjust-440,"CENTRE OF GRAVITY DOLL");
     

     //glColor3f(1.0,1.0,1.0);
     glColor3fv(get_color(COLOR_TITLE_H2));
     drawstring(100,adjust-400,"Submitted by");

     //delay();
     
     glColor3fv(get_color(COLOR_TITLE_TEXT1));
     drawstring(100,adjust-360,"Chirag Ravindra");
     
     //delay();
     
     //glColor3f(0.0,1.0,0.0);
     drawstring(100,adjust-320,"VI CSE A");
     //delay();

     //glColor3f(0.0,1.0,0.0);
     drawstring(100,adjust-280,"1BG11CS027");
    
     //delay();
     glColor3fv(get_color(COLOR_TITLE_TEXT2));
     setFont(GLUT_BITMAP_HELVETICA_12);
     drawstring(100,adjust-250,"Right click for options");
     glutPostRedisplay();
glFlush();
}

void title_menu(int choice)
{
     switch(choice)
     {
                   case 1:
                        CoG();
                        break;
                   case 0:
                        exit(0);
                        break;
     }
}
//Title INITIALIZER
void titleInit()
{
     //TITILE SCREEN COLORS
     //COLOR_WRLD_TITLE_BG=white;
     
     
     
     get_color(COLOR_TITLE_BG);
     glClearColor(vec[0],vec[1],vec[2],0);
     glClear(GL_COLOR_BUFFER_BIT);
     glViewport( 0,0, title_right, title_top );
     glMatrixMode(GL_PROJECTION);
     glLoadIdentity();
     gluOrtho2D(title_left,title_right,title_top,title_bottom);
     glMatrixMode(GL_MODELVIEW);
     glEnable(GL_DEPTH_TEST);
    
}     
void title()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    WIN_TITLE=glutCreateWindow("Computer Graphics Project (1BG11CS027)");
    glutDisplayFunc(title_display);
    glutCreateMenu(title_menu);
    glutAddMenuEntry("Start Program",1);
    glutAddMenuEntry("Exit",0);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    titleInit();
}
  
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    
    
    title();
    
    glutMainLoop();
    
    return 0;
}
