#include <iostream>
#include "stack.h"
#include "queue.h"

int main(){
  std::cout << "Create a new stack: \n";
  Stack * s = new Stack();
  
  std::cout << "Check the stack is empty: " << std::boolalpha << s->is_empty() << "\n";
  std::cout << "Pushing 1, 2, and 3 onto the stack: \n";
  s->push(1);
  s->push(2);
  s->push(3);
  std::cout << "Top of the stack: " << s->top() << "\n";
  std::cout << "First pop: " << s->pop() << "\n";
  std::cout << "Second pop: " << s->pop() << "\n";
  std::cout << "Third pop: " << s->pop() << "\n\n";

  std::cout << "Testing pop and top on empty stack: \n";
  try{
    s->pop();
  }
  catch(int e){
    std::cout << "Cannot pop empty stack\n"; 
  }

  try{
    s->top();
  }
  catch(int e){
    std::cout << "Cannot look at top of empty stack\n";
  }

  delete s;

  
  std::cout << "\nCreate a new queue: \n";
  Queue * q = new Queue();

  std::cout << "Check the queue is empty: " << std::boolalpha << q->is_empty() << "\n";
  std::cout << "Enqueueing a 1, 2, 3, 4, and 5 to the queue: \n";
  q->enqueue(1);
  q->enqueue(2);
  q->enqueue(3);
  q->enqueue(4);
  q->enqueue(5);
  std::cout << "Front of the queue: " << q->front() << "\n\n";

  std::cout << "Check the queue is full: " << std::boolalpha << q->is_full() << "\n";
  std::cout << "Try enqueueing to a full queue: \n";
  try{
    q->enqueue(6);
  }
  catch (int e){
    std::cout << "Cannot enqueue to a full queue.\n";
  }

  std::cout << "Dequeueing 5 times" << '\n';
  std::cout << "First dequeue: " << q->dequeue() << "\n";
  std::cout << "Second dequeue: " << q->dequeue() << "\n";
  std::cout << "Third dequeue: " << q->dequeue() << "\n";
  std::cout << "Fourth dequeue: " << q->dequeue() << "\n";
  std::cout << "Fifth dequeue: " << q->dequeue() << "\n\n";

  std::cout << "Check the queue is full: " << std::boolalpha << q->is_full() << "\n";
  std::cout << "Check the queue is empty: " << std::boolalpha << q->is_empty() << "\n";

  std::cout << "Try dequeue with an empty queue: \n";
  
  try{
    q->dequeue();
  }
  catch (int e){
    std::cout << "Cannot dequeue an empty queue." << '\n';
  }
  
  delete q;
  
  return 0;
}
