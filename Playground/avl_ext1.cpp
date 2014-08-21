#include <iostream.h>
#include <graphics.h>
#include <conio.h>
#include <stdlib.h>

class CNode
{
 private:
  int iData;
 public:
  CNode *pLeft,*pRight,*pParent;
  CNode(int N){ iData=N;pParent=pLeft=pRight=NULL;}
  CNode(int N,CNode *Parent){ iData=N;pParent=Parent;pLeft=pRight=NULL;}
  int GetData(){ return iData; }
};

class CBinaryTree
{
 private:
  CNode *pRoot;
  CNode *LocateNode(int Data,CNode *Root);
  CNode *LocateParent(int Data,CNode *Root);
  CNode *FindInsertionPoint(int Data,CNode *Root);
  void RotateLeft(CNode *Parent);
  void RotateRight(CNode *Parent);
  int GetBalancingFactor(CNode *Root);
  void DrawNode(CNode *Root,int X,int Y,int PrevX,int PrevY,int Level);
  void DeleteTree(CNode *pNode);
 public:
  CBinaryTree(){ pRoot=NULL; }
  ~CBinaryTree(){ DeleteTree(pRoot); }
  void AddNode(int N);
  void DeleteNode(int N);
  int GetLeftChild(int N);
  int GetRightChild(int N);
  int GetParent(int N);
  void ShowTree();
};

CNode *CBinaryTree::LocateNode(int Data,CNode *Root)
{
 CNode *pNode=Root;
 while(pNode!=NULL)
 {
  if(pNode->GetData()<Data)
   pNode=pNode->pRight;
  else
   if(pNode->GetData()>Data)
    pNode=pNode->pLeft;
   else
    break;
 }
 return pNode;
}

CNode *CBinaryTree::LocateParent(int Data,CNode *Root)
{
 CNode *pNode=Root,*pParent=NULL;
 while(pNode!=NULL && pNode->GetData()!=Data)
 {
  pParent=pNode;
  if(pNode->GetData()<Data)
   pNode=pNode->pRight;
  else
   if(pNode->GetData()>Data)
    pNode=pNode->pLeft;
 }
 return pParent;
}

CNode *CBinaryTree::FindInsertionPoint(int Data,CNode *Root)
{
 CNode *pNode=Root;
 while(pNode->pLeft!=NULL)
  if(pNode->GetData()>Data)
   pNode=pNode->pLeft;
  else
   break;
 return pNode;
}

void CBinaryTree::AddNode(int N)
{
 CNode *pNode,*pParent=NULL,*pNewNode;

 pNode=LocateNode(N,pRoot);
 pParent=LocateParent(N,pRoot);
 if(pParent==NULL)
  pRoot=new CNode(N);
 else
 {
  if(pNode==NULL)
  {
   pNewNode=new CNode(N,pParent);
   if(pParent->GetData()>N)
    pParent->pLeft=pNewNode;
   else
    pParent->pRight=pNewNode;
   }
  }
 while(pParent!=NULL)
 {
  int iBF=GetBalancingFactor(pParent->pRight)-GetBalancingFactor(pParent->pLeft);
  if(iBF<-1 || iBF>1)
  {
   if(iBF>0)
    RotateLeft(pNewNode);
   else
    RotateRight(pNewNode);
   if(pNewNode->pParent==NULL) pRoot=pNewNode;
  }
  pParent=pParent->pParent;
  pNewNode=pNewNode->pParent;
 }
}

void CBinaryTree::DeleteNode(int N)
{
 CNode *pNode=pRoot,*pParent=NULL;

 pNode=LocateNode(N,pRoot);
 pParent=LocateParent(N,pRoot);

 if(pNode!=NULL)
 {
  if(pParent==NULL)
  {
   pRoot=pNode->pRight;
   pParent=FindInsertionPoint(pNode->pLeft->GetData(),pNode->pRight);
   pParent->pLeft=pNode->pLeft;
  }
  else
  {
   if(pParent->pLeft==pNode)
   {
    if(pNode->pRight==NULL && pNode->pLeft!=NULL)
     pParent->pLeft=pNode->pLeft;
    if(pNode->pRight!=NULL && pNode->pLeft==NULL)
     pParent->pLeft=pNode->pRight;
    if(pNode->pRight!=NULL && pNode->pLeft!=NULL)
    {
     pParent->pLeft=pNode->pRight;
     pParent=FindInsertionPoint(pNode->pLeft->GetData(),pNode->pRight);
     if(pParent->GetData()>N)
      pParent->pLeft=pNode->pLeft;
     else
      pParent->pRight=pNode->pLeft;
    }
   }
   else
   {
    if(pNode->pRight==NULL && pNode->pLeft!=NULL)
     pParent->pRight=pNode->pLeft;
    if(pNode->pRight!=NULL && pNode->pLeft==NULL)
     pParent->pRight=pNode->pRight;
    if(pNode->pRight!=NULL && pNode->pLeft!=NULL)
    {
     pParent->pLeft=pNode->pRight;
     pParent=FindInsertionPoint(pNode->pLeft->GetData(),pNode->pRight);
     if(pParent->GetData()<N)
      pParent->pLeft=pNode->pLeft;
     else
      pParent->pRight=pNode->pLeft;
    }
   }
  }
  delete pNode;
 }
 else
  cout<<endl<<"Node not found!";
}

int CBinaryTree::GetLeftChild(int N)
{
 CNode *pNode=LocateNode(N,pRoot);

 if(pNode!=NULL)
  if(pNode->pLeft!=NULL)
   return pNode->pLeft->GetData();
  else
   cout<<endl<<"Node didn't have left child!";
 else
  cout<<endl<<"Node not found!";
 return 0;
}

int CBinaryTree::GetRightChild(int N)
{
 CNode *pNode=LocateNode(N,pRoot);

 if(pNode!=NULL)
  if(pNode->pRight!=NULL)
   return pNode->pRight->GetData();
  else
   cout<<endl<<"Node didn't have right child!";
 else
  cout<<endl<<"Node not found!";
 return 0;
}

int CBinaryTree::GetParent(int N)
{
 CNode *pNode=LocateParent(N,pRoot);
 if(pNode!=NULL)
  return pNode->GetData();
 else
  cout<<endl<<"Either the node not found or node is root node!";
 return 0;
}

void CBinaryTree::DrawNode(CNode *Root,int X,int Y,int PrevX,int PrevY,int Level)
{
 if(Root!=NULL)
 {
  char Data[5];
  char BF[2];

  setcolor(WHITE);
  circle(X,Y,7);
  floodfill(X,Y,WHITE);
  line(X,Y-7,PrevX,PrevY+7);

  itoa(Root->GetData(),Data,10);
  setcolor(RED);
  settextjustify(CENTER_TEXT,TOP_TEXT);
  outtextxy(X,Y-3,Data);
  itoa(GetBalancingFactor(Root->pRight)-GetBalancingFactor(Root->pLeft),BF,10);
  setcolor(GREEN);
  settextjustify(RIGHT_TEXT,TOP_TEXT);
  outtextxy(X-10,Y-2,BF);
  setcolor(WHITE);

  DrawNode(Root->pLeft,X-(30+Level),Y+30,X,Y,Level+10);
  DrawNode(Root->pRight,X+(30-Level),Y+30,X,Y,Level-10);
 }
}

void CBinaryTree::ShowTree()
{
 int gdriver = DETECT, gmode, errorcode;
 initgraph(&gdriver, &gmode, "C:\\TC\\BGI");

 DrawNode(pRoot,getmaxx()/2,10,getmaxx()/2,10,0);
 getch();

 closegraph();
}

int CBinaryTree::GetBalancingFactor(CNode *Root)
{
 if(Root!=NULL)
 {
  int iLeftBF=GetBalancingFactor(Root->pLeft);
  int iRightBF=GetBalancingFactor(Root->pRight);
  return (iLeftBF>iRightBF?iLeftBF:iRightBF)+1;
 }
 else
  return 0;
}
void CBinaryTree::RotateLeft(CNode *Node)
{
 Node->pParent->pRight=Node->pLeft;
 Node->pLeft=Node->pParent;
 Node->pParent=Node->pLeft->pParent;
 if(Node->pLeft->pParent->pLeft==Node->pLeft)
  Node->pLeft->pParent->pLeft=Node;
 else
  Node->pLeft->pParent->pRight=Node;
 Node->pLeft->pParent=Node;
}
void CBinaryTree::RotateRight(CNode *Node)
{
 Node->pParent->pLeft=Node->pRight;
 Node->pRight=Node->pParent;
 Node->pParent=Node->pRight->pParent;
 if(Node->pRight->pParent->pLeft==Node->pRight)
  Node->pRight->pParent->pLeft=Node;
 else
  Node->pRight->pParent->pRight=Node;
 Node->pRight->pParent=Node;
}
void CBinaryTree::DeleteTree(CNode *pNode)
{
 if(pNode!=NULL)
 {
  DeleteTree(pNode->pLeft);
  DeleteTree(pNode->pRight);
  delete pNode;
 }
}
void main()
{
 CBinaryTree bt;int ch;int data;

 do{
  cout<<endl<<"1.Add Node";
  cout<<endl<<"2.Delete Node";
  cout<<endl<<"3.Find Parent";
  cout<<endl<<"4.Find Left Child";
  cout<<endl<<"5.Find Right Child";
  cout<<endl<<"6.Display Tree";
  cout<<endl<<"0.Exit";
  cout<<endl<<"Enter your choice?";
  cin>>ch;
  switch (ch)
  {
   case 1:
	  cout<<"Enter node to add?";
	  cin>>data;
	  bt.AddNode(data);
	  break;
   case 2:
	  cout<<"Enter node to delete?";
	  cin>>data;
	  bt.DeleteNode(data);
	  break;
   case 3:
	  cout<<"Enter node to find it's parent?";
	  cin>>data;
	  cout<<"The parent of node "<<data<<" is "<<bt.GetParent(data);
	  break;
   case 4:
	  cout<<"Enter node to find it's left child?";
	  cin>>data;
	  cout<<"The left child of node "<<data<<" is "<<bt.GetLeftChild(data);
	  break;
   case 5:
	  cout<<"Enter node to find it's right child?";
	  cin>>data;
	  cout<<"The right of node "<<data<<" is "<<bt.GetRightChild(data);
	  break;
   case 6:
	  bt.ShowTree();
	  break;
  }
 }while(ch!=0);
}
