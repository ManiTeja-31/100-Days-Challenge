> [Fruits Into Basket] - https://leetcode.com/problems/fruit-into-baskets/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.

You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:

- You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
- Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
- Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
- Given the integer array fruits, return the maximum number of fruits you can pick.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Sliding Window + Hashmap
--------------------------------------------------------------------------------------------------------------------------------------
# PsuedoCode

Initialize left pointer to 0
Initialize maxFruits to 0
Create an empty map (basket) to track fruit types and their counts

For right pointer from 0 to end of fruits array:
    Add the current fruit to the basket (increase its count)

    While the basket has more than 2 types of fruits:
        Decrease count of fruit at the left pointer in the basket
        If count becomes 0:
            Remove that fruit type from the basket
        Move the left pointer to the right (left += 1)

    Update maxFruits as the maximum of current maxFruits and
        (right - left + 1)

Return maxFruits
--------------------------------------------------------------------------------------------------------------------------------------
# Brute Force Approach

### Steps:

1. Iterate over each index `i` as the starting point.
2. For every `i`, maintain a set (`basket`) to track fruit types.
3. Extend the subarray by moving `j` from `i` to `n-1`.
4. Add `fruits[j]` to `basket`.
5. If the basket has more than 2 types → stop expanding.
6. Keep track of the longest valid window length.
7. Return the maximum length found.

### Complexity:

* **Time:** `O(n²)` (For every starting index `i`, you may check all `j` up to `n`).
* **Space:** `O(1)` or `O(2)` → at most 2 fruit types in the set (constant).
--------------------------------------------------------------------------------------------------------------------------------------
# Optimized Approach

## **(Sliding Window + HashMap)**

### Steps:

1. Use two pointers `left` and `right` to define a window.
2. Use a hashmap to store `{fruitType → lastSeenIndex}`.
3. Expand `right` each time by adding the fruit.
4. If a **third type** appears:

   * Find the fruit with the **smallest index** in the map.
   * Remove it from the map.
   * Move `left` to just after that index (ensures only 2 types remain).
5. Update the maximum window length.
6. Continue until `right` reaches the end.

### Complexity:

* **Time:** `O(n)` (each fruit enters and leaves the window at most once).
* **Space:** `O(2)` → hashmap stores at most 2 fruit types.

---

## **Further Optimized (Two Basket Variables)**

### Steps:

1. Maintain **two baskets** (`basket1` & `basket2`) as `{fruitType, count}`.
2. Expand `right`:

   * If the fruit matches one of the baskets → increase its count.
   * If a basket is empty → assign this fruit to it.
   * If a **third type** comes:

     * Drop the basket with the **smaller count** (since it limits window).
     * Move `left` forward by that count (effectively removing that fruit).
     * Replace that basket with the new fruit.
3. Update maximum window length.
4. Continue until all fruits are processed.

### Complexity:

* **Time:** `O(n)` (each fruit processed once).
* **Space:** `O(1)` (just two baskets).

---

✅ Summary Table:

| Approach                 | Time Complexity | Space Complexity  |
| ------------------------ | --------------- | ----------------- |
| Brute Force              | `O(n²)`         | `O(1)`            |
| Sliding Window + HashMap | `O(n)`          | `O(2)` → constant |
| Two Basket Variables     | `O(n)`          | `O(1)`            |
--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
2401. Longest Nice Subarray - https://leetcode.com/problems/longest-nice-subarray/description/
340. Longest Substring with At Most K Distinct Characters- https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Maximum length of subarray with 2 distinct elements (e.g., memory usage types
