#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.h"
#include "BSTree.h"

BSTree *t = new BSTree();

TEST_CASE("Test rsearch:"){
  t->setup();

  int x = t->rsearch(10);
  CHECK(x == 10);
  x = t->rsearch(20);
  CHECK(x == 20);
  x = t->rsearch(30);
  CHECK(x == 30);

}
