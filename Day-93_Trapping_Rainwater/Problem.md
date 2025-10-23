> [Trapping Rainwater](https://leetcode.com/problems/trapping-rain-water/description/)  
> **Level:** Hard

---

# Problem Statement

Given *n* non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

---

# Pattern

> **Two Pointers** &nbsp;|&nbsp; **Stack**

---

# Pseudocode

---

# Brute Force Approach

**Step-by-step:**
1. For each bar, find the maximum height to its left and right.
2. Calculate trapped water as `min(left_max, right_max) - current height`.
3. If positive, add to total.
4. Repeat for all bars.

**Time Complexity:** `O(n²)` — For each bar, scan all bars to the left and right.  
**Space Complexity:** `O(1)` — Only variables used.

---

# Optimized Approach

**Step-by-step:**
1. Precompute max height to the left of each bar (store in array).
2. Precompute max height to the right of each bar (store in array).
3. For each bar, trapped water = `min(left_max, right_max) - current height`.
4. Sum for all bars.

**Time Complexity:** `O(n)` — Each pass is linear.  
**Space Complexity:** `O(n)` — Two arrays for left/right maximums.

---

# Optimal Approach (Space Optimized)

1. Use **two pointers**: `left` (start) and `right` (end).
2. Maintain `maxLeft` and `maxRight` values while traversing inward.
3. If `height[left] < height[right]`:
    - If `maxLeft > height[left]`, trap water = `maxLeft - height[left]`.
    - Else, update `maxLeft`.
    - Move `left++`.
4. Else:
    - If `maxRight > height[right]`, trap water = `maxRight - height[right]`.
    - Else, update `maxRight`.
    - Move `right--`.
5. Continue until pointers meet.

**Time Complexity:** `O(n)` (single pass)  
**Space Complexity:** `O(1)` (only variables, no arrays)

---

# Stack Approach

1. Use a **monotonic stack** to keep track of bars.
2. Traverse the array:
    - While the current bar is **higher** than the bar at the stack top:
        - Pop the top (this is the bottom of a trapped water container).
        - If stack becomes empty → break.
        - Compute the distance between current bar and new top.
        - Compute bounded height = `min(height[current], height[top]) - height[popped]`.
        - Multiply distance × bounded height = water trapped.
    - Push current index to stack.
3. Return total water trapped.

**Time Complexity:**  
Each index pushed & popped at most once → `O(n)`

**Space Complexity:**  
Stack stores indices → `O(n)`

---

## 📌 Key Takeaways

- **Brute Force (`O(n²)`)** — shows basic understanding.
- **DP with Precomputation (`O(n)`, `O(n)`)** — common optimal solution.
- **Two Pointers (`O(n)`, `O(1)`)** — best in interviews, space optimized.
- **Stack (`O(n)`, `O(n)`)** — alternative elegant solution, good for brownie points.

---

# Other Problems Using this Approach

- [407. Trapping Rain Water II](https://leetcode.com/problems/trapping-rain-water-ii/description/)
- [2874. Maximum Value of an Ordered Triplet II](https://leetcode.com/problems/maximum-value-of-an-ordered-triplet-ii/description/)

---

# CodeChef Equivalent

NA

---

# Real-World Use

Water storage design simulations, elevation modeling

