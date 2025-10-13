> [Coin Change] - https://leetcode.com/problems/coin-change/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

You may assume that you have an infinite number of each kind of coin.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
>Unbounded Knapsack | Dp
--------------------------------------------------------------------------------------------------------------------------------------
## ✅ 1. Top-Down DP with 2D Memoization

### 🔍 Step-by-Step Explanation

* Use a recursive function `coinCount(index, amount)`:

  * Try picking the current coin and reducing the amount.
  * Or skip the coin and move to the next index.
* Store results in a 2D memo table `memo[index][amount]` to avoid recomputation.
* Base Cases:

  * If `amount == 0`, return `0` (no more coins needed).
  * If `index >= coins.size()` or `amount < 0`, return `INT_MAX` (invalid path).
* At each step, return the **minimum** between picking and not picking the current coin.

### ✅ Time Complexity

* `O(n * amount)`
  where `n = number of coins`

### ✅ Space Complexity

* `O(n * amount)` for the memo table
* `O(amount)` recursion stack depth

---

## ✅ 2. Top-Down DP with 1D Memoization (Amount Only)

### 🔍 Step-by-Step Explanation

* Use a recursive function `dp(rem)`:

  * It tries all coins and reduces `rem` by each coin.
  * For each `rem`, store the result in a 1D memo array.
* Base Cases:

  * If `rem < 0`, return `INT_MAX` (invalid).
  * If `rem == 0`, return `0` (no more coins needed).
* For each coin, recursively find the minimum coins needed and memoize it.

### ✅ Time Complexity

* `O(amount * n)`
  (`n` is the number of coins; each amount up to `amount` is visited once)

### ✅ Space Complexity

* `O(amount)` for memoization
* `O(amount)` recursion stack depth

---

## 🧮 3. Bottom-Up DP (Tabulation)

### 🔍 Step-by-Step Explanation

* Use a DP array `dp[i]` that stores the **minimum coins needed** to make amount `i`.
* Initialize `dp[0] = 0` and the rest as `amount + 1` (a sentinel value).
* For each amount from `1` to `amount`, and for each coin:

  * If `i >= coin`, then:

    * `dp[i] = min(dp[i], dp[i - coin] + 1)`
* Final answer is in `dp[amount]`.
* If `dp[amount] > amount`, return `-1` (no combination found).

### ✅ Time Complexity

* `O(amount * n)`
  where `n = number of coins`

### ✅ Space Complexity

* `O(amount)` for the DP array

---

## 🔄 4. BFS Approach (Shortest Path Idea)

### 🔍 Step-by-Step Explanation

* Treat the problem like finding the **shortest path** from `amount` to `0`.
* Start with the `amount` in a queue.
* At each level (step), subtract each coin and enqueue the result.
* Use a `visited[]` array to prevent re-processing the same value.
* If you reach `0`, return the number of steps (coins used).
* If the queue gets exhausted, return `-1`.

### ✅ Time Complexity

* `O(amount * n)` in worst case
  (Each amount may be visited once; for each, we try `n` coins)

### ✅ Space Complexity

* `O(amount)` for the visited array and queue

---

## 🆚 Summary Table

| Approach                  | Time Complexity | Space Complexity | Notes                                      |
| ------------------------- | --------------- | ---------------- | ------------------------------------------ |
| Top-Down DP (2D Memo)     | `O(n * amount)` | `O(n * amount)`  | Memoizes based on coin index and amount    |
| Top-Down DP (1D Memo)     | `O(n * amount)` | `O(amount)`      | More space-efficient, simpler              |
| Bottom-Up DP (Tabulation) | `O(n * amount)` | `O(amount)`      | Iterative, no recursion                    |
| BFS                       | `O(n * amount)` | `O(amount)`      | Finds the shortest path (fast in practice) |

---

## 🧠 Interview Tips

* Always **start with the recursive definition**, then explain how memoization helps.
* For large inputs, **bottom-up DP** is preferred due to no recursion stack.
* The **BFS approach** is often overlooked — great for demonstrating breadth of knowledge.
* Be ready to explain **why you use `amount+1` as sentinel** in DP (represents infinity).

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
871. Minimum Number of Refueling Stops - https://leetcode.com/problems/minimum-number-of-refueling-stops/description/
2547. Minimum Cost to Split an Array - https://leetcode.com/problems/minimum-cost-to-split-an-array/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
ATM dispensing, packing boxes with exact volume 