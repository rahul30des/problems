#include <iostream>
#include <unordered_map>

using namespace std;

int minLengthSubstring(string s, string t) {

  // O(n) - Time Comp - Iterate through s and check for the char in hash, decrement count, delete if 0, check entry count
  // If 0 then the index of iterator for s + 1 is the answer
  
  unordered_map<int, int> hmap;
  int length = -1;
  
  // Iterate over t and fill in hash with (unique chars in t, count)
  // Space Complexity O(n)
  for(int i = 0; (unsigned int) i < t.size(); i++) {
    if(hmap.contains(t[i])) {
      hmap[t[i]]++;
    } else {
      hmap[t[i]] = 1;
    }
  }
  
  // Iterate over s and try empty the hashmap, ret ite count if empty
  for(int i = 0; (unsigned int) i < s.size(); i++) {
    if(hmap.contains(s[i])) {
      hmap[s[i]]--;
      if(hmap[s[i]] == 0) {
        auto it = hmap.find(s[i]);
        hmap.erase(it);
      }
      if (hmap.size() == 0) {
        return i+1;
      }
    } 
  }

  return length;
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

  string s_1 = "dcbefebce";
  string t_1 = "fd";
  int expected_1 = 5;
  int output_1 = minLengthSubstring(s_1, t_1);
  check(expected_1, output_1);

  string s_2 = "bfbeadbcbcbfeaaeefcddcccbbbfaaafdbebedddf";
  string t_2 = "cbccfafebccdccebdd";
  int expected_2 = -1;
  int output_2 = minLengthSubstring(s_2, t_2);
  check(expected_2, output_2);

  // Add your own test cases here
  
}
