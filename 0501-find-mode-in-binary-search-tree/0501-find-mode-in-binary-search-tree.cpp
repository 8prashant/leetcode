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
    vector<int> findMode(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        queue<TreeNode*> q;
        q.push(root);
        unordered_map<int,int>m;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* a=q.front();
                q.pop();
                m[a->val]++;
                if(a->left!=NULL){
                    q.push(a->left);
                }
                if(a->right!=NULL){
                    q.push(a->right);
                }
            }
        }
        unordered_map<int,vector<int>>rm;
        int ma=0;
        for(auto x:m){
            ma=max(ma,x.second);
            rm[x.second].push_back(x.first);
        }
        return rm[ma];
        
    }
};