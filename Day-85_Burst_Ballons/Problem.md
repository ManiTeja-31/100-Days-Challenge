> [312. Burst Balloons] - https://leetcode.com/problems/burst-balloons/description/
> Level - Hard
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

You are given n balloons, indexed from 0 to n - 1. Each balloon is painted with a number on it represented by an array nums. You are asked to burst all the balloons.

If you burst the ith balloon, you will get nums[i - 1] * nums[i] * nums[i + 1] coins. If i - 1 or i + 1 goes out of bounds of the array, then treat it as if there is a balloon with a 1 painted on it.

Return the maximum coins you can collect by bursting the balloons wisely.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Interval Dp
--------------------------------------------------------------------------------------------------------------------------------------
## 🧩 Problem Intuition

You are given an array of integers `nums` where each balloon has a certain number written on it.

When you **burst** a balloon `i`, you earn coins equal to:

```
nums[i-1] * nums[i] * nums[i+1]
```

After bursting balloon `i`, it disappears — so its neighbors now become adjacent.

Your task:
💡 **Find the maximum number of coins you can collect by bursting balloons in the optimal order.**

---

## 🔹 Example

```
nums = [3, 1, 5, 8]
```

Add boundary balloons (each with value 1):

```
[1, 3, 1, 5, 8, 1]
```

Possible bursting orders lead to different profits.
We need to choose the **best order** to maximize coins.

---

## 🧠 Core Idea

It’s **hard** to decide which balloon to burst first.
Instead, think **backwards** — what if we decide which balloon to burst **last** in a range?

If we burst balloon `i` last in range `(left, right)`:

* We already burst all balloons between `left` and `i`, and between `i` and `right`.
* The coins from bursting `i` last are:

  ```
  nums[left] * nums[i] * nums[right]
  ```

Thus, the problem becomes a **divide-and-conquer** problem:

* Choose a balloon `i` as the last burst between `left` and `right`.
* Recursively solve the subproblems `(left, i)` and `(i, right)`.

---

## 🪜 Step 1: Brute Force Recursive Approach

### **Intuition**

Try all possible “last burst” choices for every subarray range.
For each range `(left, right)`, try bursting each balloon `i` in between and take the best result.

### **Steps**

1. Add two imaginary balloons (value = 1) at both ends.
2. Define a recursive function `burst(left, right)`:

   * Base case: If there’s no balloon between `left` and `right`, return 0.
   * Otherwise, try every balloon `i` between `(left, right)`:

     * Burst `i` last → coins = `nums[left]*nums[i]*nums[right]`.
     * Plus coins from left and right subproblems:

       ```
       coins = nums[left]*nums[i]*nums[right] + burst(left,i) + burst(i,right)
       ```
   * Take the maximum among all choices.
3. Return `burst(0, n+1)` (whole range).

### **Complexity**

* **Time:** `O(N!)` (explores every possible bursting order)
* **Space:** `O(N)` (recursion depth)

---

## 🪜 Step 2: Top-Down DP with Memoization

### **Intuition**

In the brute-force approach, we solve the same subproblems multiple times.
We can store (memoize) the results for each range `(left, right)`.

### **Steps**

1. Add 1 at both ends of `nums`.
2. Create a 2D memo table `memo[left][right]` initialized with `-1`.
3. Modify `burst(left, right)`:

   * If result already computed → return from memo.
   * Otherwise, compute recursively as before.
   * Store the result before returning.

This ensures each `(left, right)` range is solved **only once**.

### **Complexity**

* **Time:** `O(N³)`

  * There are `O(N²)` possible ranges `(left, right)`.
  * Each range tries `O(N)` possible `i` in between.
* **Space:** `O(N²)` (for memo table) + recursion stack.

---

## 🪜 Step 3: Bottom-Up DP Approach

### **Intuition**

Convert the recursive relation into an **iterative DP**.

Instead of recursively solving `(left, right)`,
we’ll **build up** the answer for smaller ranges first and then larger ones.

### **Steps**

1. Add 1 at both ends of `nums`.
2. Create a 2D `dp` table, where `dp[left][right]` = max coins for bursting all balloons between `left` and `right`.
3. Iterate over range **lengths** (from 2 to n+1):

   * For each `left`, compute `right = left + length`.
   * Try every `i` in `(left, right)` as the last balloon to burst:

     ```
     dp[left][right] = max(dp[left][right],
         nums[left]*nums[i]*nums[right] + dp[left][i] + dp[i][right])
     ```
4. The final answer = `dp[0][n+1]`.

### **Why It Works**

* Smaller subranges are computed first.
* When we process a larger range, all its subranges are already available.

### **Complexity**

* **Time:** `O(N³)` (three nested loops: left, right, i)
* **Space:** `O(N²)` (DP table)

---

## 📘 Final Summary

| Approach         | Type        | Idea                                        | Time Complexity | Space Complexity |
| ---------------- | ----------- | ------------------------------------------- | --------------- | ---------------- |
| **Brute Force**  | Recursive   | Try all bursting orders                     | `O(N!)`         | `O(N)`           |
| **Top-Down DP**  | Memoization | Store results for each range `(l, r)`       | `O(N³)`         | `O(N²)`          |
| **Bottom-Up DP** | Iterative   | Build up results by increasing range length | `O(N³)`         | `O(N²)`          |

---

## 💡 Key Takeaways

* Think of **bursting last**, not first → turns it into a clean subproblem structure.
* Use **DP on intervals** → common in problems where you divide a range into subranges.
* Bottom-Up is more space-efficient and avoids recursion overhead.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
1000. Minimum Cost to Merge Stones - https://leetcode.com/problems/minimum-cost-to-merge-stones/description/
2. Matrix Chain Multiplication - https://www.geeksforgeeks.org/problems/matrix-chain-multiplication0303/1
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Optimal resource destruction (e.g., destroying mines).