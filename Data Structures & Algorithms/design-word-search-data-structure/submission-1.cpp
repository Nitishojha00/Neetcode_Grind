class WordDictionary {
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
    WordDictionary() {
        head = new Node();
    }
    
    void addWord(string word) {
         // 100% shi hai
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

    bool searchP(string word , Node *root ) {
        
        int n  = word.size();
        for(int i=0;i<n;i++)
        {
            if(word[i]=='.')
            {
                string str;
                for(int j=i+1;j<n;j++)
                {
                    str+= word[j];
                }
                for(int i=0;i<26;i++)
                {
                    if(root->v[i] && searchP(str,root->v[i])) return true;
                    
                }
                return false;
            }
            int idx = word[i]-'a';
            if(!root->v[idx]) return false;
            root = root->v[idx];
        }

        return root->end;
    }
    
    bool search(string word) {
        Node *root = head;
        int n  = word.size();
        for(int i=0;i<n;i++)
        {
            if(word[i]=='.')
            {
                string str;
                for(int j=i+1;j<n;j++)
                {
                    str+= word[j];
                }
                for(int i=0;i<26;i++)
                {
                    if(root->v[i] && searchP(str,root->v[i])) return true;
                }
                    return false;
            }
            int idx = word[i]-'a';
            if(!root->v[idx]) return false;
            root = root->v[idx];
        }

        return root->end;
    }
};
