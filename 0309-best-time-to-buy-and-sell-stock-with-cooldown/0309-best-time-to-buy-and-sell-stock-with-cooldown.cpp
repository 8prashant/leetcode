class Solution {
public:
    vector<vector<int>>dp;
    int check(int i,bool buy,vector<int>& p){
        if(i>=p.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        if(buy==true){
            return dp[i][buy]=max(
                -p[i]+check(i+1,false,p),
                check(i+1,buy,p)
            );
        }
        return dp[i][buy]=max(
            p[i]+check(i+2,true,p),
            check(i+1,buy,p)
        );
    }
    int maxProfit(vector<int>& p) {
        dp.resize(p.size(),vector<int>(2,-1));
        return check(0,true,p);
    }
};