class MyStack {
public:
    queue<int> Q;
    
    /** Push element x onto stack. */
    void push(int x) {
        int n = Q.size();
        Q.push(x);
        while(n--){
            Q.push(Q.front());
            Q.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int temp = Q.front(); Q.pop();
        return temp;
    }
    
    /** Get the top element. */
    int top() {
        return Q.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return Q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
