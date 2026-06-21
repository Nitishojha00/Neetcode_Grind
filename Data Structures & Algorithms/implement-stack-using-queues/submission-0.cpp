class MyStack {
public:
queue<int>st;
    MyStack() {
        
    }
    
    void push(int x) {
        int n = st.size();
        st.push(x);
        while(n--)
        {
            st.push(st.front());
            st.pop();
        }
    }
    
    int pop() {
        int e = st.front();
         st.pop();
        return e;
    }
    
    int top() {
        return st.front();
    }
    
    bool empty() {
        return st.empty();
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