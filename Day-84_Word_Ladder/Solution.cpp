//BFS Approach
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> words;
        for(auto c:wordList){
            words.insert(c);
        }
        if(words.find(endWord)==words.end()){
            return 0;
        }
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        while(!q.empty()){
            string currWord = q.front().first;
            int depth = q.front().second;
            q.pop();
            if(currWord==endWord){
                return depth;
            }
            for(int i=0;i<currWord.size();i++){
                string temp=currWord;
                for(char ch='a';ch<='z';ch++){
                    temp[i] = ch;
                    if(words.find(temp)!=words.end()){
                        q.push({temp,depth+1});
                        words.erase(temp);
                    }
                }
            }
        }
        return 0;
    }
};

//Bidirectional BFS Approach
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        if (!wordSet.count(endWord)) return 0;

        unordered_set<string> beginSet, endSet, visited;
        beginSet.insert(beginWord);
        endSet.insert(endWord);

        int level = 1;

        while (!beginSet.empty() && !endSet.empty()) {
            // Always expand the smaller set
            if (beginSet.size() > endSet.size()) swap(beginSet, endSet);

            unordered_set<string> nextSet;
            for (string word : beginSet) {
                for (int i = 0; i < word.size(); ++i) {
                    string temp = word;
                    for (char c = 'a'; c <= 'z'; ++c) {
                        temp[i] = c;
                        if (endSet.count(temp)) return level + 1;
                        if (wordSet.count(temp) && !visited.count(temp)) {
                            nextSet.insert(temp);
                            visited.insert(temp);
                        }
                    }
                }
            }

            beginSet = nextSet;
            ++level;
        }

        return 0;
    }
};
