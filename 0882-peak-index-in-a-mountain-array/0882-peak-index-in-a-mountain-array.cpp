class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

        int start=0;
        int end=arr.size()-1;
        while(start<end){
            int mid=(start+end)/2;
            if(arr[mid]>arr[mid+1]){
                end=mid;
            }
            else{
                start=mid+1;
            }
        }
        return start;
    }

};