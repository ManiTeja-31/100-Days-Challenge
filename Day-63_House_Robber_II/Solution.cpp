//Naive or Recrsion (Brute Force)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        return max(house(0,n-2,nums),house(1,n-1,nums));
    }
    int house(int ind,int end,vector<int> &nums){
        if(ind > end){
            return 0;
        }
        int loot = nums[ind] + house(ind+2,end,nums);
        int skip = house(ind+1,end,nums);
        return max(loot,skip);
    }
};

//Recursion with Memoization (Top-Down DP)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        vector<int> memo1(n+1,-1),memo2(n+1,-1);
        int lastExcluded = house(0,n-2,nums,memo1);
        int lastIncluded = house(1,n-1,nums,memo2);
        return max(lastExcluded,lastIncluded);
    }
    int house(int ind,int end,vector<int> &nums,vector<int> &memo){
        if(ind > end){
            return 0;
        }
        if(memo[ind]!=-1){
            return memo[ind];
        }
        int loot = nums[ind] + house(ind+2,end,nums,memo);
        int skip = house(ind+1,end,nums,memo);
        return memo[ind]=max(loot,skip);
    }
};

//Bottom-Up DP (Tabulation)
class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1)return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        return max(house(0,n-2,nums),house(1,n-1,nums));
    }
    int house(int start,int end,vector<int> &nums){
        int n=nums.size();
        vector<int> dp(n,0);
        dp[start]=nums[start];
        dp[start+1]=max(nums[start],nums[start+1]);
        for(int i=start+2;i<=end;i++){
            dp[i]=max(nums[i]+dp[i-2],dp[i-1]);
        }
        return dp[end];
    }
};
