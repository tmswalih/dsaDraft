#include <iostream>
using namespace std;

struct node
{
	int data;
	node *next;
	node *prev;

};

node *start = nullptr;

void insertFirst(int value)
{
	node *ptr=start;
	node* newnode= new node{value,nullptr,nullptr};
	

	if(start==nullptr)
	{
		start=newnode;
	}
	else{
		newnode->next=start;
		start->prev=newnode;
		start=newnode;
	}


}

void deleteNode(int value)
{
	node* ptr=start;
	if(start->data==value)
	{
		if(start->next==nullptr)
		{
			start=nullptr;
		}
		else{
		start=start->next;
		start->prev=nullptr;}
		return;
	}
	else
	{
	while(ptr->next->data!=value)
	{
		ptr=ptr->next;
	}
	ptr->next=ptr->next->next;
}
}

void display()
{
	 if(start==nullptr)
   
	cout<<"\nLinked List:";
	{
        cout<<"List is empty!";
    }
	node *ptr=start;
	while(ptr!=nullptr)
	{
		cout<<ptr->data<<" <--> ";
		ptr=ptr->next;
		
	}	
}

int main()
{
	int option,value;
	while(true)
	{
		cout<<"\n\nchoose an option from below";
		cout<<"\n1-InsertFirst\n2-";
		cin>>option;

		switch(option)
		{
		case 1:
			{
				cout<<"\nEnter value:";
				cin>>value;
				insertFirst(value);
				display();
				break;
			}

		case 2:
		{
			cout<<"\nEnter value:";
			cin>>value;
			deleteNode(value);
			display();
			break;

		}	

		case 0:
		{
			return 0;
		}	

		}

	}
}