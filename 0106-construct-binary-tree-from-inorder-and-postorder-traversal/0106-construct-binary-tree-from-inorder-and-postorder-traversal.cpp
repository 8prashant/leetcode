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
    TreeNode* check(vector<int>& postorder, vector<int>& inorder,int i,int j,int x,int y){
        if(x>y){
            return NULL;
        }
        for(int l=x;l<=y;l++){
            if(inorder[l]==postorder[j]){
                TreeNode* root=new TreeNode{inorder[l],nullptr,nullptr};
                root->left=check(postorder,inorder,i,(i+(l-x)-1),x,l-1);
                root->right=check(postorder,inorder,i+(l-x),j-1,l+1,y);
                return root;
            }
        }
        return NULL;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return check(postorder,inorder,0,postorder.size()-1,0,inorder.size()-1);
    }
};