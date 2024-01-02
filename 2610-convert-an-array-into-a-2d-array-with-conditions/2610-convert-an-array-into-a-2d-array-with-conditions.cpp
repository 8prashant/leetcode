class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> mp;
        vector<vector<int>> ans;
        int maxi = INT_MIN;

        for (int i : nums) {
            mp[i]++;
            maxi = max(mp[i], maxi);
        }

        for (int i = 0; i < maxi; i++) {
            vector<int> vec;

            for (auto it = mp.begin(); it != mp.end();) {
                if (it->second > 0) {
                    vec.push_back(it->first);
                    it->second--;
                }

                if (it->second == 0) {
                    it = mp.erase(it);
                } else {
                    ++it;
                }
            }

            ans.push_back(vec);
        }
        return ans;
    }
};