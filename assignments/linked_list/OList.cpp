#include <iostream>
#include "OList.h"
//while(walker) is the same as while(walker != nullptr).

OList::OList(){
  head = nullptr;
}

OList::~OList(){
  Node * trailer = nullptr;
  
  while(head != nullptr){
    trailer = head;
    head = head->getNext();
    delete trailer;
  }
}

void OList::insert(int value){
  Node *walker = head;
  Node *trailer = nullptr;
  Node *temp = new Node(value);
  
  while(walker != nullptr && value > walker->getData()){
    trailer = walker;
    walker = walker->getNext();
  }

  if(trailer == nullptr){
    temp->setNext(head);
    head = temp;
  }
  else{
    trailer->setNext(temp);
    temp->setNext(walker);
  }

  return;
}


std::string OList::toString(){
  std::string result = "";
  Node * walker = this->head;
  
  while(walker != nullptr){
    result += std::to_string(walker->getData());
    result += " -> ";
    walker = walker->getNext();
  }
  
  result = result + "nullptr";
  return result;
}

bool OList::contains(int value){
  Node *walker = head;
  
  while (walker != nullptr){
    if(walker->getData() == value){
      return true; 
    }
    
    walker = walker->getNext();
  }

  return false;
}

int OList::get(int loc){
  Node *walker = head;
  
  while(walker && loc > 0){
    walker = walker -> getNext();
    loc--;
  }
  
  if(walker != nullptr){
    return walker->getData();
  }

  return -1;
}

void OList::remove (int loc){
  Node *walker = head;
  Node *trailer = nullptr;

  while (loc > 0 && walker != nullptr){
    trailer = walker;
    walker = walker->getNext();
    loc = loc - 1;
  }

  if (walker == nullptr){
    throw std::out_of_range("out of range");
  }

  if (trailer == nullptr){
    head = walker->getNext();
    delete walker;
  }
  else{
    trailer->setNext(walker->getNext());
    delete walker;
  }
}
