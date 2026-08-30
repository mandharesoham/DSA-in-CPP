/*### 225. Implement Stack using Queues

- **Difficulty:** Easy
- **Topics:** Queue, Stack, Design

**Explanation:**
Use two queues, `q1` and `q2`, to implement a stack.

During `push()`, move all elements from `q1` to `q2`, insert the
new element into `q1`, and then move all elements back from `q2`
to `q1`. This keeps the newest element at the front of `q1`,
allowing `pop()` and `top()` to work like a stack.

**Time Complexity:**
- `push()` → O(n)
- `pop()` → O(1)
- `top()` → O(1)
- `empty()` → O(1)

**Space Complexity:** O(n)
*/

class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {}

    void push(int x) {
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while (!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
    }

    int pop() {
        int ans = q1.front();
        q1.pop();
        return ans;
    }

    int top() { return q1.front(); }

    bool empty() { return q1.empty(); }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
