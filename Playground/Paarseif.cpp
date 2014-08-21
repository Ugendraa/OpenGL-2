#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
int elsef=0;

void Error()
{
	cout<<"\nParsing error..Terminating...\n\n";
	return;
}
int nextPart(char *src, int curr,char *dest)
{
	int start,stop;
	start=curr;
	
	while(src[start]!='(')
	{
		start++;
		if(src[start]=='\0')
		{
			cout<<"\nOPEN\n";
			//Error();
			return -1;
		}
	}
	
	start++;
	
	stop=start;
	
	while(src[stop]!=')')
	{
		stop++;
		if(src[stop]=='\0') 
		{
			cout<<"\nCLOSE\n";
			//Error();
			return -1;
		}
	}
	
	
	for(int i=start ; i<stop ; i++)
	{
		dest[i-start]=src[i];
	}
	
	dest[stop-start]='\0';
	return stop;
}

int main()
{
	int curr=0;
	char input[100],cond[50],act1[50],act2[50];
	
	gets(input);
	
	for(int i=0; i<3 ; i++)
	{
		switch(i)
		{
			case 0:
				//curr=find("if",input);
				curr=nextPart(input,curr,cond);
				if(curr<0)
				{
					cout<<"\nPart0\n";
					Error();
					exit(0);
				}
				break;
			case 1:
				curr=nextPart(input,curr,act1);
				if(curr<0)
				{
					cout<<"\nPart1\n";
					Error();
					exit(0);
				}
				break;
			case 2:
				curr=nextPart(input,curr,act2);
				if(curr>0)
				{
					elsef=1;
				}
				break;
		}
	}
	
	if(elsef)
	{
		cout<<"\nif ("<<cond<<") goto 101";
		cout<<"\ngoto 102";
		cout<<"\n101: "<<act1<<"\ngoto 103";
		cout<<"\n102: "<<act2;
		cout<<"\n103: \n";
	}
	else
	{
		cout<<"\nif ("<<cond<<") goto 101";
		cout<<"\ngoto 102";
		cout<<"\n101: "<<act1;
		cout<<"\n102: \n";
	}

	return 0;
}
		
	

				
