#include<iostream>
#include<GL/glut.h>
#define COLOR_MAX (3)
#define STACK_MAX (10)
using namespace std;



typedef GLfloat float3[3];
float3 colors[COLOR_MAX]={ {1,0,0},{0,1,0},{0,0,1} };

GLfloat topX = 10;
GLfloat topY = 10;
GLfloat nodeHt = 10;
int color_n=0;

static GLfloat xRestore = 0.05f;
static GLfloat yRestore = 0.05f;


struct stack_element
{
       int data;
       struct stack_element* next;
};

typedef struct stack_element* StackElement;




class stack
{
      StackElement head,top;
      
      public:
             stack()
             {
                    top=head=newNode(0,NULL);
                 //head.data=0;
                 //head.next=NULL; 
             }
             stack(int a[], int n)
             {
                       top=head=newNode(0,NULL);
                       for(int i=0; i<n ; i++)
                       {
                               push(a[i]);
                       }
             }
             
             StackElement newNode(int data, StackElement next)
             {
                          StackElement new_element;
                          new_element= new struct stack_element;
                          new_element->data=data;
                          new_element->next=next;
                          return new_element;
             }
             
             void push(int data)
             {
                  if((head->data)>=STACK_MAX)
                                           return;
                  (head->data)++;
                  StackElement element=newNode(data,top);
                  
                  top=element;
             }
             
             StackElement pop()
             {
                          if(head->data<=0) return NULL;
                          head->data--;
                          StackElement temp=top;
                          top=top->next;
                          return temp;
             }
              
             void printStack()
             {
                  if(head->data==0)
                  {
                                   cout<<"\nStack Empty!\n";
                                   return;
                  }
                  
                         StackElement iter;
                         iter=top;
                         cout<<"\n*********\n";
                         for(int i=1; i<=head->data;i++)
                         {
                                 cout<<"\n"<<iter->data;
                                 iter=iter->next;
                         }
                         cout<<"\n*********\n"; 
             }    
            
             void drawStack()
             {
                  StackElement curr=top;
                  topY=(head->data + 2)*nodeHt;
                  //if(curr==NULL) return;
                  while(curr!=head)
                  {
                                  
                                  draw_node(curr);
                                  curr=curr->next;
                  }
             }
             int getval(StackElement n)
             {
                 return (n->data);
             }
             friend void print_num(int num, GLfloat scale=1,GLfloat x=0, GLfloat y=0, GLfloat z=0);
             friend void draw_node(StackElement n);        
          
};                 


int stack_in[5]={1,2,3,4,5};
stack s(stack_in,5);
   

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

    
    gluPerspective(35.0f, fAspect, 1.0, 40.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

}





void draw_square(GLfloat x, GLfloat y, GLfloat l)
{
     glColor3fv(colors[((color_n++)%COLOR_MAX)]);
     glBegin(GL_QUADS);
                       glVertex2f(x,y);
                       glVertex2f(x+l,y);
                       glVertex2f(x+l,y+l);
                       glVertex2f(x,y+l);
     glEnd();
     
}

void draw_node(StackElement n)
{
     //ht=119.05 wd= 104.76
      GLfloat scale= (nodeHt/119.05)*.5;
      //int num=0;
      int num=n->data;//s.getval(n);
      draw_square(topX,topY, nodeHt);
      print_num(num,scale,topX,topY);  
                                             
      topY-=(nodeHt+2);
      
}
     
 

void display()
{
     glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
     
     glMatrixMode(GL_MODELVIEW);
     glLoadIdentity();
     
   
     s.drawStack();

     glFlush();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB /*| GLUT_DEPTH*/);
    glutInitWindowSize(800, 800);
    glutCreateWindow("Stack");
    //glutReshapeFunc(myReshape);
    //glutSpecialFunc(keyControl);
    //glutIdleFunc(idler);
    glutDisplayFunc(display);
    myinit();
    glutMainLoop();
    
    return 0;
}
