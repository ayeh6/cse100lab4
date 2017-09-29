#include <iostream>
#include <string>
#include "BST.h"

using namespace std;


/****************************************************************
 * CONSTRUCTOR
 *   Creates an empty binary tree
 ****************************************************************/
BST::BST() {
}

/****************************************************************
 * DESTRUCTOR
 *   Free all memory used by current tree
 ****************************************************************/
BST::~BST() {
  // Write code to remove and deallocate all nodes in the tree
}

void BST::Insert(int toInsert) {
  // Write your code here
}

void BST::Delete(int toDelete) {
  // Write your code here
}

void BST::Transplant(Node *u, Node *v) {
  // Write your code here
}

Node *BST::Successor(Node *x) {
  // Write your code here
}

Node *BST::Minimum(Node *x) {
  // Write your code here
}

Node *BST::Maximum(Node *x) {
  // Write your code here
}

Node *BST::Search(int toFind) {
  // Write your code here
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
}

void BST::InOrder(Node *x) {
  // Write your code here
}

void BST::PostOrder(Node *x) {
  // Write your code here
}

