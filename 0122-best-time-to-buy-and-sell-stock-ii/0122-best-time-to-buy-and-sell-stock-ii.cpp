class Solution {
public:
    vector<vector<int>> dp;
    int dfs(vector<int>& prices,int p,int n , bool buy){
        if(p==n){
            return 0;
        }
        if(dp[p][buy]!=-1){
            return dp[p][buy];
        }
        if(!buy){
            return dp[p][buy]=max(
                -(prices[p])+dfs(prices,p+1,n,true),
                dfs(prices,p+1,n,buy)
            );
        }
        else{
            return dp[p][buy]=max(
                prices[p]+dfs(prices,p+1,n,false),
                dfs(prices,p+1,n,buy)
            );
        }
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        dp.assign(n,vector<int>(3,-1));
        return dfs(prices,0,n,false);
    }
};