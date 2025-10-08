// BackTracking + Map Lookup
class Solution {
public:
    map<char,vector<char>> phone;
    vector<string> res;
    vector<string> letterCombinations(string digits) {
        mapping();
        if(digits.size()==0){
            return res;
        }
        string curr;
        backTrack(curr,0,digits);
        return res;
    }
    void backTrack(string curr,int ind,string digits){
        if(ind==digits.size() ){
            res.push_back(curr);
            return;
        }
            for(auto c:phone[digits[ind]]){
                curr.push_back(c);
                backTrack(curr,ind+1,digits);
                curr.pop_back();
            }
    }

    void mapping(){
        phone['2'] = {'a','b','c'};
        phone['3'] = {'d','e','f'};
        phone['4'] = {'g','h','i'};
        phone['5'] = {'j','k','l'};
        phone['6'] = {'m','n','o'};
        phone['7'] = {'p','q','r','s'};
        phone['8'] = {'t','u','v'};
        phone['9'] = {'w','x','y','z'};
    }
};

// BackTracking + Map Lookup - Alternative
class Solution {
public:
    vector<string> res;
    unordered_map<char, string> digitToLetters{
        {'2', "abc"}, {'3', "def"}, {'4', "ghi"}, {'5', "jkl"},
        {'6', "mno"}, {'7', "pqrs"}, {'8', "tuv"}, {'9', "wxyz"}
    };

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        backtrack(0, "", digits);
        return res;
    }

    void backtrack(int index, string current, const string &digits) {
        if (index == digits.length()) {
            res.push_back(current);
            return;
        }

        string letters = digitToLetters[digits[index]];
        for (char ch : letters) {
            backtrack(index + 1, current + ch, digits);
        }
    }
};


//Iterative BFS Approach
vector<string> letterCombinations(string digits) {
    if (digits.empty()) return {};
    unordered_map<char, string> digitToLetters = {
        {'2',"abc"}, {'3',"def"}, {'4',"ghi"}, {'5',"jkl"},
        {'6',"mno"}, {'7',"pqrs"}, {'8',"tuv"}, {'9',"wxyz"}
    };

    queue<string> q;
    q.push("");
    for (char digit : digits) {
        int size = q.size();
        while (size--) {
            string curr = q.front(); q.pop();
            for (char ch : digitToLetters[digit]) {
                q.push(curr + ch);
            }
        }
    }

    vector<string> res;
    while (!q.empty()) {
        res.push_back(q.front());
        q.pop();
    }
    return res;
}
