class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        vector<vector<long long int>> graph(n);
        for(auto x:roads){
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        priority_queue<pair<long long int,long long int>> pq;
        for(long long int i=0;i<n;i++){
            pq.push({(graph[i].size()),i});
        }
        unordered_map<long long int,long long int> m;
        long long int i=n;
        while(!pq.empty()){
            pair<long long int,long long int> a=pq.top();
            pq.pop();
            m[a.second]=i;
            i--;
        }   
        long long int ans=0;
        for(auto x:roads){
            ans+=(m[x[0]]+m[x[1]]);
        }
        return ans;
    }
};