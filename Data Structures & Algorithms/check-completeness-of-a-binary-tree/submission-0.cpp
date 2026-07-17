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
    bool isCompleteTree(TreeNode* root) {
        
        queue<TreeNode*>q;
        q.push(root);
        int level = 0 , lastLevel = 0;
        while(!q.empty())
        {
            int n = q.size();
            if(n!=pow(2,level)) lastLevel++;
            while(n--)
            {
                auto temp = q.front();
                q.pop();
                if(temp->right && !temp->left) return false;

                if((temp->left || temp->right) && lastLevel)
                    return false;
                if(temp->left)
                    q.push(temp->left);
                if(temp->right) 
                   q.push(temp->right);
            }
            level++;
        }
        return true;
    }
};