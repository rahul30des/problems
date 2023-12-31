#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector <int> getMilestoneDays(vector <int> revenues, vector<int> milestones) {
   vector<int> ctotal(revenues.size(), 0);
   vector<int> out;
   int mid_index = 0;
   // Time and Space O(n)
   for(unsigned int i = 0; i < revenues.size(); i++) {
     if(i) {
         ctotal[i] = revenues[i] + ctotal[i-1];  
     } else {
         ctotal[i] = revenues[i];
     }
   }

   // Search in O(logn) and do for all n milestone values
   // Time Complexity O(nlogn)
   for(unsigned int i = 0; i < milestones.size(); i++) {
     int low_index = 0;
     int high_index = ctotal.size() - 1;
      
     while(low_index <= high_index) {
         mid_index = (low_index + high_index)/2;
         if(ctotal[mid_index] == milestones[i]) {
          break;
         } else if(ctotal[mid_index] > milestones[i]) {
          high_index = mid_index - 1;
         } else if(ctotal[mid_index] < milestones[i]) {
          low_index = mid_index + 1;
         }
      }
    out.push_back(mid_index+1);
  }
  return out;   
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
  const char* rightTick = "\u2713";
  const char* wrongTick = "\u2717";
  if (result) {
    cout << rightTick << "Test #" << test_case_number << "\n";
  }
  else {
    cout << wrongTick << "Test #" << test_case_number << ": Expected ";
    printIntegerVector(expected); 
    cout << " Your output: ";
    printIntegerVector(output);
    cout << endl; 
  }
  test_case_number++;
}

int main() {
  // Testcase 1
  vector <int> revenues_1{100, 200, 300, 400, 500};
  vector <int> milestones_1{300, 800, 1000, 1400};
  vector <int> expected_1{2, 4, 4, 5};
  vector <int> output_1 = getMilestoneDays(revenues_1, milestones_1);
  check(expected_1, output_1);

  // Testcase 2
  vector <int> revenues_2{700, 800, 600, 400, 600, 700};
  vector <int> ctotal{700, 1500, 2100, 2500, 3100,3800};
  vector <int> milestones_2{3100, 2200, 800, 2100, 1000};
  vector <int> expected_2{5, 4, 2, 3, 2};
  vector <int> output_2 = getMilestoneDays(revenues_2, milestones_2);
  check(expected_2, output_2);
  
  // Add your own test cases here
  
}
