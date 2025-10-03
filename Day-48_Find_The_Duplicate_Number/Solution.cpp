//Brute Force Approach
int findDuplicate(vector<int>& nums) {
    int n = nums.size();
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
            if (nums[i] == nums[j])
                return nums[i];
    return -1;
}

//Sorting Approach
int findDuplicate(vector<int>& nums) {
    sort(nums.begin(), nums.end()); // ❌ violates constraint
    for (int i = 1; i < nums.size(); ++i)
        if (nums[i] == nums[i - 1])
            return nums[i];
    return -1;
}

//Counting Approach or Hashing Approach or set Approach
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n=nums.size();
        vector<int> dummy(n,0);
        for(int i=0;i<n;i++){
            if(dummy[nums[i]]>0){
                return nums[i];
            }
            dummy[nums[i]]++;
        }
        return n;
    }
};

//Floyd's Tortoise and Hare (Cycle Detection) — Optimal Approach
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        if (n > 1) {
            int slow = nums[0], fast = nums[nums[0]];
            while (fast != slow) {
                fast = nums[nums[fast]];
                slow = nums[slow];
            }
            fast = 0;
            while (fast != slow) {
                fast = nums[fast];
                slow = nums[slow];
            }
            return slow;
        }
        return -1;
    }
};

//Binary Search on Value Range - Optimal Approach
int findDuplicate(vector<int>& nums) {
    int left = 1, right = nums.size() - 1;

    while (left < right) {
        int mid = (left + right) / 2;
        int count = 0;
        
        for (int num : nums)
            if (num <= mid)
                ++count;

        if (count > mid)
            right = mid;
        else
            left = mid + 1;
    }

    return left;
}
