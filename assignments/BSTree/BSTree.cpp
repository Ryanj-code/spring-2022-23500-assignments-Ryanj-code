#include <iostream>
#include "BSTree.h"

BSTree::BSTree(){
  root = nullptr;
}

void BSTree::insert(int d){ 
  
}

std::string BSTree::traverse(Node *root){
  if(root){
    return std::to_string(root->getData()) + "-->" + traverse(root->getLeft()) + traverse(root->getRight());
  } else {
    return "";
  }
}

std::string BSTree::get_debug_string(){
  std::string result = "";

  if(root == nullptr){
    return "";  
  } else { 
     result = traverse(root);
  }

  return result + "nullptr"; 
}

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
  n = new Node(7);
  n2->setLeft(n);  
}

int BSTree::search(int value){
  Node *t = root;

  while (t != nullptr){
    int tval = t->getData();
    if (tval==value){
      // here we'd really return a full object
      // with all the stuff associated with value
      // not just an int
      return value;
    }

    if (tval < value){
      t = t->getRight();
    } else {
      t = t->getLeft();
    }
    
  }

  // if we get here then the value isn't
  // in the tree

  // normally, if we had a tree of objects
  // we could return null but since we only have
  // an int, we can't return an int to represent
  // not found so we'll throw an exception

  throw 1; // we should define our exceptions. 
}

