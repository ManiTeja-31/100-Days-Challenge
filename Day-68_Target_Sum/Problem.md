> [Target Sum] - https://leetcode.com/problems/target-sum/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Dp
--------------------------------------------------------------------------------------------------------------------------------------
## 🔑 Key Insight

This is a **variation of the subset sum** problem.

Each number can be assigned either:

* A `'+'` sign → contributes positively to the sum
* A `'-'` sign → contributes negatively

If you divide the elements into two groups (positive and negative), let:

```
P = sum of positive group
N = sum of negative group
```

Then the problem reduces to solving:

```
P - N = target
P + N = total_sum
```

From these two equations:

```
P = (target + total_sum) / 2
```

We now reduce the problem to **counting the number of subsets** with sum `P`.

---

## ✅ 1. Recursive Backtracking (Naive)

### 🔍 Explanation

* Try every possible '+' or '-' assignment recursively.
* Maintain a running `sum` and index `ind`.
* At the base case (`ind == nums.size()`), check if `sum == target`.

### ✅ Time Complexity

* `O(2^n)` — Each number has two choices

### ✅ Space Complexity

* `O(n)` — Recursion stack depth

---

## 🚀 2. Top-Down DP with Memoization

### 🔍 Explanation

* Use a DP table `memo[ind][sum + offset]` to memoize results.
* `offset = 1000` handles negative sums (since sum range is `-1000` to `+1000`).
* Avoid redundant calculations by storing results for each `(ind, sum)`.

### ✅ Time Complexity

* `O(n * 2001)` → `n` elements and `sum` ranges from `-1000` to `1000`

### ✅ Space Complexity

* `O(n * 2001)` for memoization
* `O(n)` recursion stack

---

## 🧮 3. Bottom-Up DP (Tabulation using Subset Sum Transformation)

### 🔍 Transformation to Subset Sum

We convert the problem to:

```
Find the number of subsets with sum = (total + target) / 2
```

Let:

* `newTarget = (total + target) / 2`
* Use a DP array where `dp[i]` = number of ways to make sum `i`.

### 🔍 Explanation

* Initialize `dp[0] = 1` (1 way to make sum 0)
* For each `num` in `nums`, update `dp` from `newTarget` down to `num`:

  * `dp[j] += dp[j - num]`

### ⚠️ Note

If `total + target` is **odd**, return 0 (not possible to split into integers).

### ✅ Time Complexity

* `O(n * newTarget)`

### ✅ Space Complexity

* `O(newTarget)` — 1D DP array

---

## 🆚 Summary Table

| Approach                  | Time Complexity    | Space Complexity | Notes                             |
| ------------------------- | ------------------ | ---------------- | --------------------------------- |
| Recursive (Naive)         | `O(2^n)`           | `O(n)`           | Brute force; not scalable         |
| Top-Down DP (Memoization) | `O(n * 2001)`      | `O(n * 2001)`    | Handles negative sums with offset |
| Bottom-Up DP (Tabulation) | `O(n * newTarget)` | `O(newTarget)`   | Most optimal and scalable         |

---

## 🧠 Interview Tips

* Always check and explain the **mathematical transformation**:

  ```
  P - N = target
  P + N = total → P = (target + total) / 2
  ```
* Clarify **why the problem reduces to subset sum**.
* Remember to handle edge cases:

  * `abs(target) > total_sum` → 0 ways
  * `(target + total_sum)` is **odd** → 0 ways

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
282. Expression Add Operators - https://leetcode.com/problems/expression-add-operators/description/
2787. Ways to Express an Integer as Sum of Powers - https://leetcode.com/problems/ways-to-express-an-integer-as-sum-of-powers/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Budget balancing, diff in accounting, positive/negative scoring