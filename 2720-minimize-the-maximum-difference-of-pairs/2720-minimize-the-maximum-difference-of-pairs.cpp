class Solution {
public:

    bool boobies(vector<int> nums, int p, int diff){
        for(int i=1;i<nums.size();i++){
            if(nums[i]-nums[i-1]<=diff){
                p--;
                i++;
            }
        }

        return (p<=0);
    }

    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(),nums.end());
        int lo=0;
        int high=nums[nums.size()-1]-nums[0];
        int ans=high;
        int mid;
        while(lo<=high){
            mid=lo+(high-lo)/2;
            if(boobies(nums,p,mid)){
                ans=mid;
                high=mid-1;

            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};