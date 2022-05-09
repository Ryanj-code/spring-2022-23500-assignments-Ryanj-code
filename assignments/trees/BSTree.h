#pragma once 
#include "Node.h"
#include <string>

#define TREE_ERR_NULL 1

class BSTree {
 private: 
  Node *root; 

 public:
  BSTree();
  void insert(int d);
  std::string get_debug_string();
  std::string traverse(Node *root);
  void setup(); 
  int rsearch(int value);
  int rsearch(int value, Node *n);
};
