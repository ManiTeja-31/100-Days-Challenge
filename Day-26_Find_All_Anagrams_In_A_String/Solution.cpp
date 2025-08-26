//Brute Force Solution
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> result;

        // Edge case: If p is longer than s, return empty result
        if (m > n) return result;

        // Helper function to check if two strings are anagrams
        auto isAnagram = [](string &a, string &b) {
            vector<int> freq(26, 0);
            for (char c : a) freq[c - 'a']++;
            for (char c : b) freq[c - 'a']--;
            for (int count : freq) {
                if (count != 0) return false;
            }
            return true;
        };

        // Generate all substrings of length m and check for anagrams
        for (int i = 0; i <= n - m; i++) {
            string substring = s.substr(i, m); // Extract substring of length m
            if (isAnagram(substring, p)) {
                result.push_back(i); // Add starting index if it's an anagram
            }
        }

        return result;
    }
};
//Optimized Solution
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n=s.size(), m=p.size();
        vector<int> res, windowFreq(26,0), pFreq(26,0);
        if(m>n) return res;
        int left=0,right=0;
        while(right<m){
            windowFreq[s[right]-'a']++;
            pFreq[p[right]-'a']++;
            right++;
        }
        if(windowFreq==pFreq){
            res.push_back(left);
        }
        while(right<n){
            windowFreq[s[right]-'a']++;
            windowFreq[s[left]-'a']--;
            left++;
            right++;
            if(windowFreq==pFreq){
                res.push_back(left);
            }
        }
        return res;
    }
};
//Further Optimized Solution
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int n = s.size(), m = p.size();
        vector<int> res;
        if (m > n) return res;

        vector<int> windowFreq(26, 0), pFreq(26, 0);
        int matchCount = 0; // Tracks matching characters between windowFreq and pFreq

        // Initialize frequencies for the first window and p
        for (int i = 0; i < m; i++) {
            windowFreq[s[i] - 'a']++;
            pFreq[p[i] - 'a']++;
        }

        // Count initial matches
        for (int i = 0; i < 26; i++) {
            if (windowFreq[i] == pFreq[i]) matchCount++;
        }

        // Sliding window logic
        for (int left = 0, right = m; right <= n; left++, right++) {
            // Check if all characters match
            if (matchCount == 26) res.push_back(left);

            // Slide the window: remove the leftmost character and add the rightmost character
            if (right < n) {
                char addChar = s[right], removeChar = s[left];
                windowFreq[addChar - 'a']++;
                windowFreq[removeChar - 'a']--;

                // Update match count for the added character
                if (windowFreq[addChar - 'a'] == pFreq[addChar - 'a']) matchCount++;
                else if (windowFreq[addChar - 'a'] - 1 == pFreq[addChar - 'a']) matchCount--;

                // Update match count for the removed character
                if (windowFreq[removeChar - 'a'] == pFreq[removeChar - 'a']) matchCount++;
                else if (windowFreq[removeChar - 'a'] + 1 == pFreq[removeChar - 'a']) matchCount--;
            }
        }

        return res;
    }
};