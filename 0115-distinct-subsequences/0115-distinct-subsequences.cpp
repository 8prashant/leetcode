//                             LCS TABEL+PRINT LCS APPROCH
// class Solution {
// public:
//     vector<vector<int>> dpp;
//     int check(vector<vector<int>> &dp ,string &t1, string &t2,int i,int j , int ma ){
//         if(i<=0 || j<=0){
//             return 1;
//         }
//         if(dpp[i][j]!=-1){
//             return dpp[i][j];
//         }
//         int ans=0;
//         for(int l=1;l<=i;l++){
//             if(dp[l][j]==ma && t1[l-1]==t2[j-1]){
//                 ans+=check(dp,t1,t2,l-1,j-1,ma-1);
//             }
//         }
//         return dpp[i][j]=ans;
//     }


//     int numDistinct(string t1, string t2) {
//         if(t2.size()>t1.size()){
//             return 0;
//         }
//         vector<vector<int>> dp(t1.size()+1,vector<int>(t2.size()+1,-1));
//         for(int i=0;i<=t2.size();i++){
//             dp[0][i]=0;
//         }
//         for(int i=0;i<=t1.size();i++){
//             dp[i][0]=0;
//         }
//         for(int i=1;i<=t1.size();i++){
//             for(int j=1;j<=t2.size();j++){
//                 if(t1[i-1]==t2[j-1]){
//                     dp[i][j]=1+dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
//                 }
//             }
//         }
//         if(dp[t1.size()][t2.size()]!=t2.size()){
//             return 0;
//         }
//         dpp.resize(t1.size()+1,vector<int>(t2.size()+1,-1));
//         int ans=check(dp,t1,t2,t1.size(),t2.size(),dp[t1.size()][t2.size()]);
//         return ans;
//     }
// };



class Solution {
public:
//                                    MEMOIZATION
    // vector<vector<int>>dp;
    // int check(string &s, string &t,int i,int j){
    //     if(j<0){
    //         return 1;
    //     }
    //     if(i<0){
    //         return 0;
    //     }
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     if(s[i]==t[j]){
    //         return dp[i][j]=check(s,t,i-1,j)+check(s,t,i-1,j-1);
    //     }
    //     return dp[i][j]=check(s,t,i-1,j);
    // }
    int numDistinct(string s, string t) {
        // dp.resize(s.size(),vector<int>(t.size(),-1));
        // return check(s,t,s.size()-1,t.size()-1);


//                               TABULATION 
        vector<vector<size_t>>dp(s.size()+1,vector<size_t>(t.size()+1));
        for(size_t i=0;i<=t.size();i++){
            dp[0][i]=0;
        }
        for(size_t i=0;i<=s.size();i++){
            dp[i][0]=1;
        }
        for(size_t i=1;i<=s.size();i++){
            for(size_t j=1;j<=t.size();j++){
                if(s[i-1]==t[j-1]){
                    dp[i][j]=dp[i-1][j-1]+dp[i-1][j];
                }
                else{
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[s.size()][t.size()];
    }
};