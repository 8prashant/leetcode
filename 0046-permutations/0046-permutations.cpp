class Solution {
public:
    vector<vector<int>>v;
    void check(vector<int>nums,int l , int r){
        if(l==r){
            v.push_back(nums);
            return;
        }
        for(int i=l;i<=r;i++){
            swap(nums[l],nums[i]);
            check(nums,l+1,r);
            swap(nums[l],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        check(nums,0,nums.size()-1);
        return v;
    }
};