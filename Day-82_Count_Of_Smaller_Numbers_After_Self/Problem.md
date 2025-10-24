> [315. Count of Smaller Numbers After Self] - https://leetcode.com/problems/count-of-smaller-numbers-after-self/description/
> Level - Hard
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an integer array nums, return an integer array counts where counts[i] is the number of smaller elements to the right of nums[i].
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Merge Sort / Binary Indexed Tree
--------------------------------------------------------------------------------------------------------------------------------------
## 🧠 Observations

* Naively, we could check each element’s right side → `O(N²)` time.
* But that’s inefficient for large arrays.
* We can improve by using:

  * **Modified Merge Sort** (counting during merge)
  * **Binary Indexed Tree (Fenwick Tree)**
  * Or **Balanced BST / Segment Tree**

---

## 🪜 Step 1: Brute Force Approach

### **Intuition**

For each number, simply count how many numbers to its right are smaller.

### **Steps**

1. For each index `i`:

   * Initialize a counter = 0.
   * Iterate through elements `j` (where `j > i`).
   * If `nums[j] < nums[i]`, increment the counter.
2. Store the counter in the result.

---

### **Example**

```
nums = [5, 2, 6, 1]
```

| i | nums[i] | Right Side | Smaller Count |
| - | ------- | ---------- | ------------- |
| 0 | 5       | [2,6,1]    | 2             |
| 1 | 2       | [6,1]      | 1             |
| 2 | 6       | [1]        | 1             |
| 3 | 1       | []         | 0             |

✅ Output: `[2, 1, 1, 0]`

---

### **Complexity**

* **Time:** `O(N²)` (double nested loops)
* **Space:** `O(1)`

### **Notes**

* Very simple but not efficient.
* Only suitable for small inputs or conceptual understanding.

---

## 🪜 Step 2: Merge Sort Approach (Divide & Conquer)

### **Intuition**

We can use a **modified merge sort** to count smaller elements efficiently.

During merging:

* When a number from the **right half** moves before one in the **left half**,
  it means that number is **smaller and to the right** of the left-half element.

### **Core Idea**

While merging two sorted halves:

* If `left[i] <= right[j]` → normal merge.
* If `left[i] > right[j]` →
  all remaining elements in `left[i..mid]` have this smaller element to their right.

We can accumulate these counts during the merge.

---

### **Steps**

1. Store `(value, original_index)` pairs.
2. Perform merge sort recursively.
3. During the merge step:

   * If `left[i] <= right[j]`:

     * Add `rightCount` (number of smaller right-side elements already placed) to `count[left[i].index]`.
   * Else (`left[i] > right[j]`):

     * Increment `rightCount` (found a smaller element).
4. Copy merged results back.

---

### **Example**

`nums = [5, 2, 6, 1]`

* Split into halves recursively: `[5,2]` and `[6,1]`
* Merge `[5,2]` → `[2,5]` → 5 has 1 smaller to the right.
* Merge `[6,1]` → `[1,6]` → 6 has 1 smaller to the right.
* Merge `[2,5]` and `[1,6]` → `[1,2,5,6]`

  * 2 has 1 smaller (1),
  * 5 has 2 smaller (2,1).

✅ Final count = `[2,1,1,0]`

---

### **Complexity**

* **Time:** `O(N log N)` (modified merge sort)
* **Space:** `O(N)` (temporary arrays)

### **Notes**

* Classic “count inversion” pattern.
* Most intuitive divide-and-conquer solution for interviews.

---

## 🪜 Step 3: Binary Indexed Tree (Fenwick Tree) Approach

### **Intuition**

We can use a **Fenwick Tree (BIT)** to dynamically count elements smaller than the current one as we move from **right to left**.

BIT efficiently supports:

* **update(index, value)** → increment frequency
* **query(index)** → count of all elements ≤ index

---

### **Steps**

1. **Coordinate compression:**
   Since numbers may be large, we compress them into ranks (1..N).

   * Sort a copy of `nums`.
   * Each number’s rank = its position in the sorted list.
2. Initialize a Fenwick Tree with size = `n`.
3. Traverse `nums` from right to left:

   * Query BIT for `rank - 1` → how many smaller numbers we’ve seen.
   * Store the result.
   * Update BIT at `rank` by +1 (mark this number as seen).
4. Reverse results (since we processed from right to left).

---

### **Example**

`nums = [5, 2, 6, 1]`

**Step 1: Compression**

```
Sorted unique = [1, 2, 5, 6]
Ranks:
1 → 1
2 → 2
5 → 3
6 → 4
```

**Step 2: Process from right to left**

| i | nums[i] | rank | query(rank−1) | update(rank) | result[i] |
| - | ------- | ---- | ------------- | ------------ | --------- |
| 3 | 1       | 1    | 0             | +1           | 0         |
| 2 | 6       | 4    | 3             | +1           | 1         |
| 1 | 2       | 2    | 1             | +1           | 1         |
| 0 | 5       | 3    | 2             | +1           | 2         |

✅ Result = `[2, 1, 1, 0]`

---

### **Complexity**

* **Time:** `O(N log N)`
  (Each update/query = `O(log N)`; for N elements)
* **Space:** `O(N)` (Fenwick tree + arrays)

---

## 🧾 Summary Table

| Approach         | Technique                  | Time Complexity | Space Complexity | Notes                              |
| ---------------- | -------------------------- | --------------- | ---------------- | ---------------------------------- |
| **Brute Force**  | Compare each pair          | `O(N²)`         | `O(1)`           | Simple, slow                       |
| **Merge Sort**   | Count while merging        | `O(N log N)`    | `O(N)`           | Elegant divide & conquer           |
| **Fenwick Tree** | Frequency counting via BIT | `O(N log N)`    | `O(N)`           | Best for understanding prefix sums |

---

## 💡 Key Takeaways

* This problem is a **variation of inversion counting**.
* **Merge Sort** and **BIT** are both efficient and interview-acceptable.
* BIT approach is excellent for handling **streaming or dynamic** problems.
* Always perform **coordinate compression** for BIT to handle large numbers.

---

✅ **Recommended Learning Path**

1. Understand **Brute Force** (build intuition).
2. Learn **Merge Sort Counting** (divide & conquer pattern).
3. Master **Fenwick Tree** (advanced data structure usage).

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
1. Count Inversions - https://www.geeksforgeeks.org/problems/inversion-of-array-1587115620/1
493. Reverse Pairs - https://leetcode.com/problems/reverse-pairs/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Ranking systems, leaderboards, real-time tracking of players’ scores. 