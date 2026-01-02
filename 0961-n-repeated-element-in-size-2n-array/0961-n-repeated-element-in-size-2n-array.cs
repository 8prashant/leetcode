public class Solution {
    public int RepeatedNTimes(int[] nums) {
        for(int i=0;i<nums.Length-2;i++){
            if(nums[i]==nums[i+1] || nums[i]==nums[i+2]){
                return nums[i];
            }
        }
        return nums[nums.Length-1];
    }
}