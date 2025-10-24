//Brute Force Approach
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(isValid(i,j,s)){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
        
    }
    bool isValid(int l,int r,string &s){
        int balance=0;
        for(int i=l;i<=r;i++){
            if(s[i]=='('){
                balance++;
            }else{
                balance--;
            }
            if(balance<0){
                return false;
            }
        }
        return balance==0;
    }
};

//Stack Approach
class Solution {
public:
    int longestValidParentheses(string s) {
        int ans=0;
        stack<int> St;
        St.push(-1);
        for(int i=0;i<s.size();i++){
            char c=s[i];
            if(c=='('){
                St.push(i);
            }else{
                St.pop();
                if(St.empty()){
                    St.push(i);
                }
                ans=max(ans,i-St.top());
            }
        }
        return ans;
    }
};

//DP Approach
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n, 0);
        int maxLen = 0;

        for (int i = 1; i < n; i++) {
            if (s[i] == ')') {
                if (s[i-1] == '(')
                    dp[i] = (i >= 2 ? dp[i-2] : 0) + 2;
                else if (i - dp[i-1] - 1 >= 0 && s[i - dp[i-1] - 1] == '(')
                    dp[i] = dp[i-1] + 2 + ((i - dp[i-1] - 2 >= 0) ? dp[i - dp[i-1] - 2] : 0);
            }
            maxLen = max(maxLen, dp[i]);
        }
        return maxLen;
    }
};

//Two Pointer Approach
class Solution {
public:
    int longestValidParentheses(string s) {
        int left = 0, right = 0, maxLen = 0;

        // Left → Right
        for (char c : s) {
            if (c == '(') left++;
            else right++;
            if (left == right) maxLen = max(maxLen, 2 * right);
            else if (right > left) left = right = 0;
        }

        left = right = 0;

        // Right → Left
        for (int i = s.size()-1; i >= 0; i--) {
            if (s[i] == '(') left++;
            else right++;
            if (left == right) maxLen = max(maxLen, 2 * left);
            else if (left > right) left = right = 0;
        }

        return maxLen;
    }
};
