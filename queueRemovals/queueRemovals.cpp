#include <bits/stdc++.h>
// Add any extra import statements you may need here

using namespace std;

// Add any helper functions you may need here

vector <int> findPositions(vector <int> arr, int x) {
  // Write your code here
  
  return {};
}

// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
void printIntegerVector(vector <int> array) {
  int size = array.size();
  cout << "[";
  for (int i = 0; i < size; i++) {
    if (i != 0) {
      cout << ", ";
    }
   cout << array[i];
  }
  cout << "]";
}

int test_case_number = 1;

void check(vector <int>& expected, vector <int>& output) {
  int expected_size = expected.size(); 
  int output_size = output.size(); 
  bool result = true;
  if (expected_size != output_size) {
    result = false;
  }
  for (int i = 0; i < min(expected_size, output_size); i++) {
    result &= (output[i] == expected[i]);
  }
  const char* rightTick = u8"\u2713";
  const char* wrongTick = u8"\u2717";
  if (result) {
    cout << rightTick << " Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << " Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected); 
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {
  int n_1 = 6;
  int x_1 = 5;
  vector <int> arr_1{1, 2, 2, 3, 4, 5};
  vector <int> expected_1{5, 6, 4, 1, 2 };
  vector <int> output_1 = findPositions(arr_1, x_1);
  check(expected_1, output_1);

  int n_2 = 13;
  int x_2 = 4;
  vector <int> arr_2{2, 4, 2, 4, 3, 1, 2, 2, 3, 4, 3, 4, 4};
  vector <int> expected_2{2, 5, 10, 13};
  vector <int> output_2 = findPositions(arr_2, x_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
