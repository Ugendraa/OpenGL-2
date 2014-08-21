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
                        //menuInit();
                        break;
                   case 2:
                        dollType=DANCER;
                        set_menu();
                        //menuInit();
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

void start_menu()
{
     
     //******************MAIN MENU CREATION*********************************// 
    glutDestroyMenu(MENU_MAIN);
    menuInit();  
    MENU_MAIN=glutCreateMenu(main_menu);
    glutAddSubMenu("Appearance", MENU_APPEARANCE);
    glutAddSubMenu("Camera", MENU_CAMERA);
    glutAddSubMenu("Select Doll", MENU_DOLL);
    glutAddMenuEntry("Title", 1);
    glutAddMenuEntry("Exit", -1);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    
//******************MAIN MENU CREATION*********************************// 

}
