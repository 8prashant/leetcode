class Solution {
public:
    bool func(int n,vector<int>& quantities,int mid){
        int sum=0;
        for(auto x:quantities){
            int rem=0;
            if(x%mid!=0){
                rem++;
            }
            sum+=rem+x/mid;
        }
        return sum<=n;
    }
    int minimizedMaximum(int n, vector<int>& quantities) {
        int low=1;
        int high=quantities[max_element(quantities.begin(),quantities.end())-quantities.begin()];
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(func(n,quantities,mid)){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        return ans;
    }
};