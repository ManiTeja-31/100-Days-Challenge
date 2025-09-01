> [Container With Most Water] - https://leetcode.com/problems/container-with-most-water/description/
> Level - Medium
------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
Find two lines that together with the x-axis form a container, such that the container contains the most water.
Return the maximum amount of water a container can store.

Notice that you may not slant the container.
-------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Two Pointer
-------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

I used a **brute-force approach**. The idea is to try **every possible pair of lines** and calculate the area they can contain.

> ✅ Step-by-Step Logic:
For each pair `(i, j)`:
* The height of the container is the **minimum** of the two lines.
* The width is the **distance between them**, `j - i`.
* So, the area = `min(height[i], height[j]) * (j - i)`.

I use two nested loops to check all pairs and keep track of the **maximum area** found.

> 🧠 Time & Space Complexity:
* Time Complexity: O(n²) - Because we check every pair in the array.
* Space Complexity: O(1) auxiliary

It’s not the most optimal, but it’s simple and works for small inputs.
----------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

This solution uses the **two-pointer approach** to reduce time complexity from `O(n²)` to `O(n)`.

> ✅ Step-by-Step Logic:
We start with two pointers:
* `l` at the beginning, and
* `r` at the end of the array.

At each step:
* We calculate the area using `min(height[l], height[r]) * (r - l)`.
* We update the max area.
* Then we move the pointer pointing to the **shorter line** inward, because moving the taller one won’t help increase the area — only a potentially taller line can.
* If both heights are equal, we move both pointers inward.

This way, we efficiently explore the best possible area in linear time.

> 🧠 Time & Space Complexity:
* Time Complexity: O(n)
* Space Complexity: O(1)

----------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach

42. Trapping Rain Water - https://leetcode.com/problems/trapping-rain-water/description/
84. Largest Rectangle in Histogram - https://leetcode.com/problems/largest-rectangle-in-histogram/
----------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent

Trapping Rainwater - https://www.codechef.com/practice/course/google-interview-questions/GOOGLEPREP/problems/PREP19
Difference Pairs - https://www.codechef.com/practice/course/two-pointers/POINTERF/problems/PREP68
Count Pairs - https://www.codechef.com/practice/course/two-pointers/POINTERF/problems/DSAPROB15
Remove Duplicates - https://www.codechef.com/practice/course/two-pointers/POINTERF/problems/PREP69
----------------------------------------------------------------------------------------------------------------------------------
# Real-World Use

Calculating the most efficient area between two boundaries (e.g., rain collection or tank design).