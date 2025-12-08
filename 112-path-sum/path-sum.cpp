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
private:
    bool rec(TreeNode* root, int targetSum){
        if(root==NULL)  return false;
        if(!root->left && !root->right)    return (targetSum==root->val);
        bool left=rec(root->left,targetSum-root->val);
        bool right=rec(root->right,targetSum-root->val);
        return left||right;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return rec(root,targetSum);
    }
};