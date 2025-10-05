> [House Robber] - https://leetcode.com/problems/house-robber/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> DP – Non-adjacent max sum 
--------------------------------------------------------------------------------------------------------------------------------------
You're given an array `nums` where each element represents the amount of money at a house. You **cannot rob two adjacent houses**. The goal is to find the **maximum amount of money** you can rob without alerting the police.

This is a **classic DP problem** involving **decision making at each index**: either rob this house or skip it.

---

## 1. 🚫 Naive Recursion (Brute Force)

### **Explanation**

* At each house (index `i`), you make a decision:

  * **Skip the house** and go to `i + 1`
  * **Rob the house**, add its value to total, and move to `i + 2` (next non-adjacent house)
* Recursively calculate the max of both choices.
* **Explores all combinations**, making it highly inefficient for large arrays.

### **Time Complexity**

* `O(2^n)` — Exponential, due to branching at each index.

### **Space Complexity**

* `O(n)` — Due to recursion call stack.

---

## 2. 🧠 Recursion with Memoization (Top-Down DP)

### **Explanation**

* Improves brute force by **caching subproblem results** using a memoization array.
* Before solving a subproblem `i`, check if it's already computed.
* Avoids redundant recursive calls for the same index.

### **Time Complexity**

* `O(n)` — Each index is computed only once.

### **Space Complexity**

* `O(n)` — For memo array + recursion stack.

---

## 3. 📋 Bottom-Up DP (Tabulation)

### **Explanation**

* Instead of solving top-down, solve bottom-up iteratively.
* `dp[i]` represents the max money robbed up to house `i`.
* Transition:

  * `dp[i] = max(dp[i-1], nums[i] + dp[i-2])`
  * Either skip current house (`dp[i-1]`) or rob it and add value from `i-2`.
* Initialize base cases:

  * `dp[0] = nums[0]`
  * `dp[1] = max(nums[0], nums[1])`

### **Time Complexity**

* `O(n)`

### **Space Complexity**

* `O(n)` — Due to DP array.

---

## 4. 💡 Bottom-Up DP (Space Optimized)

### **Explanation**

* Optimize space by noticing that we only need `dp[i-1]` and `dp[i-2]` at each step.
* Use two variables:

  * `prev1` → max at `i-1`
  * `prev2` → max at `i-2`
* Update them iteratively.

### **Time Complexity**

* `O(n)`

### **Space Complexity**

* `O(1)` — Only two variables needed.

---

# 🔚 Summary & Comparison

| Approach                           | Time Complexity | Space Complexity | Pros                             | Cons                                 |
| ---------------------------------- | --------------- | ---------------- | -------------------------------- | ------------------------------------ |
| Naive Recursion (Brute Force)      | O(2^n)          | O(n)             | Simple to implement              | Not scalable, very slow              |
| Recursion + Memoization (Top-Down) | O(n)            | O(n)             | Easy transition from brute force | Uses extra space for recursion       |
| Bottom-Up DP (Tabulation)          | O(n)            | O(n)             | Efficient and avoids recursion   | Slightly more memory usage           |
| Bottom-Up DP (Space Optimized)     | O(n)            | O(1)             | Best performance, constant space | Logic may be less intuitive at first |

---

## ✅ Recommendation

* For interviews and production code: prefer the **Space Optimized Bottom-Up DP**.
* If you’re transitioning from recursion, use **Memoization (Top-Down DP)** for better clarity.

---
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
740. Delete and Earn - https://leetcode.com/problems/delete-and-earn/description/
256. Paint House - https://leetcode.com/problems/paint-house/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Choosing tasks/machines/data without consecutive constraints