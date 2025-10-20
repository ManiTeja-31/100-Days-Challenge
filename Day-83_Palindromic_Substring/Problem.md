> [Palindromic Substring] - https://leetcode.com/problems/palindromic-substrings/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given a string s, return the number of palindromic substrings in it.
A string is a palindrome when it reads the same backward as forward.
A substring is a contiguous sequence of characters within the string.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Expand Around Center / Dynamic Programming 
--------------------------------------------------------------------------------------------------------------------------------------
### ✅ Naive / Brute Force Approach

**Logic:**

1. We check every possible substring of the input string `s`.
2. For each substring, we check whether it is a palindrome using a helper function.
3. A palindrome is valid if the characters from the beginning and end match until the middle is reached.

**Steps:**

* Use two nested loops: outer loop starts from each index `i`, and inner loop goes from `i` to the end of the string.
* For each substring `s[i...j]`, call a helper function to check if it’s a palindrome.
* Count all substrings that are palindromes.

**Time Complexity:**

* Generating all substrings takes **O(n²)** time.
* Checking each substring for palindrome takes up to **O(n)** time.
* So overall: **O(n³)**

**Space Complexity:**

* No extra space used (excluding recursion stack if not inlined).
* So: **O(1)**

---

### ✅ Top-Down DP with Memoization

**Logic:**

1. Uses recursion with memoization to avoid recalculating palindrome checks for the same substrings.
2. For each pair `(i, j)`, recursively check if `s[i] == s[j]` and if the inner substring `s[i+1...j-1]` is a palindrome.
3. Memoize results in a 2D matrix to avoid redundant computations.

**Steps:**

* Initialize a 2D `memo` matrix with -1 to indicate uncomputed results.
* For every substring `s[i...j]`, use recursive helper to check if it’s a palindrome.
* If the characters at `i` and `j` match, recurse on `i+1` and `j-1`.
* Memoize and count all valid palindromes.

**Time Complexity:**

* There are **O(n²)** unique substring pairs.
* Each is computed once due to memoization.
* So overall: **O(n²)**

**Space Complexity:**

* 2D memoization matrix of size `n x n`: **O(n²)**
* Recursion stack can go up to **O(n)** depth in worst case.

---

### ✅ Bottom-Up DP Approach

**Logic:**

1. Build a DP table where `dp[i][j]` indicates if `s[i...j]` is a palindrome.
2. Start filling the table from the bottom up (reverse order), because `dp[i][j]` depends on `dp[i+1][j-1]`.
3. A substring is a palindrome if:

   * The characters at the ends match, and
   * The inner substring is a palindrome (or the length is less than 3).

**Steps:**

* Use two nested loops: outer from end to start, inner from current `i` to end.
* If characters at `i` and `j` match, and the substring `s[i+1...j-1]` is a palindrome (or small enough), then `s[i...j]` is also a palindrome.
* Count all such valid palindromes.

**Time Complexity:**

* Two nested loops over `n`: **O(n²)**

**Space Complexity:**

* 2D DP table of size `n x n`: **O(n²)**

---

### ✅ Expand Around Center Approach

**Logic:**

1. Every palindrome has a center — either one character (odd-length) or two characters (even-length).
2. For each character in the string, we try to expand around it as a center and count how many palindromes we find.
3. We perform two expansions per character:

   * One treating it as the center of an odd-length palindrome.
   * One treating it as the center of an even-length palindrome.

**Steps:**

* For every index `i` in the string:

  * Expand around `i, i` (odd-length).
  * Expand around `i, i+1` (even-length).
* While characters match on both sides, keep expanding and count valid palindromes.

**Time Complexity:**

* Each expansion takes at most **O(n)** time in the worst case.
* There are `2n` centers.
* So overall: **O(n²)**

**Space Complexity:**

* No extra space used: **O(1)**

---

### 🔁 Summary of Time & Space Complexities:

| Approach                  | Time Complexity | Space Complexity |
| ------------------------- | --------------- | ---------------- |
| Naive / Brute Force       | O(n³)           | O(1)             |
| Top-Down DP (Memoization) | O(n²)           | O(n²)            |
| Bottom-Up DP              | O(n²)           | O(n²)            |
| Expand Around Center      | O(n²)           | O(1)             |

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
516. Longest Palindromic Subsequence - https://leetcode.com/problems/longest-palindromic-subsequence/description/
730. Count Different Palindromic Subsequences - https://leetcode.com/problems/count-different-palindromic-subsequences/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
DNA pattern checks, linguistic processing, code obfuscation.