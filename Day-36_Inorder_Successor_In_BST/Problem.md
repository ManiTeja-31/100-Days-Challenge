> [Inorder Successor In BST] - https://www.geeksforgeeks.org/problems/inorder-successor-in-bst/1
> Level - Easy
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given a BST, and a reference to a Node k in the BST. Find the Inorder Successor of the given node in the BST. If there is no successor, return -1. 
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Stack or Recursion in Tree Traversal
--------------------------------------------------------------------------------------------------------------------------------------
# PsuedoCode

--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

1. Perform an **inorder traversal** of the BST (which gives nodes in sorted order).
2. Keep track of the **previous visited node** while traversing.
3. If the previous node is the target node `x`, then the current node is the **inorder successor**.
4. Continue traversal until found.
5. If no such node exists → return `-1`.

⏱ Time Complexity: **O(N)**
📦 Space Complexity: **O(N)** (due to recursion stack / traversal storage).
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

**Case 1: Node `x` has a right child**

* The successor will be the **leftmost node in the right subtree**.

**Case 2: Node `x` has no right child**

* Start from the root and search for `x`.
* While searching:

  * If `x->data < curr->data`, update `succ = curr` (possible successor) and move left.
  * Else move right.
* When found, the `succ` variable stores the inorder successor.

⏱ Time Complexity: **O(h)** (where `h` = height of BST, O(logN) for balanced).
📦 Space Complexity: **O(1)**
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
230. Kth Smallest Element in a BST - https://leetcode.com/problems/kth-smallest-element-in-a-bst/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
BST-based searching for scheduling, task successor, autocomplete.
