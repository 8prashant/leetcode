class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>> graph(n+1);
        for(auto x:times){
            graph[x[0]].push_back({x[1],x[2]});
        }
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<int> vis(n+1,-1);
        vector<int> dis(n+1,INT_MAX);
        dis[0]=INT_MIN;
        dis[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            vector<int> v=pq.top();
            pq.pop();
            int node=v[1],weight=v[0];
            if(vis[node]==1){
                continue;
            }
            vis[node]=1;
            for(auto& x:graph[node]){
                int no=x.first,we=x.second;
                if(vis[no]==-1){
                    dis[no]=min(dis[no],weight+we);
                    pq.push({dis[no],no});
                }
            }
        }
        sort(dis.begin(),dis.end());
        return dis[n]==INT_MAX?-1:dis[n];
        
    }
};