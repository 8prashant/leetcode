class Graph {
public:
    vector<vector<pair<int,int>>> cc;
    int node;
    Graph(int n, vector<vector<int>>& edges) :cc(n) {
        node=n;
        for(auto x:edges){
            cc[x[0]].push_back({x[1],x[2]});
        }
    }
    
    void addEdge(vector<int> edge) {
        cc[edge[0]].push_back({edge[1],edge[2]});
    }
    
    int shortestPath(int node1, int node2) {
        vector<int> dis(node,INT_MAX);
        vector<int> vis(node,-1);
        dis[node1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,node1});
        while(!pq.empty() && vis[node2]==-1){
            pair<int,int> p=pq.top();
            pq.pop();
            int weight=p.first;
            int a=p.second;
            if (vis[a]==1) continue; // Skip if the vertex has already been visited
            vis[a]=1;
            for(auto x:cc[a]){
                int we=x.second;
                int no=x.first;
                if(vis[no]==-1){
                    dis[no]=min(dis[no],dis[a]+we);
                    pq.push({dis[no],no});
                }
            }
        }
        return dis[node2]==INT_MAX?-1:dis[node2];

    }
};