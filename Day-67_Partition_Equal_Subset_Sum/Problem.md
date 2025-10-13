> [Partition Equal Subset Sum] - https://leetcode.com/problems/partition-equal-subset-sum/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an integer array nums, return true if you can partition the array into two subsets such that the sum of the elements in both subsets is equal or false otherwise.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Dp
--------------------------------------------------------------------------------------------------------------------------------------
## 🔑 Key Insight

If the total sum of the array is odd → ❌ Not possible to split equally.
If it's even → We check whether a subset with **sum = total / 2** exists.

---

## ✅ 1. Recursive Backtracking (Naive)

### 🔍 Explanation

* Define a recursive function `backTrack(index, target)`:

  * Try **including** or **excluding** the current element.
  * If `target == 0`, return `true`.
  * If `target < 0` or `index >= nums.size()`, return `false`.
* Explore all subsets recursively.

### ✅ Time Complexity

* `O(2^n)` — All subsets are explored (exponential).

### ✅ Space Complexity

* `O(n)` — Max recursion stack depth.

---

## 🚀 2. Top-Down DP with Memoization

### 🔍 Explanation

* Add memoization to avoid recomputing subproblems.
* Use a 2D memo table `memo[index][target]`.
* At each step:

  * Check if we already solved for `index` and `target`.
  * If yes, return the stored result.

### ✅ Time Complexity

* `O(n * target)`
  where `target = total / 2`

### ✅ Space Complexity

* `O(n * target)` for memo table
* `O(n)` recursion stack

---

## 🧮 3. Bottom-Up DP (1D Array)

### 🔍 Explanation

* Classic 0/1 Knapsack-style approach.
* Use a 1D DP array `dp[sum + 1]`, where `dp[j] = true` means subset sum `j` is possible.
* Start with `dp[0] = true` (sum 0 is always possible).
* For each number in `nums`:

  * Traverse `j` from `target` to `num`, updating `dp[j] |= dp[j - num]`.
* Finally, return `dp[target]`.

### ✅ Time Complexity

* `O(n * target)`

### ✅ Space Complexity

* `O(target)`

---

## 🧱 4. Bottom-Up DP (2D Array)

### 🔍 Explanation

* Use a 2D DP table `dp[i][j]`:

  * `i = 0...n`, `j = 0...target`
  * `dp[i][j] = true` if we can get sum `j` using first `i` elements.
* Base case: `dp[i][0] = true` for all `i` (sum 0 is always possible).
* Fill the table by deciding:

  * **Pick**: if `j >= nums[i-1]`, check `dp[i-1][j - nums[i-1]]`
  * **Not Pick**: carry forward `dp[i-1][j]`
* Final answer: `dp[n][target]`

### ✅ Time Complexity

* `O(n * target)`

### ✅ Space Complexity

* `O(n * target)`

---

## 🆚 Comparison Table

| Approach                  | Time Complexity | Space Complexity | Notes                              |
| ------------------------- | --------------- | ---------------- | ---------------------------------- |
| Recursive (Naive)         | `O(2^n)`        | `O(n)`           | Simple but inefficient             |
| Top-Down DP (Memoization) | `O(n * target)` | `O(n * target)`  | Optimized recursion                |
| Bottom-Up DP (1D)         | `O(n * target)` | `O(target)`      | Space efficient, preferred         |
| Bottom-Up DP (2D)         | `O(n * target)` | `O(n * target)`  | Good for clarity and understanding |

---

## 🧠 Interview Tips

* Mention you’re solving a variation of the **Subset Sum Problem**.
* Clarify that you’re **not allowed to reorder** or use elements multiple times.
* Always check whether the total sum is **even or odd** before proceeding.
* 1D DP is optimal in practice, but 2D DP is easier to **explain and visualize** in interviews.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
698. Partition to K Equal Sum Subsets - https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/
2025. Maximum Number of Ways to Partition an Array - https://leetcode.com/problems/maximum-number-of-ways-to-partition-an-array/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Load balancing, dividing containers, scheduling teams 