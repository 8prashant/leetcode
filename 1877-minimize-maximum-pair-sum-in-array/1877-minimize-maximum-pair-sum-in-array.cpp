class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ma=0;
        int i=0,j=nums.size()-1;
        while(i<j){
            ma=max(ma,nums[i]+nums[j]);
            i++;
            j--;
        }
        return ma;
    }
};