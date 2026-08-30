/*### 232. Implement Queue using Stacks

- **Difficulty:** Easy
- **Topics:** Queue, Stack, Design

**Explanation:**
Use two stacks, `s1` and `s2`, to implement a queue.

During `push()`, move all elements from `s1` to `s2`, insert the
new element into `s1`, and then move all elements back from `s2`
to `s1`.

This keeps the oldest element at the top of `s1`, so `pop()` and
`peek()` can directly access the front of the queue.

**Time Complexity:**
- `push()` → O(n)
- `pop()` → O(1)
- `peek()` → O(1)
- `empty()` → O(1)

**Space Complexity:** O(n)
*/

class MyQueue {
public:
stack<int> s1;
stack<int> s2;
    MyQueue() {
        
    }
    
    void push(int x) {
        while(!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }
        s1.push(x);
        while(!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int ans=s1.top();
        s1.pop();
        return ans;
    }
    
    int peek() {
        int ans=s1.top();
        return ans;
    }
    
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
