class Solution {
public:
    string func(string s, int i, int j) {
        if (i >= j) {
            return "";
        }
        int start = i;
        int x = i;
        vector<string> v;
        int sum = 0;

        while (x <= j) {
            if (s[x] == '1') {
                sum += 1;
            } else {
                sum -= 1;
            }
            x++;
            if (sum == 0) {
                string sub = s.substr(start + 1, x - start - 1);
                string sbs = func(sub, 0, sub.size() - 1);
                v.push_back("1" + sbs + "0");
                start = x;
            }
        }
        sort(v.begin(), v.end(), greater<string>());
        string result;
        for (auto &str : v) {
            result += str;
        }
        return result;
    }

    string makeLargestSpecial(string s) {
        if (s.size() <= 1) {
            return s;
        }
        return func(s, 0, s.size() - 1);
    }
};