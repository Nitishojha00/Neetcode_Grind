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
   bool ans = true;
   bool z = false;
    void isSame(TreeNode* p, TreeNode* q) {
        if (!ans) return;          // already false → stop
        if (!p && !q) return;      // both null → ok
        if (!p || !q) {            // one null → mismatch
            ans = false;
            return;
        }
        if (p->val != q->val) {    // value mismatch
            ans = false;
            return;
        }
        isSame(p->left, q->left);
        isSame(p->right, q->right);
    }

    bool isSameTree(TreeNode* p, TreeNode* q) {
        ans = true;      // ✅ reset before checking
        isSame(p, q);
        return ans;   // ✅ return directly
    }


void solve(TreeNode *root  , TreeNode *sub)
{
    if(!root || z) return;

    if(root->val == sub->val) {
    if(isSameTree(root, sub)) {
        z = true;
        return;   // ✅ we found it, stop further recursion
    }
}


    solve(root->left,sub);
    solve(root->right,sub);
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        solve(root,subRoot);
        return z;
    }
};
