> [Minimum Size Subarray Sum] - https://leetcode.com/problems/minimum-size-subarray-sum/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Sliding Window | PrefixSum + Binary Search
--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

### **Idea**
* Try **all possible subarrays**.
* For each starting index, expand to the right until the sum ≥ target, track length.
---

### **Step-by-Step**
1. Loop `i` from `0` to `n-1` as the starting index.
2. Initialize `sum = 0`.
3. Loop `j` from `i` to `n-1`:
   * Add `nums[j]` to `sum`.
   * If `sum >= target`, update `minLen` with `j - i + 1`.
4. Return `minLen` (or `0` if no subarray found).
---

### **Complexity**
* **Time:** O(n²) — Checking all subarrays.
* **Space:** O(1) — Only variables used.

--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

## **Approach 1 – Prefix Sum + Binary Search (O(n log n))**

### **Idea**
* Build a **prefix sum** array.
* For each starting index, use **binary search** to find the minimal ending index where sum ≥ target.
---

### **Step-by-Step**
1. Create `prefixSum[]` of length `n+1`:
   * `prefixSum[i]` = sum of first `i` elements.
2. For each `i` from 0 to n-1:
   * Required sum = `prefixSum[i] + target`.
   * Use `lower_bound` to find the smallest index `j` where `prefixSum[j] ≥ required sum`.
   * Update `minLen` with `j - i`.
3. Return `minLen` (or `0` if no subarray found).

---

### **Complexity**
* **Time:** O(n log n) — n iterations × binary search.
* **Space:** O(n) — Prefix sum array.
---

## **Approach 2 – Sliding Window (O(n))**

### **Idea**
* Use a **two-pointer** (left-right) window to maintain a running sum.
* Expand right pointer until sum ≥ target, then shrink left to minimize length.

---

### **Step-by-Step**
1. Initialize `sum = 0`, `left = 0`, `minLen = ∞`.
2. For `right` from 0 to n-1:
   * Add `nums[right]` to `sum`.
   * While `sum ≥ target`:
     * Update `minLen = min(minLen, right - left + 1)`.
     * Subtract `nums[left]` and increment `left`.
3. Return `minLen` (or `0` if not updated).

---
### **Complexity**
* **Time:** O(n) — Each element visited at most twice.
* **Space:** O(1) — Constant extra space.

---
## **Why Multiple Approaches?**
* **Brute force** — simple but impractical for large inputs.
* **Prefix sum + binary search** — faster than brute force, but extra space used.
* **Sliding window** — optimal time and space for this problem.
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
76. Minimum Window Substring - https://leetcode.com/problems/minimum-window-substring/description/
Maximum Size Subarray Sum Equals k - https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Find the shortest period of high activity (e.g., quickest burst to reach quota)