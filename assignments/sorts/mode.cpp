#include <iostream>
#include <vector>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>

void print_vector(std::vector<int> a){
  for (auto i : a){
    std::cout << i << ", ";
  }
  std::cout << "\n";
}

int count(std::vector<int> v, int value){
  int count = 0;

  for(int i = 0; i < v.size(); i++){
    if(v[i] == value){
      count++;
    }
  }

  return count;
}

int largest(std::vector<int> v){
  int largest = 0;

  for(int i = 0; i < v.size(); i++){
    if(v[i] > largest){
      largest = v[i];
    }
  }

  return largest;
}

int mode(std::vector<int> v){
  int mode = 0;
  int freq = 0;

  for(int i = 0; i < v.size(); i++){
    if((count(v, v[i])) > freq){
      freq = count(v, v[i]);
      mode = v[i];
    }
  }

  return mode;
}

int main(){
  int max = 10;
  srand(time(nullptr));
  std::vector<int> a(10);
  int i;
  for(i = 0; i < 10; i++){
    a[i] = rand()%max;
  }

  std::cout << "Vector a: ";
  print_vector(a);
  std::cout << "# of times 1 appears in vector a: " << count(a, 1) << "\n";
  std::cout << "Largest # in vector a: " << largest(a) << "\n";
  std::cout << "Mode of vector a: " << mode(a) << "\n";
}
