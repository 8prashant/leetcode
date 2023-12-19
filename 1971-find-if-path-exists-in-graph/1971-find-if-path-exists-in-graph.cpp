class Solution {
public:
    bool dfs(int a,vector<vector<int>>& graph, int source, int destination,vector<int> &vis){
        vis[a]=1;
        if(a==destination){
            return true;
        }
        bool ans=false;
        for(auto x:graph[a]){
            if(vis[x]==-1){
                ans=ans || dfs(x,graph,source,destination,vis);
            }
        }
        return ans;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if(source>=n || destination>=n){
            return false;
        }
        vector<vector<int>> graph(n);
        for(auto x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int> vis(n,-1);
        return dfs(source,graph,source,destination,vis);
        
    }
};