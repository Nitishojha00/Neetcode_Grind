class Solution {
public:
    bool ans = true;

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
        isSame(p, q);
        return ans;   // ✅ return directly
    }
};
