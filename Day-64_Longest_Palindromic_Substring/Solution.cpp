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
