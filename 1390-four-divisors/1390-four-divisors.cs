public class Solution {
    public int SumFourDivisors(int[] nums) {
        int ans=0;
        foreach(int x in nums){
            int sum=1,count=1;
            for(int i=2;i<=x;i++){
                if(x%i==0){
                    sum+=i;
                    count++;
                }
                if(count==4){
                    if(i==x){
                        ans+=sum;
                    }
                    break;
                }
            }
        }
        return ans;
    }
}