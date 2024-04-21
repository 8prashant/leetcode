class Solution {
public:
    bool check(vector<vector<int>> &v,vector<int> &vis,int &s, int &d){
        if(s==d){
            return true;
        }
        bool ans=false;
        vis[s]=1;
        for(auto x:v[s]){
            if(vis[x]==-1){
                ans=ans||check(v,vis,x,d);
            }
        }
        return ans;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> v(n);
        for(auto x:edges){
            v[x[0]].push_back(x[1]);
            v[x[1]].push_back(x[0]);
        }
        vector<int> vis(n,-1);
        return check(v,vis,source,destination);
    }
};