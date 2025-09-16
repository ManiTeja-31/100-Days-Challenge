// Brute Force Approach
class SolutionBruteForce {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        for (int i = 0; i <= n - k; ++i) {
            int mx = nums[i];
            for (int j = i; j < i + k; ++j) {
                mx = max(mx, nums[j]);
            }
            res.push_back(mx);
        }
        return res;
    }
};

// Optimized Approach using Deque
class SolutionDeque {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        deque<int> dq;
        for (int i = 0; i < n; i++) {
            while (!dq.empty() && nums[dq.back()] <= nums[i]) {
                dq.pop_back();
            }
            if (!dq.empty() && dq.front() < i - k + 1) {
                dq.pop_front();
            }
            dq.push_back(i);
            if (i >= k - 1) {
                res.push_back(nums[dq.front()]);
            }
        }
        return res;
    }
};

// Optimized Approach using Priority Queue (Max Heap)
class SolutionHeap {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        priority_queue<pair<int, int>> pq; // {num, index}
        for (int i = 0; i < n; ++i) {
            pq.push({nums[i], i});
            if (i >= k - 1) {
                while (pq.top().second <= i - k) {
                    pq.pop();
                }
                res.push_back(pq.top().first);
            }
        }
        return res;
    }
};