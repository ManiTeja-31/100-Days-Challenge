> [Longest Palindromic substring] - https://leetcode.com/problems/longest-palindromic-substring/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given a string s, return the longest palindromic substring in s.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Dynamic Programming / Center Expansion
--------------------------------------------------------------------------------------------------------------------------------------
### ✅ Brute Force (Naive Recursion)

**Logic:**

* Generate all possible substrings of `s`.
* For each substring, check if it’s a palindrome.
* Keep track of the longest palindrome found.

**Steps:**

1. Use two nested loops to generate all substrings `s[i...j]`.
2. For each substring, check if it’s a palindrome by comparing characters from both ends.
3. Update the result if this palindrome is longer than the previously stored one.

**Time Complexity:**

* Generating substrings: O(n²)
* Checking each substring for palindrome: O(n)
* **Total: O(n³)**

**Space Complexity:**

* No extra space apart from variables.
* **O(1)**

---

### ✅ Brute Force (With Index-Based Palindrome Check)

**Logic:**

* Same as above, but instead of building the substring manually, we use indices to avoid string concatenation overhead.

**Steps:**

1. Use two loops to iterate over all start and end positions.
2. Use a helper function `isPalindrome(s, i, j)` to check for palindrome in O(n) time.
3. Track the longest one seen so far.

**Time Complexity:** O(n³)
**Space Complexity:** O(1)

---

### ✅ Expand Around Center (Optimal O(n²), Very Efficient in Practice)

**Logic:**

* A palindrome mirrors around its center.
* There are `2n - 1` possible centers in a string of length `n` (odd and even lengths).
* Expand outward from each center and keep track of the longest valid palindrome.

**Steps:**

1. Iterate through each index in the string.
2. For each index:

   * Expand for **odd-length** palindromes (`i, i` as center).
   * Expand for **even-length** palindromes (`i, i+1` as center).
3. Use two pointers to expand while characters match.
4. Return the longest one found.

**Time Complexity:** O(n²)
**Space Complexity:** O(1)

---

### ✅ Top-Down DP (Recursion + Memoization)

**Logic:**

* Use recursion to check if `s[i...j]` is a palindrome.
* If characters at `i` and `j` match, recursively check if `s[i+1...j-1]` is a palindrome.
* Use a 2D memoization table to store results and avoid recomputation.

**Steps:**

1. Create a 2D memo table initialized with -1.
2. For all `(i, j)` pairs, use a recursive helper to determine palindromic status.
3. Update the result if a longer palindrome is found.

**Time Complexity:** O(n²) — each `(i, j)` pair is computed once.
**Space Complexity:** O(n²) for memo table + O(n) recursion stack.

---

### ✅ Bottom-Up DP

**Logic:**

* Use a 2D DP table where `dp[i][j]` is true if `s[i...j]` is a palindrome.
* Fill the table such that smaller substrings are solved before longer ones.

**Steps:**

1. Initialize all `dp[i][i] = true` (single character substrings).
2. Iterate over lengths from 2 to n:

   * For each length, check all substrings of that length.
   * If `s[i] == s[j]` and inner substring is palindrome, mark `dp[i][j] = true`.
3. Track the longest substring where `dp[i][j]` is true.

**Time Complexity:** O(n²)
**Space Complexity:** O(n²)

---

### ✅ Manacher’s Algorithm (O(n) Time)

**Logic:**

* Transform the original string to handle even-length and odd-length palindromes uniformly by inserting `#` between characters.
* Use a technique similar to the Z-algorithm to compute the longest palindromic span centered at each character efficiently.

**Steps:**

1. Preprocess the string: Insert `#` between characters and add sentinels `@` and `$` to avoid bounds checking.
2. Use an array `p[]` where `p[i]` stores the radius of the palindrome centered at `i`.
3. Use two pointers:

   * `center`: current center of the rightmost palindrome.
   * `right`: right boundary of that palindrome.
4. Mirror the current position to skip redundant checks.
5. Expand around current center and update `center` and `right` accordingly.
6. At the end, find the position with the maximum palindrome radius and map it back to the original string.

**Time Complexity:** O(n)
**Space Complexity:** O(n)

---

### 🔁 Summary of Time & Space Complexities

| Approach                        | Time Complexity | Space Complexity |
| ------------------------------- | --------------- | ---------------- |
| Brute Force (Substring & Check) | O(n³)           | O(1)             |
| Brute Force (Index-Based Check) | O(n³)           | O(1)             |
| Expand Around Center            | O(n²)           | O(1)             |
| Top-Down DP (Memoization)       | O(n²)           | O(n²)            |
| Bottom-Up DP                    | O(n²)           | O(n²)            |
| Manacher’s Algorithm            | O(n)            | O(n)             |

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
131. Palindrome Partitioning - https://leetcode.com/problems/palindrome-partitioning/description/
516. Longest Palindromic Subsequence - https://leetcode.com/problems/longest-palindromic-subsequence/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Genome symmetry, file pattern matching, document structure analysis