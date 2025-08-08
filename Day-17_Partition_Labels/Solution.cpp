//Brute Force  Approach
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> res;
        int n = s.size(), start = 0;
        while (start < n) {
            unordered_set<char> seen;
            int end = start;
            for (int i = start; i < n; ++i) {
                seen.insert(s[i]);
                bool valid = true;
                for (char c : seen) {
                    if (s.find(c, i + 1) != string::npos) {
                        valid = false;
                        break;
                    }
                }
                if (valid) {
                    end = i;
                    break;
                }
            }
            res.push_back(end - start + 1);
            start = end + 1;
        }
        return res;
    }
};

//Optimized Approach - Using Hash Map
class Solution {
public:
    vector<int> partitionLabels(string s) {
        map<char,int> lastOccur;
        int n=s.size();
        for(int i=0;i<n;i++){
            lastOccur[s[i]] = i;
        }
        vector<int> res;
        int start=0,end=0;
        for(int i=0;i<n;i++){
            end = max(end,lastOccur[s[i]]);
            if(end == i){
                res.push_back(end-start+1);
                start=i+1;
                end=i+1;
            }
        }
        return res;
    }
};

//Optimized Approach - Using fixed length array
class Solution {
public:
    vector<int> partitionLabels(string s) {
        vector<int> lastOccur(26,0);
        int n=s.size();
        for(int i=0;i<n;i++){
            lastOccur[s[i]-'a'] = i;
        }
        vector<int> res;
        int start=0,end=0;
        for(int i=0;i<n;i++){
            end = max(end,lastOccur[s[i]-'a']);
            if(end == i){
                res.push_back(end-start+1);
                start=i+1;
                end=i+1;
            }
        }
        return res;
    }
};