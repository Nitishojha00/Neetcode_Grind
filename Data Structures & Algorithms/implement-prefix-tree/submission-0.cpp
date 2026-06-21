class PrefixTree {
public:

class Node{
   public: vector<Node*>v;
    bool end;
    Node()
    {
        v.resize(26);
        for(int i=0;i<26;i++) 
         v[i] = nullptr;
     
        end = false;
    }
};
    Node *head;

    PrefixTree() {
        head = new Node();
    }
    
    void insert(string word) { // 100% shi hai
        // insert kro pehele waha tk phuch jao jaha tk hojai
        Node *root = head;
        int n  = word.size();
        int  i;
        for(i=0;i<n && root->v[word[i]-'a']!=nullptr;i++) // jaha tk exist kre jao
            root = root->v[word[i]-'a'];
        
        for(;i<n;i++)
        {
            auto idx = word[i]-'a';
            root->v[idx] = new Node();
            root = root->v[idx];
        }
        root->end = true;
    }
    
    bool search(string word) {
        Node *root = head;
        int n  = word.size();
        for(int i=0;i<n;i++)
        {
            int idx = word[i]-'a';
            if(!root->v[idx]) return false;
            root = root->v[idx];
        }

        return root->end;
    }
    
    bool startsWith(string word) {
        Node *root = head;
        int n  = word.size();
        for(int i=0;i<n;i++)
        {
            int idx = word[i]-'a';
            if(!root->v[idx]) return false;
            root = root->v[idx];
        }

        return true;
    }
};
