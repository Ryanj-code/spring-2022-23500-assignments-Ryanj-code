#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "OList.h"

TEST_CASE("Testing insert(int value) & toString():"){  
  OList *l = new OList();
  
  CHECK(l->toString() == "head --> nullptr");
  l->insert(-1);
  CHECK(l->toString() == "head --> -1 --> nullptr");
  l->insert(3);
  l->insert(4);
  l->insert(10);
  CHECK(l->toString() == "head --> -1 --> 3 --> 4 --> 10 --> nullptr");
  l->insert(1);
  CHECK(l->toString() == "head --> -1 --> 1 --> 3 --> 4 --> 10 --> nullptr");
  
  delete l;
}

TEST_CASE("Testing contains(int value):"){
  OList * l = new OList();
  
  CHECK(!l->contains(1));
  l->insert(1);
  CHECK(l->contains(1));
  l->insert(-5);
  l->insert(8);
  l->insert(3);
  CHECK(l->contains(-5));
  CHECK(l->contains(8));
  CHECK(l->contains(3));

  delete l;
}

TEST_CASE("Testing get():"){
  OList * l = new OList();
  
  l->insert(5);
  l->insert(7);
  l->insert(-3);
  l->insert(0);
  l->insert(1);
  CHECK(l->get(0)==-3);
  CHECK(l->get(1)==0);
  CHECK(l->get(2)==1);
  CHECK(l->get(3)==5);
  CHECK(l->get(4)==7);
  
  delete l;
}

TEST_CASE("Testing remove():"){
  OList *l = new OList();
  
  l->insert(5);
  l->insert(7);
  l->insert(-3);
  l->insert(0);
  l->insert(1);
  CHECK(l->toString() == "head --> -3 --> 0 --> 1 --> 5 --> 7 --> nullptr");
  l->remove(1);
  CHECK(l->toString() == "head --> -3 --> 1 --> 5 --> 7 --> nullptr");
  l->remove(3);
  CHECK(l->toString() == "head --> -3 --> 1 --> 5 --> nullptr");
  l->remove(0);
  CHECK(l->toString() == "head --> 1 --> 5 --> nullptr");
  
  delete l;
}

TEST_CASE("Testing reverse():"){
  OList *l = new OList();
  
  l->reverse();
  CHECK(l->toString() == "head --> nullptr");
  l->insert(5);
  l->reverse();
  CHECK(l->toString() == "head --> 5 --> nullptr");
  l->insert(7);
  l->insert(-3);
  l->insert(0);
  l->insert(1);
  l->reverse();
  CHECK(l->toString() == "head --> 7 --> 5 --> 1 --> 0 --> -3 --> nullptr");
  l->reverse();
  CHECK(l->toString() == "head --> -3 --> 0 --> 1 --> 5 --> 7 --> nullptr");
  
  delete l;
}
