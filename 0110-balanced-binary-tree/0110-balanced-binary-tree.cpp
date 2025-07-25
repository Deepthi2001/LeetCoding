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
    int height(TreeNode* root,bool &isBalancedFlag){
        if(!root) return 0;
        int lh=height(root->left,isBalancedFlag);
        int rh=height(root->right,isBalancedFlag);
        if(abs(lh-rh)>1) isBalancedFlag=false;
        return 1+max(lh,rh);
    }
    bool isBalanced(TreeNode* root) {
        bool isBalancedFlag=true;
        height(root,isBalancedFlag);
        return isBalancedFlag;
    }
};