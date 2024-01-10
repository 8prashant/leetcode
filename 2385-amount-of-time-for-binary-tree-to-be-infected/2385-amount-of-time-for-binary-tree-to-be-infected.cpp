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
    unordered_map<int,vector<int>> m;
    int n=0;
    void dfs(TreeNode* root){
        if(root->left!=NULL){
            n=max(n,root->left->val);
            m[root->val-1].push_back(root->left->val-1);
            m[root->left->val-1].push_back(root->val-1);
            dfs(root->left);
        }
        if(root->right!=NULL){
            n=max(n,root->right->val);
            m[root->val-1].push_back(root->right->val-1);
            m[root->right->val-1].push_back(root->val-1);
            dfs(root->right);
        }
    }
    int amountOfTime(TreeNode* root, int start) {
        n=max(n,root->val);
        dfs(root);
        vector<int> ans(n,INT_MAX);
        vector<int> vis(n,-1);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>>pq;
        pq.push({0,start-1});
        ans[start-1]=0;
        int res=0;
        while(!pq.empty()){
            vector<int> t=pq.top();
            pq.pop();
            int weight=t[0];
            int node=t[1];
            res=max(res,weight);
            if(vis[node]!=-1){
                continue;
            }
            vis[node]=1;
            for(auto x:m[node]){
                ans[x]=min(ans[x],ans[node]+1);
                pq.push({ans[x],x});
            }
        }
        return res;
    }
};