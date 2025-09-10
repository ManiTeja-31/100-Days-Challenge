> [Valid Parenthesis](https://leetcode.com/problems/valid-parentheses/description/)  
> **Level:** Easy

---

## Problem Statement

Given a string `s` containing just the characters `'('`, `')'`, `'{'`, `'}'`, `'['` and `']'`, determine if the input string is valid.

An input string is valid if:

1. **Open brackets must be closed by the same type of brackets.**
2. **Open brackets must be closed in the correct order.**
3. **Every close bracket has a corresponding open bracket of the same type.**

---

## Pattern

> **Stack**

---

## Stack Approach

<details>
<summary>Step-by-step explanation</summary>

1. **Initialize a Stack:**  
   Create an empty stack to keep track of opening brackets.

2. **Iterate Through the String:**  
   For each character in the string:
   - If it is an opening bracket (`(`, `[`, `{`), push it onto the stack.
   - If it is a closing bracket (`)`, `]`, `}`):
     - Check if the stack is not empty and the top of the stack is the matching opening bracket.
     - If so, pop the top element from the stack.
     - If not, the string is invalid; return false.

3. **Final Check:**  
   After processing all characters, if the stack is empty, the string is valid.  
   If the stack is not empty, there are unmatched opening brackets; return false.

</details>

---

## Iterative Replacement Approach

<details>
<summary>Step-by-step explanation</summary>

1. **Repeat Until No Change:**  
   Continuously scan the string for pairs of valid brackets: `"()"`, `"[]"`, and `"{}"`.

2. **Remove Valid Pairs:**  
   Whenever a valid pair is found, remove it from the string.

3. **Check for Completion:**  
   Repeat the process until no more pairs can be removed (the string length stops changing).

4. **Final Check:**  
   If the string is empty after all replacements, it is valid.  
   If any characters remain, the string is invalid.

</details>

---

## Other Problems Using this Approach

- [32. Longest Valid Parentheses](https://leetcode.com/problems/longest-valid-parentheses/description/)
- [1003. Check If Word Is Valid After Substitutions](https://leetcode.com/problems/check-if-word-is-valid-after-substitutions/description/)

---

## CodeChef Equivalent

**NA**

---

## Real-World Use

- Validating code syntax
-