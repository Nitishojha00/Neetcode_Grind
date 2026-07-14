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

class Solution {
public:
int i;
    TreeNode* makeTree( int l , int r , vector<int>&pre , vector<int>&in)
    {
        if(l>r)
           return nullptr;


       TreeNode* temp = new TreeNode();
        for(int j=l;j<=r;j++)
        {
            if(in[j]==pre[i])
            {
                temp->val = pre[i++];
                temp->left = makeTree(l,j-1,pre,in);
                temp->right = makeTree(j+1,r,pre,in);
                break;
            }
        }
        return temp;
    }


    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        
         i = 0;
         int n = inorder.size();
         return makeTree(0,n-1,preorder,inorder);
    }
};