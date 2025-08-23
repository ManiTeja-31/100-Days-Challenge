> [Evaluate Reverse Polish Notation] - https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

You are given an array of strings tokens that represents an arithmetic expression in a Reverse Polish Notation.

Evaluate the expression. Return an integer that represents the value of the expression.

Note that:

* The valid operators are '+', '-', '*', and '/'.
* Each operand may be an integer or another expression.
* The division between two integers always truncates toward zero.
* There will not be any division by zero.
* The input represents a valid arithmetic expression in a reverse polish notation.
* The answer and all the intermediate calculations can be represented in a 32-bit integer.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern

--------------------------------------------------------------------------------------------------------------------------------------
# PsuedoCode

--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

### 🔹 Idea:

* Process tokens from **right to left**.
* If the token is a number → return it (base case).
* If the token is an operator → recursively evaluate the next two sub-expressions and apply the operation.

### ⏱ Complexity:

* **Time:** `O(n)` (each token processed once).
* **Space:** `O(n)` (recursion stack).

### ⚠️ Drawbacks:

* Risk of **stack overflow** for very large expressions.
* Less efficient compared to stack-based iterative solution.
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

### 🔹 Idea:

* Use a **stack** to evaluate the postfix expression.
* Traverse tokens **left to right**:

  * If operand → push onto stack.
  * If operator → pop top two numbers, apply operation, push result back.
* Final stack top = result.

### ⏱ Complexity:

* **Time:** `O(n)` (single pass).
* **Space:** `O(n)` (stack for operands).

### ✅ Why Better:

* Iterative, avoids recursion depth issues.
* Straightforward to implement and understand.

---

## **Optimized Variation (Using Lambda/Helper Function)**

### 🔹 Idea:

* Same as stack-based approach.
* Encapsulate arithmetic logic in a helper (e.g., lambda `calculate(num1, num2, op)`), improving readability and modularity.

### ✅ Benefit:

* Cleaner separation of **stack mechanics** and **operation logic**.
* Easier to extend (e.g., if more operators are added later).
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
224. Basic Calculator - https://leetcode.com/problems/basic-calculator/description/
227. Basic Calculator II - https://leetcode.com/problems/basic-calculator-ii/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Postfix expression parsers in calculators, compilers.
---

## **Tips for Interviews**

* Highlight the **difference between infix and postfix**:

  * Infix: `"3 + 4"`
  * Postfix (RPN): `"3 4 +"`
* Stack approach is the **most common expectation** in interviews.
* Edge cases to mention:

  * Single operand → just return it.
  * Large numbers (use `stoi` safely if coding).
  * Division by zero is not in problem constraints, but you can note it.

---