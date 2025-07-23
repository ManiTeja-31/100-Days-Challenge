> [Two Sum] - https://leetcode.com/problems/two-sum/description/
> Level - Easy
----------------------------------------------------------------
# Problem Statement : 

Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
You may assume that each input would have exactly one solution, and you may not use the same element twice.
You can return the answer in any order.
---------------------------------------------------------------------------------------------------------------------------------------
# Pattern

> Hashmap + Array
---------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

The idea is very straightforward — we check every possible pair of elements in the array and see if their sum equals the given target.

> ✅ Step-by-Step Logic:
I use two nested loops:
1. The outer loop picks the first element (index i).
2. The inner loop picks the second element (index j > i) to avoid repeating the same pair.
   * For every pair (i, j), I check whether nums[i] + nums[j] == target.
   * If it is, I store i and j in the result vector.
3. Finally, I return the result.

> 🧠 Time & Space Complexity:
* Time Complexity: O(n²) - Because we check every pair in the array.
* Space Complexity: O(1) auxiliary (excluding the result) - Only a result vector is used for output.

---------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

The problem requires us to find two indices `i` and `j` in the array such that `nums[i] + nums[j] == target`. The key requirement is to return the indices, not the values, and each number can only be used once.

To solve this efficiently, I used a **hash map** (`unordered_map`) to store numbers we've already seen, along with their indices. The idea is to check, for every element `nums[i]`, whether the **complement** — that is, `target - nums[i]` — already exists in the map.

> 🧠 Why This Works:
If it does exist, then we've already seen a number that, when added to the current one, gives the target sum — and we immediately return the two indices.

> ✅ Step-by-step:
1. Initialize an empty hash map to store `{value: index}` pairs.
2. Iterate through the array once:
   * For each `nums[i]`, calculate the complement: `target - nums[i]`.
   * If the complement exists in the hash map, return its index and the current index.
   * If not, store `nums[i]` in the map along with its index.

> 🕒 Time and Space Complexity:
* **Time Complexity:** O(n), because we make a single pass through the array.
* **Space Complexity:** O(n), for storing elements in the hash map.

> 🔁 Example Dry Run:
Suppose `nums = [2, 7, 11, 15]` and `target = 9`:

* At `i = 0`, `nums[i] = 2`, complement is `7`. Not in map. Store `{2: 0}`.
* At `i = 1`, `nums[i] = 7`, complement is `2`. Found in map at index 0.
* So, return `[0, 1]`.

> 🚀 Why It's Optimal:
Compared to a brute-force approach which is O(n²), this method reduces it to linear time using extra space. It’s an excellent example of using a hash map to trade space for time.

---------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach

15. 3Sum -  https://leetcode.com/problems/3sum/description/
560. Subarray Sum Equals K - https://leetcode.com/problems/subarray-sum-equals-k/description/
---------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent

https://www.codechef.com/problems/TARGET
> Status: Pending
---------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use

 Detecting two financial transactions that offset each other, or matching complementary orders in a trading system.
