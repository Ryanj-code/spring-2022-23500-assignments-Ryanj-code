#include <iostream>
#include <vector>
#include <time.h>
#include <unistd.h>
#include <cstdlib>
#include <sys/time.h>
#include <math.h>

void print_vector(std::vector<int> a){
  for (auto i : a){
    std::cout << i << ", ";
  }
  std::cout << "\n";
}


int find_min_index(std::vector<int> a, int start_index, int stop_index){
  int min_index = start_index;
  int i;
  for (i = start_index ; i < stop_index; i++){
    if (a[i] < a[min_index]){
      min_index = i;
    }
  }
  return min_index;
}

std::vector<int> ssort(std::vector<int> a){
  int i,min_index,j,tmp;
  int len = a.size();
  // loop through the vector from 0 to end
  for (i=0;i<len; i++){
    // find the smallest value from i to the end
    min_index = find_min_index(a,i,len);
    
    // swap it into position i
    tmp = a[i];
    a[i] = a[min_index];
    a[min_index] = tmp;
    
  }
  return a;
}

/*
  left and right are already sorted
  merged should be a new vector with all the
  elements in left and right, and result
  should be sorted
*/
std::vector<int> merge(std::vector<int> left, std::vector<int> right){
  std::vector<int> merged;

  int l = 0;
  int r = 0;

  while (l < left.size() && r < right.size()){
    if (left[l] < right[r]){
      merged.push_back(left[l]);
      l++;
    } else {
      merged.push_back(right[r]);
      r++;
    }
  }

  // add any extra elements in left
  while (l < left.size()){
    merged.push_back(left[l]);
    l++;
  }
  
  // add any extra elements in right
  while (r < right.size()){
    merged.push_back(right[r]);
    r++;
  }
  	 
  return merged;
}

std::vector<int> msort(std::vector<int> v){
  if(v.size() < 2){
    return v;
  }

  int s = v.size();
  
  std::vector<int> left;
  std::vector<int> right;

  for(int i = 0; i < s; i++){
    if(i < s/2){
      left.push_back(v[i]);
    }
    else{
      right.push_back(v[i]);
    }
  }

  left = msort(left);
  right = msort(right);

  return merge(left, right);
}

int main() {
  std::vector<int> x = {3, -7, 8, 12, -16, 19, 4};
  std::cout << "Vector x before merge sort:\n";
  print_vector(x);

  x = msort(x);
  std::cout << "Vector x after merge sort:\n";
  print_vector(x);

  std::cout << "\n";

  std::vector<int> y = {-3, 6, 0, -12, 6, 9, 4};
  std::cout << "Vector y before merge sort:\n";
  print_vector(y);

  y = msort(y);
  std::cout << "Vector y after merge sort:\n";
  print_vector(y);
  
  
  return 0;
}
