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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return nullptr;

        int value = root->val;
        if(value>key)
        {
            root->left = deleteNode(root->left,key);
        }
        else if(value<key)
        {
            root->right = deleteNode(root->right,key);
        }
        else
        {
            if(root->right && root->left)
            {
                TreeNode *curr = root->right;
                TreeNode *prev = root;
                while(curr->left)
                {
                    prev = curr;
                    curr = curr->left;
                }
               swap(root->val,curr->val);
               prev->right = curr->right;
               delete curr;
               return root;
            }
            else if(root->left)
            {
                TreeNode *temp = root->left;
                delete root;
                return temp;
            }
            else if(root->right)
            {
                TreeNode *temp = root->right;
                delete root;
                return temp;
            }
            else
            {
                delete root;
                return nullptr;
            }
        }
        return root;
    }
};