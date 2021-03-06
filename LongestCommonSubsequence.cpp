/*
##############################################
#          Coding Interview Questions
#      Created/Modified on: June 26, 2019
#           Author: Munir Jojo-Verge
##############################################
 */
/*
Write a function that takes in two strings and returns their longest common
subsequence.


A subsequence of a string is a set of characters that aren't necessarily
adjacent in the string but that are in the same order as they appear in the
string. For instance, the characters ["a", "c", "d"] form a
subsequence of the string "abcd", and so do the characters
["b", "d"]. Note that a single character in a string and the
string itself are both valid subsequences of the string.


You can assume that there will only be one longest common subsequence.

Sample Input
str1 = "ZXVVYZW"
str2 = "XKYKZPW"

Sample Output
["X", "Y", "Z", "W"]
 */

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<char> longestCommonSubsequence(string str1, string str2) {
  // Write your code here.
  size_t str1_len = str1.length();
  size_t str2_len = str2.length();

  if (str1_len == 0 || str2_len == 0) {
    return vector<char>();
  }

  // Let's define a 3D vector that holds the lcs as a vector of char and
  // initiaize the entire matrix with "spaces"
  vector<vector<vector<char>>> lcs(
      str1_len + 1, vector<vector<char>>(str2_len + 1, vector<char>()));

  for (size_t row = 1; row < str1_len + 1; row++) {
    for (size_t col = 1; col < str2_len + 1; col++) {
      if (str1[row - 1] == str2[col - 1]) {
        vector<char> tmp = lcs[row - 1][col - 1];
        tmp.push_back(str1[row - 1]);
        lcs[row][col] = tmp;
      } else {
        lcs[row][col] = (lcs[row][col - 1].size() > lcs[row - 1][col].size()
                             ? lcs[row][col - 1]
                             : lcs[row - 1][col]);
      }
    }
  }
  return lcs[str1_len][str2_len];
}

int main() {
  vector<char> vector1S;
  vector<char> vector2S;
  vector<char> vector3S;
  vector<char> vector4S{'A', 'B', 'C', 'D', 'E', 'F', 'G'};
  vector<char> vector5S{'A', 'E'};
  vector<char> vector6S{'n', 't'};
  vector<char> vector7S{'X', 'Y', 'Z', 'W'};
  vector<char> vector8S{'8', '4', '2'};
  vector<char> vector9S{'C', 'D', 'E', 'G', 'H', 'J', 'K', 'L', 'W'};
  vector<char> vector10S{'C', 'D', 'E', 'G', 'H', 'J', 'K', 'L', 'T', 'U', 'V'};

  cout << "Test Case 1" << endl;
  cout << (longestCommonSubsequence("", "") == vector1S ? "PASS" : "FAIL")
       << endl;

  cout << "Test Case 2" << endl;
  cout << (longestCommonSubsequence("", "ABCDEFG") == vector2S ? "PASS"
                                                               : "FAIL")
       << endl;

  cout << "Test Case 3" << endl;
  cout << (longestCommonSubsequence("ABCDEFG", "") == vector3S ? "PASS"
                                                               : "FAIL")
       << endl;

  cout << "Test Case 4" << endl;
  cout << (longestCommonSubsequence("ABCDEFG", "ABCDEFG") == vector4S ? "PASS"
                                                                      : "FAIL")
       << endl;

  cout << "Test Case 5" << endl;
  cout << (longestCommonSubsequence("ABCDEFG", "APPLES") == vector5S ? "PASS"
                                                                     : "FAIL")
       << endl;

  cout << "Test Case 6" << endl;
  cout << (longestCommonSubsequence("clement", "antoine") == vector6S ? "PASS"
                                                                      : "FAIL")
       << endl;

  cout << "Test Case 7" << endl;
  cout << (longestCommonSubsequence("ZXVVYZW", "XKYKZPW") == vector7S ? "PASS"
                                                                      : "FAIL")
       << endl;

  cout << "Test Case 8" << endl;
  cout << (longestCommonSubsequence(
               "8111111111111111142",
               "222222222822222222222222222222433333333332") == vector8S
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 9" << endl;
  cout << (longestCommonSubsequence(
               "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
               "CCCDDEGDHAGKGLWAJWKJAWGKGWJAKLGGWAFWLFFWAGJWKAG") == vector9S
               ? "PASS"
               : "FAIL")
       << endl;

  cout << "Test Case 10" << endl;
  cout << (longestCommonSubsequence(
               "ABCDEFGHIJKLMNOPQRSTUVWXYZ",
               "CCCDDEGDHAGKGLWAJWKJAWGKGWJAKLGGWAFWLFFWAGJWKAGTUV") ==
                   vector10S
               ? "PASS"
               : "FAIL")
       << endl;
}