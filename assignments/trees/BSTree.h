#pragma once 
#include "Node.h"
#include <string>

#define TREE_ERR_NULL 1
#define TREE_ERR_LVL 2

class BSTree {
 private: 
  Node *root; 

 public:
  BSTree();
  void insert(int value);
  std::string get_debug_string();
  std::string traverse(Node *root);
  void setup();
  
  int search(int value);
  int rsearch(int value);
  int rsearch(int value, Node *n);

  void deleteValue(int value);

  int countLeaves(Node *n);
  int countLeaves();

  int treeHeight(Node *n);
  int treeHeight();

  int levelSum(Node *n, int curr, int lvl);
  int levelSum(int lvl);
};
