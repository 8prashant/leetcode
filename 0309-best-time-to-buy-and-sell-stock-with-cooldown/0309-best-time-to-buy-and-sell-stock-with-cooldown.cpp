class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<int>& prices,int i , int n, int buy){
        if(i>=n){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        int ans=0;
        if(buy==0){
            ans= max({
                ans,
                dfs(prices,i+1,n,1)-prices[i],
                dfs(prices,i+1,n,buy)
            });
        }
        else if(buy==1){
            ans= max({
                ans,
                dfs(prices,i+2,n,0)+prices[i],
                dfs(prices,i+1,n,buy)
            });
        }
        return dp[i][buy]=ans;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.assign(n,vector<int>(2,-1));
        return dfs(prices,0,n,0);
    }
};