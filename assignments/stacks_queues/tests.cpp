#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include "stack.h"
#include "queue.h"

Stack * s = new Stack();

TEST_CASE("Testing push(int val) and top():"){
  try{
    s->top();
  }
  catch(int e){
    CHECK(e == 1); // Use STACK_ERR_EMPTY
  }

  s->push(1);
  CHECK(s->top() == 1);
  s->push(5);
  s->push(10);
  CHECK(s->top() == 10);
  CHECK(s->top() != 5);
  s->push(-1);
  CHECK(s->top() == -1);
}

TEST_CASE("Testing pop():"){
  CHECK(s->top() == -1);
  CHECK(s->pop() == -1);
  CHECK(s->top() == 10);
  CHECK(s->pop() == 10);
  CHECK(s->top() == 5);
  CHECK(s->pop() == 5);
  CHECK(s->top() == 1);
  CHECK(s->pop() == 1);

  try{
    s->pop();
  }
  catch (int e){
    CHECK(e == 1); // Use STACK_ERR_EMPTY 
  }
}

TEST_CASE("Testing is_empty():"){
  CHECK(s->is_empty());
  s->push(1);
  CHECK(!s->is_empty());
  s->push(2);
  CHECK(!s->is_empty());
  s->pop();
  s->pop();
  CHECK(s->is_empty());

  delete s;
}

Queue * q = new Queue();

TEST_CASE("Testing enqueue(int val), dequeue(), and front():"){
  try{
    q->front();
  }
  catch(int e){
    CHECK(e == 1); // Use QUEUE_ERR_EMPTY
  }

  q->enqueue(0);
  CHECK(q->front() == 0);
  q->enqueue(1);
  CHECK(q->front() == 0);
  int check = q->dequeue();
  CHECK(check == 0);
  
  CHECK(q->front() == 1);
  q->enqueue(2);
  CHECK(q->front() == 1);
  q->enqueue(3);
  CHECK(q->front() == 1);
  q->enqueue(4);
  q->enqueue(5);

  try{
    q->enqueue(6);
  }
  catch(int e){
    CHECK(e == 2); // Use QUEUE_ERR_FULL
  }

}

// New queue for easier testing.
Queue * q2 = new Queue();

TEST_CASE("Testing is_full():"){
  // Check some cases with first queue.
  CHECK(q->is_full()); 
  q->dequeue();
  CHECK(!q->is_full());
  q->enqueue(5);
  CHECK(q->is_full());

  try{
    q2->dequeue();
  }
  catch(int e){
    CHECK(e == 1); // Use QUEUE_ERR_EMPTY
  }

  // Use second queue now with front being 0.
  CHECK(!q2->is_full());
  q2->enqueue(0);
  q2->enqueue(1);
  q2->enqueue(2);
  q2->enqueue(3);
  q2->enqueue(4);
  CHECK(q2->is_full());
  
  delete q;
}
