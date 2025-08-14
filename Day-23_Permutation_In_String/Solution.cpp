//Brute Force Approach 
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k = s1.size(), n = s2.size();
        sort(s1.begin(), s1.end());
        for (int i = 0; i <= n - k; ++i) {
            string sub = s2.substr(i, k);
            sort(sub.begin(), sub.end());
            if (sub == s1) return true;
        }
        return false;
    }
};

//Optimized Approach
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int k=s1.size(), n=s2.size();
        if(k>n)return false;
        vector<int> freqS1(26,0), freqwindow(26,0);
        int l=0,r=0;
        while(r<k){
            freqS1[s1[r]-'a']++;
            freqwindow[s2[r]-'a']++;
            r++;
        }
        if(freqS1 == freqwindow)return true;
        while(r<n){
            freqwindow[s2[l++]-'a']--;
            freqwindow[s2[r++]-'a']++;
            if(freqS1 == freqwindow)return true;
        }
        return false;
    }
};