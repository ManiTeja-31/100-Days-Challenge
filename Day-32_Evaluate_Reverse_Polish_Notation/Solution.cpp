//Recursion Based Approach
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int index = tokens.size() - 1;
        return evaluate(tokens, index);
    }

private:
    int evaluate(vector<string>& tokens, int& index) {
        string token = tokens[index--];
        if (token != "+" && token != "-" && token != "*" && token != "/") {
            return stoi(token); // Base case: return operand
        }
        
        // Recursive calls for the two operands
        int num2 = evaluate(tokens, index);
        int num1 = evaluate(tokens, index);

        // Perform the operation
        if (token == "+") return num1 + num2;
        if (token == "-") return num1 - num2;
        if (token == "*") return num1 * num2;
        return num1 / num2; // Division
    }
};
//Optimized Approach
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n=tokens.size();
        stack<int> St;
        for(int i=0;i<n;i++){
            string ch=tokens[i];
            if(ch!="+" && ch!="-" && ch!="*" && ch!="/"){
                St.push(stoi(ch));
            }else{
                int num1 = St.top(); St.pop();
                int num2 = St.top(); St.pop();
                int res=0;
                if(ch=="+"){
                    res=num1+num2;
                }else if(ch=="-"){
                    res=num2-num1;
                }else if(ch=="*"){
                    res=num1*num2;
                }else{
                    res=num2/num1;
                }
                St.push(res);
            }
        }
        return St.top();
    }
};

//Optimized Approach
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> St;

        // Lambda for performing arithmetic operations
        auto calculate = [](int num1, int num2, const string& op) -> int {
            if (op == "+") return num2 + num1;
            if (op == "-") return num2 - num1;
            if (op == "*") return num2 * num1;
            return num2 / num1; // Division
        };

        for (const string& token : tokens) {
            if (token != "+" && token != "-" && token != "*" && token != "/") {
                // Push operand onto the stack
                St.push(stoi(token));
            } else {
                // Pop top two elements for operator
                int num1 = St.top(); St.pop();
                int num2 = St.top(); St.pop();

                // Perform operation and push result
                St.push(calculate(num1, num2, token));
            }
        }
        return St.top(); // Final result
    }
};