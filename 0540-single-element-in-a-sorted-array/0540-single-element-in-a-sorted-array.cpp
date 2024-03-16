class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size()==1){
            return nums[0];
        }
        int low=0,high=nums.size()-1;
        if(nums[low]!=nums[low+1]){
            return nums[low];
        }
        if(nums[high]!=nums[high-1]){
            return nums[high];
        }
        low++;
        high--;
        while(low<=high){
            if(low==high){
                return nums[low];
            }
            int mid=low+(high-low)/2;
            if(nums[mid]!=nums[mid-1] && nums[mid]!=nums[mid+1]){
                return nums[mid];
            }
            if(nums[mid-1]==nums[mid]){
                if(mid%2!=0){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
            else if(nums[mid]==nums[mid+1]){
                if(mid%2==0){
                    low=mid+1;
                }
                else{
                    high=mid-1;
                }
            }
        }
        return 0;
    }
};