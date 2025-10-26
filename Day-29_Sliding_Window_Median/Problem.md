> [Sliding window Median] - https://leetcode.com/problems/sliding-window-median/description/
> Level - Hard
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

The median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle values.

For examples, if arr = [2,3,4], the median is 3.
For examples, if arr = [1,2,3,4], the median is (2 + 3) / 2 = 2.5.
You are given an integer array nums and an integer k. There is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

Return the median array for each window in the original array. Answers within 10-5 of the actual value will be accepted.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Sliding Window + Heaps
--------------------------------------------------------------------------------------------------------------------------------------
## 🧠 Intuition

* We’re repeatedly finding the **median** of a moving window.
* Naively sorting each window is expensive (`O(k log k)` per window).
* We need a **data structure** that:

  * Supports **insertion**
  * Supports **deletion**
  * Supports **median lookup**

Efficient structures for this:

* **Two Heaps (MaxHeap + MinHeap)**
* **Multiset** (balanced BST)
* (Advanced) **Lazy deletion heaps** for true O(log k) per operation.

---

## 🪜 Step 1: Brute Force Approach

### **Idea**

For every window of size `k`:

1. Extract the subarray `[i, i+k)`
2. Sort it
3. Find the median

---

### **Steps**

1. Slide the window one element at a time.
2. For each window:

   * Copy elements into a temporary vector.
   * Sort the vector.
   * Compute median.

---

### **Example**

```
nums = [1,3,-1,-3,5], k = 3
windows: [1,3,-1], [3,-1,-3], [-1,-3,5]
```

For `[1,3,-1]` → sorted = [-1,1,3] → median = 1

---

### **Complexity**

* **Time:** `O(n * k log k)`
  (n−k+1 windows × sorting cost)
* **Space:** `O(k)`

✅ Simple to code
❌ Too slow for large input sizes.

---

## 🪜 Step 2: Two Heaps using Multisets

### **Idea**

We maintain two multisets:

* **maxHeap (left)** → stores the smaller half of numbers
* **minHeap (right)** → stores the larger half of numbers

The heaps are balanced so that:

* Either both heaps have equal size (even window)
* Or `maxHeap` has one more element (odd window)

Median:

* If sizes equal → `(maxHeap.max + minHeap.min)/2`
* Else → `maxHeap.max`

---

### **Key Operations**

1. **Insert new element**

   * Compare it with `maxHeap.rbegin()` (largest in left half).
   * Insert into correct heap.
   * Balance both heaps.
2. **Remove outgoing element**

   * Remove from the correct heap.
   * Balance heaps again.
3. **Find median**

   * Use top values of heaps.

---

### **Balancing Rule**

* `|maxHeap.size() - minHeap.size()| <= 1`
* If imbalance occurs, move the top element from one heap to the other.

---

### **Example**

```
nums = [1,3,-1,-3,5,3,6,7], k = 3
Window = [1,3,-1]
maxHeap = [-1, 1]
minHeap = [3]
Median = 1.0
```

Slide the window:

* Add new number
* Remove old number
* Rebalance heaps
* Record median

---

### **Complexity**

* **Time:** `O(n log k)`
  (Each insertion/removal/balance takes log k)
* **Space:** `O(k)`

✅ Efficient and elegant
✅ `multiset` allows direct erasure of specific elements
❌ Slightly verbose to implement

---

## 🪜 Step 3: Two Heaps with Lazy Deletion (Optimized Heaps)

### **Idea**

Instead of a `multiset`, we can use **two priority queues** (min and max heaps).
But priority queues **don’t support deletion** of arbitrary elements.
We solve that using **lazy deletion**.

---

### **Lazy Deletion Technique**

When an element exits the window:

* Don’t immediately remove it from the heap.
* Instead, record it in a `delayed` map (`unordered_map<int,int>`).
* When a heap top is marked as deleted, **pop it lazily** when accessed.

---

### **Process**

1. **Insert new element** into the correct heap (≤ maxHeap.top() or > maxHeap.top()).
2. **Mark outgoing element** in `delayed` map.
3. **Balance heaps:**

   * Ensure size difference ≤ 1.
   * Move elements between heaps if necessary.
4. **Prune:**

   * Remove top elements from heap if they’re “delayed”.
5. **Compute median** from heap tops.

---

### **Example**

```
nums = [1,3,-1,-3,5], k = 3

Insert 1, 3, -1 → maxHeap = [1,-1], minHeap = [3]
Median = 1

Slide → remove 1
Mark delayed[1] = 1
Balance and prune top if delayed
```

---

### **Complexity**

* **Time:** `O(n log k)`
  (Each insertion/removal/prune = log k)
* **Space:** `O(k)` (Heaps + delayed map)

✅ Best balance of speed and memory
✅ True O(log k) insert/delete
✅ Common in competitive programming
⚠️ Implementation is intricate — must handle delayed elements carefully.

---

## 🧾 Summary Table

| Approach             | Technique                       | Insertion/Deletion | Time           | Space  | Notes                 |
| -------------------- | ------------------------------- | ------------------ | -------------- | ------ | --------------------- |
| **Brute Force**      | Sort every window               | `O(k log k)`       | `O(n*k log k)` | `O(k)` | Simple, slow          |
| **Two Multisets**    | Balanced BSTs                   | `O(log k)`         | `O(n log k)`   | `O(k)` | Clean C++ solution    |
| **Two Heaps (Lazy)** | Priority Queues + Lazy deletion | `O(log k)`         | `O(n log k)`   | `O(k)` | Optimal and efficient |

---

## 💡 Key Takeaways

* The **median** can be maintained dynamically using **two heaps**.
* Always **rebalance** after insertion/removal.
* **Lazy deletion** is a clever optimization to handle removals efficiently.
* Multiset version is easier to code in interviews,
  while the **lazy heap** version is best for large input constraints.

---

✅ **Recommended Strategy for Interviews**

1. Start with the **Brute Force** to explain intuition.
2. Then describe **Two Heaps (Balanced Multisets)** approach.
3. Finally, mention **Lazy Deletion** as an optimization.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
295. Find Median from Data Stream - https://leetcode.com/problems/find-median-from-data-stream/description/
3107. Minimum Operations to Make Median of Array Equal to K - https://leetcode.com/problems/minimum-operations-to-make-median-of-array-equal-to-k/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Median filtering in signal processing or real-time stock price smoothing. 