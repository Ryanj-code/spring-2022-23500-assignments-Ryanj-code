#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "Dictionary.h"

Dictionary *d = new Dictionary();
Person *p0 = new Person("Ryan", "Jiang", 0);
Person *p1 = new Person("Ken", "Chen", 1);
Person *p2 = new Person("Jonathan", "Tam", 2);
Person *p3 = new Person("Henry", "James", 3);
Person *p4 = new Person("Alison", "Bechdel", 4);

TEST_CASE("Testing insert and getKeys:"){
  CHECK(d->getKeys() == "|");
  d->insert(p0);
  CHECK(d->getKeys() == "| Jiang, Ryan |");
  d->insert(p1);
  d->insert(p2);
  CHECK(d->getKeys() == "| Tam, Jonathan | Jiang, Ryan | Chen, Ken |");
  d->insert(p3);
  CHECK(d->getKeys() == "| James, Henry | Tam, Jonathan | Jiang, Ryan | Chen, Ken |");
  d->insert(p4);
  CHECK(d->getKeys() == "| James, Henry | Tam, Jonathan | Jiang, Ryan | Bechdel, Alison | Chen, Ken |");
}

TEST_CASE("Testing hash:"){
  CHECK(d->hash("Bechdel, Alison") == 4);
  CHECK(d->hash("James, Henry") == 0);
  CHECK(d->hash("Tam, Jonathan") == 0);
  CHECK(d->hash("Chen, Ken") == 4);
  CHECK(d->hash("Jiang, Ryan") == 0);
}

TEST_CASE("Testing getPerson:"){
    Person *p = d->getPerson("Lee, Bruce");
    CHECK(p == nullptr);
    p = d->getPerson("Jiang, Ryan");
    CHECK(p == p0);
    p = d->getPerson("Bechdel, Alison");
    CHECK(p == p4);
    p = d->getPerson("Tam, Jonathan");
    CHECK(p == p2);

    delete d;
}

