//Brute Force Approach
#include <string>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        while (true) {
            // Replace valid pairs with an empty string
            size_t lenBefore = s.length();
            s = s.replace(s.find("()"), 2, "");
            s = s.replace(s.find("[]"), 2, "");
            s = s.replace(s.find("{}"), 2, "");
            
            // If the string length doesn't change, stop
            if (s.length() == lenBefore) break;
        }
        // If the string is empty, it's valid
        return s.empty();
    }
};

//Optimal Approach
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