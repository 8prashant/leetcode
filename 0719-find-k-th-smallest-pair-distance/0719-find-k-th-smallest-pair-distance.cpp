class Solution {
public:
    int check(vector<int>& nums, int k,int target){
        int count=0;
        int l=0,r=1;
        while(r<nums.size()){
            while(nums[r]-nums[l]>target){
                l++;
            }
            count+=r-l;
            r++;
        }
        return count;
    }
    int smallestDistancePair(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int l=0,r=nums[nums.size()-1]-nums[0];
        int ans=r;
        while(l<=r){
            int mid=r+(l-r)/2;
            if(check(nums,k,mid)>=k){
                ans=min(ans,mid);
                r=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        return ans;
    }
};