> [Maximal Rectangle] - https://leetcode.com/problems/maximal-rectangle/
> Level - Hard
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Stacks
--------------------------------------------------------------------------------------------------------------------------------------
## 🪜 Step 1: Brute Force (Check Every Possible Rectangle)

### **Idea**

Try all possible rectangles defined by two corners `(r1, c1)` and `(r2, c2)`
and check whether **all cells** inside are `'1'`.

---

### **Steps**

1. Iterate through all possible pairs of rows and columns.
2. For each rectangle, verify all elements are `'1'`.
3. If valid, compute its area = `(r2 - r1 + 1) × (c2 - c1 + 1)`
4. Keep track of the maximum area found.

---

### **Complexity**

| Measure | Value                                    |
| ------- | ---------------------------------------- |
| Time    | O(m² × n² × m × n) ≈ O(m⁴ n⁴) worst-case |
| Space   | O(1)                                     |

✅ Simple to understand
❌ Extremely slow (nested loops for all rectangles)

---

## 🪜 Step 2: Brute Force (Using Heights)

### **Idea**

Treat each pair of rows `(top, bottom)` as the top and bottom boundaries.
For each column, compute how many consecutive 1’s appear between these rows.
This converts the problem into checking **horizontal stretches** of equal heights.

---

### **Steps**

1. Fix a top row.
2. For each bottom row ≥ top,

   * Update a `height[]` array where
     `height[j] = number of consecutive 1’s in column j between top and bottom`.
3. Scan each row to find **the widest segment** where all heights are equal to `(bottom - top + 1)`.
4. Compute area = `width × height`.

---

### **Complexity**

| Measure | Value     |
| ------- | --------- |
| Time    | O(m² × n) |
| Space   | O(n)      |

✅ Much better than full brute force
⚠️ Still not optimal

---

## 🪜 Step 3: DP with Left, Right, and Height Arrays

### **Idea**

Use three arrays per row:

* `height[j]` = height of consecutive 1’s in column `j`
* `left[j]` = leftmost boundary where current bar of 1’s can extend
* `right[j]` = rightmost boundary where current bar can extend

Then for each cell:

```
Area = (right[j] - left[j]) × height[j]
```

---

### **Steps**

1. Traverse row by row.
2. Update heights:

   ```
   if matrix[i][j] == '1' → height[j] += 1
   else height[j] = 0
   ```
3. Update left boundaries:

   * If `'1'`, `left[j] = max(left[j], current_left)`
   * Else reset `left[j] = 0` and `current_left = j + 1`
4. Update right boundaries (right-to-left):

   * If `'1'`, `right[j] = min(right[j], current_right)`
   * Else reset `right[j] = n` and `current_right = j`
5. Compute area for each column.

---

### **Complexity**

| Measure | Value    |
| ------- | -------- |
| Time    | O(m × n) |
| Space   | O(n)     |

✅ Efficient and purely array-based
✅ Uses dynamic programming concepts
⚠️ Logic is tricky to implement correctly

---

## 🪜 Step 4: Using Largest Rectangle in Histogram (Optimal & Elegant)

### **Idea**

Each row of the matrix can be seen as the **base of a histogram**.
For every row:

* Convert it into a histogram of heights (number of consecutive 1’s above it).
* Then apply the **Largest Rectangle in Histogram** algorithm (stack-based).

---

### **Steps**

1. Initialize a `heights[]` array with 0’s.
2. For each row:

   * Update `heights[j]`:

     ```
     if matrix[i][j] == '1' → heights[j] += 1
     else heights[j] = 0
     ```
   * Compute the largest rectangle in `heights` using a **monotonic stack**:

     * Push indices of increasing heights.
     * When a smaller height appears, pop and compute the rectangle area.
     * Width = (current index - index of previous smaller - 1)
3. Keep track of the global maximum area.

---

### **Complexity**

| Measure | Value    |
| ------- | -------- |
| Time    | O(m × n) |
| Space   | O(n)     |

✅ Most intuitive and reusable
✅ Directly uses the stack logic from “Largest Rectangle in Histogram”
✅ Clean and fast

---

## 🧾 Final Comparison

| Approach                         | Technique                            | Time    | Space | Notes                  |
| -------------------------------- | ------------------------------------ | ------- | ----- | ---------------------- |
| **Brute Force (All Rectangles)** | Check all submatrices                | O(m⁴n⁴) | O(1)  | Impractical            |
| **Brute Force (Heights)**        | Fix rows, count 1’s                  | O(m²n)  | O(n)  | Better but still slow  |
| **DP (Left, Right, Height)**     | Track boundaries dynamically         | O(mn)   | O(n)  | Fast but complex logic |
| **Histogram Method**             | Use “Largest Rectangle in Histogram” | O(mn)   | O(n)  | Fastest and simplest   |

---

## 💡 Key Takeaways

* This is essentially a **2D extension** of the **Largest Rectangle in Histogram** problem.
* The **histogram approach** is the most practical and elegant — it reuses the 1D stack idea row by row.
* DP-based left/right/height tracking is an alternate optimal method but harder to code cleanly.
* All efficient solutions rely on **treating rows as histograms** to reuse known subroutines.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
221. Maximal Square - https://leetcode.com/problems/maximal-square/description/
2132. Stamping the Grid - https://leetcode.com/problems/stamping-the-grid/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Image processing, large matrix-based layouts.