#include<iostream>
#include"Global.h"
//#include"Colors.h"
#include"Menu.h"
#include"Objects.h"
#include"Title.h"
using namespace std;


int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    
    
    title();
    
    glutMainLoop();
    
    return 0;
}
