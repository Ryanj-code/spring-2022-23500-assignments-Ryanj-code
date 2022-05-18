#include <iostream>
#include "Dictionary.h"
#include "List.h"

Dictionary::Dictionary(){
  arr = new List*[5];
  for (int i =0; i < 5; i++){
    arr[i] = new List();
  }
}

Dictionary::~Dictionary(){
  for (int i = 0; i < 5; i++){
    delete arr[i];
  }
}

int Dictionary::hash(std::string key){
  int sum = 0;
  
  for (int i = 0; i < key.length(); i++){
    sum += (int) key[i];
  }
  
  return sum % 5;
}

void Dictionary::insert(Person *p){
  int i = hash(p->get_name());
  arr[i]->insert(p);
}

Person *Dictionary::getPerson(std::string name){
  Person *person = nullptr;

  int i = hash(name);
  List *l = arr[i];
  Node *walker = l->get_head();

  while(walker){
    if(name == walker->getPerson()->get_name()){
      person = walker->getPerson();
      break;
    }
    
    walker = walker->getNext();
  }

  return person;
}

std::string Dictionary::getKeys(){
  std::string result = "|";

  for (int i = 0; i < 5; i++){
    List *l = arr[i];
    result += l->toString();
  }

  return result;
}
