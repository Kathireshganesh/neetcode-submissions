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

class Codec {
public:

    // Encodes a tree to a single string.
    void serializeHelper(TreeNode* root,string& s){
        if(root==NULL){
            s+="N,";
            return;
        }
        s+=to_string(root->val)+",";

        serializeHelper(root->left,s);
        serializeHelper(root->right,s);

    
    }
    string serialize(TreeNode* root) {
        string s;
        serializeHelper(root,s);
        return s;
    }

    // Decodes your encoded data to tree.
   TreeNode* deserializeHelper(stringstream& ss){
         string value;
          getline(ss,value,',');

          if(value=="N"){
            return NULL;
          }

        TreeNode* root=new TreeNode(stoi(value));

        root->left=deserializeHelper(ss);
        root->right=deserializeHelper(ss);

        return root;
   }

    TreeNode* deserialize(string data) {
       stringstream ss(data);

        return deserializeHelper(ss);    
    }
};
