class Solution {
public:
    vector<vector<int>>dp;
    int check(int i,bool buy,vector<int>& p, int &fee){
        if(i>=p.size()){
            return 0;
        }
        if(dp[i][buy]!=-1){
            return dp[i][buy];
        }
        if(buy==true){
            return dp[i][buy]=max(
                -p[i]+check(i+1,false,p,fee),
                check(i+1,buy,p,fee)
            );
        }
        return dp[i][buy]=max(
            p[i]-fee+check(i+1,true,p,fee),
            check(i+1,buy,p,fee)
        );
    }
    int maxProfit(vector<int>& p, int fee) {
        dp.resize(p.size(),vector<int>(2,-1));
        return check(0,true,p,fee);
    }
};