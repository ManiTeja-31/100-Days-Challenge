> [House Robber II] - https://leetcode.com/problems/house-robber-ii/description/
> Level - 
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have a security system connected, and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> DP on Circular Array
--------------------------------------------------------------------------------------------------------------------------------------
This is a follow-up to the classic **House Robber** problem.

## ❓ Problem Summary

In this variation, **houses are arranged in a circle**, meaning:

* The **first and last houses are adjacent**.
* You cannot rob both the first and the last house.

## 🧠 Key Insight

To handle the circular nature:

* **Split into two linear problems**:

  1. Rob houses from **index 0 to n-2** (exclude the last house)
  2. Rob houses from **index 1 to n-1** (exclude the first house)
* Return the **maximum** of these two scenarios.

---

## 1. 🚫 Naive Recursion (Brute Force)

### **Explanation**

* Calls a helper function twice: once excluding the last house, once excluding the first.
* For each house, recursively choose to rob (and move to `i+2`) or skip (and move to `i+1`).
* Explores **all combinations** of robbing.

### **Time Complexity**

* `O(2^n)` — exponential, as every index has two choices.

### **Space Complexity**

* `O(n)` — due to recursion call stack.

---

## 2. 🧠 Recursion with Memoization (Top-Down DP)

### **Explanation**

* Same two-case split (`0 to n-2` and `1 to n-1`).
* Uses **memoization** arrays for each case to **avoid recomputation**.
* For each index, cache the best result to avoid repeated work.

### **Time Complexity**

* `O(n)` — each index is computed only once per scenario.

### **Space Complexity**

* `O(n)` — for memo arrays and recursion stack.

---

## 3. 📋 Bottom-Up DP (Tabulation)

### **Explanation**

* Iterative approach for both subarrays: `0 to n-2` and `1 to n-1`.
* Use a `dp` array where:

  * `dp[i]` = max loot up to house `i`
  * `dp[i] = max(nums[i] + dp[i-2], dp[i-1])`
* Handles base cases carefully (like when `n == 1` or `n == 2`).

### **Time Complexity**

* `O(n)` — loop runs for `n - 1` houses per scenario.

### **Space Complexity**

* `O(n)` — due to `dp` array.

---

## 🔚 Summary & Comparison

| Approach                      | Time Complexity | Space Complexity | Pros                               | Cons                                  |
| ----------------------------- | --------------- | ---------------- | ---------------------------------- | ------------------------------------- |
| Naive Recursion (Brute Force) | O(2^n)          | O(n)             | Simple to write                    | Too slow, impractical for large `n`   |
| Recursion + Memoization       | O(n)            | O(n)             | Efficient and avoids recomputation | Still uses recursion and extra memory |
| Bottom-Up DP (Tabulation)     | O(n)            | O(n)             | Iterative, no recursion needed     | Slightly more memory usage            |

---

## ✅ Recommendation

* Use **Bottom-Up DP** for interviews and production — it’s efficient and easy to explain.
* **Memoization** is good when converting from recursion.
* Avoid brute force unless illustrating the concept or for very small inputs.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
337. House Robber III - https://leetcode.com/problems/house-robber-iii/description/
600. Non-negative Integers without Consecutive Ones - https://leetcode.com/problems/non-negative-integers-without-consecutive-ones/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Same as House Robber, but for circular setups (e.g., cameras around a circular wall) 