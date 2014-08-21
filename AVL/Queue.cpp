#include<iostream>
using namespace std;
#define NODE_MAX 20
class Queue
{
      int *q,front,rear;
      
      public:
             Queue()
             {
                    q=new int[NODE_MAX];
                    front=0;
                    rear=-1;
             }
             
             void insert(int data)
             {
                  if(front>rear)
                  {
                               front=rear=0;
                               q[rear++]=data;
                  }
                  else
                  {
                               q[rear++]=data;
                  }
                      
             }
             
             int pop()
             {
                 int temp=q[front];
                 front++;
                 return temp;
             } 
             
             void display()
             {
                  if(front>rear)
                  {
                                cout<<"\nQueue is empty..\n";
                                return;
                  }
                  cout<<"\n";
                  for(int i=front; i< rear ; i++)
                  {
                          cout<<"\t"<<q[i];
                  }
                  cout<<"\n";
             }
};

int main()
{
          Queue q;
          int y=1,c;
          while(y)
          {
                  
                  
                  cout<<"\n1.Insert\n2.Pop\n3.Display\n0.Exit\n";
                  cin>>y;
                  
                  switch(y)
                  {
                           case 1: 
                                
                                cout<<"\nEnter element to insert: "; cin>>c;
                                q.insert(c);
                                break;
                           case 2:
                                cout<<"\nElement popped : "<<q.pop()<<endl;
                                break;
                           case 3:
                                q.display();
                                break;
                           case 0:
                                cout<<"\nTerminating..\n";
                                break;
                           default:
                                   cout<<"\nBad input. Retry..\n";
                  }
          }
}
                                
                                
                               
