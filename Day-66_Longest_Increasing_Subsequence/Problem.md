> [Longest Increasing Subsequence] - https://leetcode.com/problems/longest-increasing-subsequence/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an integer array nums, return the length of the longest strictly increasing subsequence.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Dp
--------------------------------------------------------------------------------------------------------------------------------------
## ✅ 1. Recursive Backtracking (Naive)

### 🔍 Step-by-Step Explanation

* Define a recursive function `LIS(index, prevIndex)`:

  * At each step, decide whether to **pick** the current number or **skip** it.
  * If picked, `nums[index]` must be greater than `nums[prevIndex]`.
  * Explore both choices and return the maximum length.
* Use `prevIndex = -1` initially to indicate no previous number.

### ✅ Time Complexity

* **Exponential:** `O(2^n)`
  (Every number can either be picked or not)

### ✅ Space Complexity

* `O(n)` recursion stack depth

---

## 🚀 2. Top-Down DP with Memoization

### 🔍 Step-by-Step Explanation

* Improve the recursive solution by memoizing the results.
* Use a 2D memo table `memo[index][prevIndex + 1]`:

  * Offset by `+1` to handle `prevIndex = -1`.
* Store and reuse computed values to avoid redundant recursion.

### ✅ Time Complexity

* `O(n^2)`
  (`n` states for `index` × `n` states for `prevIndex`)

### ✅ Space Complexity

* `O(n^2)` for memo table
* `O(n)` recursion stack

---

## 🧮 3. Bottom-Up DP (Tabulation)

### 🔍 Step-by-Step Explanation

* Use a 1D DP array `dp[i]`:

  * Stores the length of LIS ending at index `i`.
* Initialize all `dp[i] = 1` (every number is a subsequence of length 1).
* For each `i`, check all `j < i`:

  * If `nums[i] > nums[j]`, update `dp[i] = max(dp[i], dp[j] + 1)`
* Return the **maximum value in dp**.

### ✅ Time Complexity

* `O(n^2)`

### ✅ Space Complexity

* `O(n)` for the `dp` array

---

## ⚡ 4. Optimized Bottom-Up DP with Binary Search (Patience Sorting)

### 🔍 Step-by-Step Explanation

* Maintain a list `tails`:

  * `tails[i]` = the smallest possible **tail** of an increasing subsequence of length `i+1`
* For each number in `nums`:

  * Use `lower_bound()` to find the index to replace in `tails`.
  * If number is greater than all tails, append it.
  * Otherwise, replace the first tail that’s ≥ number.
* The size of `tails` gives the length of LIS.

### ✅ Time Complexity

* `O(n log n)`
  (Binary search for each of `n` elements)

### ✅ Space Complexity

* `O(n)` for the `tails` list

---

## 🆚 Summary Table

| Approach                     | Time Complexity | Space Complexity | Notes                                      |
| ---------------------------- | --------------- | ---------------- | ------------------------------------------ |
| Recursive (Naive)            | `O(2^n)`        | `O(n)`           | Simple but inefficient                     |
| Top-Down DP (Memoization)    | `O(n^2)`        | `O(n^2)`         | Optimized recursion                        |
| Bottom-Up DP (Tabulation)    | `O(n^2)`        | `O(n)`           | Classic DP approach                        |
| Optimized DP (Binary Search) | `O(n log n)`    | `O(n)`           | Fastest method using patience sorting idea |

---

## 🧠 Interview Tips

* Start with the **basic recursive** definition to build intuition.
* Explain **memoization** to reduce redundant work.
* Bottom-up DP is easiest to implement for interviews.
* The `O(n log n)` approach is best when asked for an optimized solution.
* Mention that the **optimized solution gives length only**, not the actual sequence (unless tracked separately).

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
354. Russian Doll Envelopes - https://leetcode.com/problems/russian-doll-envelopes/description/
673. Number of Longest Increasing Subsequence - https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Career progression, price trend analysis, version upgrades