#include <iostream>
#include "OList.h"
#include "Node.h"

int main(){
  List *l = new OList();

  l->insert("0");
  l->insert("2");
  l->insert("4");
  l->insert("7");
  l->insert("9");

  return 0;
}
