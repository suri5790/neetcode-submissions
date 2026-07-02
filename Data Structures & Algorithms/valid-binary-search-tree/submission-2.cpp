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
    bool isValidBST(TreeNode* root) {
        stack<pair<TreeNode*,pair<long long,long long >>>st;
        st.push({root,{LLONG_MIN,LLONG_MAX}});
        while(!st.empty()){
            auto it=st.top();st.pop();
            if(it.first->left)st.push({it.first->left,{it.second.first,it.first->val}});
            if(it.first->right)st.push({it.first->right,{it.first->val,it.second.second}});
            if(it.first->val>=it.second.second ||it.first->val<=it.second.first)return false;
        }
        return true;
    }
};