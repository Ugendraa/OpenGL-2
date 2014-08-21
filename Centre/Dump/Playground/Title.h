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
  
