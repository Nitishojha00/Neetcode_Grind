class LFUCache {
    struct Node {
        int key, value, freq;
        Node(int k, int v, int f=1): key(k), value(v), freq(f) {}
    };

    int capacity, minFreq;
    unordered_map<int, list<Node>> freqList;           // freq -> list of nodes
    unordered_map<int, list<Node>::iterator> nodeMap;  // key -> node iterator

    void touch(list<Node>::iterator it) {
        int k = it->key, v = it->value, f = it->freq;
        freqList[f].erase(it);
        if (freqList[f].empty()) {
            freqList.erase(f);
            if (minFreq == f) minFreq++;
        }
        freqList[f+1].push_front(Node(k, v, f+1));
        nodeMap[k] = freqList[f+1].begin();
    }

public:
    LFUCache(int capacity): capacity(capacity), minFreq(0) {}

    int get(int key) {
        if (capacity <= 0 || nodeMap.find(key) == nodeMap.end())
            return -1;
        auto it = nodeMap[key];
        int val = it->value;
        touch(it);
        return val;
    }

    void put(int key, int value) {
        if (capacity <= 0) return;

        if (nodeMap.find(key) != nodeMap.end()) {
            auto it = nodeMap[key];
            it->value = value;
            touch(it);
            return;
        }

        if (nodeMap.size() >= capacity) {
            auto it = --freqList[minFreq].end(); // last element
            nodeMap.erase(it->key);
            freqList[minFreq].erase(it);
            if (freqList[minFreq].empty()) freqList.erase(minFreq);
        }

        freqList[1].push_front(Node(key, value));
        nodeMap[key] = freqList[1].begin();
        minFreq = 1;
    }
};
