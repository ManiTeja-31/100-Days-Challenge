> [Longest Subarray Of 1's After Deleing One Element] - https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/description/ 
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given a binary array nums, you should delete one element from it.

Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Sliding Window + Count Zeros
--------------------------------------------------------------------------------------------------------------------------------------
> **Constraints:**
>
> * Delete **exactly** one element.
> * A valid subarray may be empty (but must result from removing one element).

---

## 🛠️ Approach 1: Brute Force

### 🔍 Idea

* Try deleting **each element** one by one.
* For each new array, count the **maximum length of continuous 1's**.

### ✅ Steps

1. For every index `i`, create a new array without the element `nums[i]`.
2. In the new array, count the maximum stretch of consecutive `1`s.
3. Keep track of the overall maximum.

### ⏱ Time Complexity: `O(n^2)`

### 🗂 Space Complexity: `O(n)` (for each temp array)

---

## ⚡ Approach 2: Optimal — Sliding Window

### 🔍 Idea

* Maintain a window that can contain **at most one `0`** (which we pretend to remove).
* Use two pointers (`left`, `right`) to define the window.
* When you see a second zero, **move the left pointer past the first zero**.

### ✅ Steps

1. Slide `right` from `0` to `n-1`.
2. When a `0` is found:

   * If it's the first zero, mark its index.
   * If it's the second zero, move `left` to one past the first zero.
3. Update the max window size (`right - left`).

### 🔁 Code Logic

```cpp
if(nums[right] == 0) {
    if(ind != -1) {
        left = ind + 1; // Move past previous 0
    }
    ind = right; // Store current 0 index
}
```

### ⏱ Time Complexity: `O(n)`

### 🗂 Space Complexity: `O(1)`

---

## 📌 Edge Case

If the array contains **all 1's**, then after deleting **one** element, the answer is `n - 1`.

---

## 📝 Summary

| Approach       | Time Complexity | Space Complexity | Notes                    |
| -------------- | --------------- | ---------------- | ------------------------ |
| Brute Force    | O(n²)           | O(n)             | Simple but slow          |
| Sliding Window | O(n)            | O(1)             | Optimal for this problem |

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
1004. Max Consecutive Ones III - https://leetcode.com/problems/max-consecutive-ones-iii/description/
424. Longest Repeating Character Replacement - https://leetcode.com/problems/longest-repeating-character-replacement/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Network packet stream monitoring with one allowed drop.