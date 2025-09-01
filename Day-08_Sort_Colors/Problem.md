> [Sort Colors] - https://leetcode.com/problems/sort-colors/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an array nums with n objects colored red, white, or blue, sort them in-place so that objects of the same color are adjacent, with the colors in the order red, white, and blue.
We will use the integers 0, 1, and 2 to represent the color red, white, and blue, respectively.
You must solve this problem without using the library's sort function.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Dutch National Flag Algorithm
--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

The code uses the classic **Insertion Sort** algorithm to sort the array. Here's how it works:

* We iterate from index `1` to `n-1`, treating the left portion of the array (from `0` to `i-1`) as already sorted.
* For each element `nums[i]`, we store it as a `key`, and compare it with elements in the sorted portion.
* We shift all elements greater than `key` to the right to make space.
* Finally, we insert the `key` into its correct position.

In the context of this problem, even though the input only has `0`s, `1`s, and `2`s, insertion sort doesn’t leverage this information — it treats it like any general unsorted list.

> "While this code solves the problem, it's not optimal for this specific scenario. Since the array only contains three unique elements, we can use the **Dutch National Flag algorithm**, which solves it in one pass with constant space and linear time — O(n). That would be a better fit in practice."

🧠 Time & Space Complexity:

* Time Complexity: 
    * Worst Case: O(n²) - Happens when the array is sorted in reverse order (e.g., all 2s, then 1s, then 0s).
    * Best Case: O(n) - If the array is already sorted, no shifting happens.
    * Average Case: O(n²)
* Space Complexity: O(1) It’s an **in-place** sorting algorithm — it doesn’t use extra memory apart from a few variables.

--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

### 🇳🇱 Dutch National Flag Algorithm — Conceptual Explanation:

We maintain **three pointers**:
1. **`low`**: All elements before this index are 0s (`[0, low-1]`)
2. **`mid`**: Current element under consideration.
3. **`high`**: All elements after this index are 2s (`[high+1, n-1]`)

We traverse the array with the `mid` pointer and perform actions based on the value at `nums[mid]`:

#### 🔁 Algorithm Steps:

* If `nums[mid] == 0`:
  * Swap `nums[low]` and `nums[mid]`
  * Increment both `low` and `mid`
    (Because we’ve put a 0 in its correct place)
* If `nums[mid] == 1`:
  * Just increment `mid`
    (Because 1 is in the middle section, so we leave it)
* If `nums[mid] == 2`:
  * Swap `nums[mid]` and `nums[high]`
  * Decrement `high`
    (But **do not** increment `mid` because the swapped value needs to be checked again)

🧠 Time & Space Complexity:

* Time Complexity: O(n) Every element is processed **at most once**.
* Space Complexity: O(1) It uses only constant extra space (just the 3 pointers).
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach

--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent

--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
 Sorting items into 3 categories like low/med/high, or red/yellow/green flags.


