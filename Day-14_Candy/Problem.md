> [Candy] - https://leetcode.com/problems/candy/description/
> Level - Hard
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
You are giving candies to these children subjected to the following requirements:
Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Greedy + Bidirectional pass
--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

In brute force, we:
* Start by giving every child 1 candy.
* Repeatedly loop over the array and adjust candies if the rules are violated.
* We continue this process until no more updates are needed.
**Drawback**: It can take multiple full passes in the worst case.

🧠 Time & Space Complexity:
* Time Complexity: `O(N^2)`
* Space Complexity: `O(N)`
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

This is the most optimal and clean solution used in interviews.

1. Give every child 1 candy (base condition).
2. **Left to Right Pass**:
   * If a child has a higher rating than the one before, give them more candy.
3. **Right to Left Pass**:
   * If a child has a higher rating than the one after, ensure they have more candy.
   * Use `max(res[i], res[i+1] + 1)` to prevent reducing values from the first pass.
This way we ensure both rules are satisfied in `O(N)` time.

🧠 Time & Space Complexity:
* Time Complexity: `O(N)`
* Space Complexity: `O(N)`
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
3122. Minimum Number of Operations to Satisfy Conditions - https://leetcode.com/problems/minimum-number-of-operations-to-satisfy-conditions/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Reward distribution based on ranking (bonuses, grades)
