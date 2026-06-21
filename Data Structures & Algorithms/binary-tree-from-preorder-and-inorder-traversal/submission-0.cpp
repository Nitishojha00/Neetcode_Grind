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
int i = 0;
    TreeNode *makeTree(vector<int>& preorder, vector<int>& inorder, int l , int r)
    {
        if(l>r)  return nullptr;
        
        TreeNode *root = new TreeNode(preorder[i]);
        int j;
        for( j=l;j<r;j++)
        {
            if(inorder[j]==preorder[i]) break;
        }
        i++;
       root->left = makeTree(preorder,inorder,l,j-1);
       root->right = makeTree(preorder,inorder,j+1,r);
       return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        return makeTree(preorder,inorder,0,preorder.size()-1);
    }
};
