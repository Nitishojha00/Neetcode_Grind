/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Codec {
public:

    void dfs(vector<string>&v , TreeNode *root)
    {
        if(!root)
        {
            v.push_back("N");
            return;
        }

        v.push_back(to_string(root->val));
        dfs(v,root->left);
        dfs(v,root->right);
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        vector<string>v;
        dfs(v,root);
        string s = "";
        for(int  i=0;i<v.size();i++)
        {
            s+=v[i];
            s+='#';
        }
        return s;
    }

    TreeNode *makeTree(int &i , vector<string>&v)
    {
        if(v[i]=="N")
        {
            i++;
            return nullptr;
        }

        TreeNode *root;
        root = new TreeNode(stoi(v[i++]));
        root->left = makeTree(i,v);
        root->right = makeTree(i,v);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        vector<string>v;
        string s;
        int i = 0;
        int n = data.size();
        while(i < n)
        {
            string s = "";
            while(i < n && data[i] != '#')
                s += data[i++];

            v.push_back(s);
            i++;
        }
        i = 0;
        return makeTree(i,v);
    }
};
