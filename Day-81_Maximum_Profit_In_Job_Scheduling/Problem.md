> [Maximum Profit In Job scheduling] - https://leetcode.com/problems/maximum-profit-in-job-scheduling/
> Level - Hard
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

We have n jobs, where every job is scheduled to be done from startTime[i] to endTime[i], obtaining a profit of profit[i].

You're given the startTime, endTime and profit arrays, return the maximum profit you can take such that there are no two jobs in the subset with overlapping time range.

If you choose a job that ends at time X you will be able to start another job that starts at time X.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> DP + Binary Search (Weighted Interval Scheduling) 
--------------------------------------------------------------------------------------------------------------------------------------
## 🧩 Problem Intuition

You are given:

* `startTime[i]` → when the i-th job starts
* `endTime[i]` → when the i-th job ends
* `profit[i]` → profit you earn if you do this job

You must select **non-overlapping jobs** such that **total profit is maximized**.

Think of it like this:

* Each job is an “interval” with a profit.
* You can’t take overlapping intervals.
* You want to pick the most profitable combination.

---

## 🔹 Step 1: Recursive Approach (Brute Force Backtracking)

### Intuition

This is the most direct (but inefficient) way to solve the problem.

At each job, you have **two choices**:

1. **Pick** the current job (if it doesn’t overlap with the previous chosen job)
2. **Skip** the current job

We recursively explore both possibilities and take the maximum.

It’s basically a **decision tree**:

* Each node = one job.
* Two branches = pick or skip.

### Steps

1. Sort jobs by start time (so we can easily compare future jobs).
2. Start recursion from index `0`.
3. If the previous job’s end time ≤ current job’s start time, you can pick it.
4. Otherwise, skip it.
5. Return the maximum of “pick” and “skip”.

### Time Complexity

* ( O(2^N) ) → because each job can either be picked or skipped.

### Space Complexity

* ( O(N) ) → recursion stack.

---

## 🔹 Step 2: Brute Force with “next()” Function

### Intuition

In the previous method, every time we “pick” a job, we continue checking all next jobs one by one.
Here, we explicitly find the **next non-overlapping job** using a helper function `next()`.

This slightly optimizes the recursive traversal but still explores all possibilities.

### Steps

1. Sort jobs by start time.
2. For each job at index `i`:

   * Find the next index `j` such that `job[j].start >= job[i].end`.
3. Recursively compute:

   * `pick = profit[i] + schedule(nextInd)`
   * `skip = schedule(i + 1)`
4. Take `max(pick, skip)`.

### Time Complexity

* ( O(N^2) ): For every job, the `next()` search may take ( O(N) ), and recursion explores up to ( N ) states.

### Space Complexity

* ( O(N) ): Recursion depth.

---

## 🔹 Step 3: Top-Down DP with Memoization

### Intuition

In the brute-force recursive version, we compute the same results multiple times.
So we use a **DP array (memoization)** to store the result of each state `ind`.

Now each subproblem (starting from index `ind`) is computed only **once**.

### Steps

1. Sort jobs by start time.
2. Define a memo array initialized with `-1`.
3. When you calculate `schedule(ind)`, store the result in `memo[ind]`.
4. If it’s already calculated, return from `memo`.

### Time Complexity

* ( O(N^2) ): because each job calls `next()` which still takes ( O(N) ).

### Space Complexity

* ( O(N) ): for the `memo` array and recursion stack.

---

## 🔹 Step 4: Top-Down DP with Binary Search

### Intuition

We can improve the `next()` search using **binary search**.

Since jobs are sorted by start time, we can efficiently find the next job whose start time ≥ current job’s end time in ( O(\log N) ).

This drastically improves performance.

### Steps

1. Sort jobs by start time.
2. Use binary search to find the next job index (`nextInd`).
3. Use memoization to store results.
4. Compute:

   * `pick = profit[i] + schedule(nextInd)`
   * `skip = schedule(i + 1)`
5. Return `max(pick, skip)`.

### Time Complexity

* ( O(N \log N) ): Each job does a binary search once.

### Space Complexity

* ( O(N) ): Memoization + recursion stack.

---

## 🔹 Step 5: Bottom-Up DP with Binary Search

### Intuition

Instead of recursion, we can iteratively fill a DP table.

Here we sort jobs by **end time** instead of start time — this way, when we process job `i`, all possible non-overlapping jobs come before it.

We build up our result like this:

* `dp[i]` = maximum profit including jobs up to index `i`.

For each job `i`:

1. **Include** the job’s profit + best profit of last non-overlapping job.
2. **Exclude** it (take `dp[i-1]`).
3. `dp[i] = max(include, exclude)`.

We find the last non-overlapping job using **binary search** on end times.

### Steps

1. Sort jobs by end time.
2. Initialize `dp[0] = profit[0]`.
3. For each job `i` from `1` to `n-1`:

   * Binary search for last job `j` with `end[j] ≤ start[i]`.
   * `include = profit[i] + dp[j]` (if exists)
   * `dp[i] = max(include, dp[i-1])`.
4. Return `dp[n-1]`.

### Time Complexity

* ( O(N \log N) ):

  * Sorting → ( O(N \log N) )
  * Each iteration’s binary search → ( O(\log N) )

### Space Complexity

* ( O(N) ): DP array.

---

## 🧠 Summary of All Approaches

| Approach                     | Technique                   | Time Complexity | Space Complexity | Notes                                 |
| ---------------------------- | --------------------------- | --------------- | ---------------- | ------------------------------------- |
| Recursive                    | Plain recursion             | (O(2^N))        | (O(N))           | Exponential, explores all paths       |
| Brute Force + next()         | Sequential next search      | (O(N^2))        | (O(N))           | Slightly better but still inefficient |
| Top-Down DP                  | Memoization                 | (O(N^2))        | (O(N))           | Avoids recomputation                  |
| Top-Down DP + Binary Search  | Memoization + Binary Search | (O(N \log N))   | (O(N))           | Efficient and clean                   |
| Bottom-Up DP + Binary Search | Iterative DP                | (O(N \log N))   | (O(N))           | Most optimized and widely used        |

---

## 🚀 Final Intuition Recap

* Start simple: recursion → explore all.
* Then avoid repeating work → memoization.
* Then optimize the next job lookup → binary search.
* Finally, convert recursion to iteration → bottom-up DP.

The **bottom-up binary search DP** is the most efficient and elegant — it’s the one usually expected in interviews.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
2008. Maximum Earnings From Taxi - https://leetcode.com/problems/maximum-earnings-from-taxi/description/
2054. Two Best Non-Overlapping Events - https://leetcode.com/problems/two-best-non-overlapping-events/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Scheduling jobs with profits and deadlines (e.g., assigning delivery orders to maximize tips). 