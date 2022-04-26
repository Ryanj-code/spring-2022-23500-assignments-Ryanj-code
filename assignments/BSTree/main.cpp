#include <iostream>
#include "Node.h"

int main(){

  Node *n = new Node(10);
  std::cout << n->getData() << "\n";
  Node *n2 = new Node(20);
  n->setLeft(n2);
  n2 = new Node(50);
  n->setRight(n2);

  std::cout << n->getLeft()->getData() << "\n";
  std::cout << n->getRight()->getData() << "\n";

  Node *n3 = new Node(30);
  Node *n4 = new Node(40);
  n2->setLeft(n3);
  n3->setLeft(n4);

  Node *n6 = new Node(60);
  n2->setLeft(n6);
  n6 = new Node(70);
  n2->setRight(n6);
    
  return 0;
}
