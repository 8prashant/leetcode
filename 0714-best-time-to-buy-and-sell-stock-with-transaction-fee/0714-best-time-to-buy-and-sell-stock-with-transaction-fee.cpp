class Solution {
public:
    vector<vector<int>>dp;
    int dfs(int p,int n,vector<int>& prices,int buy,int fee){
        if(p==n){
            return 0;
        }
        if(dp[p][buy]!=-1){
            return dp[p][buy];
        }
        if(buy==0){
            return dp[p][buy]=max(
                dfs(p+1,n,prices,1,fee)-prices[p],
                dfs(p+1,n,prices,buy,fee)
            );
        }
        return dp[p][buy]=max(
            dfs(p+1,n,prices,0,fee)+(prices[p]-fee),
            dfs(p+1,n,prices,buy,fee)
        );
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n=prices.size();
        dp.assign(n,vector<int>(2,-1));
        return dfs(0,n,prices,0,fee);
    }
};