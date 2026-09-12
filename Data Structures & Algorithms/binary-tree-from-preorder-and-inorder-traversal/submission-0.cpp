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
    unordered_map<int,int> mp;
    int preindex=0;
    TreeNode* solve(vector<int>& preorder,int start,int end){
           if(start>end) return NULL;
           int val=preorder[preindex++];

           TreeNode* root=new TreeNode(val);

           int index=mp[val];

           root->left=solve(preorder,start,index-1);
           root->right=solve(preorder,index+1,end);

           return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
       return  solve(preorder,0,inorder.size()-1);
    }
};
