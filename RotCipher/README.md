Rotational Cipher

One simple way to encrypt a string is to "rotate" every alphanumeric character by a certain amount. Rotating a character means replacing it with another character that is a certain number of steps away in normal alphabetic or numerical order.
For example, if the string "Zebra-493?" is rotated 3 places, the resulting string is "Cheud-726?". Every alphabetic character is replaced with the character 3 letters higher (wrapping around from Z to A), and every numeric character replaced with the character 3 digits higher (wrapping around from 9 to 0). Note that the non-alphanumeric characters remain unchanged.
Given a string and a rotation factor, return an encrypted string.
Signature
string rotationalCipher(string input, int rotationFactor)
Input
1 <= |input| <= 1,000,000
0 <= rotationFactor <= 1,000,000
Output
Return the result of rotating input a number of times equal to rotationFactor.
Example 1
input = Zebra-493?
rotationFactor = 3
output = Cheud-726?
Example 2
input = abcdefghijklmNOPQRSTUVWXYZ0123456789
rotationFactor = 39
output = nopqrstuvwxyzABCDEFGHIJKLM9012345678
Need hints?

C++
-
#include <bits/stdc++.h>
// Add any extra import statements you may need here
​
using namespace std;
​
// Add any helper functions you may need here
char rotate(char input, int factor) {
  if(input >= 'A' && input <= 'Z')
    return ((input - 'A' + factor) % 26) + 'A';
   else if(input >= 'a' && input <= 'z')
    return ((input - 'a' + factor) % 26) + 'a';
  else if(input >= '0' && input <= '9') 
    return ((input - '0' + factor) % 10) + '0';
  else return input;
}
​
string rotationalCipher(string input, int rotationFactor) {
  for(auto i = 0; i < input.size(); i++) {
    input[i] = rotate(input[i], rotationFactor);
​
  }
  return input;
}
​
​
​
​
​
​
​
​
​
​
​
​
// These are the tests we use to determine if the solution is correct.
// You can add your own at the bottom.
​
void printString(string& str) {
  cout << "[\"" << str << "\"]";
}
​
int test_case_number = 1;
​
CONSOLE
Remove
Choose the programming language you're most comfortable withLearn about this new feature
