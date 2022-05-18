#pragma once
#include "List.h"

#define DICT_ERR_NO_PERSON 1

class Dictionary{
 private:
  List ** arr;
  
 public:
  Dictionary();
  ~Dictionary();

  void insert(Person *p);
  int hash(std::string key);
  Person *getPerson(std::string name);
  std::string getKeys();
};
