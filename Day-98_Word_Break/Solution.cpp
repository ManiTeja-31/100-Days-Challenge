//Recursion Approach
bool wordBreakHelper(string s, unordered_set<string>& dict) {
    if (s.empty()) return true;

    for (int i = 1; i <= s.size(); i++) {
        string prefix = s.substr(0, i);
        if (dict.count(prefix) && wordBreakHelper(s.substr(i), dict))
            return true;
    }
    return false;
}

bool wordBreak(string s, vector<string>& wordDict) {
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    return wordBreakHelper(s, dict);
}

//Recursion + Memoization Approach
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        vector<int> memo(s.size(), -1); // -1: unvisited, 0: false, 1: true
        return canBreak(0, s, dict, memo);
    }

    bool canBreak(int start, string& s, unordered_set<string>& dict, vector<int>& memo) {
        if (start == s.size()) return true;
        if (memo[start] != -1) return memo[start];

        for (int end = start + 1; end <= s.size(); end++) {
            string word = s.substr(start, end - start);
            if (dict.count(word) && canBreak(end, s, dict, memo))
                return memo[start] = true;
        }
        return memo[start] = false;
    }
};


//Bottom-Up DP Approach
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> dict(wordDict.begin(), wordDict.end());
        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // base case

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && dict.count(s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }

        return dp[n];
    }
};


//Trie + Dp Approach
class TrieNode {
public:
    bool isWord;
    unordered_map<char, TrieNode*> children;
    TrieNode() : isWord(false) {}
};

class Trie {
public:
    TrieNode* root;
    Trie() { root = new TrieNode(); }

    void insert(const string& word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children.count(c))
                node->children[c] = new TrieNode();
            node = node->children[c];
        }
        node->isWord = true;
    }
};

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        Trie trie;
        for (auto& w : wordDict)
            trie.insert(w);

        int n = s.size();
        vector<bool> dp(n + 1, false);
        dp[0] = true; // base case: empty string can be segmented

        for (int i = 0; i < n; i++) {
            if (!dp[i]) continue;

            TrieNode* node = trie.root;
            for (int j = i; j < n; j++) {
                char c = s[j];
                if (!node->children.count(c)) break;  // no valid prefix → stop
                node = node->children[c];
                if (node->isWord)
                    dp[j + 1] = true;  // substring s[i..j] is valid
            }
        }

        return dp[n];
    }
};

