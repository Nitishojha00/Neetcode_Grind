class MyQueue {
public:
stack<int>st;
    MyQueue() {
        
    }
    
    void push(int val) {
        int n = st.size();
        stack<int>x;
        while(!st.empty())
        {
            x.push(st.top());
            st.pop();
        }
        st.push(val);
        while(!x.empty())
        {
            st.push(x.top());
            x.pop();
        }
    }
    
    int pop() {
        int val = st.top();
        st.pop();

        return val;
    }
    
    int peek() {
        return st.top();
    }
    
    bool empty() {
        return st.empty();
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