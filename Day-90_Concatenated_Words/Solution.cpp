//Brute Force/Recursive (word break) Approach
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dist(words.begin(),words.end());
        vector<string> res;
        for(auto word:words){
            dist.erase(word);
            if(canForm(word,dist)){
                res.push_back(word);
            }
            dist.insert(word);
        }
        return res;
    }
    bool canForm(string word,unordered_set<string> &dist){
        int n=word.size();
        vector<int> dp(n+1,false);
        dp[0]=true;
        for(int i=0;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && dist.find(word.substr(j,i-j))!=dist.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

//Dp + Length Order/ Sorting words by length Approach
class Solution {
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> dist(words.begin(),words.end());
        vector<string> res;
        sort(words.begin(),words.end(),
        [](const string &a,const string &b){
            return a.size() < b.size();
        });
        for(auto word:words){
            dist.erase(word);
            if(canForm(word,dist)){
                res.push_back(word);
            }
            dist.insert(word);
        }
        return res;
    }
    bool canForm(string word,unordered_set<string> &dist){
        int n=word.size();
        vector<int> dp(n+1,false);
        dp[0]=true;
        for(int i=0;i<=n;i++){
            for(int j=0;j<i;j++){
                if(dp[j] && dist.find(word.substr(j,i-j))!=dist.end()){
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};

//Trie + Dp Approach
struct TrieNode {
    TrieNode* child[26];
    bool isWord;
    TrieNode() {
        isWord = false;
        for (int i = 0; i < 26; i++) child[i] = nullptr;
    }
};

class Solution {
private:
    TrieNode* root;
    
    void insertTrie(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            int idx = c - 'a';
            if (!node->child[idx]) {
                node->child[idx] = new TrieNode();
            }
            node = node->child[idx];
        }
        node->isWord = true;
    }
    
    bool dfsCanForm(const string& word, int start, int count) {
        int n = word.size();
        if (start == n) {
            return count >= 2;
        }
        TrieNode* node = root;
        for (int i = start; i < n; i++) {
            int idx = word[i] - 'a';
            if (!node->child[idx]) return false;
            node = node->child[idx];
            if (node->isWord) {
                if (dfsCanForm(word, i + 1, count + 1)) return true;
            }
        }
        return false;
    }
    
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        root = new TrieNode();
        vector<string> result;
        sort(words.begin(), words.end(), [](const string& a, const string& b){
            return a.size() < b.size();
        });
        for (string& w : words) {
            if (w.empty()) continue;
            if (dfsCanForm(w, 0, 0)) {
                result.push_back(w);
            } else {
                insertTrie(w);
            }
        }
        return result;
    }
};

