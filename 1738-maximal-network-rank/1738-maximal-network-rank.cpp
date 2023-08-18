class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
       vector<vector<int>> adj(n, vector<int> (n));

       vector<int> indegree(n,0);
       for(auto x: roads)
       {
           adj[x[0]][x[1]]=adj[x[1]][x[0]]=1;
           indegree[x[0]]++;
           indegree[x[1]]++;
       }

       int rank=0;

       for(int i=0;i<n;i++)
       {
           for(int j=i+1;j<n;j++)
           {
               rank= max(rank, indegree[i]+indegree[j]-adj[i][j]);
           }
       }

       return rank;
       
    }
};