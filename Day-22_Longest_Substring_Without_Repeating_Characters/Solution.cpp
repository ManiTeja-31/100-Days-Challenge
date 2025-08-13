//Brute Force Approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxLen = 0;
        for(int i=0;i<n;i++){
            set<int> Myset;
            Myset.insert(s[i]);
            for(int j=i+1;j<n;j++){
                if(Myset.find(s[j])!=Myset.end()){  
                    break;
                }
                Myset.insert(s[j]);
            }
            maxLen = max(maxLen,(int)Myset.size());
        }
        return maxLen;
    }
};

//Optimized Approach
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int maxLen = 0;
        int l=0,r=0;
        unorderd_map<char,int> pos;
        while(l<n && r<n){
            if(pos.find(s[r])!=pos.end() && pos[s[r]]>=l){
                l=pos[s[r]]+1;
            }
            pos[s[r]] = r;
            maxLen = max(maxLen, r-l+1);
            r++;

        }
        return maxLen;
    }
};