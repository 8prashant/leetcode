                                //MEMOIZATION
// class Solution {
// public:
//     vector<vector<int>> dp;
//     int check(int i,bool buy,vector<int>& p){
//         if(i>=p.size()){
//             return 0;
//         }
//         if(dp[i][buy]!=-1){
//             return dp[i][buy];
//         }
//         if(buy){
//             return dp[i][buy]=max(
//                 -p[i]+check(i+1,false,p),
//                 check(i+1,buy,p)
//             );
//         }
//         return dp[i][buy]=max(
//             +p[i]+check(i+1,true,p),
//             check(i+1,buy,p)
//         );
//     }
//     int maxProfit(vector<int>& prices) {
//         dp.resize(prices.size(),vector<int>(2,-1));
//         return check(0,true,prices);
//     }
// };
                                //TABULATION
 
class Solution {
public:
    int maxProfit(vector<int>& p) {
        vector<vector<int>> dp(p.size()+1,vector<int>(2));
        int n=p.size();
        dp[n][0]=dp[n][1]=0;

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==0){
                    dp[i][j]=max(-p[i]+dp[i+1][1],dp[i+1][0]);
                }
                else{
                    dp[i][j]=max(p[i]+dp[i+1][0],dp[i+1][1]);
                }
            }
        }
        return dp[0][0];
    }
};
