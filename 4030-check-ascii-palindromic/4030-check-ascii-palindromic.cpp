class Solution {
public:
    bool isPalindromic(string s) {
        string got = "";

        for (const auto &c: s) {
            int ascii = int(c);

            string bin = bitset<8>(ascii).to_string();

            got += bin;
        }

        int i = 0, j = got.size() - 1;
        while (i < j) {
            if (got[i++] != got[j--]) {
                return false;
            }
        }

        return true;
    }
};