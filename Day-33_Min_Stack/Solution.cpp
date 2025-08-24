//Solution-1
class MinStack {
public:
    stack<int> minStack,mainStack;
    MinStack() {
        
    }
    
    void push(int val) {
        mainStack.push(val);
        if(minStack.empty() || minStack.top()>=mainStack.top()){
            minStack.push(val);
        }
    }
    
    void pop() {
        if(minStack.top()==mainStack.top()){
            minStack.pop();
            mainStack.pop();
        }else{
            mainStack.pop();
        }
    }
    
    int top() {
        return mainStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

//Approach-2
#include <stack>
using namespace std;

class MinStack {
public:
    stack<pair<int, int>> st; // Stack stores pairs: (value, current_min)

    MinStack() {
        // Constructor initializes the stack
    }
    
    void push(int val) {
        // If the stack is empty, the current minimum is the value itself
        if (st.empty()) {
            st.push({val, val});
        } else {
            // Otherwise, compare val with the current minimum (top.second)
            int currentMin = min(val, st.top().second);
            st.push({val, currentMin});
        }
    }
    
    void pop() {
        // Simply pop the top element
        st.pop();
    }
    
    int top() {
        // Return the top value (top.first)
        return st.top().first;
    }
    
    int getMin() {
        // Return the current minimum (top.second)
        return st.top().second;
    }
};

