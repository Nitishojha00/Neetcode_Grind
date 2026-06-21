class MedianFinder {
public:
priority_queue<int , vector<int>  , greater<>>pq;
priority_queue<int>p;
    int n = 0;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        
        n++;
        if((n+2)/2==p.size())
        {
            int e = p.top();
            cout<<p.size()<<endl;
            p.pop();
            pq.push(max(num,e));
            p.push(min(num,e));
        }
        else
        { // yaha to direst insertion krna hai
            pq.push(num);
            p.push(pq.top());
            pq.pop();
        }
    }


    double findMedian() {

        if(n%2==0)
        {
            int val = p.top();
            p.pop();
            int val1 = p.top();
            p.push(val);

            return (double)(val+val1)/2;
        }
        else
        {
            return p.top();
        }
    }
};
