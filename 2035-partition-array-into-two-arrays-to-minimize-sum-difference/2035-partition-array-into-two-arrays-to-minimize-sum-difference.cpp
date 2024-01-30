class Solution {
public:
    void dfs(int index,int n,vector<int>& sub,vector<int>& nums,vector<vector<int>>& res){
        if(index==n){
            int sum=0;
            for(int i=0;i<sub.size();i++){
                sum+=sub[i];
            }
            res[sub.size()].push_back(sum);
            return;
        }
        dfs(index+1,n,sub,nums,res);
        sub.push_back(nums[index]);
        dfs(index+1,n,sub,nums,res);
        sub.pop_back();
    }
    int minimumDifference(vector<int>& nums) {
        int n=nums.size(),ts=0;
        for(int i=0;i<nums.size();i++){
            ts+=nums[i];
        }
        int half=ts/2;
        vector<int> sub;
        vector<vector<int>> left(n/2+1);
        vector<vector<int>> right(n/2+1);
        dfs(0,n/2,sub,nums,left);
        dfs(n/2,n,sub,nums,right);

        int ans=INT_MAX;
        for(int idx=0; idx<=n/2; ++idx){
            sort(right[idx].begin(), right[idx].end());
        }
        for(int i=0;i<=n/2;i++){
            for(auto x:left[i]){
                int target=half-x;
                int it=lower_bound(right[(n/2)-i].begin(),right[(n/2)-i].end(),target)-right[(n/2)-i].begin();
                if(it==right[(n/2)-i].size()){
                    it-=1;
                }
                ans=min(ans,abs((ts-(x+right[(n/2)-i][it]))-(x+right[(n/2)-i][it])));
                if(it-1>=0){
                    ans=min(ans,abs((ts-(x+right[(n/2)-i][it]))-(x+right[(n/2)-i][it])));
                }
            }
        }
        return ans;
    }
};