class Solution {
public:
    long long maximumOr(vector<int>& nums, int k) {
        long base = 0, backup = 0, best = 0;
        for (auto num : nums)
            backup |= base & num, base |= num;
        for (auto num : nums) 
            best = max(best, base - num | backup | long(num) << k);
        return best;
    }
};