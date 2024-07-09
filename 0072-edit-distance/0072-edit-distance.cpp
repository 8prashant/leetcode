class Solution {
public:

//              MEMOIZATION

//     vector<vector<int>>dp;
//     int check(string &w1, string &w2,int i,int j){
//         if(i<0 && j<0){
//             return 0;
//         }
//         if(i<0){
//             return j+1;
//         }
//         if(j<0){
//             return i+1;
//         }
//         if (dp[i][j] != -1) {
//             return dp[i][j];
//         }
//         if(w1[i]==w2[j]){
//             return dp[i][j]=check(w1,w2,i-1,j-1);
//         }
//         return dp[i][j]=min({1+check(w1,w2,i-1,j),1+check(w1,w2,i,j-1),1+check(w1,w2,i-1,j-1)});
//     }
    int minDistance(string w1, string w2) {
        // dp.resize(w1.size(),vector<int>(w2.size(),-1));
        // return check(w1,w2,w1.size()-1,w2.size()-1);

//                               TABULATION

        vector<vector<size_t>> dp(w1.size()+1,vector<size_t>(w2.size()+1));
        dp[0][0]=0;
        for(size_t i=1;i<=w2.size();i++){
            dp[0][i]=i;
        }
        for(size_t i=1;i<=w1.size();i++){
            dp[i][0]=i;
        }
        for(size_t i=1;i<=w1.size();i++){
            for(size_t j=1;j<=w2.size();j++){
                if(w1[i-1]==w2[j-1]){
                    dp[i][j]=dp[i-1][j-1];
                }
                else{
                    dp[i][j]=min({1+dp[i-1][j],1+dp[i][j-1],1+dp[i-1][j-1]});
                }
            }
        }
        return dp[w1.size()][w2.size()];

    }
};