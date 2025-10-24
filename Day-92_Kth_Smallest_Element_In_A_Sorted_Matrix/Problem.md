> [378. Kth Smallest Element in a Sorted Matrix] - https://leetcode.com/problems/kth-smallest-element-in-a-sorted-matrix/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an n x n matrix where each of the rows and columns is sorted in ascending order, return the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

You must find a solution with a memory complexity better than O(n2).
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Heap / Binary Search
--------------------------------------------------------------------------------------------------------------------------------------
## 🧠 Observations

* Each **row** and **column** is sorted → we can use this property to reduce work.
* There are multiple strategies to find the k-th smallest element:

  * Naively flatten and sort.
  * Use heaps.
  * Use binary search on value range.

---

## 🪜 Step 1: Naive (Flatten and Sort)

### **Intuition**

* Combine all elements into a single array.
* Sort them.
* The k-th smallest element is at position `k - 1`.

### **Steps**

1. Traverse the entire matrix and push all elements into a 1D array.
2. Sort the array.
3. Return the element at index `k-1`.

### **Complexity**

* **Time:** `O(N² log(N²))` → sorting `N²` elements.
* **Space:** `O(N²)` → extra array.

### **Notes**

* Simple and easy to implement.
* Inefficient for large matrices.

---

## 🪜 Step 2: Max-Heap Approach

### **Intuition**

Use a **max-heap** of size `k` to keep track of the `k` smallest elements seen so far.

The largest among those `k` (i.e., heap top) will be the **k-th smallest**.

### **Steps**

1. Traverse all elements in the matrix.
2. Push each element into the heap.
3. If heap size exceeds `k`, pop the largest element.
4. After traversal, the heap top is the k-th smallest element.

### **Example**

```
matrix = [
  [1, 5, 9],
  [10, 11, 13],
  [12, 13, 15]
], k = 8
```

* Push elements one by one.
* Keep only 8 smallest ones.
* The largest among them = 13 (8th smallest).

### **Complexity**

* **Time:** `O(N² log k)`
  (Each push/pop operation costs `O(log k)`.)
* **Space:** `O(k)` (heap size at most `k`)

### **Notes**

* Better than full sort.
* Works even if matrix wasn’t sorted, but doesn’t fully use the sorted property.

---

## 🪜 Step 3: Min-Heap Approach (Using Sorted Property)

### **Intuition**

The matrix is **sorted row-wise and column-wise**, so the smallest elements are always in the top-left area.
We can use a **min-heap** to explore the smallest elements in order.

Think of it as merging `n` sorted lists (each row is sorted).

### **Steps**

1. Push the first element of each row into a **min-heap** along with its position `(value, row, col)`.
2. Repeat `k` times:

   * Pop the smallest element from the heap.
   * If that element has a next column, push that next element from the same row.
3. After `k` pops, the last popped element is the answer.

### **Example**

Matrix:

```
[1, 5, 9]
[10, 11, 13]
[12, 13, 15]
```

Heap progression:

1. Push `[1,10,12]` → pop `1`
2. Push next from row 0 → `[5,10,12]`
3. Pop → `5`
4. Push next from row 0 → `[9,10,12]`
5. Pop → `9`
6. Push next from row 1 → `[10,11,12]`
   ... continue till the 8th pop → `13`

✅ Answer = 13

### **Complexity**

* **Time:** `O(k log n)`
  (Each heap operation costs `O(log n)`; we do `k` pops.)
* **Space:** `O(n)` (heap stores up to one element per row.)

### **Notes**

* Efficient and intuitive.
* Uses the matrix’s sorted property effectively.

---

## 🪜 Step 4: Binary Search on Value Range

### **Intuition**

Because the matrix is sorted, the k-th smallest element must lie between the smallest (`matrix[0][0]`) and largest (`matrix[n-1][n-1]`) values.

We can **binary search** on this value range, counting how many numbers are ≤ mid each time.

---

### **Steps**

1. Set search range:

   ```
   low = matrix[0][0]
   high = matrix[n-1][n-1]
   ```
2. While `low < high`:

   * Compute `mid`.
   * Count how many elements in the matrix are ≤ `mid`.
   * If count < k → move right (`low = mid + 1`)
   * Else → move left (`high = mid`)
3. Return `low` (the k-th smallest).

---

### **Counting Step (Efficiently)**

To count how many elements ≤ `mid`:

* Start from **bottom-left** of the matrix.
* If current value ≤ `mid`, move **right** (since all above are smaller → add all in that column).
* If current value > `mid`, move **up**.

This counts elements in **O(N)** time per iteration.

---

### **Example**

Matrix:

```
[1,  5,  9]
[10, 11, 13]
[12, 13, 15]
```

k = 8

Binary search range: `[1, 15]`

| mid           | count(≤mid) | Action                 |
| ------------- | ----------- | ---------------------- |
| 8             | 3           | count < 8 → move right |
| 12            | 6           | count < 8 → move right |
| 13            | 8           | count ≥ 8 → move left  |
| ✅ Result = 13 |             |                        |

---

### **Complexity**

* **Time:** `O(N log(Max - Min))`
  (`O(log(range))` binary search × `O(N)` count per iteration)
* **Space:** `O(1)`

---

## 🧾 Summary Table

| Approach          | Technique           | Time Complexity     | Space Complexity | Notes                           |
| ----------------- | ------------------- | ------------------- | ---------------- | ------------------------------- |
| **Naive**         | Flatten + Sort      | `O(N² log N²)`      | `O(N²)`          | Simple, not optimal             |
| **Max-Heap**      | Keep top k smallest | `O(N² log k)`       | `O(k)`           | Better, ignores sorted property |
| **Min-Heap**      | Merge sorted rows   | `O(k log N)`        | `O(N)`           | Uses sorted rows efficiently    |
| **Binary Search** | On value range      | `O(N log(Max−Min))` | `O(1)`           | Most optimal & elegant          |

---

## 💡 Key Takeaways

* If matrix is **not sorted**, use heap approaches.
* If matrix is **sorted both row & column**, prefer **Binary Search**.
* **Min-Heap** is often the easiest to code and explain in interviews.
* **Binary Search** gives best scalability when matrix values have a limited range.

---

✅ **Recommended Learning Path**

1. Start with **Flatten + Sort** (for clarity)
2. Learn **Max-Heap** (understand heap logic)
3. Move to **Min-Heap** (efficient and intuitive)
4. Master **Binary Search on value range** (for optimization)

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
632. Smallest Range Covering Elements from K Lists - https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/description/
668. Kth Smallest Number in Multiplication Table - https://leetcode.com/problems/kth-smallest-number-in-multiplication-table/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Merging K sorted data streams, median-of-streams computations