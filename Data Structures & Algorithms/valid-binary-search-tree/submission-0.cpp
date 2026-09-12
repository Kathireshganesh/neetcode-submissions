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
    bool solve(TreeNode* root, long long min, long long max) {
        if (root == NULL) return true;

        if (root->val <= min || root->val >= max) return false;
        if (!solve(root->left, min, root->val)) return false;

        if (!solve(root->right, root->val, max)) return false;

        return true;
    }
    bool isValidBST(TreeNode* root) {


        return solve(root, LLONG_MIN, LLONG_MAX);
    }
};
