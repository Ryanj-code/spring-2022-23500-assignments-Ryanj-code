#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Node.h"
#include "BSTree.h"

BSTree *t = new BSTree();

TEST_CASE("Test rsearch:"){
  t->setup();

  int x = t->rsearch(10);
  CHECK(x == 10);
  x = t->rsearch(3);
  CHECK(x == 3);
  x = t->rsearch(30);
  CHECK(x == 30);
}

TEST_CASE("Testing insert:"){
  BSTree t2;
  
  t2.insert(10);
  CHECK(t2.get_debug_string() == ", 10, ");
  t2.insert(3);
  CHECK(t2.get_debug_string() == ", 3, , 10, ");
  t2.insert(-1);
  CHECK(t2.get_debug_string() == ", -1, , 3, , 10, ");
  t2.insert(0);
  CHECK(t2.get_debug_string() == ", -1, , 0, , 3, , 10, ");
}

TEST_CASE("Testing deleteValue:"){
  BSTree t3;
  
  t3.setup();
  CHECK(t3.get_debug_string() == ", 3, , 5, , 8, , 10, , 15, , 20, , 30, ");
  
  t3.deleteValue(10);
  CHECK(t3.get_debug_string() == ", 3, , 5, , 8, , 15, , 20, , 30, ");
  
  t3.deleteValue(3);
  CHECK(t3.get_debug_string() == ", 5, , 8, , 15, , 20, , 30, ");
  t3.deleteValue(30);
  CHECK(t3.get_debug_string() == ", 5, , 8, , 15, , 20, ");
  
}

TEST_CASE("Testing countLeaves:"){
  BSTree *t4 = new BSTree();
  CHECK(t4->countLeaves() == 0);
    
  t4->setup();
  CHECK(t4->countLeaves() == 4);
  CHECK(t4->get_debug_string() == ", 3, , 5, , 8, , 10, , 15, , 20, , 30, ");
  t4->insert(9);
  CHECK(t4->countLeaves() == 4);
  CHECK(t4->get_debug_string() == ", 3, , 5, , 8, , 9, , 10, , 15, , 20, , 30, ");
  t4->insert(6);
  CHECK(t4->countLeaves() == 5);
  t4->deleteValue(6);
  CHECK(t4->countLeaves() == 4);
}

TEST_CASE("Testing treeHeight:"){
  BSTree *t5 = new BSTree();
  CHECK(t5->treeHeight() == 0);
  
  t5->setup();
  CHECK(t5->treeHeight() == 3);
  t5->insert(40);
  t5->insert(50);
  CHECK(t5->treeHeight() == 5);
  t5->deleteValue(40);
  CHECK(t5->treeHeight() == 4);
}

TEST_CASE("Testing levelSum:"){
  BSTree *t6 = new BSTree();
  t6->setup();
  CHECK(t6->levelSum(0) == 0);
  CHECK(t6->levelSum(1) == 10);
  CHECK(t6->levelSum(2) == 25);
  CHECK(t6->levelSum(3) == 56);
  
  try {
    t6->levelSum(4);
  } catch (int e){
    CHECK(e == TREE_ERR_LVL);
  }
}
