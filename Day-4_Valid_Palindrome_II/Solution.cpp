//Brute Force Solution
class Solution {
public:
    bool validPalindrome(string s) {
        for (int i = 0; i < s.size(); ++i) {
            string t = s.substr(0, i) + s.substr(i + 1);
            if (isPalindrome(t)) return true;
        }
        return isPalindrome(s);
    }
    bool isPalindrome(const string& str) {
        int l = 0, r = str.size() - 1;
        while (l < r) {
            if (str[l++] != str[r--]) return false;
        }
        return true;
    }
};
//Optimized Solution
class Solution {
public:
    bool validPalindrome(string s) {
        int l=0,r=s.size()-1;
        while(l<r)
        {
            if(s[l]==s[r]){
                l++;
                r--;
            }else{
                return helper(l+1,r,s) || helper(l,r-1,s);
            }
        }
        return true;
    }
    bool helper(int l,int r,string s){
        while(l<r){
            if(s[l]!=s[r])
            {
                return false;
            }
            l++;
            r--;
        }
        return true;
    }
};