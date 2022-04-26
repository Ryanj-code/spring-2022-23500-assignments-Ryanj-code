#pragma once 
#include "Node.h"
#include <string>

class BSTree {
 private: 
  Node *root; 

 public:
  BSTree();
  void insert(int d);
  std::string get_debug_string();
  std::string traverse(Node *root);
  void setup(); 
};
