> [Lemonade Change] - https://leetcode.com/problems/lemonade-change/description/
> Level - Easy
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

At a lemonade stand, each lemonade costs $5. Customers are standing in a queue to buy from you and order one at a time (in the order specified by bills). Each customer will only buy one lemonade and pay with either a $5, $10, or $20 bill. You must provide the correct change to each customer so that the net transaction is that the customer pays $5.

Note that you do not have any change in hand at first.

Given an integer array bills where bills[i] is the bill the ith customer pays, return true if you can provide every customer with the correct change, or false otherwise.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Greedy Coin simulator
--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

### **Idea**
* At each step, try all possible ways to give change.
* Track how many \$5 and \$10 bills you have.
* Recursively check if you can serve all customers.
---

### **Step-by-Step**
1. Start with `five = 0`, `ten = 0`.
2. If the customer pays with:
   * **\$5** → Take the bill, increase `five`.
   * **\$10** → Must give one \$5 as change; if not available, fail.
   * **\$20** → Two possible ways:
     * Give **one \$10 and one \$5**.
     * Give **three \$5s**.
3. Explore both ways (if possible) using DFS.
4. If we reach the end without failing, return true.
---
### **Complexity**
* **Time:** O(2^N) → In the worst case, for every \$20 bill, we branch into two choices.
* **Space:** O(N) recursion stack.
---
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

## **Approach 1 – Optimized (Map Tracking)**

### **Idea**
* Instead of exploring all possibilities, use a **greedy strategy**:
  * Always prefer giving **one \$10 + one \$5** over **three \$5s** when giving \$15 change.
* Use a map to track the number of \$5, \$10, and \$20 bills.
---

### **Step-by-Step**
1. For each bill:
   * If **\$5** → increment `change[5]`.
   * If **\$10** → check if we have a \$5; if yes, decrement it and increment `change[10]`; else fail.
   * If **\$20**:
     * Prefer giving `change[10]` and `change[5]` (more optimal).
     * Else, give three \$5s.
     * If neither possible, fail.
2. If we finish without failing, return true.
---

### **Complexity**
* **Time:** O(N) → One pass through customers.
* **Space:** O(1) → Map stores at most 3 keys.
---

## **Approach 2 – Optimized with Two Variables**

### **Idea**
* We only need to track the number of \$5 and \$10 bills.
* No need to store \$20 bills (they’re never used as change).
---

### **Step-by-Step**
1. Initialize `five = 0`, `ten = 0`.
2. For each bill:
   * If **\$5** → `five++`.
   * If **\$10** → need one \$5; if not available, return false; else `five--` and `ten++`.
   * If **\$20**:
     * Prefer one \$10 + one \$5 (if possible).
     * Else, give three \$5s.
     * If neither possible, return false.
3. Return true if all customers are served.
---

### **Complexity**
* **Time:** O(N) → Single pass.
* **Space:** O(1) → Only two counters.
---

### **Why Greedy Works**
When giving \$15 change, using a \$10 bill first is optimal because:
* It preserves more \$5 bills for future customers.
* \$5 bills are the only way to give change for \$10 payments later.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
2241. Design an ATM Machine - https://leetcode.com/problems/design-an-atm-machine/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Change return in vending machines or cash counters.