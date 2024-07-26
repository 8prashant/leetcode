class Solution {
public:
    int dij(int src,int n,vector<vector<pair<int,int>>> &graph,int &distanceThreshold){
        vector<int> vis(n,-1);
        vector<int> ans(n,INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        pq.push({0,src});
        ans[src]=0;
        while(!pq.empty()){
            vector<int> v=pq.top();
            pq.pop();
            int node=v[1],weight=v[0];
            if(vis[node]!=-1){
                continue;
            }
            vis[node]=1;
            for(auto x:graph[node]){
                int no=x.first,we=x.second;
                if(vis[no]==-1){
                    ans[no]=min(ans[no],we+weight);
                    pq.push({ans[no],no});
                }
            }
        }
        int res=0;
        cout<<"src="<<src<<"->";
        for(auto x:ans){
            cout<<x<<" ";
            if(x<=distanceThreshold){
                res++;
            }
        }
        cout<<endl;
        return res;
    }
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto x:edges){
            graph[x[0]].push_back({x[1],x[2]});
            graph[x[1]].push_back({x[0],x[2]});
        }
        int mi=INT_MAX,ma=INT_MIN;
        for(int i=0;i<n;i++){
            int ans=dij(i,n,graph,distanceThreshold);
            if(ans<mi){
                mi=ans;
                ma=i;
            }
            else if(ans==mi){
                ma=max(ma,i);
            }
            cout<<"i="<<i<<" "<<ans<<endl;
        }
        return ma;
        
    }
};