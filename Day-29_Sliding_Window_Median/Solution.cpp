//Brute Force Approach
vector<double> medianSlidingWindow(vector<int>& nums, int k) {
    vector<double> res;
    for (int i = 0; i + k <= nums.size(); i++) {
        vector<int> window(nums.begin() + i, nums.begin() + i + k);
        sort(window.begin(), window.end());
        if (k % 2 == 1)
            res.push_back(window[k / 2]);
        else
            res.push_back(((double)window[k/2 - 1] + window[k/2]) / 2.0);
    }
    return res;
}

//Sliding Window with Two Heaps
class Solution {
    multiset<int> maxHeap, minHeap; // left (small half), right (large half)
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        for (int i = 0; i < nums.size(); i++) {
            insert(nums[i]);
            
            if (i >= k) remove(nums[i - k]);  // remove the element going out of the window
            
            if (i >= k - 1) res.push_back(median());
        }
        return res;
    }

    void balance() {
        // keep sizes balanced: maxHeap may have 1 more than minHeap
        while (maxHeap.size() > minHeap.size() + 1) {
            minHeap.insert(*maxHeap.rbegin());
            maxHeap.erase(prev(maxHeap.end()));
            //maxHeap.erase(maxHeap.find(*maxHeap.rbegin()));
        }
        while (minHeap.size() > maxHeap.size()) {
            maxHeap.insert(*minHeap.begin());
            minHeap.erase(minHeap.begin());
        }
    }

    void insert(int val) {
        if (maxHeap.empty() || val <= *maxHeap.rbegin())
            maxHeap.insert(val);
        else
            minHeap.insert(val);
        balance();
    }

    void remove(int val) {
        if (maxHeap.find(val) != maxHeap.end())
            maxHeap.erase(maxHeap.find(val));
        else
            minHeap.erase(minHeap.find(val));
        balance();
    }

    double median() {
        if (maxHeap.size() == minHeap.size())
            return ((double)*maxHeap.rbegin() + *minHeap.begin()) / 2.0;
        else
            return *maxHeap.rbegin();
    }
};

//Two Heaps with Lazy Deletion
class Solution {
    priority_queue<int> maxHeap; // left (small half)
    priority_queue<int, vector<int>, greater<int>> minHeap; // right (large half)
    unordered_map<int, int> delayed; // count of elements to be deleted
    int maxHeapSize = 0, minHeapSize = 0; // sizes excluding delayed elements
public:
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        vector<double> res;
        for (int i = 0; i < nums.size(); i++) {
            insert(nums[i]);
            
            if (i >= k) remove(nums[i - k]);  // remove the element going out of the window
            
            if (i >= k - 1) res.push_back(median());
        }
        return res;
    }
    void balance() {
        // keep sizes balanced: maxHeap may have 1 more than minHeap
        if (maxHeapSize > minHeapSize + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
            maxHeapSize--;
            minHeapSize++;
            prune(maxHeap);
        } else if (minHeapSize > maxHeapSize) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
            minHeapSize--;
            maxHeapSize++;
            prune(minHeap);
        }
    }
    void prune(priority_queue<int>& heap) {
        while (!heap.empty()) {
            int num = heap.top();
            if (delayed.count(num)) {
                delayed[num]--;
                if (delayed[num] == 0) delayed.erase(num);
                heap.pop();
            } else {
                break;
            }
        }
    }
    void prune(priority_queue<int, vector<int>, greater<int>>& heap) {
        while (!heap.empty()) {
            int num = heap.top();
            if (delayed.count(num)) {
                delayed[num]--;
                if (delayed[num] == 0) delayed.erase(num);
                heap.pop();
            } else {
                break;
            }
        }
    }
    void insert(int val) {
        if (maxHeap.empty() || val <= maxHeap.top()) {
            maxHeap.push(val);
            maxHeapSize++;
        } else {
            minHeap.push(val);
            minHeapSize++;
        }
        balance();
    }
    void remove(int val) {
        delayed[val]++;
        if (val <= maxHeap.top()) {
            maxHeapSize--;
            if (val == maxHeap.top()) prune(maxHeap);
        } else {
            minHeapSize--;
            if (val == minHeap.top()) prune(minHeap);
        }
        balance();
    }
    double median() {
        if (maxHeapSize == minHeapSize)
            return ((double)maxHeap.top() + minHeap.top()) / 2.0;
        else
            return maxHeap.top();
    }
};

