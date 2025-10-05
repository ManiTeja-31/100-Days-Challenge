//Naive or Recrsion (Brute Force)
class Solution {
public:
    int rob(vector<int>& nums) {
        return house(0,nums);
    }
    int house(int ind,vector<int> &nums){
        if(ind>=nums.size()){
            return 0;
        }
        int skip = house(ind+1,nums);
        int loot = nums[ind]+house(ind+2,nums);
        return max(skip,loot);
    }
};

//Recursion with Memoization (Top-Down DP)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        vector<int> memo(n+1,-1);
        return house(0,nums,memo);
    }
    int house(int ind,vector<int> &nums,vector<int> &memo){
        if(ind>=nums.size()){
            return 0;
        }
        if(memo[ind]!=-1){
            return memo[ind];
        }
        int skip = house(ind+1,nums,memo);
        int loot = nums[ind]+house(ind+2,nums,memo);
        return memo[ind] = max(skip,loot);
    }
};

//Bottom-Up DP (Tabulation)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        vector<int> dp(n+1,0);
        dp[0]=nums[0];
        dp[1]=max(nums[0], nums[1]);
        for(int i=2;i<n;i++){
            dp[i] = max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[n-1];
    }
};

//Bottom-Up DP (Tabulation) - Space Optimized
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        int prev2=nums[0];
        int prev1=max(nums[0], nums[1]);
        for(int i=2;i<n;i++){
            int curr = max(nums[i]+prev2,prev1);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};