#include<iostream>
#include<stdlib.h>

using namespace std;

typedef struct node
{
	struct node* left;
	int payload;
	struct node* right;
}Node;

Node* root = NULL;
Node* create();
void Insert(Node*, Node* = root);
void Traversal(Node* = root);
void DeleteWithoutLeftChild(Node* = root);
void DeleteWithoutRightChild(Node* = root);
void DeleteWithChild(Node* = root, char = 'r');

void main()
{
	for (int i = 0; i < 7; i++)
		Insert(create());

	cout << "Display the elements: \n";
	Traversal();

	DeleteWithChild();
	cout << "Display the elements: \n";
	Traversal();
	system("pause");
}

void Insert(Node* ptr, Node* temp)
{
	if (temp == NULL)
		root = ptr;
	else if (temp->payload < ptr->payload)
	{
		if (temp->right == NULL)
			temp->right = ptr;
		else
			Insert(ptr,temp->right);
	}
	else if (temp->payload > ptr->payload)
	{
		if (temp->left == NULL)
			temp->left = ptr;
		else
			Insert(ptr, temp->left);
	}
}

void Traversal(Node* temp)
{
	if (temp)
	{
		Traversal(temp->left);
		cout << temp->payload << "  ";
		Traversal(temp->right);
	}
}

Node* create()
{
	Node* ptr = (Node*)calloc(1, sizeof(Node));
	cout << "Enter Payload: ";
	cin >> ptr->payload;
	return ptr;
}

void DeleteWithoutLeftChild(Node* parent)
{
	Node* temp = parent->left;
	if (temp->left != NULL)
		DeleteWithoutLeftChild(parent->left);
	else
	{
		parent->left = temp->right;
		cout <<endl<< "Node is : " << temp->payload << endl;
		free(temp);
		return;
	}
}

void DeleteWithoutRightChild(Node* parent)
{
	Node* temp = parent->right;
	if (temp->right != NULL)
		DeleteWithoutRightChild(parent->right);
	else
	{
		parent->right = temp->left;
		cout << endl<< "Node is : " << temp->payload<< endl;
		free(temp);
	}
}

void DeleteWithChild(Node* parent1, char ch)
{
	Node* parent;
	if (ch = 'r')
		parent = parent1->right;
	else
		parent = parent1->left;
	if (!parent->left->left && !parent->left->right && !parent->right->left && !parent->right->right)
	{
		parent1->right = parent->right;
		parent->right->left = parent->left;
		cout << "\nNode is : " << parent->payload << endl;
		free(parent);
	}
	else
		DeleteWithChild(parent);
}