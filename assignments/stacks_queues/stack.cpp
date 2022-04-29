#include "stack.h"

Stack::Stack(){
  stack = nullptr;
}

Stack::~Stack(){
  Node *walker = stack;
  while(stack != nullptr){
    Node *temp = stack;
    stack = stack->getNext();
    delete temp;
  }
}

void Stack::push(int val){
  Node * newValue = new Node(val, stack);
  stack = newValue;
  return;
}

int Stack::pop(){
  if(stack == nullptr){
    throw STACK_ERR_EMPTY;
  }

  int top = stack->getData();
  Node *del = stack;
  stack = stack->getNext();
  delete del;
  return top;
}

int Stack::top(){
  if(stack == nullptr){
    throw STACK_ERR_EMPTY
  }
  return stack->getData();
}

bool Stack::is_empty(){
  if(stack == nullptr){
    return true;
  }
  return false;
}
