class Solution {
public:
    vector<vector<int>> dp;
    int dfs(int k, int n){
        if(k==0 || n==0){
            return 0;
        }
        if(k==1 || n==1){
            return n;
        }
        // if(n==1){
        //     return 1;
        // }
        // if(n==0){
        //     return 0;
        // }
        if(dp[k][n]!=-1){
            return dp[k][n];
        }
        int ans=1e8;
        int i=1,j=n;
        while(i<=j){
            int m=(i+j)/2;
            int nb=dfs(k,n-m);
            int b=dfs(k-1,m-1);
            ans=min(ans,1+max(nb,b));
            if(nb>=b){
                i=m+1;
            }
            else{
                j=m-1;
            }
        }
        return dp[k][n]=ans;
    }
    int superEggDrop(int k, int n) {
        dp.assign(k+1,vector<int>(n+1,-1));
        return dfs(k,n);
    }
};