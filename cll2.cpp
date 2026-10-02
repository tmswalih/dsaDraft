#include <iostream>
using namespace std;

struct node
{
    int data;
    node* next;

};

node* last= nullptr;

void insertFirst(int value)
{
    node* ptr=last;
    node* newnode= new node{value,nullptr};

    if(last==nullptr)
    {
        last=newnode;
        newnode->next=last;
        return;
    }
    newnode->next=last->next;
    last->next=newnode;
}

void deleteFirst()
{
    if(last==nullptr)
    {
        cout<<"!";
    }
    else if(last->next==nullptr)
    {
        last=nullptr;

    }
    else{

        last=last->next;
    }
}

void insertLast(int value)
{
    node* ptr=last;
    node* newnode= new node{value,nullptr};

    if(last==nullptr)
    {
        last=newnode;
        return;
    }
    while(ptr->next!=nullptr)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;

}

void deleteLast()
{
    if(last==nullptr)
    {
        cout<<"!";
    }
    else if(last->next==nullptr)
    {
        last=nullptr;

    }
    else{
        
        node* ptr=last;
        while(ptr->next->next!=nullptr)
        {
           ptr=ptr->next;
        }
        ptr->next=nullptr;
            
       
    }
}

void display()
{
    cout<<"\nLinked List:";
    if(last==nullptr)
    {
        cout<<"List is empty!";
    }
    
    node *ptr=last;
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
        cout<<"\n1-InsertFirst\n2-DeleteFirst\n3-InsertLast\n4-DeleteLast\n0-Exit";
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
            deleteFirst();
            display();
            break;

        }   
        case 3:
        {
            cout<<"\nEnter value:";
            cin>>value;
            insertLast(value);
            display();
            break;
        }
        case 4:
        {
            deleteLast();
            display();
            break;

        }   

        case 0:
        {
            return 0;
            break;
        }  
        default:cout<<"Invalied choice";break; 

        }

    }
}