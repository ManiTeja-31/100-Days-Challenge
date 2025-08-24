> [Min Stack] - https://leetcode.com/problems/min-stack/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

Implement the MinStack class:

* MinStack() initializes the stack object.
* void push(int val) pushes the element val onto the stack.
* void pop() removes the element on the top of the stack.
* int top() gets the top element of the stack.
* int getMin() retrieves the minimum element in the stack.
* You must implement a solution with O(1) time complexity for each function.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
Stack with Auxiliary Min Tracking
--------------------------------------------------------------------------------------------------------------------------------------
# PsuedoCode

--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

* Maintain only a normal stack.
* For `getMin()`, traverse the entire stack to find the minimum.
* Each `getMin()` call takes **O(n)** time.

👉 Why it’s brute force:
Because every time you want the minimum, you scan through all elements. Not efficient if there are multiple queries.
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

### ✅ **Approach 1: Using Two Stacks**

* Maintain two stacks:

  * **mainStack** → stores all elements
  * **minStack** → stores the minimums seen so far
* When pushing, also push into `minStack` if it’s the new minimum.
* When popping, check if the popped element is also the minimum; if yes, pop from both.
* `getMin()` is **O(1)** since top of `minStack` is always the current minimum.

⏱️ Complexity:

* Push: O(1)
* Pop: O(1)
* Top: O(1)
* GetMin: O(1)

---

### ✅ **Approach 2: Single Stack with Pair**

* Use **one stack of pairs** → `(value, currentMin)`
* Each push stores the element along with the minimum up to that point.
* Example: push 5 → `(5, 5)`; push 3 → `(3, 3)`; push 7 → `(7, 3)`.
* Now, `getMin()` = `stack.top().second`.

⏱️ Complexity:

* Push: O(1)
* Pop: O(1)
* Top: O(1)
* GetMin: O(1)

👉 This saves the need for two stacks but uses slightly more memory per element.
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
716. Max Stack - https://leetcode.com/problems/max-stack/description/

--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
* Real-time minimum (e.g., stocks, stats, undo operations).
* **Stock Market Monitoring:** Track stock prices where you need to quickly check the lowest price in the current window.
* **Memory Management:** Keep track of minimum free memory in a stack of resource allocations.
* **Browser History / Undo Systems:** Need quick min/max lookups on changes.
* **Competitive Programming**: Subproblems inside range minimum queries, sliding windows, etc.
---
## 🧩 How to Identify This Problem

* When you see **“track minimum/maximum dynamically while inserting and removing”**,
  → Think of **supporting data structures** alongside the main one.
* For `getMin()` in **O(1)** → means **store the min during push**, not compute later.
