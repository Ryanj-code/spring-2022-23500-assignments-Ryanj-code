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
  /*
     pre-order traversal
     
     1. process the node
     2. recurse to left subtree
     3. recurse to right subtree

     a = std::to_string(n->getData());
     b =  traverse(n->getLeft());
     c =  traverse(n->getRight());

     
     post-order traversal
     
     1. recurse to left subtree
     2. recurse to right subtree
     3. process the node
      
     a =  traverse(n->getLeft());
     b =  traverse(n->getRight());
     c = std::to_string(n->getData());
      

    in-order traversal
	
    1. recurse left subtree
    2. process node
    3. recurse right subtree
    */
    
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

int BSTree::rsearch(int value, Node *n){
  if (n == nullptr){
    throw TREE_ERR_NULL;
  } // If n becomes nullptr, throw exception.

  int data = n->getData();
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

// we will always insert new nodes as leaves
void BSTree::insert(int value){

  // make a new node
  Node *newnode = new Node(value);
  
  // search for where the node would go as a leaf
  // that is, search until we get to null
  // we can use the piggyback strategy of having
  // a second pointer trail the lead pointer
  Node *p = root;
  Node *trailer;

  
  while (p != nullptr) {
    // note that trailer is one level behind
    trailer = p;
    if (p->getData() == value){
      // do the stuff when the node is already in the tree
      return;
    }
    else if (p->getData() < value){
      p = p->getRight(); 
    } else {
      p = p->getLeft();
    }
  }
  
  // handle the special case of the tree
  // being empty (null)
  if (root==nullptr){
    root=newnode;
  } else {
    // trailer points to the node ABOVE where the new node
    // will go.
    // we have to figure out if newnode goes on the
    // left of trailer or on the right of trailer
    if (trailer->getData() < value){
      trailer->setRight(newnode);
    } else {
      trailer->setLeft(newnode);
    }

  }
}

void BSTree::deleteValue(int value){
  
}
  
int BSTree::countLeaves(Node *n){
  if(n == nullptr){
    throw 1;
  }
  else if(n->getLeft() == nullptr && n->getRight() == nullptr){
    return 1;
  }
  
  return countLeaves(n->getLeft()) + countLeaves(n->getRight());
}

int BSTree::countLeaves(){
  return countLeaves(root);
}

int BSTree::treeHeight(Node *n){
  if(n == nullptr){
    return -1;
  }

  int left = treeHeight(n->getLeft());
  int right = treeHeight(n->getRight());
 
  if(left > right){
    return left + 1;
  }
  else{
    return right + 1;
  }
}

int BSTree::treeHeight(){
  return treeHeight(root);
}

int BSTree::levelSum(Node *n, int curr, int lvl){
  if(n == nullptr){
    return 0;
  }

  if(curr == lvl){
    return n->getData();
  } // Return root.

  return levelSum(n->getLeft(), curr + 1, lvl) + levelSum(n->getRight(), curr + 1, lvl);
}

int BSTree::levelSum(int lvl){
  if(lvl < 0 || treeHeight() < lvl){
    throw 2;
  } // Throw exception when level is negative or greater than the height of the tree.

  return levelSum(root, 1, lvl);
}

