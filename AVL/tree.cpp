#include<iostream>
using namespace std;
#define NODE_MAX 20
struct node
{
       int id,data,level;
       struct node* left;
       struct node* right;
};

typedef struct node* Node;


class Queue
{
      
      Node *q;
      int front,rear,empty;
      
      public:
             Queue()
             {
                    q=new Node[NODE_MAX];
                    front=0;
                    rear=-1;
                    empty=1;
                    
             }
             
             void insert(Node item)
             {
                  if(front>rear)
                  {
                               front=rear=0;
                               q[rear]=item;
                               empty=0;
                  }
                  else
                  {
                               q[++rear]=item;
                  }
                      
             }
             
             Node pop()
             {
                 Node temp=q[front];
                 front++;
                 if(front>rear)
                 {
                               front=0;
                               rear=-1;
                               empty=1;
                 }
                 return temp;
             } 
             
             bool isEmpty() { return empty; }
            
};
             

class tree
{
      Node root;
      int count;
      //int node_count=0;
      
      public:
             tree()
             {
                   count=0;
                   root=createNode(0,NULL,NULL);
             }
             tree(int data)
             {
                   count=0;
                   root=createNode(data,NULL,NULL);
             }
             
             tree(int nodes[],int n)
             {
                      //build the tree
             }
             
             Node createNode(int data, Node lchild, Node rchild,int root_level=-1)
             {
                            int c=++count;     
                            Node temp = new struct node;
                            temp->id=c;
                            temp->data=data;
                            temp->level=root_level+1;
                            temp->left=lchild;
                            temp->right=rchild;
                            
                            return temp;
             }
             void display()
             {
                  cout<<"\n...\n";
                  bfs();
                  cout<<"\n..\n";
             }
             
             void bfs()
             {
			 
                  
                  static int visited[NODE_MAX];
                  Queue Q;
                  
                 
                  
                  Node curr;
                  int curr_level=0,old_level=0;
                  
                  Q.insert(root);
                  
                  while(!Q.isEmpty())
                  {
                  
                                 curr=Q.pop();  
                                 curr_level=curr->level;
                                 if(curr_level>old_level)
                                 {
                                                         old_level=curr_level;
                                                         cout<<"\n";
                                 }
                                                         
                                 cout<<"\t"<<curr->data; 
                                 visited[curr->id]=1;
                                 for(int i=0; i<2; i++)
                                 {
                                          Node child;
                                          if(i==0)  child=curr->left; 
                                          else      child=curr->right ;
                                          
                                          if(child==NULL) continue;
                                          if(!visited[child->id])
                                                            Q.insert(child);
                                 }
                                 
                                                     
                  
                  
                  }
                  
            
                  
             }

			 void insert(int in)
			 {
					bool done=false;
					
					Node curr=root,temp;
					
					while(!done)
					{
							if(curr->data==in)
							{
								cout<<"\nElement exists!\n";
								done=true;
							}
							else if(curr->data>in)
							{
								temp=curr->left;
								
								if(temp==NULL)
								{
									temp=createNode(in,NULL,NULL,curr->level);
									curr->left=temp;
									done=true;
								}
								else
								{
									curr=curr->left;
								}
							}
							else
							{
								temp=curr->right;
								
								if(temp==NULL)
								{
									temp=createNode(in,NULL,NULL,curr->level);
									curr->right=temp;
									done=true;
								}
								else
								{
									curr=curr->right;
								}
							}
					}
              }		
};



int main()
{
    tree q(5);
    
    int ch=1,c;
	
	while(ch)
	{
		cout<<"\n1.Insert\n2.Display\n0.Exit\nEnter choice : "; cin>>ch;
		
		switch(ch)
                  {
                           case 1: 
                                
                                cout<<"\nEnter element to insert: "; cin>>c;
                                q.insert(c);
                                break;
                           
                           case 2:
                                q.display();
                                break;
                           case 0:
                                cout<<"\nTerminating..\n";
                                break;
                           default:
                                   cout<<"\nBad input. Retry..\n";
                  }
		
    }
    system("pause");
}
    
    
