> [218. The Skyline Problem ] - https://leetcode.com/problems/the-skyline-problem/
> Level - Hard
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

A city's skyline is the outer contour of the silhouette formed by all the buildings in that city when viewed from a distance. Given the locations and heights of all the buildings, return the skyline formed by these buildings collectively.

The geometric information of each building is given in the array buildings where buildings[i] = [lefti, righti, heighti]:

lefti is the x coordinate of the left edge of the ith building.
righti is the x coordinate of the right edge of the ith building.
heighti is the height of the ith building.
You may assume all buildings are perfect rectangles grounded on an absolutely flat surface at height 0.

The skyline should be represented as a list of "key points" sorted by their x-coordinate in the form [[x1,y1],[x2,y2],...]. Each key point is the left endpoint of some horizontal segment in the skyline except the last point in the list, which always has a y-coordinate 0 and is used to mark the skyline's termination where the rightmost building ends. Any ground between the leftmost and rightmost buildings should be part of the skyline's contour.

Note: There must be no consecutive horizontal lines of equal height in the output skyline. For instance, [...,[2 3],[4 5],[7 5],[11 5],[12 7],...] is not acceptable; the three lines of height 5 should be merged into one in the final output as such: [...,[2 3],[4 5],[12 7],...]
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Sweep Line + Max-Heap
--------------------------------------------------------------------------------------------------------------------------------------
### 🧠 Example

```
Input:
buildings = [[2,9,10], [3,7,15], [5,12,12], [15,20,10], [19,24,8]]

Output:
[[2,10], [3,15], [7,12], [12,0], [15,10], [20,8], [24,0]]
```

Explanation:

* At x=2 → building height 10 begins
* At x=3 → taller building (15) appears
* At x=7 → height drops from 15 to 12
* At x=12 → no building → height 0
* At x=15 → new height 10
* At x=20 → drops to 8
* At x=24 → back to ground level (0)

---

## 🧩 Intuition

Think of sweeping a vertical line across the skyline from **left to right**.
Whenever we **enter** or **leave** a building, the maximum height might change.
Those points of change define the **key points** of the skyline.

---

## 🪜 Step 1: Brute Force Approach

### **Idea**

* For every x-coordinate, record the **maximum height** of any building covering that x.
* Then, track points where height changes.

### **Steps**

1. Find the maximum x-coordinate (`maxX`).
2. Create an array `height` of size `maxX + 1`.
3. For each building:

   * For every x in `[left, right)`, set:

     ```
     height[x] = max(height[x], building_height)
     ```
4. Traverse `height` and whenever height changes, add a key point.

### **Complexity**

| Measure | Value                                    |
| ------- | ---------------------------------------- |
| Time    | O(N × W) — where W = max width on x-axis |
| Space   | O(W)                                     |

✅ Simple to implement
❌ Inefficient for large coordinate ranges (e.g., 10⁹)

---

## 🪜 Step 2: Divide and Conquer (Like Merge Sort)

### **Idea**

* Treat the skyline as a **merge** of smaller skylines.
* Recursively divide buildings into halves, compute skylines for each half, and merge.

---

### **Steps**

1. **Base case:**

   * For one building `[l, r, h]`, skyline = `[[l, h], [r, 0]]`.

2. **Recursive case:**

   * Divide buildings into two halves.
   * Recursively get skylines for left and right halves.
   * **Merge** two skylines by comparing heights from both sides (like merging sorted arrays).

3. **During merge:**

   * Track the current heights from both skylines (`h1`, `h2`).
   * The visible height at each x = `max(h1, h2)`.
   * Add a new key point only if the visible height changes.

---

### **Complexity**

| Measure | Value                           |
| ------- | ------------------------------- |
| Time    | O(N log N)                      |
| Space   | O(N) (recursion + merge result) |

✅ Efficient
✅ Merges naturally reflect skyline overlaps
⚠️ Implementation-heavy

---

## 🪜 Step 3: Sweep Line with Multiset (Balanced Tree)

### **Idea**

Use a **sweep line algorithm** to track active building heights while scanning x-coordinates.

---

### **Steps**

1. For each building:

   * Add two “events”:

     * `(left, +height)` — building starts
     * `(right, -height)` — building ends
2. Sort events by:

   * x ascending
   * If same x → process higher heights first (for correct skyline ordering)
3. Use a **multiset** to store active heights.

   * On entering: insert height
   * On leaving: erase height
4. After each event, find `currMax = *heights.rbegin()`.

   * If `currMax` changes from previous height → add a key point.

---

### **Complexity**

| Measure | Value                                              |
| ------- | -------------------------------------------------- |
| Time    | O(N log N) (sorting + log N per insertion/removal) |
| Space   | O(N)                                               |

✅ Clean, elegant, and widely used
✅ No manual merging required
⚠️ Duplicates must be handled carefully in `multiset`

---

## 🪜 Step 4: Sweep Line with Priority Queue (Heap + Lazy Deletion)

### **Idea**

Use a **max heap** instead of a multiset to track current building heights.
Since removing arbitrary elements from a heap is tricky, use **lazy deletion**.

---

### **Steps**

1. Create building start/end events:

   * `(left, +height)` → add to heap
   * `(right, -height)` → mark height for deletion
2. Sort events by:

   * x ascending
   * Height descending
3. While processing events:

   * On entering: push height into heap.
   * On leaving: increment a counter in a hash map (`toRemove`).
   * Remove (prune) heights that are in `toRemove` from top of heap.
4. The top of the heap gives the current tallest height.

   * If it changes → record a new skyline point.

---

### **Complexity**

| Measure | Value      |
| ------- | ---------- |
| Time    | O(N log N) |
| Space   | O(N)       |

✅ Efficient & scalable
✅ Avoids duplicate height tracking
✅ Handles overlapping & ending buildings neatly

---

## 🧾 Final Comparison

| Approach                  | Technique                | Time       | Space | Notes                                  |
| ------------------------- | ------------------------ | ---------- | ----- | -------------------------------------- |
| **Brute Force**           | Height map               | O(N × W)   | O(W)  | Simple but infeasible for large inputs |
| **Divide & Conquer**      | Recursive merge          | O(N log N) | O(N)  | Clean conceptual model                 |
| **Sweep Line (Multiset)** | Balanced BST             | O(N log N) | O(N)  | Elegant and clean                      |
| **Sweep Line (Heap)**     | Max Heap + Lazy Deletion | O(N log N) | O(N)  | Most practical and scalable            |

---

## 💡 Key Takeaways

* Think of the skyline as **transitions** between building heights.
* Sweep Line algorithms efficiently process **enter** and **leave** events.
* Divide & Conquer approach resembles **merge sort** logic.
* Using `multiset` or a `max heap` gives optimal O(N log N) solutions.
* This is a great example of combining **geometry**, **sorting**, and **data structures**.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
699. Falling Squares - https://leetcode.com/problems/falling-squares/description/
2381. Shifting Letters II - https://leetcode.com/problems/shifting-letters-ii/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
City silhouette visualization, resource monitoring over time