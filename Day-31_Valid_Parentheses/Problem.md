> [Valid Parenthesis] - https://leetcode.com/problems/valid-parentheses/description/
> Level - Easy
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

1. Open brackets must be closed by the same type of brackets.
2. Open brackets must be closed in the correct order.
3. Every close bracket has a corresponding open bracket of the same type.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Stack
--------------------------------------------------------------------------------------------------------------------------------------
# PsuedoCode

--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

### 🔹 Idea:

* Repeatedly remove valid bracket pairs `"()"`, `"{}"`, `"[]"` until no more can be removed.
* If the string becomes empty → **Valid**.
* If characters remain → **Invalid**.

### ⏱ Complexity:

* **Time:** `O(n²)` (each scan can take `O(n)` and may repeat up to `n/2` times).
* **Space:** `O(1)` (no extra data structure, just modifies the string).

### ⚠️ Drawbacks:

* Inefficient for large strings.
* Repeated rescans waste time.
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

### 🔹 Idea:

* Use a **stack** to simulate bracket matching.
* Push opening brackets into the stack.
* For closing brackets: check if the stack’s top matches; if yes → pop, else → invalid.
* At the end, if the stack is empty → valid.

### ⏱ Complexity:

* **Time:** `O(n)` (single pass).
* **Space:** `O(n)` (stack can hold all opening brackets in the worst case).

### ✅ Why Better:

* Avoids repeated rescanning.
* Elegant and efficient for long strings.
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
301. Remove Invalid Parentheses - https://leetcode.com/problems/remove-invalid-parentheses/description/
921. Minimum Add to Make Parentheses Valid - https://leetcode.com/problems/minimum-add-to-make-parentheses-valid/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Think of it like **nested folders** or **HTML tags**:

* Open a folder → put it on the stack.
* You must close the most recently opened folder before closing an older one.
* If you close in the wrong order, or close something never opened → invalid.

---

## **4. Tips for Interviews**

* If the string length is **odd**, it’s automatically invalid (quick check).
* Always check if the stack is **empty** before accessing the top.
* Emphasize that this is a **classic stack pattern** used in:

  * Expression parsing.
  * Compiler syntax validation.
  * HTML/XML tag validation.

---
