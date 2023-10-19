#include <iostream>
#include <vector>
#include <cmath>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

int getBillionUsersDay(vector <float> growthRates) {
  // N is app count
  unsigned int N = growthRates.size();
  int exp = 1;
  int mid_idx = exp;
  double total = 0;
  double searchTerm = pow(10,9);

  // Calculate for exp 1
  for(unsigned int i = 0; i < N; i++) {
    total += pow(growthRates[i], exp);
  }

  if(total > searchTerm) {
      return exp;
  } else {
      total = 0;
      // O(log2n) running complexity
      while(total < searchTerm) {
          exp <<= 1;
          total = 0;
          for(unsigned int i = 0; i < N; i++) {
              total += pow(growthRates[i], exp);
          } 
      }
      // Binary Search to triangulate on the exact exp
      int low_idx = exp>>2;
      int high_idx = exp;

      // Time Complexity O(log(n))
      while(low_idx <= high_idx) {
          total = 0;
          mid_idx = (low_idx + high_idx)/2;
          for(unsigned int i = 0; i < N; i++) {
              total += pow(growthRates[i], mid_idx);
          }
          if(total == searchTerm) {
              // Exact Search Term found
              break;
          } else if(total < searchTerm) {
              low_idx = mid_idx + 1;
          } else if(total > searchTerm) {
              high_idx = mid_idx - 1;
          }
      }  
  }
  return mid_idx;
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printInteger(int n) {
  cout << "[" << n << "]";
}

int test_case_number = 1;

void check(int expected, int output) {
  bool result = (expected == output);
  const char* rightTick = "\u2713";
  const char* wrongTick = "\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printInteger(expected); 
    cout << " Your output: ";
    printInteger(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {

  vector <float> test_1{1.1, 1.2, 1.3};
  int expected_1 = 79;
  int output_1 = getBillionUsersDay(test_1);
  check(expected_1, output_1);

  vector <float> test_2{1.01, 1.02};
  int expected_2 = 1047;
  int output_2 = getBillionUsersDay(test_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
