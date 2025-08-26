> [Next Greater Element I] - https://leetcode.com/problems/next-greater-element-i/description/
> Level - Easy
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

The next greater element of some element x in an array is the first greater element that is to the right of x in the same array.

You are given two distinct 0-indexed integer arrays nums1 and nums2, where nums1 is a subset of nums2.

For each 0 <= i < nums1.length, find the index j such that nums1[i] == nums2[j] and determine the next greater element of nums2[j] in nums2. If there is no next greater element, then the answer for this query is -1.

Return an array ans of length nums1.length such that ans[i] is the next greater element as described above
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Monotonic Stack
--------------------------------------------------------------------------------------------------------------------------------------
# PsuedoCode

--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

### Idea:

* For each element in `nums1`, locate its position in `nums2`.
* From that position, scan towards the right in `nums2` until we find a greater element.
* If found, store it. If not, return `-1`.

### Steps:

1. Loop over each element in `nums1`.
2. Inside, loop over `nums2` to find the matching element.
3. Once found, do another loop to search for the **next greater** element to the right.
4. Push result into the answer list.

### Complexity:

* Outer loop (`nums1`): `O(m)`
* Search in `nums2`: `O(n)`
* Scan right: `O(n)`
  👉 **Time Complexity:** `O(m * n)` (could go up to quadratic).
  👉 **Space Complexity:** `O(1)` extra (ignoring output).
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

### Idea:

Instead of repeatedly scanning `nums2`, **precompute the next greater element for every number in `nums2`** using a stack.
Then directly map results for `nums1` in `O(1)` lookups.

### Steps:

1. Traverse `nums2` **from right to left**.

   * Maintain a stack that is **monotonically decreasing** (top always has the next greater candidate).
   * For each element `nums2[i]`:

     * Pop from stack until you find an element greater than `nums2[i]`.
     * If stack is empty → no next greater, store `-1`.
     * Otherwise, stack top is the next greater.
   * Store result in a `Hash` (map: `nums2[i] → nextGreater`).
   * Push current element into the stack.
2. Once preprocessing is done, simply iterate `nums1`.

   * Lookup results directly in the `Hash`.

### Complexity:

* Preprocessing `nums2`: `O(n)` (each element pushed and popped once).
* Lookup for `nums1`: `O(m)`.
  👉 **Time Complexity:** `O(m + n)`.
  👉 **Space Complexity:** `O(n)` for stack + hash map.
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
503. Next Greater Element II - https://leetcode.com/problems/next-greater-element-ii/description/
556. Next Greater Element III - https://leetcode.com/problems/next-greater-element-iii/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Stock span problem, future weather prediction, CPU pipeline hazard checks