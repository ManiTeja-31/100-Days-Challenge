> [355. Design Twitter] - https://leetcode.com/problems/design-twitter/description/
> Level - Medium
--------------------------------------------------------------------------------------------------------------------------------------
# Problem Statement : 

Design a simplified version of Twitter where users can post tweets, follow/unfollow another user, and is able to see the 10 most recent tweets in the user's news feed.

Implement the Twitter class:

Twitter() Initializes your twitter object.
void postTweet(int userId, int tweetId) Composes a new tweet with ID tweetId by the user userId. Each call to this function will be made with a unique tweetId.
List<Integer> getNewsFeed(int userId) Retrieves the 10 most recent tweet IDs in the user's news feed. Each item in the news feed must be posted by users who the user followed or by the user themself. Tweets must be ordered from most recent to least recent.
void follow(int followerId, int followeeId) The user with ID followerId started following the user with ID followeeId.
void unfollow(int followerId, int followeeId) The user with ID followerId started unfollowing the user with ID followeeId.
--------------------------------------------------------------------------------------------------------------------------------------
# Pattern
> Design / Heap + HashMap
--------------------------------------------------------------------------------------------------------------------------------------
# 🐦 Twitter Design — Implementation Approaches

The goal is to implement a simplified Twitter with:

1. `postTweet(userId, tweetId)` — user posts a tweet.
2. `getNewsFeed(userId)` — returns **10 most recent tweets** from the user and their followees.
3. `follow(followerId, followeeId)` — follow a user.
4. `unfollow(followerId, followeeId)` — unfollow a user.

---

## 1️⃣ Naive / Brute Force Approach

### **Idea**

* Store **all tweets in a global list**.
* To get a news feed, **scan all tweets** and collect those from the user and their followees.

```cpp
vector<pair<int,int>> tweets; // {userId, tweetId}
unordered_map<int, unordered_set<int>> followees;
```

* `postTweet` → append to global tweets list.
* `getNewsFeed` → iterate all tweets in reverse, pick tweets of followees, take top 10.

### **Pros**

* Simple and easy to implement.

### **Cons**

* `getNewsFeed` is **O(totalTweets)** — inefficient if there are millions of tweets.
* Memory is fine, but performance is bad.

---

## 2️⃣ Store Tweets Per User

### **Idea**

* Store each user’s tweets in a separate list.
* Maintain `timeStamp` for ordering.

```cpp
unordered_map<int, vector<pair<long long,int>>> tweets; // userId -> [(time, tweetId)]
unordered_map<int, unordered_set<int>> friends;         // follower -> followees
```

* `getNewsFeed`:

  * Merge own tweets and followees’ tweets.
  * Sort merged list by timestamp descending.
  * Take top 10.

### **Pros**

* Only merge relevant tweets → faster than scanning all tweets.
* Supports multiple users efficiently.

### **Cons**

* Sorting merged tweets every time → **O(n log n)**, where n = total tweets from user + followees.
* Still not optimal for many followees with many tweets.

---

## 3️⃣ Per User Tweets + Min-Heap

### **Idea**

* Use **min-heap of size 10** to keep only the **top 10 latest tweets** while merging.

```cpp
priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> minHeap;
```

* For each followee’s tweet:

  * Push to heap.
  * If heap size > 10 → pop the smallest timestamp.
* At the end → heap contains 10 most recent tweets.

### **Pros**

* No full sort required.
* `getNewsFeed` → O(k log 10) per tweet of followees (`k` = total tweets of followees).

### **Cons**

* Still iterate all tweets of all followees.
* Good improvement if each user has many tweets.

---

## 4️⃣ Merge K Sorted Lists (Optimized)

### **Idea**

* Treat each user’s tweet list as a **sorted list by time**.
* Use **max-heap** to merge the latest tweets efficiently (like merging k sorted lists).

```cpp
struct Tweet {
    long long time;
    int tweetId;
    int userId;
    int index; // index in user's tweet list
    bool operator<(const Tweet& other) const {
        return time < other.time; // max-heap
    }
};
```

* Steps:

  1. Push **latest tweet** from each followee into a max-heap.
  2. Pop the heap → get the latest tweet.
  3. Push the next latest tweet from the same user.
  4. Repeat until 10 tweets collected.

### **Pros**

* Only process tweets needed for top 10 → **O(10 log k)**, k = number of followees.
* Efficient for large-scale systems.

### **Cons**

* Slightly more complex to implement.
* Needs careful handling of indices in user tweet lists.

---

## ⚡ Summary Table

| Approach             | Data Structure                    | Time Complexity | Pros                     | Cons                         |
| -------------------- | --------------------------------- | --------------- | ------------------------ | ---------------------------- |
| Naive                | Global tweets list                | O(totalTweets)  | Simple                   | Slow for large data          |
| Per User             | tweets per user, merge & sort     | O(n log n)      | Faster than naive        | Sorting overhead             |
| Min-Heap             | tweets per user, min-heap size 10 | O(k log 10)     | Keeps top 10 efficiently | Iterates all followee tweets |
| Merge K Sorted Lists | max-heap                          | O(10 log k)     | Optimal for top 10 feed  | Slightly complex             |

---

### ✅ Key Design Insights

1. **Store per-user tweets** → avoids scanning irrelevant data.
2. **Use timestamps** → ensures correct ordering.
3. **Use heap for top-k** → prevents full sort, reduces processing time.
4. **Merge K sorted lists** → best solution for real Twitter-scale feeds.
5. Always **follow self** for easy inclusion of own tweets.

--------------------------------------------------------------------------------------------------------------------------------------
# Other Problems Using this Approach
460. LFU Cache - https://leetcode.com/problems/lfu-cache/description/
146. LRU Cache - https://leetcode.com/problems/lru-cache/description/
588. Design In-Memory File System - https://leetcode.com/problems/design-in-memory-file-system/description/
--------------------------------------------------------------------------------------------------------------------------------------
# CodeChef Equivalent
NA
--------------------------------------------------------------------------------------------------------------------------------------
# Real-World Use
Social media backend design, feed generators.