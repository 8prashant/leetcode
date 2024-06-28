class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,int>m;
        vector<int>vis(n,-1);
        for(auto x:roads){
            m[x[0]]++;
            m[x[1]]++;
            vis[x[0]]=1;
            vis[x[1]]=1;
        }
        for(int i=0;i<n;i++){
            if(vis[i]==-1){
                m[i]=0;
            }
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(auto x:m){
            pq.push({x.second,x.first});
        }
        long long int sum=1;
        unordered_map<int,int>value;
        while(!pq.empty()){
            pair<int,int>t=pq.top();
            pq.pop();
            value[t.second]=sum;
            sum++;
        }
        long long int ans=0;
        for(auto x:roads){
            ans+=value[x[0]]+value[x[1]];
        }
        return ans;
    }
};