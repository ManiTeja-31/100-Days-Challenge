> [3Sum Closest] - https://leetcode.com/problems/3sum-closest/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.
Return the sum of the three integers.
You may assume that each input would have exactly one solution.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Two Pointer + Sorting
--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

The given approach is a **brute-force** solution. It checks every possible triplet in the array and compares the sum of that triplet to the target, keeping track of the sum that is closest to the target.

We initialize a variable `closest` with the sum of the first three elements. Then we iterate through all unique combinations of three numbers using three nested loops and compute their sum. For each sum, we check how far it is from the target using `abs(target - sum)`. If it's **closer** than the previously stored `closest`, we update `closest`.
Finally, after examining all triplets, we return the closest sum.

🧠 Time & Space Complexity:🧠 Time & Space Complexity:

* Time Complexity: O(n³) We use three nested loops
* Space Complexity: O(1) — We're only using a few variables (`closest`, `sum`, etc.) 
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

We are given an array and a target number, and we want to find the triplet (three numbers) whose sum is closest to the target.
To do this efficiently, we use the two-pointer technique after sorting the array:
1. Sort the array first to bring all elements in order — this is crucial for the two-pointer logic to work.
2. We fix one element at a time (let's call it `nums[i]`), and for the remaining part of the array (to the right of `i`), we use two pointers:
   * One starting just after `i` (`left`)
   * One starting at the end of the array (`right`)
3. We compute the **sum of the fixed element and the two pointers**.
   * If this sum is closer to the target than any previous sum, we **update our answer**.
   * If the sum is **less than** the target, we move the `left` pointer to the right to increase the sum.
   * If the sum is **greater than** the target, we move the `right` pointer to the left to decrease the sum.
4. This continues until the `left` and `right` pointers cross. We do this for every `i` in the array.

🧠 Time & Space Complexity:

* Time Complexity: O(n²)
  * Sorting the array takes `O(n log n)`
  * The main loop runs `n` times, and for each iteration, the two-pointer part takes up to `O(n)` time.
  * So overall: `O(n log n + n²)` → Dominated by `O(n²)`
* Space Complexity: O(1) We use only a few extra variables to track the closest sum.
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach

658. Find K Closest Elements - https://leetcode.com/problems/find-k-closest-elements/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent

--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Closest match of 3 deals to a target value (e.g., budget approximation)