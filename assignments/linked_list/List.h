#pragma once
#include "Node.h"

class List{
 private:
  Node *head;

 public:
  List();
  ~List();
  void insert(std::string data);
  void remove(int index);
  Node * locate(int index);
  std::string toString();
};
