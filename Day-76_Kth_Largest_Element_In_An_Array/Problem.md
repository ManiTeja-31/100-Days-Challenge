> [Kth Largest Element in an Array] - https://leetcode.com/problems/kth-largest-element-in-an-array/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Quickselect / Heap
--------------------------------------------------------------------------------------------------------------------------------------
## 1. 📚 Sorting Approach

### **Explanation**

* Sort the array in **descending order**.
* Return the element at index `k - 1`.

### **Time Complexity**

* `O(n log n)` — due to sorting.

### **Space Complexity**

* `O(1)` — in-place sorting (if allowed), otherwise `O(n)` for auxiliary space.

### **Pros**

* Simple and easy to implement.
* Useful for small inputs.

### **Cons**

* Not optimal for large datasets.
* Doesn’t meet performance expectations for large-scale input (`O(n log n)`).

---

## 2. 🛠️ Max Heap (Priority Queue)

### **Explanation**

* Insert all elements into a **max heap**.
* Pop the heap `k - 1` times.
* The top of the heap is the k-th largest element.

### **Time Complexity**

* `O(n + k log n)`

  * `O(n)` to build the heap
  * `O(log n)` per pop, done `k-1` times

### **Space Complexity**

* `O(n)` — to store the heap.

### **Pros**

* Straightforward to implement using STL.

### **Cons**

* Not optimal space-wise.
* Still slower than optimal methods for large `n`.

---

## 3. ⚖️ Min Heap of Size k (Optimal Heap Approach)

### **Explanation**

* Maintain a **min heap of size `k`**.
* For each element in the array:

  * Add it to the heap.
  * If the heap size exceeds `k`, remove the smallest element.
* The top of the heap is the k-th largest element.

### **Time Complexity**

* `O(n log k)` — inserting into heap of size `k`.

### **Space Complexity**

* `O(k)` — for the min heap.

### **Pros**

* Very efficient for large arrays with small `k`.
* One of the **most optimal heap-based approaches**.

### **Cons**

* Slightly more code overhead than full heap.

---

## 4. ⚡ Quick Select (Optimal)

### **Explanation**

* Uses a variant of **QuickSort partitioning**:

  * Choose a pivot and partition the array into:

    * Elements ≥ pivot (left side)
    * Elements < pivot (right side)
* Recursively search in the partition that contains the k-th largest element.
* Stops when the pivot is the k-th element.

> This is similar to QuickSort but only processes one side at each step.

### **Time Complexity**

* **Average:** `O(n)`
* **Worst-case:** `O(n²)` (rare, with poor pivot choice)

### **Space Complexity**

* `O(1)` (in-place)
* `O(n)` worst case for recursion stack if not tail-recursive

### **Pros**

* **Fastest approach** on average.
* Doesn’t require extra memory.
* Commonly used in interview problems.

### **Cons**

* Slightly complex to implement correctly.
* Worst-case performance not ideal without randomization.

---

# 🔚 Summary & Comparison

| Approach          | Time Complexity       | Space Complexity | Pros                                 | Cons                                   |
| ----------------- | --------------------- | ---------------- | ------------------------------------ | -------------------------------------- |
| Sorting           | O(n log n)            | O(1)             | Simple and intuitive                 | Not optimal for large arrays           |
| Max Heap          | O(n + k log n)        | O(n)             | Easy to use with STL                 | Higher space usage                     |
| Min Heap (Size k) | O(n log k)            | O(k)             | Efficient and optimal for many cases | Slightly more complex implementation   |
| Quick Select      | O(n) avg, O(n²) worst | O(1)             | Most optimal on average              | Worst-case performance, harder to code |

---

## ✅ Recommendation

* Use **Min Heap of size k** if:

  * You want optimal performance and **built-in heap** utilities.
  * You’re dealing with large datasets and small `k`.

* Use **Quick Select** if:

  * You want **in-place**, fast selection.
  * You’re comfortable with partitioning logic (like in QuickSort).

* Avoid full **sorting or max heap** for very large inputs or in performance-critical code.
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
658. Find K Closest Elements - https://leetcode.com/problems/find-k-closest-elements/description/
324. Wiggle Sort II - https://leetcode.com/problems/wiggle-sort-ii/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Analytics dashboards, leaderboard ranking