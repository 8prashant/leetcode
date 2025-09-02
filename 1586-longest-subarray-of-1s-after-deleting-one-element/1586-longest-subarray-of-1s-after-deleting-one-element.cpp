class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int zero=0;
        int one=0;
        int ans=0;
        int i=0,j=0;
        while(j<nums.size()){
            while(zero>1){
                if(nums[i]==0){
                    zero--;
                }
                else{
                    one--;
                }
                i++;
            }
            if(nums[j]==0){
                zero++;
            }
            else{
                one++;
            }
            ans=max(ans,(((j-i)+1)-(zero==0?1:zero)));
            j++;
        }
        return ans;
    }
};