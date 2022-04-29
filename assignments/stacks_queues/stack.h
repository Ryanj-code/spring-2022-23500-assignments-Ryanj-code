#pragma once

#include "Node.h"

#define STACK_ERR_EMPTY 1

class Stack{
 private:
  Node *stack;
  
 public:
  Stack();
  ~Stack();
  void push(int val); // add an item to the top of the stack
  int pop(); // remove and return the top item
  int top(); // return but do not remove the top item
  bool is_empty(); // return true if empty, false otherwise
};
