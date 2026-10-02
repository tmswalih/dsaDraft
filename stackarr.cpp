#include <iostream>
using namespace std;

int top=-1,max=5;
int *stackArray;

void push()
{
	int x;
	if(top== max-1 )
	{
		cout<<"StackOverflow";
		return;
	}
	cout<<"Enter the value";
	cin>>x;
	stackArray[++top]=x;

}

void pop()
{

	if(top==-1)
	{
		cout<<"StackUnderflow";
		return;
	}
	cout<<"\nPopped."<<stackArray[top--]<<" ";

}

void display()
{
	int i;
	if(top==-1)
	{
		cout<<"\nStack is empty";
		return;

	}cout<<"\nStack:";
	for(int i=top;i!=-1;i--)
	{
		cout<<stackArray[i]<<"  ";
	}
}






int main()
{

	stackArray= new int[max];
	int option;

	

	while(true)
	{
		cout<<"Please choose an option from below\n1-Push\n2-Pop\n3-display\n0-Exit";
	cin>>option;
		switch (option)
		{
		case 1:{push();display();break;}
		case 2:{pop();display();break;}
		case 3:display();break;
		case 4:return 0;break;
		default:break;	

		}
	}
}
