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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        stack<TreeNode*>s;stack<TreeNode*>t;
        s.push(p);t.push(q);
        while(!s.empty() && !t.empty()){
            TreeNode* x=s.top();s.pop();
            TreeNode* y=t.top();t.pop();
            if(!x && !y)continue;
            if((!y && x) ||(!x && y)||x->val!=y->val)return false;
            s.push(x->left);s.push(x->right);
            t.push(y->left);t.push(y->right);
        }
        return true;
    }
};
