//Recursion or Brute Force Approach
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int maxLen=0;
        string ans="";
        for(int i=0;i<n;i++){
            string curr="";
            for(int j=i;j<n;j++){
                curr+=s[j];
                if(check(curr) && curr.size()>=maxLen){
                    maxLen=curr.size();
                    ans=curr;
                }
            }
        }
        return ans;
    }
    bool check(string pal){
        int n=pal.size();
        for(int i=0;i<n/2;i++){
            if(pal[i]!=pal[n-i-1]){
                return false;
            }
        }
        return true;
    }
};

//Recursion or Brute Force Approach - Alternative
bool isPalindrome(const string& s, int left, int right) {
    while (left < right) {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}

string longestPalindrome(string s) {
    int n = s.length();
    string res;

    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (isPalindrome(s, i, j) && (j - i + 1 > res.length())) {
                res = s.substr(i, j - i + 1);
            }
        }
    }

    return res;
}

//Expand Around Center - Optimal Approach
class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string res="";
        for(int i=0;i<n;i++){
            string odd = pal(s,i,i);
            string even = pal(s,i,i+1);
            if(odd.size() > res.size()) res=odd;
            if(even.size() > res.size())res=even;
        }
        return res;
    }
    string pal(string s,int left,int right){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
        }
        return s.substr(left+1,right-left-1);
    }
};

//recursion with Memoization (Top-Down DP)
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> memo(n, vector<int>(n, -1)); // -1: uncomputed, 0: false, 1: true
        int maxLen = 0;
        int startIdx = 0;

        for (int i = 0; i < n; ++i) {
            for (int j = i; j < n; ++j) {
                if (isPal(s, i, j, memo)) {
                    int len = j - i + 1;
                    if (len > maxLen) {
                        maxLen = len;
                        startIdx = i;
                    }
                }
            }
        }

        return s.substr(startIdx, maxLen);
    }

    bool isPal(string &s, int i, int j, vector<vector<int>> &memo) {
        if (i >= j) return true;

        if (memo[i][j] != -1)
            return memo[i][j];

        if (s[i] != s[j])
            return memo[i][j] = 0;

        return memo[i][j] = isPal(s, i + 1, j - 1, memo);
    }
};


//Bottom-Up DP Approach
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));
        int start = 0, maxLen = 1;

        for (int i = 0; i < n; ++i)
            dp[i][i] = true;

        for (int len = 2; len <= n; ++len) {
            for (int i = 0; i <= n - len; ++i) {
                int j = i + len - 1;
                if (s[i] == s[j] && (len == 2 || dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    if (len > maxLen) {
                        start = i;
                        maxLen = len;
                    }
                }
            }
        }
        return s.substr(start, maxLen);
    }
};


//Manacher's Algorithm - Optimal O(n) Approach
class Solution {
public:
    string longestPalindrome(string s) {
        string t = "@";
        for (char c : s) {
            t += "#";
            t += c;
        }
        t += "#$";

        int n = t.size();
        vector<int> p(n, 0);
        int center = 0, right = 0;
        int maxLen = 0, centerIndex = 0;

        for (int i = 1; i < n - 1; ++i) {
            int mirror = 2 * center - i;

            if (i < right)
                p[i] = min(right - i, p[mirror]);

            while (t[i + (1 + p[i])] == t[i - (1 + p[i])])
                ++p[i];

            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }

            if (p[i] > maxLen) {
                maxLen = p[i];
                centerIndex = i;
            }
        }

        int start = (centerIndex - maxLen) / 2;
        return s.substr(start, maxLen);
    }
};
