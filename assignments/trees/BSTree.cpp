#include <iostream>
#include "Node.h"
#include "BSTree.h"

BSTree::BSTree(){
  root = nullptr;
}

// Traversal - visit every node in the tree
// O(n)
std::string BSTree::traverse(Node *n){
  std::string a,b,c;

  if (n==nullptr){
    return "";
  }
  else {
    a =  traverse(n->getLeft());
    b = std::to_string(n->getData());
    c =  traverse(n->getRight());

    return a + ", " + b+ ", " + c;
  }
};

std::string BSTree::get_debug_string(){
  return traverse(root);
};

void BSTree::setup(){
  Node *n = new Node(10);
  root = n;
  n = new Node(20);
  root->setRight(n);
  Node *n2 = new Node(30);
  n->setRight(n2);
  n2 = new Node(15);
  n->setLeft(n2);
  n2 = new Node(5);
  root->setLeft(n2);
  n = new Node(3);
  n2->setLeft(n);
  n = new Node(8);
  n2->setRight(n);

}

int BSTree::rsearch(int value, Node *n){
  if (n == nullptr){
    throw TREE_ERR_NULL;
  } // If n becomes nullptr, throw exception.

  int data = p->getData();
  if (value == data){
    return data;
  } // Just return data if the value is equal to the node's current data.
  
  else if (value < data){
    return rsearch(value, n->getLeft());
  } // Search left subtree to check if value is less than that node's value.
  
  else {
    return rsearch(value, n->getRight());
  } // Search right subtree to check if value is greater than that node's value.

}

int BSTree::rsearch(int value){
  return rsearch(value, root);
}
