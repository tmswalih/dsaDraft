#include <iostream>
using namespace std;

struct Node
{
	int data;
	Node* left;
	Node* right;
	
};

Node* left=nullptr;
Node* right=nullptr;

Node* createnode(int value)
{
	Node* newnode = new Node();
	newnode->data= value;
	newnode->left=newnode->right= nullptr;
	return newnode;
}


Node* insert(int value,Node* root)
{
	if(root==nullptr)
		return createnode(value);
	if(value<root->data)
		root->left=insert(value,root->left);
	else if(value>root->data)
		root->right=insert(value,root->right);
	return root;
}

void inorder(Node* root)
{
	
	if(root!=nullptr)
	{
		
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
void postorder(Node* root)
{
	if(root!=nullptr)
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}
void preorder(Node* root)
{
	if(root!=nullptr)
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
		
	}
}




int main(){
	Node* root=nullptr;
	int option,flag=1,value;

	while(true)
	{cout<<"\nChoose an option from below\n1.insertNode\n2.deleteNode\n3.Preorder Traversal\n4.Postorder Traversal\n5.Inorder Traversal\n6.Exit\n";

	cin>>option;

	switch (option)
	{
		case 1:
		{
			cout<<"\nEnter the value\t\t";
			cin>>value;
			root=insert(value,root);
			inorder(root); 
			break;
		}	
	case 2:
		{
			cout<<"Inorder Traversal";
			inorder(root);
			break;
		}
	case 3:
		{
			cout<<"Postorder Traversal";
			postorder(root);
			break;
		}
	case 4:
		{
			cout<<"preorder Traversal";
			preorder(root);
			break;
		}		

		case 0:
		{
			return false;	
			break;
		}
		default:
		break;	



		
	}
	}


}


