#include <iostream>
#include "OList.h"
#include "Node.h"

int main(){
  OList *l = new OList();

  std::cout << "Checking insert has inserted 0, 2, 4, 7, 9:\n";
  
  l->insert(0);
  l->insert(2);
  l->insert(4);
  l->insert(7);
  l->insert(9);

  std::cout << "OList l: " << l->toString() << "\n\n";

  std::cout << "Checking if contains works:\n";
  std::cout << "Checking if l contains 1 (false):\n";
  std::cout << std::boolalpha << (l->contains(1)) << "\n";
  std::cout << "Checking if l contains 2 (true):\n";
  std::cout << std::boolalpha << (l->contains(2)) << "\n";

  std::cout << "\nChecking get:\n";
  std::cout << "get(0): " << l->get(0) << "\n";
  std::cout << "get(3): " << l->get(3) << "\n";

  std::cout << "\nChecking remove:\n";
  std::cout << "remove(1):\n";
  l->remove(1);
  std::cout << "OList l: " << l->toString() << "\n";
  std::cout << "remove(3):\n";
  l->remove(3);
  std::cout << "OList l: " << l->toString() << "\n";

  std::cout << "\nChecking reverse:\n";
  l->reverse();
  std::cout << "OList l: " << l->toString() << "\n";
  l->reverse();
  std::cout << "OList l: " << l->toString() << "\n";
  return 0;
}
