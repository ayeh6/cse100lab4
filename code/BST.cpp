#include <iostream>
#include <string>
#include "BST.h"

using namespace std;


/****************************************************************
 * CONSTRUCTOR
 *   Creates an empty binary tree
 ****************************************************************/
BST::BST() {
	root = NULL;
}

/****************************************************************
 * DESTRUCTOR
 *   Free all memory used by current tree
 ****************************************************************/
BST::~BST() {
  // Write code to remove and deallocate all nodes in the tree
	delete root;
}

void BST::Insert(int toInsert) {
  // Write your code here
	Node* x = new Node;
	Node* y = new Node;
	Node* z = new Node;
	x = root;
	y = NULL;
	z->val = toInsert;
	z->left = NULL;
	z->right = NULL;
	while (x != NULL)
	{
		y = x;
		if(z->val < x->val)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	z->parent = y;
	if (y == NULL)
	{
		root = z;
	}
	else if (z->val < y->val)
	{
		y->left = z;
	}
	else
	{
		y->right = z;
	}
}

void BST::Delete(int toDelete) {
  // Write your code here
	Node* z = new Node;
	z = Search(toDelete);
	//cout << "z value is " << z->val << endl;
	if(z == NULL)
	{
		//cout << "z is null" << endl;
		return;
	}
	if(z->left == NULL)
	{
		//cout << "z left is null" << endl;
		Transplant(z,z->right);
	}
	else if(z->right == NULL)
	{
		//cout << "z right is null" << endl;
		Transplant(z,z->left);
	}
	else
	{
		Node* y = new Node;
		y = Minimum(z->right);
		if(y->parent != z)
		{
			Transplant(y,y->right);
			y->right = z->right;
			y->right->parent = y;
		}
		Transplant(z,y);
		y->left = z->left;
		y->left->parent = y;
	}
}

void BST::Transplant(Node *u, Node *v) {
  // Write your code here
	if(u->parent == NULL)
	{
		root = v;
	}
	else if(u == u->parent->left)
	{
		u->parent->left = v;
	}
	else
	{
		u->parent->right = v;
	}
	if(v != NULL)
	{
		v->parent = u->parent;
	}
}

Node *BST::Successor(Node *x) {
  // Write your code here
	if(x->right != NULL)
	{
		return Minimum(x->right);
	}
	Node* y = new Node;
	y = x->parent;
	while((y != NULL) && (x == y->right))
	{
		x = y;
		y = y->parent;
	}
	return y;
}

Node *BST::Minimum(Node *x) {
  // Write your code here
	while(x->left != NULL)
	{
		x = x->left;
	}
	return x;
}

Node *BST::Maximum(Node *x) {
  // Write your code here
	while(x->right != NULL)
	{
		x = x->right;
	}
	return x;
}

Node *BST::Search(int toFind) {
  // Write your code here
	Node* x = new Node;
	x = root;
	while((x != NULL) && (toFind != x->val))
	{
		if(toFind < x->val)
		{
			x = x->left;
		}
		else
		{
			x = x->right;
		}
	}
	return x;
}

void BST::Print(TraversalOrder Order) {
  if(Order==InOrderTrav)
    InOrder(root);
  else if(Order==PreOrderTrav)
    PreOrder(root);
  else if(Order==PostOrderTrav)
    PostOrder(root);
}

void BST::PreOrder(Node *x) {
  // Write your code here
	if(x == NULL)
	{
		return;
	}
	cout << x->val << endl;
	PreOrder(x->left);
	PreOrder(x->right);
}

void BST::InOrder(Node *x) {
  // Write your code here
	if(x == NULL)
	{
		return;
	}
	InOrder(x->left);
	cout << x->val << endl;
	InOrder(x->right);
}

void BST::PostOrder(Node *x) {
  // Write your code here
	if(x == NULL)
	{
		return;
	}
	PostOrder(x->left);
	PostOrder(x->right);
	cout << x->val << endl;
}

