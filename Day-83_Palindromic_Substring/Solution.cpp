//Naive or Brute Force Approach
bool isPalindrome(const string& s, int left, int right) {
    while (left < right) {
        if (s[left++] != s[right--]) return false;
    }
    return true;
}

int countSubstrings(string s) {
    int count = 0;
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            if (isPalindrome(s, i, j)) {
                count++;
            }
        }
    }
    return count;
}


//Top-Down DP with Memoization
class Solution {
public:
    int countSubstrings(string s) {
        int n=s.size();
        int count=0;
        vector<vector<int>> memo(n,vector<int> (n,-1));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPal(i,j,s,memo)){
                    count++;
                }
            }
        }
        return count;
    }
    bool isPal(int start,int end,string s,vector<vector<int>> &memo){
        if(start>=end){
            return true;
        }
        if(memo[start][end]!=-1){
            return memo[start][end];
        }
        if(s[start]!=s[end]){
            return memo[start][end] = false;
        }
        return memo[start][end] = isPal(start+1,end-1,s,memo);
    }
};

//Bottom-Up DP Approach
int countSubstrings(string s) {
    int n = s.size(), count = 0;
    vector<vector<bool>> dp(n, vector<bool>(n, false));

    for (int i = n - 1; i >= 0; --i) {
        for (int j = i; j < n; ++j) {
            if (s[i] == s[j] && (j - i <= 2 || dp[i + 1][j - 1])) {
                dp[i][j] = true;
                count++;
            }
        }
    }
    return count;
}

//Expand Around Center Approach
class Solution {
public:
    int count=0;
    int countSubstrings(string s) {
        int n=s.size();
        for(int i=0;i<n;i++){
            isPal(i,i,s);
            isPal(i,i+1,s);
        }
        return count;
    }
    void isPal(int left,int right, string s){
        while(left>=0 && right<s.size() && s[left]==s[right]){
            left--;
            right++;
            count++;
        }
    }
};