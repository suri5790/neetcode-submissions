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
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode* &res){
        if(!root)return false;
        bool left=dfs(root->left,p,q,res);
        bool right=dfs(root->right,p,q,res);
        if((root==q ||root==p) && (left||right)){res=root;}
        if(left && right){res=root;}
        if(root==q||root==p)return true;
        return left||right;
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* res=nullptr;
        bool ch=dfs(root,p,q,res);
        return res;
    }
};
