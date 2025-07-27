> [Move Zeros] - https://leetcode.com/problems/move-zeroes/description/
> Level - Easy
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.
Note that you must do this in-place without making a copy of the array.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Two Pointer + In Place Modification 
--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

🧭Step-by-step Explanation:
1. Create a new array of the same size filled with zeroes.
2. Iterate through the original array, and every time you find a **non-zero element**, you **place it into the new array**, one by one, starting from the beginning.
3. Since the new array is initially full of zeroes, all remaining spots after placing the non-zero elements are already zeroes.
4. Finally, you **copy the new array back** to the original array to reflect the changes.

🧠 Time & Space Complexity:
* Time Complexity: O(n) – you go through the array once.
* Space Complexity: O(n) – you use an extra array of the same size.

--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

🧭Step-by-step Explanation:
1. We use two pointers—one pointer (`j`) tracks the position where the next non-zero element should be placed, and the other (`i`) iterates over the array.
2. As we go through the array:
   * If the current element is **non-zero**, we **place it at position `j`**.
   * After placing the non-zero element, we **increment `j`** to point to the next available position.
3. The key idea is:
   * Every time we find a non-zero element, we move it to the front (if it's not already there).
   * By the end of the loop, all non-zero elements are packed at the front in order, and the remaining positions naturally become zeros.

🧠 Time & Space Complexity:
* Since we’re swapping only when necessary, the solution is both **efficient (O(n))** and **space-optimal (O(1))**.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach

26. Remove Duplicates from Sorted Array - https://leetcode.com/problems/remove-duplicates-from-sorted-array/
2164. Sort Even and Odd Indices Independently - https://leetcode.com/problems/sort-even-and-odd-indices-independently/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent

--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Defragmenting memory, shifting non-null values in databases or spreadsheets.