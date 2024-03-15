class Solution {
public:
    int findMin(vector<int>& nums) {
        int ans=INT_MAX;
        int low=0,high=nums.size()-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            ans=min({ans,nums[mid],nums[low],nums[high]});
            if(nums[high]>=nums[mid]){
                high=mid-1;
            }
            else if(nums[low]<=nums[mid]){
                low=mid+1;
            }
        }
        return ans;
    }
};