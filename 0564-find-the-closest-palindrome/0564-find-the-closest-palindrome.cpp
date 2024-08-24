class Solution {
public:
    string makePalindrome(const string& half, bool oddLength) {
        string palindrome = half;
        for (int i = oddLength ? half.size() - 2 : half.size() - 1; i >= 0; --i) {
            palindrome += half[i];
        }
        return palindrome;
    }

    string nearestPalindromic(string n) {
        int len = n.size();
        long long original = stoll(n);
        if (len == 1) {
            return to_string(original - 1);
        }
        string half = n.substr(0, (len + 1) / 2);
        long long halfNum = stoll(half);
        string pal1 = makePalindrome(to_string(halfNum), len % 2 != 0);      
        string pal2 = makePalindrome(to_string(halfNum + 1), len % 2 != 0); 
        string pal3 = makePalindrome(to_string(halfNum - 1), len % 2 != 0); 
        string pal4 = string(len - 1, '9');     
        string pal5 = "1" + string(len - 1, '0') + "1";                    

        long long palNum1 = stoll(pal1);
        long long palNum2 = stoll(pal2);
        long long palNum3 = stoll(pal3);
        long long palNum4 = stoll(pal4);
        long long palNum5 = stoll(pal5);

        long long closest = -1;
        long long minDiff = LLONG_MAX;

        vector<long long> candidates = {palNum1, palNum2, palNum3, palNum4, palNum5};

        for (long long candidate : candidates) {
            if (candidate != original) {
                long long diff = abs(candidate - original);
                if (diff < minDiff || (diff == minDiff && candidate < closest)) {
                    closest = candidate;
                    minDiff = diff;
                }
            }
        }

        return to_string(closest);
    }
};
