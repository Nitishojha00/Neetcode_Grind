class MinStack {
public:
stack<int>st , mn;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(mn.empty())
            mn.push(val);
        else
            mn.push(min(mn.top(),val));
    }
    
    void pop() {
        st.pop();
        mn.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return mn.top();
    }
};
