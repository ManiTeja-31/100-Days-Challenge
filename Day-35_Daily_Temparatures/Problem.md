> [Daily Temparatures] - https://leetcode.com/problems/daily-temperatures/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an array of integers temperatures represents the daily temperatures, return an array answer such that answer[i] is the number of days you have to wait after the ith day to get a warmer temperature. If there is no future day for which this is possible, keep answer[i] == 0 instead.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Monotonic Stack
--------------------------------------------------------------------------------------------------------------------------------------
# PsuedoCode

--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

1. For each day `i`, scan forward (from `i+1` to `n-1`) until you find a day `j` such that `temperatures[j] > temperatures[i]`.
2. If such a `j` exists, answer for day `i` = `j - i`.
3. Otherwise, answer is `0` (no warmer day in the future).

**Time Complexity:** `O(n^2)` (since each element may compare with all future elements).
**Space Complexity:** `O(1)` (excluding output array).
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

1. Use a **stack** to keep track of indices of days, ensuring the stack is **monotonic decreasing** in terms of temperature.

   * Why? Because if today’s temperature is higher than the top of the stack, then we’ve found the "next warmer day" for that earlier index.
2. Traverse the array **backwards** (from last day to first):

   * While stack is not empty **and** top element’s temperature ≤ current day’s temperature → pop it (since it’s useless).
   * If stack is not empty → the answer for the current index is `(stack.top_index - i)`.
   * Push `(temperature, index)` for the current day into the stack.
3. This ensures each element is **pushed and popped at most once**.

**Time Complexity:** `O(n)` (linear, since each index enters and leaves the stack once).
**Space Complexity:** `O(n)` (stack stores indices in the worst case).
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
901. Online Stock Span - https://leetcode.com/problems/online-stock-span/description/
42. Trapping Rain Water - https://leetcode.com/problems/trapping-rain-water/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Weather monitoring system to calculate warm-up days