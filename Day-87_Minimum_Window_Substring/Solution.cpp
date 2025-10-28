//Brute Force Approach
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        string ans = "";
        int minLen = INT_MAX;

        for (int i = 0; i <= m - n; ++i) {
            for (int j = i + n - 1; j < m; ++j) {
                string window = s.substr(i, j - i + 1);
                if (containsAll(window, t)) {
                    if (window.size() < minLen) {
                        minLen = window.size();
                        ans = window;
                    }
                    break; // No need to check longer windows starting at i
                }
            }
        }
        return ans;
    }
    bool containsAll(string window, string t) {
        vector<int> count(128, 0);
        for (char c : window) count[c]++;
        for (char c : t) {
            if (--count[c] < 0) return false;
        }
        return true;
    }
};

//Optimized Approach
class Solution {
public:
    string minWindow(string s, string t) {
        int m=s.size(),n=t.size();
        string ans = "";
        if(n>m) return ans;
        int minLen = INT_MAX;
        vector<int> tMap(256,0),windowMap(256,0);
        int left=0, right=0, startIndex=0;
        for(int i=0;i<n;i++){
            tMap[t[i]]++;
        }
        while(right<m){
            windowMap[s[right]]++;
            while(isValid(tMap,windowMap)){
                if(minLen >= right-left+1){
                    minLen = right-left+1; 
                    startIndex = left;
                }
                windowMap[s[left]]--;
                left++;
            }
            
            right++;
        }
        ans = minLen==INT_MAX?"": s.substr(startIndex,minLen);
        return ans;
    }
    bool isValid(vector<int> &tMap, vector<int> &windowMap){
        for(int i=0;i<256;i++){
            if(tMap[i] > windowMap[i]){
                return false;
            }
        }
        return true;
    }
};


//Optimized Approach with few Changes
class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size(), n = t.size();
        if (n > m) return ""; // Edge case: If t is longer than s

        vector<int> tMap(128, 0), windowMap(128, 0); // 128 for English letters
        for (char c : t) tMap[c]++; // Build frequency map for t

        int left = 0, right = 0, startIndex = 0, minLen = INT_MAX, required = n;

        while (right < m) {
            char rChar = s[right];
            if (tMap[rChar] > 0) { // Update required only for valid chars
                if (windowMap[rChar] < tMap[rChar]) required--;
            }
            windowMap[rChar]++; // Expand the window

            while (required == 0) { // Shrink the window
                if (minLen > right - left + 1) { // Update result
                    minLen = right - left + 1;
                    startIndex = left;
                }

                char lChar = s[left];
                if (tMap[lChar] > 0) {
                    if (windowMap[lChar] == tMap[lChar]) required++;
                }
                windowMap[lChar]--; // Shrink the window
                left++;
            }

            right++; // Expand the window
        }

        return minLen == INT_MAX ? "" : s.substr(startIndex, minLen);
    }
};