class Solution {
public:
    int first=INT_MAX,last=INT_MIN;
    void check(int i , int j,vector<int>& nums, int &target){
        if(i>j){
            return;
        }
        while(i<=j){
            int mid=j+(i-j)/2;
            if(nums[mid]==target){
                first=min(first,mid);
                last=max(last,mid);
                check(i,mid-1,nums,target);
                check(mid+1,j,nums,target);
                return;
            }
            if(target>nums[mid]){
                i=mid+1;
            }
            else{
                j=mid-1;
            }
        }
        return;

    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0){
            return {-1,-1};
        }
        check(0,nums.size()-1,nums,target);
        if(first==INT_MAX){
            return {-1,-1};
        }
        return {first,last};
    }
};