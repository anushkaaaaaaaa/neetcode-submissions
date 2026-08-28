#include <stack>
#include <algorithm>

class MinStack {
private:
    std::stack<int> s;
    std::stack<int> minS;

public:
    MinStack() {
        // Initialization is handled by default constructors of std::stack
    }
    
    void push(int val) {
        s.push(val);
        
        // Push to minS if it is empty OR if val is less than or equal to current min
        if (minS.empty() || val <= minS.top()) {
            minS.push(val);
        }
    }
    
    void pop() {
        // If the top of main stack is the current minimum, remove it from minS as well
        if (s.top() == minS.top()) {
            minS.pop();
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return minS.top();
    }
};