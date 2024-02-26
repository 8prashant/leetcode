class Solution {
public:
    vector<int> dp;
    int dfs(int i,int n,vector<int>& cost){
        if(i>=n){
            return 0;
        }

        if(dp[i]!=-1){
            return dp[i];
        }
        int ans=INT_MAX;
        ans=min(ans,cost[i]+dfs(i+1,n,cost));
        ans=min(ans,cost[i]+dfs(i+2,n,cost));
        // cout<<i<<" ans="<<ans<<endl;
        return dp[i]=ans;
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        dp.assign(n,-1);
        int ans=min({dfs(0,n,cost),dfs(1,n,cost)});
        return ans;
    }
};