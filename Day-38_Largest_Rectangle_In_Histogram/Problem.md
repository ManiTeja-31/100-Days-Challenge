> [Largest Rectangle in Histogram] - https://leetcode.com/problems/largest-rectangle-in-histogram/description/
> Level - Hard
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Monotonic Stack
--------------------------------------------------------------------------------------------------------------------------------------
## 🪜 Step 1: Brute Force Approach

### **Idea**

Try all possible pairs of bars `(i, j)` and find the smallest height between them.
Use that as the rectangle height, and `(j - i + 1)` as the width.

---

### **Steps**

1. For each starting bar `i`,

   * Initialize `minHeight = heights[i]`.
2. Expand the window to every possible `j ≥ i`.

   * Update `minHeight = min(minHeight, heights[j])`.
   * Compute area = `(j - i + 1) × minHeight`.
3. Keep track of the maximum area seen.

---

### **Complexity**

| Measure | Value |
| ------- | ----- |
| Time    | O(n²) |
| Space   | O(1)  |

✅ Easy to understand
❌ Too slow for large `n` (double loop)

---

## 🪜 Step 2: Optimized Approach (Next & Previous Smaller Element)

### **Idea**

For each bar, find:

* The **first smaller bar to its left**
* The **first smaller bar to its right**

That defines how far the current bar can extend while still being the **minimum height** in that range.

Then area for each bar = `height[i] × (right[i] - left[i] - 1)`

---

### **Steps**

1. **Find Previous Smaller Elements (Left boundary)**

   * Use a stack to store indices of increasing heights.
   * For each index `i`, pop until a smaller height is found.
   * Store that index as the **left boundary**.

2. **Find Next Smaller Elements (Right boundary)**

   * Do the same in reverse (right-to-left).
   * Store the first smaller element’s index to the right.

3. Compute area for each bar using:

   ```
   width = right[i] - left[i] - 1  
   area = height[i] × width
   ```

4. Track the maximum area.

---

### **Complexity**

| Measure | Value |
| ------- | ----- |
| Time    | O(n)  |
| Space   | O(n)  |

✅ Efficient and intuitive once stack logic is clear
⚠️ Must handle left/right boundaries carefully

---

## 🪜 Step 3: Single Stack Optimized Solution (Most Elegant)

### **Idea**

Instead of explicitly finding left and right smaller bars,
use a **single pass stack** that dynamically computes areas when necessary.

---

### **Steps**

1. Append a `0` to the end of the array → ensures all bars get processed.
2. Iterate through `heights`:

   * Push indices onto stack while current bar ≥ top of stack.
   * When current bar < top of stack →
     Pop the top index, treating that height as the **smallest bar** in a rectangle.

     * **Height:** `heights[top]`
     * **Width:** `i - stack.top() - 1` (or `i` if stack is empty)
     * Compute area = `height × width`
     * Update `maxArea`.
3. Continue until all bars are processed.

---

### **Complexity**

| Measure | Value |
| ------- | ----- |
| Time    | O(n)  |
| Space   | O(n)  |

✅ Linear time
✅ Clean implementation
✅ No need to store left/right arrays

---

## 🧾 Final Comparison

| Approach               | Technique              | Time  | Space | Notes                        |
| ---------------------- | ---------------------- | ----- | ----- | ---------------------------- |
| **Brute Force**        | Try all rectangles     | O(n²) | O(1)  | Simple but too slow          |
| **Left/Right Smaller** | Stack + Precomputation | O(n)  | O(n)  | Intuitive, uses extra arrays |
| **Single Stack**       | One-pass stack         | O(n)  | O(n)  | Most optimal & elegant       |

---

## 💡 Key Takeaways

* The **stack** keeps track of **increasing bar indices**.
* When a **smaller bar** is found, it means previous bars can no longer extend further — compute area immediately.
* Pushing a `0` at the end forces the algorithm to compute all remaining areas.
* This **single stack** pattern is used in related problems like:

  * **Maximal Rectangle in Matrix**
  * **Trapping Rain Water**
  * **Next Greater Element**

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
85. Maximal Rectangle - https://leetcode.com/problems/maximal-rectangle/description/
1793. Maximum Score of a Good Subarray - https://leetcode.com/problems/maximum-score-of-a-good-subarray/description/
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Sky-scraper skyline height calculation, histogram-based compression.