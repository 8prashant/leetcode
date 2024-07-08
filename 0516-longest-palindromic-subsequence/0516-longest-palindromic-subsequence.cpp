class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string r=s;
        reverse(r.begin(),r.end());
        vector<vector<int>>dp(s.size()+1,vector<int>(r.size()+1,-1));
        for(int i=0;i<=s.size();i++){
            dp[0][i]=0;
        }
        for(int i=0;i<=r.size();i++){
            dp[i][0]=0;
        }

        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=r.size();j++){
                if(s[i-1]==r[j-1]){
                    dp[i][j]=1+dp[i-1][j-1];
                }
                else{
                    dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        // for(auto x:dp){
        //     for(auto y:x){
        //         cout<<y<<" ";
        //     }
        //     cout<<endl;
        // }
        return dp[s.size()][r.size()];
    }
};