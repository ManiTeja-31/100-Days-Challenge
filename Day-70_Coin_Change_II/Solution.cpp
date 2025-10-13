//Recursive Approach
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        return coinCount(0,amount,coins);
    }
    int coinCount(int ind,int currAmount,vector<int> &coins){
        if(currAmount==0){
            return 1;
        }
        if(ind>=coins.size() || currAmount<0){
            return 0;
        }
        int pick =  coinCount(ind,currAmount-coins[ind],coins);
        int notPick = coinCount(ind+1,currAmount,coins);
        return pick+notPick;
    }
};

//Top-Down DP with Memoization
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>> memo(n,vector<int> (amount+1,-1));
        return coinCount(0,amount,coins,memo);
    }
    int coinCount(int ind,int currAmount,vector<int> &coins,vector<vector<int>> &memo){
        if(currAmount==0){
            return 1;
        }
        if(ind>=coins.size() || currAmount<0){
            return 0;
        }
        if(memo[ind][currAmount]!=-1){
            return memo[ind][currAmount];
        }
        int pick =  coinCount(ind,currAmount-coins[ind],coins,memo);
        int notPick = coinCount(ind+1,currAmount,coins,memo);
        return memo[ind][currAmount] = pick+notPick;
    }
};

//Bottom-Up DP with Tabulation
class Solution {
public:
    const int MOD = 1e9 + 7;
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<long long> dp(amount + 1, 0);  // Use long long to prevent overflow
        dp[0] = 1;

        for (int j = 0; j < n; j++) {
            for (int i = coins[j]; i <= amount; i++) {
                dp[i] += dp[i - coins[j]] ;
            }
        }

        return dp[amount];
    }
};

