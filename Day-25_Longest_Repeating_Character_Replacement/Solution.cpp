// Brute Force Approach
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxLen = 0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int len = j-i+1;
                string curr = s.substr(i, len);
                int maxfreq = countFreq(curr);
                int replacement = curr.size() - maxfreq;
                if(replacement <= k){
                    maxLen = max(maxLen, (int)curr.size());
                }
            }
        }
        return maxLen;
    }
    int countFreq(string curr){
        int maxFreq=0;
        int n=curr.size();
        vector<int> arr(26,0);
        for(int i=0;i<n;i++){
            arr[curr[i]-'A']++;
            maxFreq = max(maxFreq,arr[curr[i]-'A']);
        }
        return maxFreq;
    }
};

// Brute Force Approach - O(n^2)
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int maxLen = 0;
        for(int i=0;i<n;i++){
            vector<int> freq(26,0);
            int maxFreq=0;
            for(int j=i;j<n;j++){
                freq[s[j]-'A']++;
                maxFreq = max(maxFreq,freq[s[j]-'A']);
                int len = j-i+1;
                int replacement = len - maxFreq;
                if(replacement <= k){
                    maxLen = max(maxLen, len);
                }
            }
        }
        return maxLen;
    }
};

//Optimized Approach - Sliding Window
class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size(), maxLen = 0, maxFreq=0;
        int left = 0, right = 0;
        vector<int> freq(26,0);
        while(right < n){
            freq[s[right]-'A']++;
            maxFreq = max(maxFreq, freq[s[right]-'A']);
            int currLen = right - left + 1;
            
            if(currLen - maxFreq > k){
                freq[s[left]-'A']--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
            right++;
        }
        return maxLen;
    }
};

