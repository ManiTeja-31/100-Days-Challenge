# Problem Statement

You are given an array of integers `nums`, and there is a sliding window of size `k` which moves from the very left of the array to the very right. You can only see the `k` numbers in the window. Each time the sliding window moves right by one position.

**Return the max sliding window.**

> **Level:** Hard

---

## Pattern

**Sliding Window + Deque**

---

## Approaches

### Brute Force Approach

**Step-wise Explanation:**
1. For each possible window of size `k` in the array, iterate through all elements in that window.
2. Find the maximum element in the current window.
3. Store this maximum in the result array.
4. Move the window one position to the right and repeat until the end of the array.

**Time Complexity:**  
- O(n * k), where n is the number of elements in `nums`.  
  For each window (n - k + 1 windows), we scan k elements.

**Space Complexity:**  
- O(n - k + 1) for the result array.

**Interview Note:**  
This approach is simple and easy to implement but inefficient for large arrays or windows, as it repeatedly scans overlapping elements.

---

### Optimized Approach using Deque

**Step-wise Explanation:**
1. Use a double-ended queue (deque) to store indices of useful elements for each window.
2. For each element:
    - Remove indices from the back of the deque if their corresponding values are less than the current element (they can't be the max for future windows).
    - Remove indices from the front if they are out of the current window's range.
    - Add the current index to the back of the deque.
3. The front of the deque always contains the index of the maximum element for the current window.
4. After the first k-1 elements, add the max for each window to the result.

**Time Complexity:**  
- O(n), because each element is pushed and popped from the deque at most once.

**Space Complexity:**  
- O(k) for the deque, O(n - k + 1) for the result.

**Interview Note:**  
This approach is optimal for this problem and leverages the deque to efficiently keep track of potential maximums, avoiding redundant comparisons.

---

### Optimized Approach using Priority Queue (Max Heap)

**Step-wise Explanation:**
1. Use a max heap (priority queue) to keep track of the maximum element in the current window.
2. For each element:
    - Push the element and its index into the heap.
    - If the window has reached size k, pop elements from the heap if their indices are outside the current window.
    - The top of the heap is the maximum for the current window.
3. Add the maximum to the result for each window.

**Time Complexity:**  
- O(n log k), because each insertion and deletion in the heap takes O(log k) time.

**Space Complexity:**  
- O(k) for the heap, O(n - k + 1) for the result.

**Interview Note:**  
This approach is easier to code than the deque method and works well, but is slightly less efficient due to the log k factor from heap operations. It’s useful when you need to generalize to other problems requiring order statistics in a window.

---

## Summary Table

| Approach     | Time Complexity | Space Complexity | Key Data Structure |
|--------------|----------------|------------------|-------------------|
| Brute Force  | O(n * k)       | O(n)             | None              |
| Deque        | O(n)           | O(k)             | Deque             |
| Max Heap     | O(n log k)     | O(k)             | Priority Queue    |

---

## Other Problems Using this Approach

- [76. Minimum Window Substring](https://leetcode.com/problems/minimum-window-substring/description/)
- [2398. Maximum Number of Robots Within Budget](https://leetcode.com/problems/maximum-number-of-robots-within-budget/description/)

---

## CodeChef Equivalent

NA

---

## Real-World Use

- Max stock price in last k days
- Sensor max reading in a moving window