class Solution {
public:
    vector<vector<int>> v;
    void check(vector<int>&arr, int l, int r, int k) {
        if (arr.size() == k) {
            v.push_back(arr);
            return;
        }
        for (int i = l; i <= r; i++) {
            arr.push_back(i);
            check(arr, i+ 1, r, k);
            arr.pop_back();
        }
    }

    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        check(arr, 1, n , k);
        return v;
    }
};
