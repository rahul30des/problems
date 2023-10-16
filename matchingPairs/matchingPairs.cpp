#include <iostream>
#include <algorithm>
#include <set>
#include <string>
#include <sstream>

using namespace std;

int matchingPairs(string s, string t) {
   stringstream ss;
   
  string temp = ss.str();
  set<string> mismatchS;
  int matching = 0;

  // Strings are matched char by char
  // Note no of matching chars, put non-matching in hash
  for (int i = 0; (unsigned int) i < s.length(); i++) {
    if (s[i] != t[i]) {
      ss<< s[i] << t[i];
      string temp = ss.str();
      ss.str("");
      mismatchS.insert(temp);
    } else {
      matching++;
    }
  }

  // If there exists mismatches = logic for swapping
  // check among mismatch pairs if reverse pair exists
  // If yes, swappping actually removes 2 mismatches
  for (string mism : mismatchS) {
    // s = "abcd"
    // t = "adcb"
    // replace b,d with d,b
    ss<< mism[1] << mism[0];
    string reverse = ss.str();
    if (mismatchS.find(reverse) != mismatchS.end()) {
      return matching + 2;
    }
  }

  // Finally return matching count
  // If mismatch is 1 then matching is len - 2
  // If mismatch is 0 then matching is len - 2
  if (mismatchS.size() <= 1) {
    matching--;
  }
  if (mismatchS.size() == 0) { // Identical strings will be -2
    matching--;
  }
  return matching;
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
  string s_1 = "abcde";
  string t_1 = "adcbe";
  int expected_1 = 5;
  int output_1 = matchingPairs(s_1, t_1);
  check(expected_1, output_1);

  string s_2 = "abcd";
  string t_2 = "abcd";
  int expected_2 = 2;
  int output_2 = matchingPairs(s_2, t_2);
  check(expected_2, output_2);

  // Add your own test cases here 
}
