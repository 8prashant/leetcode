class MyStack {
public:
    stack<int>s;
    MyStack() {
        s.push(1);
        s.pop();
    }
    
    void push(int x) {
        s.push(x);
    }
    
    int pop() {
        int a=s.top();
        s.pop();
        return a;
    }
    
    int top() {
        int a=s.top();
        return a;
    }
    
    bool empty() {
        return s.empty();
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