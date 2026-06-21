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
int ans = INT_MIN;
    int maxPathsum(TreeNode* root) {
        if(!root) return 0;

        int val1 = maxPathsum(root->left);
        int val2 = maxPathsum(root->right);

        ans = max(ans,max({root->val,val1+val2+root->val,val1+root->val,val2+root->val}));
        return max({root->val,val1+root->val,val2+root->val});
    }
     int maxPathSum(TreeNode* root) {
        maxPathsum(root);
        return ans;
     }
};
