class LRUCache {
public:
    class Node{
        public:
        Node *prev , *next;
        int val ,  key;

        Node(int k , int v)
        {
            key = k ;
            val = v;
        }
    };

    unordered_map<int,Node*>mp;
    int n;
    Node *l , *r;
    LRUCache(int capacity) {
        n = capacity;
        l = new Node(-1,-1);
        r = new Node(-1,-1);
        l->next = r;
        r->prev = l;
    }
    
    int get(int key) {
        
        if(mp.find(key) == mp.end()) return -1;

        Node *temp = mp[key];
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        Node *last = r->prev;
        last->next = temp;
         r->prev = temp;
         temp->prev = last;
         temp->next = r;
         return temp->val;
    }
    
    void put(int key, int value) {
        if(mp.find(key)!=mp.end())
        {
            Node *temp = mp[key];
            temp->prev->next = temp->next;
            temp->next->prev = temp->prev;

            Node *last = r->prev;
            last->next = temp;
            r->prev = temp;
            temp->prev = last;
            temp->next = r;
            temp->val = value;
        }
        else
        {
            Node *temp = new Node(key,value);
            Node *last = r->prev;
            last->next = temp;
            r->prev = temp;
            temp->prev = last;
            temp->next = r;
            mp[key] = temp;
        }

        if(mp.size()>n)
        {
            Node *start = l->next;
            start->next->prev = l;
            l->next = start->next;
            mp.erase(start->key);
            delete start;
        }
    }
};
