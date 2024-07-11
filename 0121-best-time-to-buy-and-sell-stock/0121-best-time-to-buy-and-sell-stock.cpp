class Solution {
public:
    int maxProfit(vector<int>& p) {
        int ans=0;
        int mi=p[0];
        for(int i=1;i<p.size();i++){
            if(mi<p[i]){
                ans=max(ans,(p[i]-mi));
            }
            mi=min(mi,p[i]);
        }
        return ans;
    }
};