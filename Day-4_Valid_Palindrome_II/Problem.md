> [Valid Palindrome II] - https://leetcode.com/problems/valid-palindrome-ii/description/
> Level - Easy
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 
Given a string s, return true if the s can be palindrome after deleting at most one character from it.

--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Two-pointer skip logic
--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

We are asked whether a given string can be turned into a palindrome by removing **at most one character**. A straightforward way to solve this is to try removing each character one by one and check if the resulting string is a palindrome.

🧠Step-by-Step Explanation:
1. Iterate Over the String:
   * Loop through every character position in the string.
2. Create Modified Strings:
   * For each character, imagine deleting that character and forming a new string.
3. Check for Palindrome:
   * For every such modified string (after removing one character), check if it's a valid palindrome.
4. Return Decision:
   * If any of the modified strings is a palindrome, return `true` (since only one removal is allowed).
   * If **none** of the modified strings result in a palindrome, then return `false`.
5. Edge Case Handling:
   * If the original string is already a palindrome, it should also return `true`.

🧠 Time & Space Complexity:

* Time Complexity: O(n²) — Because for each of the `n` characters, we are creating a new string and checking for a palindrome, which takes `O(n)` time.
* Space Complexity: O(1) - No extra space is used aside from variables.
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

We are asked to determine if a string can be converted to a palindrome by removing **at most one character**. This is a variation of the classic two-pointer palindrome check, with one allowed exception.

🧭Step-by-step Explanation:
1. Two Pointers (Left & Right):
   * Start from both ends (`l = 0`, `r = n-1`).
   * Move inwards while characters match.
2. First Mismatch:
   * At the first mismatch (`s[l] != s[r]`), we have two choices:
     * Remove the left character: Check if `s[l+1...r]` is a palindrome.
     * Remove the right character: Check if `s[l...r-1]` is a palindrome.
3. Helper Function:
   * The helper function checks whether a substring between two indices is a valid palindrome.
4. Return Value:
   * Return `true` if either of the two substrings formed by removing one character is a palindrome.
   * If the entire string passes without mismatch, return `true` directly.

🧠 Time & Space Complexity:
* Time Complexity: O(n) - Only one pass is needed unless a mismatch is found, in which case two O(n) checks are made.
* Space Complexity: O(1) - No extra space is used aside from variables.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
5. Longest Palindromic Substring - https://leetcode.com/problems/longest-palindromic-substring/
131. Palindrome Partitioning - https://leetcode.com/problems/palindrome-partitioning/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent

3-Blast Palindrome - https://www.codechef.com/practice/course/3-star-difficulty-problems/DIFF1700/problems/BLAST3
Weird Palindrome Making - https://www.codechef.com/practice/course/2-star-difficulty-problems/DIFF1500/problems/MAKEPAL
The Next Palindrome - https://www.codechef.com/problems/PALIN
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Fuzzy search engines (spell correction), typo-tolerant login validation.