//Sorting Approach
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end(), greater<int>());
    return nums[k - 1];
}
};

//Using Max Heap (Priority Queue)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int> pq;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        for(int i=0;i<k-1;i++){
            pq.pop();
        }
        return pq.top();
    }
};

//Using Min Heap of size k (Priority Queue) - Optimal
int findKthLargest(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> minHeap;
    
    for (int num : nums) {
        minHeap.push(num);
        if (minHeap.size() > k)
            minHeap.pop(); // remove smallest
    }

    return minHeap.top();
}

//Using Quick Select - Optimal
int partition(vector<int>& nums, int left, int right) {
    int pivot = nums[right];
    int i = left;

    for (int j = left; j < right; ++j) {
        if (nums[j] >= pivot) {
            swap(nums[i], nums[j]);
            ++i;
        }
    }

    swap(nums[i], nums[right]);
    return i;
}

int quickSelect(vector<int>& nums, int left, int right, int k) {
    if (left <= right) {
        int pivotIndex = partition(nums, left, right);

        if (pivotIndex == k)
            return nums[pivotIndex];
        else if (pivotIndex < k)
            return quickSelect(nums, pivotIndex + 1, right, k);
        else
            return quickSelect(nums, left, pivotIndex - 1, k);
    }
    return -1;
}

int findKthLargest(vector<int>& nums, int k) {
    int n = nums.size();
    return quickSelect(nums, 0, n - 1, k - 1);
}

