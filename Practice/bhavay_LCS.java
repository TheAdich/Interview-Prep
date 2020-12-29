/**
Given a string s, find the longest palindromic subsequence's in s.
You may assume that the maximum length of s is 1000.

Example 1:
Input: "bbbab"
Output: "bbbb"

Example 2:
Input: "cbbd"
Output: "bb"
**/


//      abcdef
//   bcdef         abcde
// cde                 cde

// dp[2][4] ="c"


import java.io.*;

class MyCode {
  private static String longestPalindromic(String str, int start, int end, String[][] dp) {
    if (start > end)
      return "";
    if (start == end)
      return "" + str.charAt(start);

    if (dp[start][end].length() > 0)
      return dp[start][end];

    char startChar = str.charAt(start);
    char endChar = str.charAt(end);
    if (startChar == endChar)
      return startChar + longestPalindromic(str, start + 1, end - 1, dp) + endChar;

    String exculdeStart = longestPalindromic(str, start + 1, end, dp);
    String excludeEnd = longestPalindromic(str, start, end - 1, dp);

    return dp[start][end] = exculdeStart.length() >= excludeEnd.length() ? exculdeStart : excludeEnd;
  }
  public static void main (String[] args) {
    String str = "badaab";
    String[][] dp = new String[str.length()][str.length()];
    String lps = longestPalindromic(str, 0, str.length() - 1, dp);
    System.out.println(lps);
    // System.out.println("Hello Java");
  }
}
