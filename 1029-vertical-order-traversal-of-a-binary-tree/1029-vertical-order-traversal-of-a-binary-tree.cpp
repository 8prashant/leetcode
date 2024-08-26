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
    unordered_map<int,vector<pair<int,int>>>m;
    void check(TreeNode* root,int x,int y){
        if(root==NULL){
            return;
        }
        m[y].push_back({x,root->val});
        check(root->left,x+1,y-1);
        check(root->right,x+1,y+1);
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        if(root==NULL){
            return {};
        }
        check(root,0,0);
        priority_queue<pair<int,vector<pair<int,int>>>,vector<pair<int,vector<pair<int,int>>>>,greater<pair<int,vector<pair<int,int>>>>>pq;
        for(auto x:m){
            pq.push({x.first,x.second});
        }
        vector<vector<int>>ans;
        while(!pq.empty()){
            pair<int,vector<pair<int,int>>>p=pq.top();
            pq.pop();
            vector<pair<int,int>>v=p.second;
            sort(v.begin(),v.end());
            vector<int>res;
            for(auto x:v){
                res.push_back(x.second);
            }
            ans.push_back(res);
        }
        return ans;
    }
};