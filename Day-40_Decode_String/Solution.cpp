//Iterative Using Two Stacks (Optimal & Standard)
class Solution {
public:
    string decodeString(string s) {
        int n=s.size();
        stack<string> strStack;
        stack<int> countStack;
        string curr;
        int num=0;
        for(auto c:s){
            if(isdigit(c)){
                num = num*10+(c-'0');
            }
            else if(c=='['){
                strStack.push(curr);
                curr.clear();
                countStack.push(num);
                num=0;
            }else if(c==']'){
                int k=countStack.top(); countStack.pop();
                string prev = strStack.top(); strStack.pop();
                string temp;
                while(k--){
                    temp+=curr;
                }
                curr=prev+temp;
            }else{
                curr+=c;
            }
        }
        return curr;
    }
};

//Recursive (Top-Down DFS) Approach
class Solution {
public:
    int i = 0;

    string decodeString(string s) {
        return decode(s);
    }

    string decode(const string& s) {
        string result;
        int num = 0;

        while (i < s.size()) {
            char c = s[i];

            if (isdigit(c)) {
                num = num * 10 + (c - '0');
                i++;
            }
            else if (c == '[') {
                i++; // skip '['
                string inner = decode(s); // decode inside bracket
                while (num--) result += inner;
                num = 0;
            }
            else if (c == ']') {
                i++; // skip ']'
                return result;
            }
            else {
                result += c;
                i++;
            }
        }

        return result;
    }
};
