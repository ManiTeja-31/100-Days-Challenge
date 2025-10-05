> [Climbing Stairs] - https://leetcode.com/problems/climbing-stairs/description/
> Level - Easy
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

You are climbing a staircase. It takes n steps to reach the top.
Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Fibonacci / DP on Steps
--------------------------------------------------------------------------------------------------------------------------------------
This is a variation of the **Fibonacci sequence**, where:

* `ways(n) = ways(n-1) + ways(n-2)`
* Base cases: `ways(0) = 1`, `ways(1) = 1`

---

## 1. 🚫 Naive Recursion (Brute Force)

### **Explanation**

* Treat the problem recursively: to reach step `n`, we could have come from step `n-1` or `n-2`.
* So, the function calls itself for `n-1` and `n-2` until base cases are hit.
* It explores **all possible paths** but recomputes the same subproblems many times.

### **Time Complexity**

* `O(2^n)` — exponential growth due to repeated subproblems.

### **Space Complexity**

* `O(n)` — due to the recursion stack (max depth `n`).

---

## 2. 🧠 Recursion with Memoization (Top-Down DP)

### **Explanation**

* Improves naive recursion by **caching results** of subproblems using a memoization array.
* Whenever a subproblem (`ways(i)`) is solved, store its result in an array.
* On subsequent calls, check the array before computing again.

### **Time Complexity**

* `O(n)` — each subproblem is computed only once.

### **Space Complexity**

* `O(n)` — for both the recursion stack and the memoization array.

---

## 3. 🧠 Alternative Memoization (More Intuitive)

### **Explanation**

* Instead of calling from step 1 or 2 to n (as in previous version), this version directly computes from step `n` down to base cases using recursion.
* Still uses memoization to cache subproblem results.

### **Time Complexity**

* `O(n)`

### **Space Complexity**

* `O(n)`

---

## 4. 📋 Bottom-Up DP (Tabulation)

### **Explanation**

* Use an iterative approach: build up the solution from base cases.
* Create a DP array where each entry `dp[i]` stores the number of ways to reach step `i`.
* Use the recurrence relation: `dp[i] = dp[i-1] + dp[i-2]`

### **Time Complexity**

* `O(n)`

### **Space Complexity**

* `O(n)` — due to the DP array.

---

## 5. 💡 Optimized DP (Constant Space)

### **Explanation**

* Instead of storing all `n` results, we only need the last two to compute the next step.
* Maintain two variables to store the number of ways to reach the two previous steps, and iteratively update them.

### **Time Complexity**

* `O(n)`

### **Space Complexity**

* `O(1)` — constant space.

---

## 6. 🧮 Matrix Exponentiation (Logarithmic Time)

### **Explanation**

* Uses the matrix form of Fibonacci:

  ```
  [F(n+1)]   = [1 1]^n
  [F(n)  ]     [1 0]
  ```
* Efficiently computes this using **exponentiation by squaring**.
* This drastically reduces the time complexity.

### **Time Complexity**

* `O(log n)` — due to fast matrix exponentiation.

### **Space Complexity**

* `O(1)` — if matrix multiplication is done in-place, otherwise `O(log n)` if recursion is used.

---

## 7. ✨ Binet’s Formula (Closed-form Fibonacci)

### **Explanation**

* Uses a mathematical formula to directly compute the `n`-th Fibonacci number:

  ```
  F(n) = (phi^(n+1)) / sqrt(5)
  where phi = (1 + sqrt(5)) / 2
  ```
* Requires rounding due to floating point precision.

### **Time Complexity**

* `O(1)` — constant time.

### **Space Complexity**

* `O(1)`

---

# 🔚 Summary & Comparison

| Approach                   | Time Complexity | Space Complexity | Pros                                 | Cons                                      |
| -------------------------- | --------------- | ---------------- | ------------------------------------ | ----------------------------------------- |
| Naive Recursion            | O(2^n)          | O(n)             | Simple to write and understand       | Extremely inefficient for large `n`       |
| Recursion + Memoization    | O(n)            | O(n)             | Optimized over naive recursion       | Uses extra space for memo + call stack    |
| Top-Down Alternative       | O(n)            | O(n)             | Cleaner & direct with intuitive base | Same space drawback                       |
| Bottom-Up DP (Tabulation)  | O(n)            | O(n)             | Iterative and avoids call stack      | Still uses O(n) space                     |
| Optimized DP (Const Space) | O(n)            | O(1)             | Best for practical use, very fast    | Slightly less intuitive than tabulation   |
| Matrix Exponentiation      | O(log n)        | O(1)             | Very efficient for large `n`         | Overkill for small `n`, more complex math |
| Binet’s Formula            | O(1)            | O(1)             | Instant result using math            | May cause precision errors for large `n`  |

---

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
746. Min Cost Climbing Stairs - https://leetcode.com/problems/min-cost-climbing-stairs/description/
403. Frog Jump - https://leetcode.com/problems/frog-jump/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Count the number of ways to reach the top of stairs — similar to modeling user journey steps, robotic arm moves, etc.