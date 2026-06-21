class MyHashMap {
public:
vector<int>value;
    MyHashMap() {
       value.resize(1e6+10,-1);
    }
    
    void put(int key, int val) {
        value[key] = val;
    }
    
    int get(int key) {
        return value[key];
    }
    
    void remove(int key) {
        value[key] = -1;
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */