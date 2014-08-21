#include<iostream>
//#include"Colors.h"
#include"Global.h"
#include"Menu.h"
#include"Objects.h"
#include"Title.h"
#include"CoG.h"
using namespace std;


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    
    
    title();
    
    glutMainLoop();
    
    return 0;
}
