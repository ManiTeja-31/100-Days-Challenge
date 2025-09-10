//Stack based solution

class Solution {
public:
    bool isValid(string s) {
        int n=s.size();
        stack<char> St;
        for(int i=0;i<n;i++){
            if(s[i]=='(' || s[i]=='[' || s[i]=='{'){
                St.push(s[i]);
            }else if(!St.empty()){
                if((s[i]==')' && St.top()=='(') ||
                (s[i]==']' && St.top()=='[') ||
                (s[i]=='}' && St.top()=='{')){
                    St.pop();
                }else{
                    return false;
                }
            }else{
                return false;
            }
        }
        if(St.empty())return true;
        else return false;
    }
};

//Iterative Replacement
class Solution {
public:
    bool isValid(string s) {
        int prevLen = -1;
        while (prevLen != s.length()) {
            prevLen = s.length();
            size_t pos;
            while ((pos = s.find("()")) != string::npos) s.erase(pos, 2);
            while ((pos = s.find("[]")) != string::npos) s.erase(pos, 2);
            while ((pos = s.find("{}")) != string::npos) s.erase(pos, 2);
        }
        return s.empty();
    }
};