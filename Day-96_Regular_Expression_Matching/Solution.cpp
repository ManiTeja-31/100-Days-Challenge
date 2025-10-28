//Naive Or Recursive Approach
class Solution {
public:
    bool isMatch(string s, string p) {
        return match(s, p, 0, 0);
    }

    bool match(const string &s, const string &p, int i, int j) {
        if (j == p.size()) return i == s.size();

        bool first_match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));

        if (j+1 < p.size() && p[j+1] == '*') {
            // zero occurrence OR one/more occurrence
            return match(s, p, i, j+2) || (first_match && match(s, p, i+1, j));
        } else {
            return first_match && match(s, p, i+1, j+1);
        }
    }
};

//Top-Down DP with Memoization
class Solution {
public:
    bool isMatch(string s, string p) {
        int m=s.size(),n=p.size();
        vector<vector<int>> memo(m+1,vector<int> (n+1,-1));
        return match(s, p, 0, 0,memo);
    }

    bool match(const string &s, const string &p, int i, int j,vector<vector<int>> &memo) {
        if (j == p.size()) return i == s.size();
        if(memo[i][j]!=-1){
            return memo[i][j];
        }
        bool first_match = (i < s.size() && (s[i] == p[j] || p[j] == '.'));
        bool ans;
        if (j+1 < p.size() && p[j+1] == '*') {
            // zero occurrence OR one/more occurrence
            ans = match(s, p, i, j+2,memo) || (first_match && match(s, p, i+1, j,memo));
        } else {
            ans = first_match && match(s, p, i+1, j+1,memo);
        }
        return memo[i][j] = ans;
    }
};


//Bottom-Up DP Approach
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));
        dp[m][n] = true; // empty string matches empty pattern

        for (int i = m; i >= 0; i--) {
            for (int j = n-1; j >= 0; j--) {
                bool first_match = (i < m && (s[i] == p[j] || p[j] == '.'));
                if (j+1 < n && p[j+1] == '*') {
                    dp[i][j] = dp[i][j+2] || (first_match && dp[i+1][j]);
                } else {
                    dp[i][j] = first_match && dp[i+1][j+1];
                }
            }
        }

        return dp[0][0];
    }
};

//Space Optimized Bottom-Up DP Approach
class Solution {
public:
    bool isMatch(string s, string p) {
        int m = s.size(), n = p.size();
        vector<bool> dp_next(n+1, false), dp_curr(n+1, false);

        dp_next[n] = true; // empty string matches empty pattern

        for (int i = m; i >= 0; i--) {
            dp_curr[n] = (i == m); // empty pattern
            for (int j = n-1; j >= 0; j--) {
                bool first_match = (i < m && (s[i] == p[j] || p[j] == '.'));

                if (j+1 < n && p[j+1] == '*') {
                    dp_curr[j] = dp_curr[j+2] || (first_match && dp_next[j]);
                } else {
                    dp_curr[j] = first_match && dp_next[j+1];
                }
            }
            dp_next = dp_curr; // move current row to next
        }

        return dp_curr[0];
    }
};

