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
void camInit();

//GENERAL INITIALIZER
void myinit();

//WINDOW RESHAPE HANDLER
void myReshape(int w, int h);
//HANDLER FOR TILTING USING SPECIAL KEYS
void upKeyControl(int key, int x, int y);

void keyControl(int key, int x, int y);
void idler();

//DRAW THE REQUIRED DOLL
void drawToyCapman();
void drawToyDancer();
//DRAW THE SURFACE
void drawGround();
//SET CAMERA VALUES
void setCam();

//DRAW THE SCENE
void RenderScene(void);

//HANDLER FOR NORMAL KEYBOARD INPUT
void processKeys(unsigned char key, int xx, int yy);
void main_menu(int choice);


void color_menu(int choice);
void capman_appearance_menu(int item);
void world_appearance_menu(int item);
void appearance_menu(int choice);
void camera_menu(int choice);
void doll_menu(int choice);
void dancer_appearance_menu(int item);

void set_menu();                                             
void menuInit();

void CoG();
//FUNCTION TO SELECT BITMAP FONT
void setFont(void *font);
//FUNCTION TO DRAW BITMAP string at (x,y)
void drawstring(GLfloat x,GLfloat y,char *string);
void title_display();

void title_menu(int choice);
//Title INITIALIZER
void titleInit();
void title();
  
int main(int argc, char *argv[]);

