#include<iostream>
#include"customGL.cpp"
#include<GL/glut.h>
#define STACK_MAX (10)
using namespace std;

extern GLfloat topY,topX,nodeHt;

struct stack_element
{
       int data;
       struct stack_element* down;
	   struct stack_element* up;
};

typedef struct stack_element* StackElement;




class stack
{
      StackElement head,top;
      
      public:
             stack()
             {
                    top=head=newNode(0,NULL,NULL);
                 //head.data=0;
                 //head.down=NULL; 
             }
             stack(int a[], int n)
             {
                       top=head=newNode(0,NULL,NULL);
                       for(int i=0; i<n ; i++)
                       {
                               push(a[i]);
                       }
             }
             
             StackElement newNode(int data, StackElement down, StackElement up)
             {
                          StackElement new_element;
                          new_element= new struct stack_element;
                          new_element->data=data;
                          new_element->down=down;
						  new_element->up=up;
                          return new_element;
             }
             
             void push(int data)
             {
                  if((head->data)>=STACK_MAX)
                                           return;
                  (head->data)++;
                  StackElement element=newNode(data,top,NULL);
                  top->up=element;
                  top=element;
             }
             
             StackElement pop()
             {
                          if(head->data<=0) return NULL;
                          head->data--;
                          StackElement temp=top;
                          top=top->down;
                          return temp;
             }
             
             void drawStackDown()
             {
                  StackElement curr=top;
                  topY=(head->data + 2)*nodeHt;
                  
				  while(curr!=head)
                  {
                                  
                                  draw_node(curr);
								  //draw_arrow();
                                  curr=curr->down;
                  }
				  
             }
			 
			 void drawStackUp()
             {
                  StackElement curr=head;
                  topY=nodeHt;
				  topX=nodeHt;
                 
				  draw_base();
                  while(curr!=top)
                  {
                                  draw_arrow();
                                  draw_node(curr);
                                  curr=curr->up;
                  }
             }
             
             friend void print_num(int num, GLfloat scale,GLfloat x, GLfloat y, GLfloat z);
             friend void draw_node(StackElement n);  
			//friend void draw_arrow();
          
};
