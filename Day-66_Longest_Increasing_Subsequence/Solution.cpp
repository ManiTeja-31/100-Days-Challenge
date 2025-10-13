//Recursive Approach
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        return LIS(0,-1,nums);
    }
    int LIS(int ind,int prevInd,vector<int> &nums){
        if(ind==nums.size()){
            return 0;
        }
        int notPick = LIS(ind+1,prevInd,nums);
        int pick=0;
        if(prevInd==-1 || nums[ind]>nums[prevInd]){
            pick = 1+LIS(ind+1,ind,nums);
        }
        return max(pick,notPick);
    }
};

//Top-Down DP with Memoization
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> memo(n,vector<int> (n+1,-1));
        return LIS(0,-1,nums,memo);
    }
    int LIS(int ind,int prevInd,vector<int> &nums,vector<vector<int>> &memo){
        if(ind==nums.size()){
            return 0;
        }
        if(memo[ind][prevInd+1]!=-1){
            return memo[ind][prevInd+1];
        }
        int notPick = LIS(ind+1,prevInd,nums,memo);
        int pick=0;
        if(prevInd==-1 || nums[ind]>nums[prevInd]){
            pick = 1+LIS(ind+1,ind,nums,memo);
        }
        return memo[ind][prevInd+1] = max(pick,notPick);
    }
};

//Bottom-Up DP with Tabulation
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int> dp(n,1);
        int lis=1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
            lis=max(lis,dp[i]);
        }
        return lis;
    }
};

//Optimized Bottom-Up DP with Binary Search
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tails;

        for (int num : nums) {
            auto it = lower_bound(tails.begin(), tails.end(), num);
            if (it == tails.end()) {
                tails.push_back(num); // start new LIS
            } else {
                *it = num; // replace with smaller value
            }
        }

        return tails.size();
    }
};