> [Find The Duplicate Number](https://leetcode.com/problems/find-the-duplicate-number/description/)
> **Level:** Medium

---

# Problem Statement

Given an array of integers `nums` containing $n + 1$ integers where each integer is in the range $[1, n]$ inclusive.

There is only **one repeated number** in `nums`, return this repeated number.

**You must solve the problem without modifying the array `nums` and using only constant extra space.**

---

## Pattern
> Floyd’s Cycle Detection / Binary Search

---

## Approaches

### 1. Brute Force Approach
**Intuition:**
Check every possible pair in the array to see if any two numbers are the same.

**Step-by-step:**
- Loop through each element with index `i`.
- For each `i`, loop through all elements after it with index `j`.
- If `nums[i] == nums[j]`, return `nums[i]` as the duplicate.

**Time Complexity:** $O(N^2)$

**Space Complexity:** $O(1)$

---

### 2. Sorting Approach
**Intuition:**
If the array is sorted, duplicates will be adjacent.

**Step-by-step:**
- Sort the array (note: this violates the "read-only" constraint).
- Loop through the array and check if any two consecutive elements are equal.
- Return the duplicate if found.

**Time Complexity:** $O(N \log N)$

**Space Complexity:** $O(1)$ (if in-place sort is allowed)

---

### 3. Counting/Hashing/Set Approach
**Intuition:**
Use extra space to keep track of numbers seen so far.

**Step-by-step:**
- Create a frequency array (or set) to mark numbers as seen.
- Loop through the array:
	- If the number is already marked, return it as duplicate.
	- Otherwise, mark it as seen.

**Time Complexity:** $O(N)$

**Space Complexity:** $O(N)$

---

### 4. Floyd's Tortoise and Hare (Cycle Detection) — Optimal Approach
**Intuition:**
Treat the array as a linked list where each value points to the next index. The duplicate creates a cycle. Use cycle detection to find the duplicate.

**Step-by-step:**
- Initialize two pointers, `slow` and `fast`.
- Move `slow` by one step and `fast` by two steps until they meet (cycle detected).
- Reset `fast` to the start and move both pointers one step at a time until they meet again. The meeting point is the duplicate.

**Time Complexity:** $O(N)$

**Space Complexity:** $O(1)$

---

### 5. Binary Search on Value Range — Optimal Approach
**Intuition:**
Count how many numbers are less than or equal to `mid`. If the count is more than `mid`, the duplicate is in the lower half; otherwise, it's in the upper half.

**Step-by-step:**
- Set `left = 1`, `right = n - 1`.
- While `left < right`:
	- Compute `mid = (left + right) / 2`.
	- Count how many numbers in the array are less than or equal to `mid`.
	- If `count > mid`, set `right = mid`; else, set `left = mid + 1`.
- Return `left` as the duplicate.

**Time Complexity:** $O(N \log N)$

**Space Complexity:** $O(1)$

---

# Other Problems Using this Approach
41. First Missing Positive - https://leetcode.com/problems/first-missing-positive/description/
142. Linked List Cycle II - https://leetcode.com/problems/linked-list-cycle-ii/description/
---

# CodeChef Equivalent
NA

---

# Real-World Use
Finding duplicate IDs in data entries