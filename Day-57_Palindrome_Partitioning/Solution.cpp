//Naive Or Recursive Backtracking Approach
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<string>> partition(string s) {
        backTrack(0,s);
        return res;
    }
    void backTrack(int ind,string s){
        if(ind==s.size()){
            res.push_back(path);
            return;
        }

        for(int end=ind;end<s.size();end++){
            if(isPalindrome(ind,end,s)){
                path.push_back(s.substr(ind,end-ind+1));
                backTrack(end+1,s);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(int start,int end,string s){
        while(start<end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
};

//Top-Down DP with Memoization
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<int>> memo;
    vector<vector<string>> partition(string s) {
        int n=s.size();
        memo = vector<vector<int>> (n,vector<int> (n,-1));
        backTrack(0,s);
        return res;
    }
    void backTrack(int ind,string s){
        if(ind==s.size()){
            res.push_back(path);
            return;
        }

        for(int end=ind;end<s.size();end++){
            if(isPalindrome(ind,end,s)){
                path.push_back(s.substr(ind,end-ind+1));
                backTrack(end+1,s);
                path.pop_back();
            }
        }
    }
    bool isPalindrome(int start,int end,string s){
        if(memo[start][end]!=-1){
            return memo[start][end];
        }
        int l=start,r=end;
        while(l<r){
            if(s[l++]!=s[r--]){
                return memo[start][end] = false;
            }
        }
        return memo[start][end] = true;
    }
};

//Bottom-Up DP with Tabulation
class Solution {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Precompute palindrome substrings
        for (int len = 1; len <= n; ++len) {
            for (int i = 0; i + len - 1 < n; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len <= 2 || dp[i + 1][j - 1]))
                    dp[i][j] = true;
            }
        }

        vector<vector<string>> result;
        vector<string> current;
        backtrack(0, s, dp, current, result);
        return result;
    }
    void backtrack(int start, string& s, vector<vector<bool>>& dp,
                   vector<string>& current, vector<vector<string>>& result) {
        if (start == s.size()) {
            result.push_back(current);
            return;
        }

        for (int end = start; end < s.size(); ++end) {
            if (dp[start][end]) {
                current.push_back(s.substr(start, end - start + 1));
                backtrack(end + 1, s, dp, current, result);
                current.pop_back();
            }
        }
    }
};