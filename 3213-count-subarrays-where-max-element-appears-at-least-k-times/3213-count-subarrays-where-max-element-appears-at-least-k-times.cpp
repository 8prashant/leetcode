class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        long long int ans=0;
        long long int i=0,j=0;
        long long int count=0;

        long long int ma=0;
        for(auto x:nums){
            if(x>ma){
                ma=x;
            }
            //ma=max(ma,x);
        }

        while(j<nums.size()){
            if(nums[j]==ma){
                count++;
            }
            while(count>=k){
                if(nums[i]==ma){
                    count--;
                }
                i++;
                ans+=(nums.size()-j);
            }
            j++;
        }

        return ans;
    }
};