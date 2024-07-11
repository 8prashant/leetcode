class Solution {
public:
    vector<vector<vector<int>>>dp;
    int check(int i,int t,bool buy,vector<int>& p){
        if(i>=p.size() || t>=2){
            return 0;
        }
        if(dp[i][buy][t]!=-1){
            return dp[i][buy][t];
        }
        if(buy){
            return dp[i][buy][t]=max(-p[i]+check(i+1,t,false,p),check(i+1,t,buy,p));
        }
        return dp[i][buy][t]=max(p[i]+check(i+1,t+1,true,p),check(i+1,t,buy,p));
    }
    int maxProfit(vector<int>& prices) {
        dp.resize(prices.size(),vector<vector<int>>(2,vector<int>(2,-1)));
        return check(0,0,true,prices);
    }
};