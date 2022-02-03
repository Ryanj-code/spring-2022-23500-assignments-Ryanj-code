#include <iostream>

int stepPerms(int n){
  
  if(n == 1){
    return 1;
  } // Return 1 ways if n equals 1.

  if(n == 2){
    return 2;
  } // Return 2 ways if n equals 2.

  if(n == 3){
    return 4;
  } // Returns 4 ways if n equals 4.

  return stepPerms(n-1) + stepPerms(n-2) + stepPerms(n-3);
} // Keeps calling stepPerms(n-1) + stepPerms(n-2) + stepPerms(n-3) because the number of ways to climb the stair for n > 3
// Is equal to the sum of the previous 3 number's ways to climb the stairs.
// Example: # of ways for 5 = 13, # of ways for 4 = 7, # of ways for 3 = 4, # of ways for 2 = 2.
// To get # of ways for 4; # of ways for 3 = 4, # of ways for 2 = 2, # of ways for 1 = 1.      
// Therefore, 7 = 4 + 2 + 1.
// Result: 13 = 7 + 4 + 2. # of ways for 5 steps is 13.                                                  

int main() {
  std::cout << "# of ways: " << stepPerms(1) << std::endl;
  std::cout << "# of ways: " << stepPerms(3) << std::endl;
  std::cout << "# of ways: " << stepPerms(5) << std::endl;
  std::cout << "# of ways: " << stepPerms(6) << std::endl;
  std::cout << "# of ways: " << stepPerms(7) << std::endl;
}
