class Solution {
public:
    bool func(vector<int>& weights, int days,int mid){
        int cd=1;
        int sum=0;
        for(auto x:weights){
            if(x>mid){
                return false;
            }
            if(sum+x<=mid){
                sum+=x;
            }
            else{
                sum=x;
                cd+=1;
            }
        }
        return cd<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=1;
        int high=0;
        for(auto x:weights){
            high+=x;
        }
        int ans=high;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(func(weights,days,mid)){
                ans=min(ans,mid);
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};