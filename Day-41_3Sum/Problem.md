> [3Sum] - https://leetcode.com/problems/3sum/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Two Pointer + Sorting
--------------------------------------------------------------------------------------------------------------------------------------
# PsuedoCode

--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

### ✅ Steps:

1. Iterate through all possible triplets `(i, j, k)` using **3 nested loops**.
2. For each triplet, check if their sum equals `0`.
3. Store the triplet in a set (or use sorting) to avoid duplicates.
4. Convert the set back to a list of triplets as the final result.

### ⏱️ Time Complexity:

* **O(n³)** → Three nested loops.
* Sorting triplet before inserting into set → O(3 log 3), negligible compared to cubic time.

### 💾 Space Complexity:

* **O(k)**, where `k` is the number of unique triplets stored (extra set for duplicates).
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

### ✅ Steps:

1. **Sort** the array.
2. Iterate through each element `nums[i]` as the **first element of triplet**.

   * If `nums[i] > 0`, break early (since sum can’t be zero anymore).
   * Skip duplicates for `nums[i]`.
3. Use **two pointers** (`left` = i+1, `right` = n-1):

   * Compute `sum = nums[i] + nums[left] + nums[right]`.
   * If `sum == 0` → add triplet, move both pointers while skipping duplicates.
   * If `sum < 0` → increase `left` to make sum larger.
   * If `sum > 0` → decrease `right` to make sum smaller.
4. Continue until all triplets are checked.

### ⏱️ Time Complexity:

* Sorting → **O(n log n)**
* Outer loop (`i`) → **O(n)**
* Two-pointer search → **O(n)** per `i`
* **Overall: O(n²)**

### 💾 Space Complexity:

* **O(1)** extra (ignoring result storage).
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
454. 4Sum II - https://leetcode.com/problems/4sum-ii/description/
1442. Count Triplets That Can Form Two Arrays of Equal XOR - https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Finding 3 stock price changes that sum to zero (neutral net impact)

