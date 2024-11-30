class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i=0,j=nums.size()-1;
        while(i<=j){
            int mid=(j-i)/2+i;
            if(nums[mid]==target){
                return true;
            }
            if(nums[i]==nums[mid]&&nums[mid]==nums[j]){
                i++;
                j--;
            }
                else{
                if(nums[i]<=nums[mid]){
                    if(nums[i]<=target && nums[mid]>target){
                        j=mid-1;
                    }
                    else{
                        i=mid+1;
                    }
                }
                else{
                    if(nums[mid]<target && nums[j]>=target){
                        i=mid+1;
                    }
                    else{
                        j=mid-1;
                    }
                }
            }
        }
        return false;
    }
};