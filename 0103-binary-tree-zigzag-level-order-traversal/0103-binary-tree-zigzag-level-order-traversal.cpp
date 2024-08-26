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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        deque<TreeNode*>dq;
        vector<vector<int>>ans;
        dq.push_back(root);
        int i=1;
        while(!dq.empty()){
            int s=dq.size();
            if(i%2!=0){
                vector<int>a;
                for(int i=0;i<s;i++){
                    TreeNode* curr=dq.front();
                    dq.pop_front();
                    a.push_back(curr->val);
                    if(curr->left!=NULL){
                        dq.push_back(curr->left);
                    }
                    if(curr->right!=NULL){
                        dq.push_back(curr->right);
                    }
                }
                ans.push_back(a);
                i++;
            }
            else{
                vector<int>a;
                for(int i=0;i<s;i++){
                    TreeNode* curr=dq.back();
                    dq.pop_back();
                    a.push_back(curr->val);
                    if(curr->right!=NULL){
                        dq.push_front(curr->right);
                    }
                    if(curr->left!=NULL){
                        dq.push_front(curr->left);
                    }
                }
                ans.push_back(a);
                i++;
            }
        }
        return ans;
    }
};