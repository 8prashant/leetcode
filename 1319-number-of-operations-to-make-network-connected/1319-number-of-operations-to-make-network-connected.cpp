class Solution {
public:
    int scc=0,ce=0;//scc=strongly connected computers, sce=crital edges
    int level=0;
    void dfs(int a,int parent,vector<vector<int>> &graph,vector<int> &dis,vector<int> &sdis,vector<int> &vis){
        vis[a]=1;
        // scc++;
        if(graph[a].size()>0){
            scc++;
        }
        dis[a]=sdis[a]=level;
        level++;
        for(auto x:graph[a]){
            if(x==parent){
                continue;
            }
            else if(vis[x]!=-1){
                sdis[a]=min(sdis[a],sdis[x]);
            }
            else{
                dfs(x,a,graph,dis,sdis,vis);
                sdis[a]=min(sdis[a],sdis[x]);
                if(sdis[x]>dis[a]){
                    cout<<"critical edge={"<<a<<","<<x<<"}"<<endl;
                    ce++;
                }
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        // sce=connections.size();
        vector<vector<int>> graph(n);
        for(auto x:connections){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int> vis(n, -1);
        vector<int> dis(n, INT_MAX);
        vector<int> sdis(n, INT_MAX);
        int e=-1;
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                e++;
                dfs(i,-1,graph,dis,sdis,vis);
            }
        }
        // int ae=connections.size()-(scc-1)-ce;
        int ae=connections.size()-(scc-1);
        if(scc==n){
            return 0;
        }

        cout<<"scc="<<scc<<" ce="<<ce<<" e="<<e<<" ae="<<ae<<endl;
        return ae>=e?e:-1;
    }
};