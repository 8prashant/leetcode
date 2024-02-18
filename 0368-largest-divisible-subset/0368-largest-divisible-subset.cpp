class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> lcs(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if((nums[i]%nums[j]==0 || nums[j]%nums[i]==0) && (lcs[i].size()<lcs[j].size())){
                    lcs[i]=lcs[j];
                }
            }
            lcs[i].push_back(nums[i]);
        }
        int ma=0,pa;
        for(int i=0;i<n;i++){
            if(lcs[i].size()>ma){
                ma=lcs[i].size();
                pa=i;
            }
        }
        return lcs[pa];
    }
};