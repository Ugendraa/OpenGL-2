#include<iostream>
#include<gl/glut.h>
#define NUM_COLORS (21)
using namespace std;



enum COLORS
{
        black,
        white,
        
        papaya_whip,
        
        
        deep_sky_blue,
        light_sky_blue,
        
        dark_green,
        yellow_green,
        
        yellow,
        gold,
        
        indian_red,
        saddle_brown,
        sandy_brown,
        tannish,
        
        fire_brick,
        dark_orange,
        red,
        violet_red,
        
        skin1,
        skin2,
        skin3,
        skin4
     
};    

GLfloat color[NUM_COLORS][3]={
        {0,0,0}       /*black*/,
        {255,255,255} /*white*/,
        {255,239,213} /*papaya_whip*/,
        {000,191,255} /*deep_sky_blue*/,
        {000,191,255} /*light_sky_blue*/,
        {000,100,000} /*dark_green*/,
        {154,205,050} /*yellow_green*/,
        {255,255,000} /*yellow*/,
        {255,215,000} /*gold*/,
        {205,92,92}   /*indian_red*/,
        {139,69,19}   /*saddle_brown*/,
        {244,164,96}  /*sandy_brown*/,
        {210,180,140} /*tannish*/,
        {178,34,34}   /*fire_brick*/,
        {255,140,000} /*dark_orange*/,
        {255,000,000} /*red*/,
        {199,021,133} /*violet_red*/,
        {255,218,185} /*skin1*/,
        {238,207,161} /*skin2*/,
        {139,121,94}  /*skin3*/,
        {139,000,000} /*skin4*/
};

GLfloat vec[3];

void set_color(GLfloat vec[],COLORS c)
{
     vec[0]=color[c][0]/255;
     vec[1]=color[c][1]/255;
     vec[2]=color[c][2]/255;
}
 
GLfloat* get_color(COLORS c)
{
        
         vec[0]=color[c][0]/255;
         vec[1]=color[c][1]/255;
         vec[2]=color[c][2]/255;
         return vec;
}

