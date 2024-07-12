class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int i=0,j=0;
        int ans=0;
        while(j<nums.size()){
            if(nums[j]%2!=0){
                k--;
            }
            while(k<=0){
                int l=j+1;
                while(l<nums.size()){
                    if(nums[l]%2!=0){
                        break;
                    }
                    l++;
                }
                if(nums[i]%2!=0){
                    k++;
                }
                ans+=(l-j);
                i++;
            }
            j++;
        }
        return ans;
    }
};