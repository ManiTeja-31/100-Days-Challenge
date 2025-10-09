> [Basic Calculator] - https://leetcode.com/problems/basic-calculator/description/
> Level - Hard
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given a string s representing a valid expression, implement a basic calculator to evaluate it, and return the result of the evaluation.

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Stack + Expression Parsing
--------------------------------------------------------------------------------------------------------------------------------------
## ✅ Approach 1: Brute Force Using Two Stacks

### 🔍 Idea:

* Use two stacks:

  * `results` to store intermediate results.
  * `signs` to store the sign before each parenthesis.
* Parse the string character by character.
* Handle numbers, operators, and parentheses accordingly.

### 🧠 Key Operations:

* On `'+'` or `'-'`: apply the current sign to the number and update `result`.
* On `'('`: push current `result` and `sign`, reset both.
* On `')'`: calculate current result, then combine with the previous result/sign from stack.

### ⏱️ Time Complexity: `O(n)`

### 🗂️ Space Complexity: `O(n)` (stacks)

---

## ✅ Approach 2: Stack-Based with Operator Precedence Handling

### 🔍 Idea:

* Similar to Approach 1, but uses:

  * `numberStack` for numbers
  * `operatorStack` for operators
* Handles **unary minus** by inserting a leading zero (e.g., `-2` becomes `0 - 2`).

### 🧠 Edge Handling:

* For unary `+`/`-` (like `-2` or `(-3)`), push `0` before the operator.
* For every closing `')'`, process operators until `'('`.

### 🛠️ Helper Function:

* `processTop()` handles the top two numbers and the top operator.

### ⏱️ Time Complexity: `O(n)`

### 🗂️ Space Complexity: `O(n)`

---

## ✅ Approach 3: Further Optimized with Minimal Stack Use

### 🔍 Idea:

* Similar to Brute Force, but even cleaner.
* Uses:

  * One stack for result context (`results`)
  * One stack for sign context (`signs`)
* Avoids using two stacks for values and operators separately.

### 🧠 Workflow:

1. Keep building `num` as you encounter digits.
2. On `'+'`/`'-'`: apply previous `sign`, update result, update `sign`.
3. On `'('`: store current `result` and `sign`, then reset both.
4. On `')'`: compute current expression, multiply with sign before parenthesis, and combine with outer expression.
5. At the end: add any remaining `num` to `result`.

### 🧹 Cleanest and most efficient for this specific problem.

---

## 📌 Summary of Approaches

| Approach            | Stack Use                      | Handles Unary Minus      | Modifies String | Complexity | Notes                      |
| ------------------- | ------------------------------ | ------------------------ | --------------- | ---------- | -------------------------- |
| Brute Force         | `results`, `signs`             | ❌ (no explicit handling) | ✅               | O(n)       | Straightforward            |
| Optimized (2-stack) | `numberStack`, `operatorStack` | ✅                        | ✅               | O(n)       | Explicit operator handling |
| Further Optimized   | `results`, `signs`             | ✅ (implicitly)           | ✅               | O(n)       | Clean and preferred        |

---

## 📝 Interview Notes

* This problem **tests understanding of expression evaluation and stack usage**.
* Be clear on operator precedence — though this problem only has `+` and `-`.
* Know how to handle **unary operators** and **nested parentheses**.
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
227. Basic Calculator II - https://leetcode.com/problems/basic-calculator-ii/description/
282. Expression Add Operators - https://leetcode.com/problems/expression-add-operators/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Custom language interpreters, formula evaluators.