class FreqStack {
public:
unordered_map<int,int>freq;
stack<pair<int,int>>s;  // store  the (element , element with maxfreq)
int prev = 0;
    FreqStack() {
        s.push({-1,-1});
    }
    
    void push(int val) {
        freq[val]++;
        if(freq[val]>=freq[s.top().second])
        {
            s.push({val,val});
        }
        else
        {
            s.push({val,s.top().second});
        }
    }
    
    int pop() {
        int value = s.top().second;
        freq[value]--;
        stack<int>st;
        while(s.top().first!=value)
        {
            st.push(s.top().first);
            freq[st.top()]--;
            s.pop();
        }
        s.pop();
        while(!st.empty())
        {
            push(st.top());
            st.pop();
        }

        return value;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */