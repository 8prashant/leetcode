class Solution {
public:
    int scc=0;
    void dfs(int a,vector<vector<int>> &graph,vector<int> &vis){
        vis[a]=1;
        if(graph[a].size()>0){
            scc++;
        }
        for(auto x:graph[a]){
            if(vis[x]==-1){
                dfs(x,graph,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>> graph(n);
        for(auto x:connections){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int> vis(n, -1);
        int e=-1;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                e++;
                dfs(i,graph,vis);
            }
        }
        int ae=connections.size()-(scc-1);
        if(scc==n){
            return 0;
        }
        return ae>=e?e:-1;
    }
};