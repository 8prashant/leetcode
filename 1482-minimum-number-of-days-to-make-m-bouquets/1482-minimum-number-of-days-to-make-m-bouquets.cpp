class Solution {
public:
    bool func(vector<int>& nums,size_t m, size_t k,size_t mid){
        size_t ans=0;
        size_t count=0;
        for(auto x:nums){
            if(x<=mid){
                count++;
            }
            else{
                ans+=count/k;
                count=0;
            }
        }
        ans+=count/k;
        return ans>=m;
    }
    int minDays(vector<int>& nums,int m, int k) {
        if(nums.size()/k<m){
            return -1;
        }
        size_t low=nums[min_element(nums.begin(),nums.end())-nums.begin()];
        size_t high=nums[max_element(nums.begin(),nums.end())-nums.begin()];
        size_t ans=high;
        while(low<=high){
            size_t mid=low+(high-low)/2;
            if(func(nums,m,k,mid)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};