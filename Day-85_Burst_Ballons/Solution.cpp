//Brute Force Approach
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        return burst(0,n+1,nums);
    }
    int burst(int left,int right,vector<int> &nums){
        if(right-left==1){
            return 0;
        }
        int ans=0;
        for(int i=left+1;i<right;i++){
            int coins = nums[left]*nums[i]*nums[right];
            coins+=burst(left,i,nums)+burst(i,right,nums);
            ans = max(ans,coins);
        }
        return ans;
    }
};

//Top-Down DP with Memoization
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n=nums.size();
        nums.insert(nums.begin(),1);
        nums.push_back(1);
        vector<vector<int>> memo(n+2,vector<int> (n+2,-1));
        return burst(0,n+1,nums,memo);
    }
    int burst(int left,int right,vector<int> &nums,vector<vector<int>> &memo){
        if(right-left==1){
            return 0;
        }
        if(memo[left][right]!=-1){
            return memo[left][right];
        }
        int ans=0;
        for(int i=left+1;i<right;i++){
            int coins = nums[left]*nums[i]*nums[right];
            coins+=burst(left,i,nums,memo)+burst(i,right,nums,memo);
            ans = max(ans,coins);
        }
        return memo[left][right] = ans;
    }
};

//Bottom-Up DP Approach
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        nums.insert(nums.begin(), 1);
        nums.push_back(1);

        vector<vector<int>> dp(n+2, vector<int>(n+2, 0));

        for (int len = 2; len <= n+1; len++) {
            for (int left = 0; left + len <= n+1; left++) {
                int right = left + len;
                for (int i = left + 1; i < right; i++) {
                    dp[left][right] = max(dp[left][right],
                        nums[left]*nums[i]*nums[right] + dp[left][i] + dp[i][right]);
                }
            }
        }
        return dp[0][n+1];
    }
};
