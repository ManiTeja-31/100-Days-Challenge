> [Coin Change II] - https://leetcode.com/problems/coin-change-ii/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.

You may assume that you have an infinite number of each kind of coin.

The answer is guaranteed to fit into a signed 32-bit integer.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Dp
--------------------------------------------------------------------------------------------------------------------------------------
## ✅ 1. Recursive Backtracking (Naive)

### 🔍 Step-by-Step Explanation

1. Define a recursive function `coinCount(index, amount)`:

   * **Base Case 1:** If `amount == 0`, return `1` (valid combination).
   * **Base Case 2:** If `amount < 0` or `index == coins.size()`, return `0`.
2. At each step:

   * **Pick** the current coin (stay at `index`, subtract coin value from amount).
   * **Not Pick** the current coin (move to `index + 1`, keep amount unchanged).
3. Return the total combinations: `pick + notPick`.

### ✅ Time Complexity

* **Exponential:** `O(2^n)` where `n = amount` in worst case.

### ✅ Space Complexity

* `O(amount)` recursion stack depth.

---

## 🚀 2. Top-Down DP with Memoization

### 🔍 Step-by-Step Explanation

1. Add memoization to the recursive approach to **avoid recomputation**.
2. Use a 2D memo table `memo[index][amount]` to store results.
3. Before recursive calls, check if the result is already computed.
4. Return stored value if available.

### ✅ Time Complexity

* `O(n * amount)`
  where `n = number of coins`

### ✅ Space Complexity

* `O(n * amount)` for memo table
* `O(amount)` recursion stack

---

## 🧮 3. Bottom-Up DP (Tabulation)

### 🔍 Step-by-Step Explanation

1. Use a 1D DP array `dp[i]` where `dp[i]` represents the number of ways to form amount `i`.
2. Initialize `dp[0] = 1` (1 way to make amount 0 — pick nothing).
3. For each coin:

   * For `i = coin` to `amount`:

     * `dp[i] += dp[i - coin]`
   * This ensures combinations are counted **without considering order** (each coin added in outer loop).

### ✅ Time Complexity

* `O(n * amount)`
  where `n = number of coins`

### ✅ Space Complexity

* `O(amount)` for the DP array

---

## 🆚 Summary Table

| Approach               | Time Complexity | Space Complexity | Notes                            |
| ---------------------- | --------------- | ---------------- | -------------------------------- |
| Recursive (Naive)      | `O(2^amount)`   | `O(amount)`      | Simple but inefficient           |
| Top-Down DP (Memo)     | `O(n * amount)` | `O(n * amount)`  | Efficient and easy to implement  |
| Bottom-Up DP (Tabular) | `O(n * amount)` | `O(amount)`      | Most efficient in terms of space |

---

## 🧠 Interview Tips

* Mention the **difference from Coin Change I**:

  * Coin Change I → minimum coins
  * Coin Change II → number of combinations
* Emphasize that the **order doesn't matter**, so outer loop is on coins.
* Use **DP[0] = 1** as the base case (1 way to make 0).
* You may highlight that **1D DP** works due to the **unbounded knapsack pattern**.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
2585. Number of Ways to Earn Points - https://leetcode.com/problems/number-of-ways-to-earn-points/description/
3592. Inverse Coin Change - https://leetcode.com/problems/inverse-coin-change/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
