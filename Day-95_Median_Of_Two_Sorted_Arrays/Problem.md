> [4. Median of Two Sorted Arrays] - https://leetcode.com/problems/median-of-two-sorted-arrays/
> Level - Hard
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given two sorted arrays nums1 and nums2 of size m and n respectively, return the median of the two sorted arrays.

The overall run time complexity should be O(log (m+n)).
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Binary Search / Divide & Conquer
--------------------------------------------------------------------------------------------------------------------------------------

## 🧠 Intuition

* We want to find the **middle element(s)** of the sorted merged array **without merging** fully.
* Depending on the total size (`m + n`):

  * If **odd** → median is the middle element.
  * If **even** → median is the average of the two middle elements.

---

## 🪜 Step 1: Naive Approach (Merge and Find Median)

### **Idea**

Merge both sorted arrays completely and then compute the median.

### **Steps**

1. Use two pointers (`i` for `nums1`, `j` for `nums2`).
2. Push the smaller of the two into a merged array.
3. Once both arrays are merged, compute:

   * If total size odd → `merged[mid]`
   * If even → `(merged[mid] + merged[mid-1]) / 2.0`

---

### **Example**

```
nums1 = [1, 3], nums2 = [2]
Merged = [1, 2, 3]
Median = 2
```

---

### **Complexity**

* **Time:** `O(m + n)` → Full merge
* **Space:** `O(m + n)` → Extra merged array

✅ **Easy to implement**, but **not optimal** for large arrays.

---

## 🪜 Step 2: Merge Until Median Found (Space-Optimized)

### **Idea**

You don’t actually need the *entire merged array*.
You only need to merge **until** you reach the median index.

### **Steps**

1. Compute total length → `m + n`
2. Compute mid indices:

   * If even: median = `(a[mid1] + a[mid2]) / 2`
   * If odd: median = `a[mid2]`
3. Merge only until we reach those positions using two pointers.

---

### **Example**

```
nums1 = [1, 3], nums2 = [2, 4]
Merged until mid:
→ [1, 2, 3, 4]
mid1 = 1, mid2 = 2 → Median = (2 + 3) / 2 = 2.5
```

---

### **Complexity**

* **Time:** `O(m + n)` (still linear merge)
* **Space:** `O(1)` (no merged array)

✅ More efficient memory-wise.
❌ Still not logarithmic time.

---

## 🪜 Step 3: Optimal Approach — Binary Search (O(log(min(m, n)))

### **Intuition**

We use **binary search** on the smaller array to find a **partition** such that:

* The **left half** of both arrays combined contains the smaller elements.
* The **right half** contains the larger elements.

We then check partition correctness using comparisons between elements near the cut.

---

### **Key Concept**

If we partition both arrays as:

```
A: [A_left | A_right]
B: [B_left | B_right]
```

We want:

```
max(A_left, B_left) ≤ min(A_right, B_right)
```

If this condition holds:

* The **left side** has the smaller half of numbers.
* The **right side** has the larger half.

Then the median is:

* If total length even → average of the two middle elements.
* If odd → max of left side.

---

### **Steps**

1. Always apply binary search on the **smaller array** (for efficiency).
2. Let:

   ```
   i = partition index in nums1
   j = (m + n + 1)/2 - i
   ```

   (ensures left and right halves are balanced)
3. Compute:

   ```
   maxLeftA = (i == 0) ? -∞ : nums1[i-1]
   minRightA = (i == m) ? +∞ : nums1[i]
   maxLeftB = (j == 0) ? -∞ : nums2[j-1]
   minRightB = (j == n) ? +∞ : nums2[j]
   ```
4. Check:

   * If `maxLeftA <= minRightB && maxLeftB <= minRightA` → Correct partition.
   * Else, adjust binary search:

     * If `maxLeftA > minRightB` → move `high = i - 1`
     * Else → move `low = i + 1`
5. Compute median:

   * If total length odd → `max(maxLeftA, maxLeftB)`
   * Else → `(max(maxLeftA, maxLeftB) + min(minRightA, minRightB)) / 2`

---

### **Example**

```
nums1 = [1, 3]
nums2 = [2]

m = 2, n = 1
Binary search on nums2 (smaller array)
```

* Partition 1:

  ```
  A_left = [1], A_right = [3]
  B_left = [2], B_right = []
  ```
* maxLeftA = 1, minRightA = 3
  maxLeftB = 2, minRightB = +∞
  ✅ Condition holds (1 ≤ ∞, 2 ≤ 3)

Median = max(maxLeftA, maxLeftB) = max(1, 2) = 2

---

### **Complexity**

* **Time:** `O(log(min(m, n)))`
* **Space:** `O(1)`

✅ Best possible — logarithmic time and constant space.

---

## 🧾 Summary Table

| Approach                    | Technique         | Time                | Space      | Notes                    |
| --------------------------- | ----------------- | ------------------- | ---------- | ------------------------ |
| **Naive**                   | Merge both arrays | `O(m + n)`          | `O(m + n)` | Simple merge             |
| **Partial Merge**           | Stop at median    | `O(m + n)`          | `O(1)`     | Memory efficient         |
| **Optimal (Binary Search)** | Partition logic   | `O(log(min(m, n)))` | `O(1)`     | Best, used in interviews |

---

## 💡 Key Takeaways

* The **binary search partition** method is the optimal and most elegant solution.
* Always **binary search on the smaller array** to minimize iterations.
* Understand partition condition →
  `maxLeftA ≤ minRightB && maxLeftB ≤ minRightA`
* Handle edge cases with **INT_MIN** and **INT_MAX** carefully.

---

✅ **Final Tip:**
This is a **must-know** problem for interviews — it combines binary search logic with careful boundary handling.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
295. Find Median from Data Stream - https://leetcode.com/problems/find-median-from-data-stream/description/
719. Find K-th Smallest Pair Distance - https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Finding median across distributed logs/datasets