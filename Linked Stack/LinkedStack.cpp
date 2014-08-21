#include<iostream>
using namespace std;
#define STACK_MAX 10

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
                  if(head->data>=STACK_MAX)
                                           return;
                  head->data++;
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
          
};                 
/*      
int main()
{
    stack s;
    
    s.printStack();
    s.push(10);
    s.printStack();
    s.push(20);
    s.printStack();
    s.push(30);
    s.printStack();
    
    StackElement temp = s.pop();
    if(temp) cout<<"\nElement popped : "<<temp->data<<endl;
    s.printStack();
    
    temp = s.pop();
    if(temp) cout<<"\nElement popped : "<<temp->data<<endl;
    s.printStack();
    
    temp = s.pop();
    if(temp) cout<<"\nElement popped : "<<temp->data<<endl;
    s.printStack();
    
    temp = s.pop();
    if(temp) cout<<"\nElement popped : "<<temp->data<<endl;
    s.printStack();
    
    temp = s.pop();
    if(temp) cout<<"\nElement popped : "<<temp->data<<endl;
    s.printStack();
    
    system("pause");
}
    
*/
