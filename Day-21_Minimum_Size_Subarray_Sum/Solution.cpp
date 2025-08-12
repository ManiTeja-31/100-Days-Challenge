//Brute Force Approach
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int minLen = INT_MAX;
        for(int i=0;i<n;i++){
            int sum=nums[i];
            if(sum>=target)minLen=1;
            for(int j=i+1;j<n;j++){
                sum+=nums[j];
                if(sum>=target){
                    minLen = min(minLen, j-i+1);
                }
            }
        }
        return minLen!=INT_MAX?minLen:0;
    }
};

//Optimized Approach - PrefixSum
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        vector<int> prefixSum(n+1, 0);
        for (int i = 0; i < n; ++i)
            prefixSum[i+1] = prefixSum[i] + nums[i];
        int minLen = INT_MAX;
        for (int i = 1; i <= n; ++i) {
            int need = prefixSum[i] - target;
            auto it = lower_bound(prefixSum.begin(), prefixSum.begin()+i, need);
            if (it != prefixSum.begin()+i)
                minLen = min(minLen, i - (int)(it - prefixSum.begin()));
        }
        return minLen == INT_MAX ? 0 : minLen;
    }
};

//Optimized Approach - Sliding Window
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int minLen = INT_MAX;
        int sum=0,l=0,r=0;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                minLen = min(minLen,r-l+1);
                sum-=nums[l++];
            }
            r++;
        }
        return minLen!=INT_MAX?minLen:0;
    }
};