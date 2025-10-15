> [Longest Common Subsequence] - https://leetcode.com/problems/longest-common-subsequence/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given two strings text1 and text2, return the length of their longest common subsequence. If there is no common subsequence, return 0.

A subsequence of a string is a new string generated from the original string with some characters (can be none) deleted without changing the relative order of the remaining characters.

For example, "ace" is a subsequence of "abcde".
A common subsequence of two strings is a subsequence that is common to both strings.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Dp
--------------------------------------------------------------------------------------------------------------------------------------
## ✅ 1. Recursive Approach (Naive)

### 🔍 Logic

* Use recursion to explore all possible subsequences.
* If `text1[i] == text2[j]`, count it and recurse to `i+1, j+1`.
* Else, try both `i+1, j` and `i, j+1`, and return the max.

### 🧠 Base Case

* If `i` or `j` reaches the end of its string → return 0.

### ✅ Time Complexity

* `O(2^n)` — Exponential in worst-case (very inefficient for large inputs)

### ✅ Space Complexity

* `O(n + m)` — Maximum depth of recursion stack

---

## ✅ 2. Top-Down DP (Memoization)

### 🔍 Logic

* Same logic as recursion, but use a `dp[i][j]` table to memoize overlapping subproblems.

### 🧠 Optimization

* Avoid redundant recursive calls.
* Use a `2D memo` array where:

  * `memo[i][j]` stores LCS of `text1[i:]` and `text2[j:]`.

### ✅ Time Complexity

* `O(n * m)` — each state `(i, j)` is computed only once

### ✅ Space Complexity

* `O(n * m)` — for memo table
* `O(n + m)` — recursion stack

---

## ✅ 3. Bottom-Up DP (Tabulation)

### 🔍 Logic

* Fill a `dp` table from the bottom-right corner up.
* `dp[i][j]` means: LCS length for `text1[i:]` and `text2[j:]`.
* If `text1[i] == text2[j]`, then `dp[i][j] = 1 + dp[i+1][j+1]`.
* Else, `dp[i][j] = max(dp[i+1][j], dp[i][j+1])`.

### ✅ Time Complexity

* `O(n * m)` — two nested loops

### ✅ Space Complexity

* `O(n * m)` — 2D table

---

## ✅ 4. Space Optimized Bottom-Up DP

### 🔍 Logic

* Only use two 1D arrays: `curr` and `next`, instead of a full 2D table.
* We only need the next row to compute the current one.

### ✅ Time Complexity

* `O(n * m)`

### ✅ Space Complexity

* `O(m)` — using two rows of size `m + 1`

---

## 🔢 Summary Table

| Approach                  | Time Complexity | Space Complexity | Notes                             |
| ------------------------- | --------------- | ---------------- | --------------------------------- |
| Recursive (Naive)         | `O(2^n)`        | `O(n + m)`       | Very inefficient for large inputs |
| Top-Down DP (Memoization) | `O(n * m)`      | `O(n * m)`       | Efficient with memoization        |
| Bottom-Up DP (Tabulation) | `O(n * m)`      | `O(n * m)`       | Standard and clear DP approach    |
| Space Optimized DP        | `O(n * m)`      | `O(m)`           | Best for space efficiency         |

---

## ✅ Example

```txt
text1 = "abcde"
text2 = "ace"

LCS = "ace" → Length = 3
```

---

## 🧠 Interview Tips

* LCS is foundational for problems like:

  * Edit Distance
  * Minimum Insertions/Deletions
  * Longest Palindromic Subsequence
* For 2D DP, always ask:

  * What does `dp[i][j]` represent?
  * What’s the recurrence relation?

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
72. Edit Distance - https://leetcode.com/problems/edit-distance/description/
583. Delete Operation for Two Strings - https://leetcode.com/problems/delete-operation-for-two-strings/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
DNA sequence matching, diff tools (Git), text comparison 