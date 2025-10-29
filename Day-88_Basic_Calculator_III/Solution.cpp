//Naive Or Recursive Approach
class Solution {
public:
    int calculate(string s) {
        int i = 0;
        return helper(s, i);
    }

    int helper(string &s, int &i) {
        stack<int> st;
        long num = 0;
        char sign = '+';

        for (; i < s.size(); i++) {
            char c = s[i];
            if (isdigit(c)) {
                num = num * 10 + (c - '0');
            }
            if (c == '(') {
                i++;  // skip '('
                num = helper(s, i); // evaluate inside parentheses
            }
            // If operator or end of string or closing parenthesis
            if ((!isdigit(c) && c != ' ' && c != '(') || i == s.size() - 1) {
                if (sign == '+') st.push(num);
                else if (sign == '-') st.push(-num);
                else if (sign == '*') {
                    int top = st.top(); st.pop();
                    st.push(top * num);
                } else if (sign == '/') {
                    int top = st.top(); st.pop();
                    st.push(top / num);
                }
                sign = c;
                num = 0;
            }
            if (c == ')') break; // end of this recursive level
        }

        int sum = 0;
        while (!st.empty()) {
            sum += st.top();
            st.pop();
        }
        return sum;
    }
};


//Optimized Approach Using Two Stacks
class Solution {
public:
    int calculate(string s) {
        stack<int> nums;
        stack<char> ops;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char c = s[i];

            if (c == ' ') continue;

            if (isdigit(c)) {
                long num = 0;
                while (i < n && isdigit(s[i])) {
                    num = num * 10 + (s[i] - '0');
                    i++;
                }
                nums.push(num);
                i--; // step back because for loop will increment i
            }
            else if (c == '(') {
                ops.push(c);
            }
            else if (c == ')') {
                while (!ops.empty() && ops.top() != '(') {
                    int b = nums.top(); nums.pop();
                    int a = nums.top(); nums.pop();
                    char op = ops.top(); ops.pop();
                    nums.push(applyOp(a, b, op));
                }
                ops.pop(); // remove '('
            }
            else { // operator +, -, *, /
                while (!ops.empty() && precedence(ops.top()) >= precedence(c)) {
                    int b = nums.top(); nums.pop();
                    int a = nums.top(); nums.pop();
                    char op = ops.top(); ops.pop();
                    nums.push(applyOp(a, b, op));
                }
                ops.push(c);
            }
        }

        // Evaluate remaining ops
        while (!ops.empty()) {
            int b = nums.top(); nums.pop();
            int a = nums.top(); nums.pop();
            char op = ops.top(); ops.pop();
            nums.push(applyOp(a, b, op));
        }

        return nums.top();
    }

private:
    int precedence(char op) {
        if (op == '+' || op == '-') return 1;
        if (op == '*' || op == '/') return 2;
        return 0;
    }

    int applyOp(int a, int b, char op) {
        if (op == '+') return a + b;
        if (op == '-') return a - b;
        if (op == '*') return a * b;
        return a / b;
    }
};
