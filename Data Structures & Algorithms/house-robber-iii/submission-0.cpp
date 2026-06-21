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
pair<int,int> dfs(TreeNode *root)
{
        if(!root) return {0,0};

        auto p = dfs(root->left);
        auto q = dfs(root->right);

        int withRoot = p.second+root->val+q.second;
        int withoutRoot = max(p.first,p.second)+max(q.first,q.second);
        return {withRoot,withoutRoot};
}
    int rob(TreeNode* root) {
        // somethink like dp
        auto result = dfs(root);
        return max(result.first, result.second);
    }
};