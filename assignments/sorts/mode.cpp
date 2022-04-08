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
  int max = 0;

  for(int i = 0; i < v.size(); i++){
    freq = count(v, v[i]);
    
    if(freq > max){
      max = freq;
      mode = v[i];
    }
  }

  return mode;
}

int mode2(std::vector<int> v){
  int large = largest(v);
  int arr[large];
    
  for(int i = 0; i < large; i++){
    arr[i] = 0;
  }
    
  int max = 0;
  int index = 0;

  for(int i = 0; i < v.size(); i++){
    arr[v[i]] += 1;
  }
    
  for(int i = 0; i < large; i++){
    if(arr[i] > max){
      max = arr[i];
      index = i; 
    }
  }

  return index;
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

  std::vector<int> b {1, 3, 3, 4, 5, 7, 9};
  std::cout << "Vector b: ";
  print_vector(b);
  std::cout << "# of times 1 appears in vector a: " << count(b, 1) << "\n";
  std::cout << "Largest # in vector a: " << largest(b) << "\n";
  std::cout << "Mode of vector a: " << mode(b) << "\n";
}
