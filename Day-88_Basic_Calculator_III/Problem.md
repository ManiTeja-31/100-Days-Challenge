> [772 - Basic Calculator III] - 
> Level - Hard
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Implement a basic  calculator to evaluate a simple expression string.

The expression string contains only non-negative integers, '+', '-', '*', '/' operators, and open '(' and closing parentheses ')'. The integer division should truncate toward zero.


You may assume that the given expression is always valid. All intermediate results will be in the range of [-231, 231 - 1].

Note: You are not allowed to use any built-in function which evaluates strings as mathematical expressions, such as eval().
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Stacks
--------------------------------------------------------------------------------------------------------------------------------------
## 1️⃣ Naive / Recursive Approach

### **Idea**

* Parse the expression character by character.
* Use recursion to handle parentheses.
* Use a stack to handle operations and intermediate results.
* Evaluate sub-expressions when:

  * You hit an operator.
  * You reach a `)` or the end of the string.

### **Steps**

1. Use helper function `helper(s, i)` where `i` is the current parsing index.
2. Maintain:

   * `stack<int>` → stores values after each operation.
   * `num` → current number being built.
   * `sign` → the last operation (`+`, `-`, `*`, `/`).
3. When encountering:

   * **Digit** → build the number.
   * **‘(’** → recursively evaluate until corresponding `’)’`.
   * **Operator or end of expression** → apply the previous operator.
   * **‘)’** → end current recursion level and return the computed value.
4. Sum all numbers in the stack at the end.

### **Pseudocode**

```cpp
if (sign == '+') st.push(num);
else if (sign == '-') st.push(-num);
else if (sign == '*') { int top = st.top(); st.pop(); st.push(top * num); }
else if (sign == '/') { int top = st.top(); st.pop(); st.push(top / num); }
```

### **Complexity**

| Measure | Cost                                    |
| ------- | --------------------------------------- |
| Time    | O(n) average (each char processed once) |
| Space   | O(n) recursion + stack                  |

### **Pros**

✅ Handles parentheses naturally via recursion
✅ Clean and intuitive

### **Cons**

❌ Uses recursion — risk of stack overflow for very deep nested parentheses

---

## 2️⃣ Optimized Approach – Two Stack Method

### **Idea**

* Use **two stacks**:

  * `nums` → for operands.
  * `ops` → for operators and parentheses.
* Process expression **iteratively**, respecting operator precedence.
* Apply operators when:

  * Current operator has **lower or equal precedence** than the top of the operator stack.
  * You reach a closing parenthesis.

### **Steps**

1. Parse string left to right.
2. If digit → extract full number and push to `nums`.
3. If `(` → push to `ops`.
4. If `)` → evaluate until matching `(` is found.
5. If operator → apply previous higher-precedence operators first.
6. After parsing, apply all remaining operations.

### **Key Helper Functions**

```cpp
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

int applyOp(int a, int b, char op) {
    if (op == '+') return a + b;
    if (op == '-') return a - b;
    if (op == '*') return a * b;
    return a / b;
}
```

### **Complexity**

| Measure | Cost              |
| ------- | ----------------- |
| Time    | O(n)              |
| Space   | O(n) (for stacks) |

### **Pros**

✅ Fully iterative (no recursion)
✅ Handles precedence and parentheses elegantly
✅ Efficient and clean logic

### **Cons**

❌ Slightly more code to manage two stacks manually

---

## ⚡ Comparison Summary

| Approach  | Type              | Handles Parentheses      | Precedence Control     | Time | Space | Notes                       |
| --------- | ----------------- | ------------------------ | ---------------------- | ---- | ----- | --------------------------- |
| Recursive | Recursive + Stack | ✅ Natural via recursion  | ✅ Handled inside logic | O(n) | O(n)  | Very intuitive              |
| Two-Stack | Iterative         | ✅ With explicit handling | ✅ Via precedence()     | O(n) | O(n)  | More efficient, stack-based |

---

## 💡 Key Insights

* Parentheses cause nested sub-expressions → recursion or stack required.
* Operator precedence (`*` and `/` before `+` and `-`) must be maintained.
* Integer division truncates toward zero in C++.
* Skip whitespace while parsing.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
282. Expression Add Operators - https://leetcode.com/problems/expression-add-operators/description/
227. Basic Calculator II - https://leetcode.com/problems/basic-calculator-ii/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Compilers, interpreters, calculator software.