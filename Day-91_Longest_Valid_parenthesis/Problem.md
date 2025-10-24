> [Longest Valid Parenthesis] - https://leetcode.com/problems/longest-valid-parentheses/description/
> Level - Hard
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given a string containing just the characters '(' and ')', return the length of the longest valid (well-formed) parentheses substring.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Stack / Dynamic Programming
--------------------------------------------------------------------------------------------------------------------------------------
## 🧠 Problem Intuition

You’re given a string `s` consisting only of `'('` and `')'`.
You need to find the **length of the longest valid (well-formed)** parentheses substring.

A valid substring means:

* Every `'('` has a matching `')'`.
* Parentheses are properly nested.

### Example

```
Input: s = "(()"
Output: 2     → "()"

Input: s = ")()())"
Output: 4     → "()()"
```

---

## 🪜 Step 1: Brute Force Approach

### **Intuition**

Try **all possible substrings** and check if they form valid parentheses.
Keep track of the **maximum valid length**.

This is the most straightforward (but inefficient) solution.

---

### **Steps**

1. Generate all possible substrings `(i, j)`.
2. For each substring, check if it’s valid using a helper function `isValid(i, j)`.
3. In `isValid`, maintain a `balance` counter:

   * Increment for `'('`, decrement for `')'`.
   * If balance < 0 → invalid.
   * If after traversal, `balance == 0` → valid.
4. Track the longest valid substring.

---

### **Example**

`s = ")()())"`

We’ll check all substrings like:

* `")("`, `")()"`, `")()("`, etc.
  The valid ones are `"()"` and `"()()"`, the longest having length `4`.

---

### **Complexity**

* **Time:**

  * There are `O(N²)` substrings.
  * Each validity check takes `O(N)`.
  * ⇒ Total = `O(N³)`
* **Space:**

  * `O(1)` (only a few counters).

---

## 🪜 Step 2: Stack Approach

### **Intuition**

Use a **stack** to track indices of parentheses.
Whenever you encounter a `')'`, check if it forms a valid pair with `'('`.

Instead of checking substrings directly, we’ll use **indices** to compute valid lengths efficiently.

---

### **Steps**

1. Initialize a stack and push `-1` (base index for length calculation).
2. Traverse each character:

   * If `'('` → push index.
   * If `')'`:

     * Pop the top index.
     * If stack becomes empty → push current index (reset base).
     * Else → calculate the valid length = `i - stack.top()` and update max.
3. Return the maximum length.

---

### **Example**

`s = ")()())"`

| Step | i   | s[i] | Stack              | MaxLen | Explanation  |
| ---- | --- | ---- | ------------------ | ------ | ------------ |
| Init |     |      | [-1]               | 0      | Base         |
| 0    | `)` |      | Pop `-1`, push 0   | 0      | Reset base   |
| 1    | `(` |      | [0, 1]             | 0      | Push '('     |
| 2    | `)` |      | Pop 1 → [0]; len=2 | **2**  | Valid "()"   |
| 3    | `(` |      | [0, 3]             | 2      | Push '('     |
| 4    | `)` |      | Pop 3 → [0]; len=4 | **4**  | Valid "()()" |
| 5    | `)` |      | Pop 0 → []; push 5 | 4      | Reset base   |

✅ Max length = 4

---

### **Complexity**

* **Time:** `O(N)`
* **Space:** `O(N)` (stack stores indices)

---

## 🪜 Step 3: DP (Dynamic Programming) Approach

### **Intuition**

We can use a DP array where `dp[i]` represents the **length of the longest valid substring ending at index `i`**.

We only care about substrings that end with `')'`, since a valid substring can’t end with `'('`.

---

### **Steps**

1. Initialize a DP array of size `n`, filled with zeros.
2. Traverse `s` from index 1:

   * Case 1: `s[i] == ')'` and `s[i-1] == '('`
     → Found "()"
     → `dp[i] = dp[i-2] + 2`
   * Case 2: `s[i] == ')'` and `s[i-1] == ')'`
     → Check if there’s a `'('` matching `s[i - dp[i-1] - 1]`
     → If yes:

     ```
     dp[i] = dp[i-1] + 2 + dp[i - dp[i-1] - 2]
     ```
3. Track the maximum in `dp`.

---

### **Example**

`s = ")()())"`

| i | s[i] | dp[i] | Explanation     |
| - | ---- | ----- | --------------- |
| 0 | `)`  | 0     | invalid         |
| 1 | `(`  | 0     | invalid         |
| 2 | `)`  | 2     | Found "()"      |
| 3 | `(`  | 0     | invalid         |
| 4 | `)`  | 4     | Found "()()"    |
| 5 | `)`  | 0     | breaks sequence |

✅ Max = 4

---

### **Complexity**

* **Time:** `O(N)`
* **Space:** `O(N)` (DP array)

---

## 🪜 Step 4: Two-Pointer Approach

### **Intuition**

We can solve it in **O(1) space** using two linear scans.

* Left → Right: count `'('` and `')'`.

  * When counts equal → valid substring found.
  * When `')'` exceeds → reset counters.
* Right → Left: handles cases like `"(()"` where `'('` remains unmatched.

---

### **Steps**

1. Initialize `left = right = maxLen = 0`.
2. Traverse Left → Right:

   * Increment `left` for `'('`, `right` for `')'`.
   * If equal → `maxLen = max(maxLen, 2 * right)`.
   * If `right > left` → reset both.
3. Traverse Right → Left:

   * Increment `right` for `')'`, `left` for `'('`.
   * If equal → update `maxLen`.
   * If `left > right` → reset both.
4. Return `maxLen`.

---

### **Example**

`s = "(()())"`

**Left → Right:**

* `'('` increases → left = 2, right = 2 → valid length = 4
* end → max = 6 after final balance

✅ Result = 6

---

### **Complexity**

* **Time:** `O(N)`
* **Space:** `O(1)`

---

## 🧾 Summary Table

| Approach         | Technique                   | Time    | Space  | Notes                            |
| ---------------- | --------------------------- | ------- | ------ | -------------------------------- |
| **Brute Force**  | Try all substrings          | `O(N³)` | `O(1)` | Very slow                        |
| **Stack**        | Track unmatched indices     | `O(N)`  | `O(N)` | Intuitive and fast               |
| **DP**           | Longest valid ending at `i` | `O(N)`  | `O(N)` | Great for learning DP on strings |
| **Two Pointers** | Scan both directions        | `O(N)`  | `O(1)` | Most space-efficient             |

---

## 💡 Key Takeaways

* Always think in terms of **structure**: every `'('` must have a matching `')'`.
* Stack and DP both simulate matching behavior efficiently.
* The **two-pointer** method is the cleanest optimal solution (for interviews).
* Practice on variations — like counting valid groups or reconstructing the substring.

---

✅ **Recommended Order to Learn**

1. Understand **Brute Force** (conceptual clarity)
2. Move to **Stack** (index-based intuition)
3. Study **DP** (subproblem thinking)
4. Master **Two Pointer** (optimal pattern)

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
921. Minimum Add to Make Parentheses Valid - https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/
301. Remove Invalid Parentheses - https://leetcode.com/problems/remove-invalid-parentheses/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Validating nested code segments, HTML/XML correctness, chatbot input parsing