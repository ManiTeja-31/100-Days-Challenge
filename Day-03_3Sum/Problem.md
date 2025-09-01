> [3Sum] - https://leetcode.com/problems/3sum/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

Notice that the solution set must not contain duplicate triplets.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Sorting + Two-pointer
--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

I used a brute-force approach to find all unique triplets in the array that sum to zero.

✅ Step-by-Step Logic:
1. Sort the array to handle duplicates more easily and to ensure consistent triplet ordering.
2. Use three nested loops to try every combination of (i, j, k) where i < j < k.
3. For each triplet:
   * Check if nums[i] + nums[j] + nums[k] == 0.
   * If it is, add the triplet to a set to avoid duplicates.
4. After checking all combinations, convert the set to a vector and return it.

🧪 Why use a set?
* To avoid duplicate triplets like [-1, 0, 1] and [0, -1, 1].
* Sorting the array ensures that all valid triplets are stored in increasing order like [-1, 0, 1], so we can directly use a set of vectors.

🧠 Time & Space Complexity:
* Time Complexity: O(n³) - We check every combination using three loops.
* Space Complexity:	O(k) - Where k is the number of unique triplets stored in the set.
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

We aim to find all **unique triplets** in the array that sum up to zero. Instead of using three nested loops (O(n³)), we **sort the array** and use a **two-pointer technique**, reducing time complexity to **O(n²)**.

✅ Step-by-Step Logic:
1. **Sort the array**
   Sorting helps:
   * Handle duplicates efficiently
   * Use the two-pointer approach (works only on sorted data)
2. **Fix the first element (i)**
   Loop through the array with index `i` from `0` to `n-2`.
3. **Skip duplicate first elements**
   If the current `nums[i]` is the same as the previous one, we skip it to **avoid duplicate triplets**.
4. **Apply Two Pointer Technique**
   * Initialize two pointers:
     `left = i + 1` and `right = n - 1`
   * While `left < right`:
     * Compute the sum: `nums[i] + nums[left] + nums[right]`
     * If the sum is **zero**, we’ve found a triplet:
       * Add it to the result
       * Skip any duplicate `nums[left]` or `nums[right]` to avoid repeating the same triplet
       * Move both pointers inward
     * If the sum is **less than 0**, we move `left` rightward (to increase sum)
     * If the sum is **greater than 0**, we move `right` leftward (to decrease sum)

🧠 Time & Space Complexity:
* Time Complexity: `O(n²)` - Outer loop runs `n` times, inner loop runs at most `n` times per iteration 
* Space Complexity: `O(1)` auxiliary (result space not counted as extra space)                           

🔍 Why It Works:
* Sorting ensures we can use the **two-pointer** strategy effectively.
* By **skipping duplicates**, we avoid storing the same triplet more than once.
* Much faster and cleaner than brute-force, especially for large arrays.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach

18. 4Sum - https://leetcode.com/problems/4sum/description/
Ksum - https://medium.com/@dipayansanyal/ksum-summing-of-k-values-to-reach-a-target-d225b2f06c8d
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent

Three Numbers - https://www.codechef.com/practice/course/3-star-difficulty-problems/DIFF1700/problems/THREENUMBERS
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Detecting 3-party reconciliations (e.g., where 3 numbers must sum to zero in accounting or game balancing).