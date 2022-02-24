#include <iostream>
#include "List.h"

List::List(){
  head = nullptr;
}

List::~List(){
  Node *walker = head;
  while(walker != nullptr){
    Node *del = walker;
    delete del;
    walker = walker->getNext();
  }
  
  head = nullptr;    
}

void List::insert(std::string data){
  // create a new node
  Node *new_node = new Node(data);

  // insert the new node
  new_node->setNext(head);
  head=new_node;  
}

void List::remove(int index){
  Node *walker = head;
  int count = 0;
  
  while(walker != nullptr && count < index - 1){
    walker = walker->getNext();
    count++;
  }

  Node *del = walker->getNext();
  walker = walker->getNext();
  delete del;
}

Node * List::locate(int index){
  Node *walker = head;
  int count = 0;

  while(walker != nullptr && count < index - 1){
    walker = walker->getNext();
    count++;
  }

  return walker;
}

std::string List::toString(){
  Node *walker = head;
  std::string s = "";
  while(walker != nullptr){
    s = s + walker->getData() + "-->";
    walker = walker->getNext();
  }

  s = s + "nullptr";
  
  return s;
}
	    
