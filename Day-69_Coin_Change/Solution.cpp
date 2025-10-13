//Top-Down DP with Memoization
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>> memo(n,vector<int> (amount+1,-1));
        int res=coinCount(0,0,coins,amount,memo);
        return res==INT_MAX?-1:res;
    }
    int coinCount(int ind,int count,vector<int> &coins,int amount,vector<vector<int>> &memo){
        if(amount==0){
            return 0;
        }
        if(ind >= coins.size() || amount<0){
            return INT_MAX;
        }
        if(memo[ind][amount]!=-1){
            return memo[ind][amount];
        }
        int next=coinCount(ind,count+1,coins,amount-coins[ind],memo);
        int pick = next==INT_MAX?next:1+next;
        int notpick = coinCount(ind+1,count,coins,amount,memo);
        return memo[ind][amount] = min(pick,notpick);
    }
};

//Top-Down DP with Memoization alternative
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> memo(amount + 1, -2); // -2 = not computed
        int res = dp(coins, amount, memo);
        return res == INT_MAX ? -1 : res;
    }

    int dp(vector<int>& coins, int rem, vector<int>& memo) {
        if (rem < 0) return INT_MAX;
        if (rem == 0) return 0;
        if (memo[rem] != -2) return memo[rem];

        int minCoins = INT_MAX;
        for (int coin : coins) {
            int res = dp(coins, rem - coin, memo);
            if (res != INT_MAX)
                minCoins = min(minCoins, res + 1);
        }

        memo[rem] = minCoins;
        return minCoins;
    }
};

//Bottom-Up DP with Tabulation
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<int> dp(amount+1,amount+1);
        dp[0] = 0;
        for(int i=1;i<=amount;i++){
            for(int j=0;j<n;j++){
                if(i>=coins[j]){
                    dp[i] = min(dp[i],dp[i-coins[j]]+1);
                }
            }
            
        }
        return dp[amount]==amount+1?-1:dp[amount];
    }
    
};

//BFS Approach
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        queue<int> q;
        vector<bool> visited(amount + 1, false);
        q.push(amount);
        visited[amount] = true;

        int steps = 0;

        while (!q.empty()) {
            int size = q.size();
            steps++;
            while (size--) {
                int curr = q.front(); q.pop();
                for (int coin : coins) {
                    int next = curr - coin;
                    if (next == 0) return steps;
                    if (next > 0 && !visited[next]) {
                        visited[next] = true;
                        q.push(next);
                    }
                }
            }
        }

        return -1;
    }
};
