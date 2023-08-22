class Solution {

public:

    string convertToTitle(int cn) {
        


        vector<char> lst;

        string s;

        while (cn > 0) {

            if (cn >= 26) {

                int a = cn % 26;

                if (a == 0) {

                    a = 26;

                    cn -= 1;

                }

                lst.push_back(static_cast<char>(a + 64));

                cn /= 26;

            } else {

                lst.push_back(static_cast<char>(cn + 64));

                break;

            }

        }

        for (int i = lst.size() - 1; i >= 0; i--) {

            s += lst[i];

        }

        return s;

    }

};