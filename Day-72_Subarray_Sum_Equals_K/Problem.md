> [Subarray Sum Equals K] - https://leetcode.com/problems/subarray-sum-equals-k/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an array of integers nums and an integer k, return the total number of subarrays whose sum equals to k.
A subarray is a contiguous non-empty sequence of elements within an array.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Prefix Sum + Hashmap
--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

In the brute-force solution:

* We're checking **all possible subarrays**.
* For each starting index `i`, we loop through every possible ending index `j ≥ i`, compute the sum of the subarray `nums[i..j]` in-place, and compare it with `k`.

This approach is very intuitive and works well for small input sizes.

🧠 Time & Space Complexity:
* Time Complexity: O(n²) - Outer loop: `O(n)` + Inner loop: `O(n)` in the worst case
* Space Complexity: O(1)
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

Let’s optimize the brute-force by avoiding repeated summation using **prefix sums** and a **hash map**.

The key idea:

> If the sum of elements from index `0` to `i` is `prefix[i]`, and there exists a previous sum `prefix[j]` such that `prefix[i] - prefix[j] == k`, then the subarray from `j+1` to `i` sums to `k`.
So:
* Keep track of all prefix sums we've seen so far and how many times each has occurred using a `unordered_map`.
* For each new prefix sum, we:
  * Check if `(prefix[i] - k)` exists in the map → it means there's a previous subarray that can be excluded to give a subarray that sums to `k`.

This avoids nested loops entirely.

### ✏️ Slight Improvement Tip:

We don’t actually need to build a `prefix[]` array. You can calculate and update prefix sum on the fly.
1. Initialize `sum = 0`, `count = 0`
2. For each element in the array:
   * Add to `sum`
   * If `sum == k`, increment count
   * If `sum - k` exists in the map, it means there’s a subarray ending here that sums to `k`
   * Update map with current `sum`

🧠 Time & Space Complexity:
* Time Complexity: O(n)
* Space Complexity: O(n) HashMap storing prefix sums in worst case (all unique sums)
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach

523. Continuous Subarray Sum - https://leetcode.com/problems/continuous-subarray-sum/description/
560. Subarray Sum Equals K - https://leetcode.com/problems/subarray-sum-equals-k/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
Subarray Sum equals k - https://www.codechef.com/learn/course/hashing/HASH04/problems/HASHP03
Maximum Subarray Sum - https://www.codechef.com/learn/course/arrays/ARRAYS02/problems/DSAAGP12
Maximum Sum of K Elements - https://www.codechef.com/practice/course/two-pointers/SLIDINGWINDO/problems/SLDW0102
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Detecting spikes of cumulative traffic or log counts hitting threshold.










