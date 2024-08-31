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
    TreeNode* check(vector<int>& preorder, vector<int>& inorder,int i,int x,int y){
        if(x>y){
            return NULL;
        }
        for(int l=x;l<=y;l++){
            if(inorder[l]==preorder[i]){
                TreeNode* root=new TreeNode{inorder[l],nullptr,nullptr};
                root->left=check(preorder,inorder,i+1,x,l-1);
                root->right=check(preorder,inorder,i+(l-x)+1,l+1,y);
                return root;
            }
        }
        return NULL;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return check(preorder,inorder,0,0,inorder.size()-1);
    }
};