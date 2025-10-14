//Recursive Approach
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int longest = 0;
        return LCS(0,0,text1,text2);
    }
    int LCS(int i,int j,string t1,string t2){
        if(i>=t1.size() || j>=t2.size()){
            return 0;
        }
        if(t1[i]==t2[j]){
            return 1+LCS(i+1,j+1,t1,t2);
        }else{
            return max(LCS(i+1,j,t1,t2),LCS(i,j+1,t1,t2));
        }
    }
};

//Top-Down DP with Memoization
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>> memo(m,vector<int> (n,-1));
        return LCS(0,0,text1,text2,memo);
    }
    int LCS(int i,int j,string &t1,string &t2,vector<vector<int>> &memo){
        if(i>=t1.size() || j>=t2.size()){
            return 0;
        }
        if(memo[i][j]!=-1){
           return memo[i][j];
        }
        if(t1[i]==t2[j]){
            return memo[i][j] = 1+LCS(i+1,j+1,t1,t2,memo);
        }else{
            return memo[i][j] = max(LCS(i+1,j,t1,t2,memo),LCS(i,j+1,t1,t2,memo));
        }
    }
};

//Bottom-Up DP with Tabulation
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m=text1.size(),n=text2.size();
        vector<vector<int>> dp(m+1,vector<int> (n+1,0));
        for(int i=m-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(text1[i]==text2[j]){
                    dp[i][j] = 1+dp[i+1][j+1];
                }else{
                    dp[i][j] = max(dp[i+1][j],dp[i][j+1]);
                }
            }
        }
        return dp[0][0];
    }
    
};

//Space Optimized Bottom-Up DP
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size(), m = text2.size();
        vector<int> next(m + 1, 0), curr(m + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (text1[i] == text2[j]) {
                    curr[j] = 1 + next[j + 1];
                } else {
                    curr[j] = max(next[j], curr[j + 1]);
                }
            }
            next = curr;
        }

        return next[0];
    }
};
