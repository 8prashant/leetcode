class Solution {
public:
    int findKthPositive(vector<int>& vec, int k) {
        int n=vec.size();
        if(k<vec[0]){
            return k;
        }
        int low=0,high=n-1;
        int ans;
        while(low<=high){
            int mid=low+(high-low)/2;
            if(vec[mid]-(mid+1)>=k){
                ans=mid;
                high=mid-1;
            }
            else{
                low=mid+1;
            }
        }
        // cout<<"high="<<high<<endl;
        return vec[high]+(k-(vec[high]-(high+1)));
    }
};