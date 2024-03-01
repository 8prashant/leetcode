class Solution {
public:
    vector<vector<vector<int>>> dp;
    int dfs(int k, vector<int>& prices,int i , int n,int buy){
        if(i==n || k==0){
            return 0;
        }
        if(dp[i][k][buy]!=-1){
            return dp[i][k][buy];
        }
        int ans=0;
        if(buy==0){
            ans=max({
                ans,
                dfs(k,prices,i+1,n,1)-prices[i],
                dfs(k,prices,i+1,n,buy)
            });
        }
        if(buy==1){
            ans=max({
                ans,
                dfs(k-1,prices,i+1,n,0)+prices[i],
                dfs(k,prices,i+1,n,buy)
            });
        }
        return dp[i][k][buy]=ans;
    }
    int maxProfit(int k, vector<int>& prices) {
        int n=prices.size();
        dp.assign(n,vector<vector<int>>(k+1,vector<int>(2,-1)));
        return dfs(k,prices,0,n,0);
    }
};