#include <iostream>
#include "Dictionary.h"

int main(){
  Dictionary *d = new Dictionary();
  std::cout << "The Current Dictionary: " << d->getKeys() << '\n';

  Person *p0 = new Person("Ryan", "Jiang", 0);
  Person *p1 = new Person("Ken", "Chen", 1);
  Person *p2 = new Person("Jonathan", "Tam", 2);
  Person *p3 = new Person("Henry", "James", 3);
  Person *p4 = new Person("Alison", "Bechdel", 4);

  std::cout << "\nInserting 5 people into the Dictionary\n";
  d->insert(p0);
  d->insert(p1);
  d->insert(p2);
  d->insert(p3);
  d->insert(p4);

  std::cout << "The Current Dictionary: " << d->getKeys() << "\n\n";

  std::cout << "Getting address of Ryan Jiang: " << d->getPerson("Jiang, Ryan")
	    << "\nAddress of Ryan Jiang: " << p0 << '\n';  

  std::cout << "Getting address of Henry James: " << d->getPerson("James, Henry")
            << "\nAddress of Henry James: " << p3 << '\n';
  
  return 0;
}
