//Brute Force Appraoch
class Solution {
public:
    int calculate(string s) {
        stack<int> results;
        stack<int> signs;
        int result = 0;
        int sign = 1; // 1 means '+', -1 means '-'
        int num = 0;
        int n = s.size();

        for (int i = 0; i < n; ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * num;
                sign = 1;
                num = 0;
            } else if (c == '-') {
                result += sign * num;
                sign = -1;
                num = 0;
            } else if (c == '(') {
                results.push(result);
                signs.push(sign);
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * num;
                result = results.top() + signs.top() * result;
                results.pop();
                signs.pop();
                num = 0;
            }
            // Ignore spaces
        }
        result += sign * num; // For the last number
        return result;
    }
};
//Optimized solution
class Solution {
public:
    int calculate(string s) {
        int n = s.size();
        if (s.empty()) return 0;

        stack<int> numberStack;  // Stack for numbers
        stack<char> operatorStack;  // Stack for operators
        int i = 0;

        while (i < n) {
            if (s[i] == ' ') {
                i++;  // Skip spaces
            } else if (s[i] == '(') {
                operatorStack.push(s[i]);
                i++;
            } else if (s[i] == '+' || s[i] == '-') {
                // Handle unary minus (e.g., "-2")
                if ((i > 0 && (s[i-1] == '(' || s[i-1] == ' ')) || i == 0) {
                    numberStack.push(0);  // Push 0 for unary operators
                }
                operatorStack.push(s[i]);
                i++;
            } else if (s[i] == ')') {
                // Process until matching '('
                while (operatorStack.top() != '(') {
                    processTop(numberStack, operatorStack);
                }
                operatorStack.pop();  // Remove '('
                i++;
            } else {
                // Process multi-digit numbers
                int num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                numberStack.push(num);
            }
        }

        // Process remaining operators
        while (!operatorStack.empty()) {
            processTop(numberStack, operatorStack);
        }

        return numberStack.top();
    }

private:
    void processTop(stack<int> &numberStack, stack<char> &operatorStack) {
        int num1 = numberStack.top(); numberStack.pop();
        int num2 = numberStack.top(); numberStack.pop();
        char op = operatorStack.top(); operatorStack.pop();

        int result = 0;
        if (op == '+') {
            result = num2 + num1;
        } else if (op == '-') {
            result = num2 - num1;
        }
        numberStack.push(result);
    }
};

//Further optimization
class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int sign = 1; // 1 means '+', -1 means '-'
        int num = 0;
        stack<int> results;
        stack<int> signs;

        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            } else if (c == '+') {
                result += sign * num;
                num = 0;
                sign = 1;
            } else if (c == '-') {
                result += sign * num;
                num = 0;
                sign = -1;
            } else if (c == '(') {
                // Push current result and sign to stack
                results.push(result);
                signs.push(sign);
                // Reset for new sub-expression
                result = 0;
                sign = 1;
            } else if (c == ')') {
                result += sign * num;
                num = 0;
                result = results.top() + signs.top() * result;
                results.pop();
                signs.pop();
            }
            // Ignore spaces
        }
        result += sign * num; // Add any number left at the end
        return result;
    }
};