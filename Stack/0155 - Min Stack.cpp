/*
Problem: 155. Min Stack
Platform: LeetCode
Difficulty: Medium

Topics:
- Stack
- Design

Time Complexity:
- push: O(1)
- pop: O(1)
- top: O(1)
- getMin: O(1)

Space Complexity: O(n)
*/

class MinStack {
public:
    stack<pair<int, int>> st; // val , minVal
    MinStack() {}

    void push(int value) {
        if (st.empty()) {
            st.push({value, value});
        } else {
            int minVal = min(st.top().second, value);
            st.push({value, minVal});
        }
    }

    void pop() { st.pop(); }

    int top() { return st.top().first; }

    int getMin() { return st.top().second; }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
