> [Palindrome Partition] - https://leetcode.com/problems/palindrome-partitioning/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given a string s, partition s such that every substring of the partition is a palindrome. Return all possible palindrome partitioning of s.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> BackTracking + Dp
--------------------------------------------------------------------------------------------------------------------------------------
## ✅ 1. Naive Recursive Backtracking

### 🔍 Step-by-Step Explanation

1. Start from index `0`.
2. Try to form all substrings `s[ind...end]`.
3. For each substring:

   * Check if it's a **palindrome**.
   * If it is:

     * Add it to the current path.
     * Recursively partition the remaining string from `end + 1`.
     * Backtrack by removing the last added substring.
4. If the index reaches the end of the string, add the current path to the result.

### ✅ Time Complexity

* **Worst-case:** `O(2^n * n)`

  * There are `2^n` possible partitions.
  * Checking palindrome takes `O(n)` time.

### ✅ Space Complexity

* `O(n)` recursion stack
* `O(n)` extra space for storing current partition path

---

## 🚀 2. Top-Down DP (Memoization)

### 🔍 Step-by-Step Explanation

This approach builds on the naive one, with a **memoization table** to cache palindrome checks.

1. Before checking if `s[start...end]` is a palindrome, check if the result is already computed in `memo[start][end]`.
2. If cached, use it directly to save time.
3. Otherwise, perform the check and store the result in `memo`.

### ✅ Time Complexity

* **Improved:** `O(2^n)` recursion + `O(n^2)` for memoized palindrome checks

### ✅ Space Complexity

* `O(n^2)` for `memo` table
* `O(n)` recursion stack

---

## 📉 3. Bottom-Up DP (Tabulation)

### 🔍 Step-by-Step Explanation

This approach precomputes **all palindromic substrings** using a DP table.

1. Create a 2D DP table `dp[i][j]`:

   * `true` if `s[i...j]` is a palindrome.
2. Fill the table:

   * Substrings of length 1 and 2 are trivial.
   * For longer substrings, use the recurrence:

     * `dp[i][j] = (s[i] == s[j]) && dp[i+1][j-1]`
3. Once precomputation is done:

   * Use the DP table to guide backtracking.
   * Avoid redundant palindrome checks.

### ✅ Time Complexity

* `O(n^2)` for palindrome DP table
* `O(2^n)` for generating all partitions

### ✅ Space Complexity

* `O(n^2)` for DP table
* `O(n)` recursion stack

---

## 🆚 Summary Table

| Approach                  | Time Complexity | Space Complexity | Optimization                                |
| ------------------------- | --------------- | ---------------- | ------------------------------------------- |
| Naive Backtracking        | `O(2^n * n)`    | `O(n)`           | Simple recursion                            |
| Top-Down DP (Memoization) | `O(2^n + n^2)`  | `O(n^2)`         | Caches palindrome checks                    |
| Bottom-Up DP (Tabulation) | `O(n^2 + 2^n)`  | `O(n^2)`         | Precomputes all palindromes for fast lookup |

---

## 🧠 Interview Tips

* **Start with** the naive recursive solution to show clarity of logic.
* Then **optimize using memoization** to reduce redundant palindrome checks.
* Finally, explain the **DP tabulation** method as a preprocessing trick to make palindrome lookups `O(1)`.
* Be ready to explain **why the number of partitions is exponential** and how we reduce overhead.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
132. Palindrome Partitioning II - https://leetcode.com/problems/palindrome-partitioning-ii/description/
1745. Palindrome Partitioning IV - https://leetcode.com/problems/palindrome-partitioning-iv/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Palindromic segmentation in DNA strings or encryption   