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

std::vector<int> qsort(std::vector<int> list){

  int i,j;
  
  // base case
  if (list.size() <= 1){
    return list;
  }

  // select a pivot value.
  // for now, just pick list[0]
  int pivot = list[0];
  
  // make 2 new vectors
  std::vector<int> lower,higher;

  // copy all the values < pivot value to lower
  // copy all the values >= pivot value to higher;
  for (i=1; i < list.size(); i++){
    if (list[i] < pivot){
      lower.push_back(list[i]);
    } else {
      higher.push_back(list[i]);
    }
  }
  
  lower = qsort(lower);
  higher = qsort(higher);

  // copy everything back into list
  for (i=0 ; i < lower.size(); i++){
    list[i]=lower[i];
  }

  list[i] = pivot;
  i++;

  for (j=0;j<higher.size();j++){
    list[i] = higher[j];
    i++;
  }
  
  // return the sorted list
  return list; 
}


//Quick sort algorithm from https://www.geeksforgeeks.org/iterative-quick-sort/

// Function to swap numbers
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* 
This function takes last element as pivot, places the pivot element at its 
correct position in sorted array, and places all smaller (smaller than pivot) 
to left of pivot and all greater elements to right of pivot.

Code modifications:
Switched pivot to good pivot as discussed in class.
Switched variable name from x to pivot.
*/
int partition(std::vector<int> &arr, int l, int h){
  int pivotIndex = h;
  int pivot = arr[pivotIndex];
  
  int i = (l - 1);

  for (int j = l; j <= h - 1; j++) {
    if (arr[j] <= pivot) {
      i++;
      swap(&arr[i], &arr[j]);
    }
  }

  swap(&arr[i + 1], &arr[h]);
  return (i + 1);
}
 
/* 
A[] --> Array to be sorted,
l --> Starting index,
h --> Ending index 
*/
void qsort2(std::vector<int> &A, int l, int h){
  if (l < h) {
    /* Partitioning index */
    int p = partition(A, l, h);
    qsort2(A, l, p - 1);
    qsort2(A, p + 1, h);
  }
}


void print_help(char *command_name){
  std::cout << "Usage: "<< command_name;
  std::cout << " [-h|-p|-m N|-s N|-a algorithm]\n\n";
  std::cout << " -m MAX_ELEMENT_SIZE\n";
  std::cout << " -s DATA_SET_SIZE\n";
  std::cout << " -a[s|m]: s - selection, m - merge, q - qsort, r - qsort2\n";
}

extern char *optarg;

int main(int argc, char *argv[]) {
  /*
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
  */

  int size = 20; // default vector size
  int max_val = 100; // default max value for entries

  char algorithm = 's' ; //default to selection sort
  bool print = false; // do we print before and after sorting?  
  char c;


  while ( ( c = getopt(argc, argv, "phs:m:a:")) != -1){

    switch (c) {
      case 'h' :
        print_help(argv[0]);
        exit(0);
        break;
      case 'p' :
        print = true;
        break;
      case 's' :
        size = std::stoi(optarg);
        break;
      case 'm' :
        max_val = std::stoi(optarg);
        break;
      case 'a':
        algorithm = optarg[0]; // or *optarg
      }
    }

    
  srand(time(nullptr));
  std::vector<int> a(size);
  int i;
  for (i=0;i<size; i++){
    a[i] = rand()%max_val;  
  }

    
  if (print) {  
    print_vector(a);
    std::cout << "\n";
  }

  std::cout << "Starting the sort!\n";
  struct timeval tp;

  gettimeofday(&tp,NULL);
  long start_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

  if (algorithm == 's'){
    a = ssort(a);
  } else if (algorithm == 'm'){

    a = msort(a);
  } else if (algorithm == 'q'){
    a = qsort(a);
  }
  else if(algorithm == 'r'){
    qsort2(a, 0, a.size()-1);
  }
    
  
  gettimeofday(&tp,NULL);
  long current_time = tp.tv_sec *1000 + tp.tv_usec / 1000;

  long elapsed = current_time - start_time;

  if (print) {
    print_vector(a);
  }
  
  std::cout << "Algorithm: " << algorithm << "\n";
  std::cout << "Time: " << elapsed << "\n";
  
  return 0;
}
