class Solution {
public:
    map<vector<int>,int> m;
    int level=0;
    void dfs(int a,int parent,vector<vector<int>> &graph,vector<int> &dis,vector<int> &sdis,vector<int> &vis){
        dis[a]=sdis[a]=level;
        vis[a]=1;
        level+=1;
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
                    vector<int> v={(min(x,a)),(max(x,a))};
                    auto it=m.find(v);
                    if(it!=m.end()){
                        m.erase(it);
                    }
                }
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=0;
        int i=0;
        for (auto x : edges) {
            n = max({n, x[0], x[1]});
            m[{x[0], x[1]}] = i;
            i++;
        }

        vector<vector<int>> graph(n + 1);
        for(auto x:edges){
            n=max({n,x[0],x[1]});
            m[{x[0],x[1]}]=i;i++;
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<int> vis(n + 1, -1);
        vector<int> dis(n + 1, INT_MAX);
        vector<int> sdis(n + 1, INT_MAX);
        for(int i=1;i<=n;i++){
            if(vis[i]==-1){
                dfs(i,-1,graph,dis,sdis,vis);
            }
        }
        vector<int> ans;
        int ma=INT_MIN;
        for(auto x:m){
            if(x.second>ma){
                ma=x.second;
                ans=x.first;
            }
        }
        return ans;

    }
};