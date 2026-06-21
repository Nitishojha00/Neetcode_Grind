class MyHashSet {
public:
vector<bool>present;
    MyHashSet() {
        present.resize(1e6+10);
    }
    
    void add(int key) {
        present[key] = 1;
    }
    
    void remove(int key) {
        present[key] = 0;
    }
    
    bool contains(int key) {
        return present[key];
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */