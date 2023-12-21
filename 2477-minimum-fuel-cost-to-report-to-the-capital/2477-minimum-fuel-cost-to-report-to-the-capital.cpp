class Solution {
public:
    long long int ans=0;
    vector<long long int> dfs(long long int a,vector<vector<long long int>> &graph,vector<long long int> &vis,int &space){
        long long int car=0,seats=0;
        vis[a]=1;
        for(auto x:graph[a]){
            if(vis[x]==-1){
                vector<long long int> v=dfs(x,graph,vis,space);
                ans+=v[0];
                car+=v[0];
                seats+=v[1];
            }
        }
        car-=seats/space;
        seats=seats%space;
        if(seats==0){
            car+=1;
            seats=space;
        }
        return {car, seats - 1};
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        long long int n=0;
        vector<vector<long long int>> graph(100000);
        for(auto x:roads){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        vector<long long int> vis(100000,-1);
        vis[0]=1;
        vector<long long int> v;
        for(auto x:graph[0]){
            v=dfs(x,graph,vis,seats);
            ans+=v[0];
        }
        return ans;
    }
};