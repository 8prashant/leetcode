class Solution {
public:
    void dfs2(int a,vector<vector<int>> &graph,vector<int> &v,int &size){
        v[a]=1;
        for(auto x:graph[a]){
            if(v[x]==-1){
                size++;
                dfs2(x,graph,v,size);
            }
        }
    }
    bool dfs(int a,vector<vector<int>> &graph,vector<int> &vis,int &size){
        vis[a]=1;
        bool ans;
        if(graph[a].size()==size){
            ans=true;
        }
        else{
            ans=false;
        }
        for(auto x:graph[a]){
            if(vis[x]==-1){
                bool res=dfs(x,graph,vis,size);
                ans =ans && res;
            }
        }
        return ans;
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for(auto x:edges){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int> vis(n,-1);
        int ans=0;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                int size=0;
                vector<int> v(n,-1);
                dfs2(i,graph,v,size);
                bool check=dfs(i,graph,vis,size);
                if(check==true){
                    ans+=1;
                }
            }
        }
        return ans;
    }
};