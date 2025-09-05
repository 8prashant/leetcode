class Solution {
public:
    int makeTheIntegerZero(int num1, int num2) {
        for (long long k = 1; k <= 36; ++k) {
            long long target = num1 - k * num2;
            if (target < k) {
                break;
            }
            if (__builtin_popcountll(target) <= k) {
                return k;
            }
        }
        
        return -1;
    }
};