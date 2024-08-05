class Solution {
public:
    vector<int>dp;
    int check(int i ,vector<int>& arr, int k){
        if(i>=arr.size()){
            return 0;
        }
        if(dp[i]!=-1){
            return dp[i];
        }
        int ma=0;
        int ans=INT_MIN;
        for(int l=i;l<i+k&&l<arr.size();l++){
            ma=max(ma,arr[l]);
            ans=max(ans,(
                ((l-i+1)*ma)+check(l+1,arr,k)
            ));
        }
        return dp[i]=ans;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size(),-1);
        return check(0,arr,k);
    }
};