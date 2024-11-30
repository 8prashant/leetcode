class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int i=0;
        int j=nums.size()-1;
        while(i<=j){
            int mid=(j-i)/2+i;
            if(nums[mid]<target){
                i=mid+1;
            }
            else if(nums[mid]>target){
                j=mid-1;
            }
            else{//Means nums[mid]==target
                int f=mid;
                int l=mid;
                while(f-1>=0 && nums[f-1]==target){
                    f--;
                }
                while(l+1<=nums.size()-1 && nums[l+1]==target){
                    l++;
                }
                return {f,l};
            }
        }
        return {-1,-1};
    }
};