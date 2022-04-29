#include "queue.h"

Queue::Queue(){
  head = 0;
  tail = 0;
  queue = new int[5];
}

Queue::~Queue(){
  delete []queue;
}

int Queue::enqueue(int val){
  if(is_full()){
    throw QUEUE_ERR_FULL;
  }

  else{
    queue[tail%5] = val;
    tail++;
  }

  return;
}

int Queue:dequeue(){
  if(is_empty()){
    throw QUEUE_ERR_EMPTY;
  }

  int front = queue[head%5];
  head++;

  return front;
}

int Queue::front(){
  if(is_empty()){
    throw QUEUE_ERR_EMPTY;
  }

  return queue[head];
}

bool Queue::is_empty(){
  if(head == tail){
    return true;
  }
  return false;
}

bool Queue::is_full(){
  if(tail - head > 6){
    return true;
  }
  return false;
}
