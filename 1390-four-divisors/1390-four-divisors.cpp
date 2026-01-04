class Solution {
public:
    int sumFourDivisors(vector<int>& nums) {
        int ans=0;
        for(auto x:nums){
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
};