class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        long long mini=-1e17;
        long long a=mini,b=mini,c=mini;
        long long res=mini;
        long long prev=nums[0];
        for(int i=1; i<nums.size(); i++){
            long long na=mini,nb=mini,nc=mini;
            long long curr=nums[i];
            if(prev<curr){
               na=max(prev,a)+curr;
               nc=max(b,c)+curr;
            }else if(prev>curr){
               nb=max(b,a)+curr;
            }
            a=na;
            b=nb;
            c=nc;
            res=max(res,c);
            prev=curr;
        }
        return res;
    }
};