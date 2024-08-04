class Solution {
public:
    vector<vector<int>>dp;
    int check(int i,int j ,vector<int>& cuts){
        if(j-i<=1){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=INT_MAX;
        for(int l=i+1;l<j;l++){
            ans=min(ans,(
                (cuts[j]-cuts[i])+check(i,l,cuts)+check(l,j,cuts)
            ));
        }
        return dp[i][j]=ans;
    }
    int minCost(int n, vector<int>& cuts) {
        cuts.insert(cuts.begin(),0);
        cuts.push_back(n);
        sort(cuts.begin(),cuts.end());
        n=cuts.size();
        dp.resize(n,vector<int>(n,-1));
        return check(0,cuts.size()-1,cuts);
    }
};