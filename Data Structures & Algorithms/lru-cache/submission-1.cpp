class LRUCache {
public:

class Node {
    public:
    Node *left , *right;
    int key  , val;
    Node(int k , int v)
    {
        key = k , val = v;
        left = right = nullptr;
    }
};
    unordered_map<int,Node*>mp;
    int n;
    Node *l , *r;
    LRUCache(int capacity) {
        n = capacity;
        l = new Node(-1,-1);
        r = new Node(-1,-1);
        l->right = r;
        r->left = l;
    }
    
    int get(int key) 
    {
        // only shift to front and return the value
        if(mp.find(key)==mp.end()) return -1;
        Node *temp = mp[key];
         temp->left->right = temp->right;
         temp->right->left = temp->left;
        Node *p = r->left;
        temp->left = p;
        p->right = temp;
        temp->right = r;
        r->left = temp;
        return temp->val;
    }
    
    void put(int key, int value) 
    {
        if(mp.find(key)!=mp.end()) // already present only i have to update the value
        {
            Node *temp = mp[key];
            temp->left->right = temp->right;
            temp->right->left = temp->left;
            Node *p = r->left;
            temp->left = p;
            p->right = temp;
            temp->right = r;
            r->left = temp;
            temp->val = value;
        }
        else
        {
            Node *temp = new Node(key,value);
            mp[key] = temp;
             Node *p = r->left;
            temp->left = p;
            p->right = temp;
            temp->right = r;
            r->left = temp;
        }

        if(mp.size()>n) //remove the element that present in last 
        {
            Node * dl = l->right;
            l->right = dl->right;
            dl->right->left = l;
            mp.erase(dl->key);
            delete dl;
        }
    }
};
