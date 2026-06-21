class MyCircularQueue {
public:
vector<int>a;
int l = -1 , r = -1;
int n;
    MyCircularQueue(int k) {
        a.resize(k);
        n = k;
    }
    
    bool enQueue(int value) {
        // if its full
        cout<<l<<endl;
        if((r+1)%n==l)  return false;

        r = (r+1)%n;
        a[r] = value;
        if(l==-1) l = 0; // first elemnt inserted
        return true;
    }
    
    bool deQueue() {
        // left se element nikalenge
        if(l==-1) return false; // already empty
        if(l==r)
        {
            l = -1 , r = -1;
        }
        else
         l = (l+1)%n;
        return true;
    }
    
    int Front() {
       return l==-1?-1:a[l];
    }
    
    int Rear() {
        return r==-1?-1:a[r];
    }
    
    bool isEmpty() {
        return l==-1;
    }
    
    bool isFull() {
        return (r+1)%n==l;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */